function [] = gen_wrap(varin)
% Diese Funktion generiert den C-Code für ein Matlab-Interface für einen
% mit gen_lqdocpip generierten Solver.
% 
% Zu beachten:
%   - Diese Funktion muss nach dem Generieren des Solver-Quellcodes durch
%   gen_lqdocpip aufgerufen werden, da die Daten aus der globalen
%   Variablen "gendata" benötigt werden.
%   - Beim Benutzen muss das an das Interface übergebene Struct folgende
%   Felder besitzen:
%      - Hxx, Hxu, Huu, Hss,
%      - f0x, f0u, f0s,
%      - fx, fu, f,
%      - gx, gu, g,
%      - xinit (= x0, Startzustand)
%   Fehlt eines dieser Felder (oder die Dimension entspricht nicht dem bei
%   der Erstellung des Quellcodes angegeben Werts), stürzt MATLAB ab;
%   entsprechende Sicherungsfunktionen sind geplant aber momentan noch
%   nicht enthalten.
% ---------------------------------------
%
% Programmiert 2014-2016 von Fabian Krank
% Kontakt: fabian.krank@googlemail.com
%

% #############
% # Changelog #
% #############
%
% DD.MM.YYYY (Autor):
%   - Bsp (Änderung)

global gendata
global genstr

if isempty(gendata)
    error('Erst Codegenerator für Solver ausführen!');
end

nx = gendata.dim.n_x;
nu = gendata.dim.n_u;
n_c = gendata.dim.n_c;
n_s = gendata.dim.n_s;
max_iter = gendata.parameter.max_iter;

%% Generierung Daten für Input - Ouput
% Gütefunktion
cat     = {'J'   'J'   'J'   'J'   'J'   'J'   'J'   };
varname = {'Hxx' 'Hxu' 'Huu' 'Hss' 'f0x' 'f0u' 'f0s' };
dim1    = {nx    nx    nu    n_s    nx    nu    n_s    };
dim2    = {nx    nu    nu    n_s    1     1     1     };

Jvars = {};
for i=1:length(cat)
    Jvars{i}.cat     = cat{i};
    Jvars{i}.name    = varname{i};
    Jvars{i}.dim1    = dim1{i};
    Jvars{i}.dim2    = dim2{i};
end

% Gleichungenebenbedingungen
cat     = {'eq' 'eq' 'eq'};
varname = {'fx' 'fu' 'f' };
dim1    = {nx   nx   nx  };
dim2    = {nx   nu   1   };

eqvars = {};
for i=1:length(cat)
    eqvars{i}.cat     = cat{i};
    eqvars{i}.name    = varname{i};
    eqvars{i}.dim1    = dim1{i};
    eqvars{i}.dim2    = dim2{i};
end

% Ungleichungsnebenbedingungen
cat     = {'ineq' 'ineq' 'ineq'};
varname = {'gx'   'gu'   'g'   };
dim1    = {n_c     n_c     n_c    };
dim2    = {nx     nu     1     };

ineqvars = {};
for i=1:length(cat)
    ineqvars{i}.cat     = cat{i};
    ineqvars{i}.name    = varname{i};
    ineqvars{i}.dim1    = dim1{i};
    ineqvars{i}.dim2    = dim2{i};
end

% Optimierungsvariablen x, u, s, p, y, nu, yny
cat     = {'optvars' 'optvars' 'optvars' 'optvars' 'optvars' 'optvars'};
varname = {'x'       'u'       's'       'p'       'y'       'nu'    };
dim1    = {nx        nu        n_s       nx        n_c+n_s   n_c+n_s   };
dim2    = {1         1         1         1         1         1       };

optvars = {};
for i=1:length(cat)
    optvars{i}.cat     = cat{i};
    optvars{i}.name    = varname{i};
    optvars{i}.dim1    = dim1{i};
    optvars{i}.dim2    = dim2{i};
end

% Schrittvariablen dx, du, ds, dp, dy, dnu, dyny
cat     = {'stepvars' 'stepvars' 'stepvars' 'stepvars' 'stepvars' 'stepvars'};
varname = {'dx'       'du'       'dp'       'dy'       'dnu'      'ds'      };
dim1    = {nx         nu         nx         n_c+n_s    n_c+n_s    n_s       };
dim2    = {1          1          1          1          1          1         };

stepvars = {};
for i=1:length(cat)
    stepvars{i}.cat     = cat{i};
    stepvars{i}.name    = varname{i};
    stepvars{i}.dim1    = dim1{i};
    stepvars{i}.dim2    = dim2{i};
end

cat     = {'rhsvar' 'rhsvar' 'rhsvar' 'rhsvar' 'rhsvar' 'rhsvar' 'rhsvars'};
varname = {'rf0x'   'rf0u'   'rf0s'   'rf'     'rc'     'rk'     'rs'     };
dim1    = {nx       nu       n_s       nx       n_c        n_c+n_s   n_s   };
dim2    = {1        1        1        1        1        1        1};

rhsvars = {};
for i=1:length(cat)
    rhsvars{i}.cat     = cat{i};
    rhsvars{i}.name    = varname{i};
    rhsvars{i}.dim1    = dim1{i};
    rhsvars{i}.dim2    = dim2{i};
end

cat     = {'rrhsvar' 'rrhsvar' 'rrhsvar' 'rrhsvar' };
varname = {'rrf0x'   'rrf0u'   'rhsxs'   'yny'      };
dim1    = {nx        nu        n_s        n_c     };
dim2    = {1         1         1         1       };

rrhsvars = {};
for i=1:length(cat)
    rrhsvars{i}.cat     = cat{i};
    rrhsvars{i}.name    = varname{i};
    rrhsvars{i}.dim1    = dim1{i};
    rrhsvars{i}.dim2    = dim2{i};
end

% Blockeliminationsverfahren
cat     = {'Be'  'Be'  'Be'  'Be'  'Be'  'Be' 'Be'  'Be'  'Be'  'Be'};
varname = {'Gxx' 'Gxu' 'Guu' 'Rux' 'Vxx' 'L'  'Gx'  'Gu'  'Vx'  'Ru'};
dim1    = {nx    nx    nu    nu    nx    nu   nx    nu    nx    nu};
dim2    = {nx    nu    nu    nx    nx    nu   1     1     1     1};

Bvars = {};
for i=1:length(cat)
    Bvars{i}.cat     = cat{i};
    Bvars{i}.name    = varname{i};
    Bvars{i}.dim1    = dim1{i};
    Bvars{i}.dim2    = dim2{i};
end

cat     = {'debug1'     'debug1'    'debug1'       'debug1'       'debug1'        'debug1'       'debug1'    'debug1'  };
varname = {'debug_dgap' 'debug_phi' 'debug_minphi' 'debug_norm_d' 'debug_norm_r0' 'debug_norm_r' 'debug_mu0' 'debug_mu'};
dim1    = {max_iter     max_iter    max_iter       1              1               max_iter       1           max_iter  };
dim2    = {1            1           1              1              1               1              1           1         };
singlevar={1            1           1              1              1               1              1           1         };

singlevars = {};
for i=1:length(cat)
    singlevars{i}.cat     = cat{i};
    singlevars{i}.name    = varname{i};
    singlevars{i}.dim1    = dim1{i};
    singlevars{i}.dim2    = dim2{i};
    singlevars{i}.singlevar    = singlevar{i};
end


cat     = {'debug2'          'debug2'               'debug2'       'debug2'     };
varname = {'debug_alpha_max' 'debug_mehrotra_alpha' 'debug_mu_aff' 'debug_sigma'};
dim1    = {max_iter          max_iter               max_iter       max_iter     };
dim2    = {1                 1                      1              1            };
singlevar={1                 1                      1              1            };


singlevars2 = {};
for i=1:length(cat)
    singlevars2{i}.cat     = cat{i};
    singlevars2{i}.name    = varname{i};
    singlevars2{i}.dim1    = dim1{i};
    singlevars2{i}.dim2    = dim2{i};
    singlevars2{i}.singlevar    = singlevar{i};
end

cat     = {'intvar' 'intvar'     'intvar'       'intvar'};
varname = {'iter'   'error_line' 'error_source' 'termcode'};
dim1    = {1        1            1              1};
dim2    = {1        1            1              1};
singlevar={1        1            1              1};
intvar =  {1        1            1              1};

intvars = {};
for i=1:length(cat)
    intvars{i}.cat       = cat{i};
    intvars{i}.name      = varname{i};
    intvars{i}.dim1      = dim1{i};
    intvars{i}.dim2      = dim2{i};
    intvars{i}.singlevar = singlevar{i};
    intvars{i}.intvar    = intvar{i};
end


cat     = {'stat'          'stat'              'stat'            'stat'           'stat'};
varname = {'stat_iter_ref' 'stat_num_iter_ref' 'stat_num_factor' 'stat_num_solve' 'stat_time'};
dim1    = {max_iter        1                   1                 1                max_iter};
dim2    = {1               1                   1                 1                1};
singlevar={1               1                   1                 1                1};
intvar =  {1               1                   1                 1                0};

statvars = {};
for i=1:length(cat)
    statvars{i}.cat       = cat{i};
    statvars{i}.name      = varname{i};
    statvars{i}.dim1      = dim1{i};
    statvars{i}.dim2      = dim2{i};
    statvars{i}.singlevar = singlevar{i};
    statvars{i}.intvar    = intvar{i};
end

var_in = {Jvars{1:end} eqvars{1:end} ineqvars{1:end}};
if gendata.debug == 1
var_out= {Jvars{1:end} eqvars{1:end} ineqvars{1:end} optvars{1:end} ...
    stepvars{1:end} ...
    rhsvars{1:end}...
    rrhsvars{1:end}...
    Bvars{1:end}...
    singlevars{1:end}...
    singlevars2{1:end}...
    intvars{1:end} ...
    statvars{1:end} ...
    };
else
    var_out= {optvars{1:end} statvars{1:end} intvars{1:end}};
end


%% Quellcodegenerierung
includestr = [];
varinstr = [];
varoutstr = [];

path_orig = pwd;
%cd(gendata.path_algorithmus);

includes = {'mex.h' [gendata.name '_glqdocpip.h']};

includestr = gen_include(includes);
varinstr = gen_wrap_var_in(var_in);
varoutstr = gen_wrap_var_out(var_out);

genstr = includestr;
addl('')
addl(varinstr)
addl(varoutstr)
addl('')
addl('void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])')
      
addl('{')
%addl('float *alpha_max, *mehrotra_fpd, *mehrotra_alpha;')
addl('int termcode = -2;')    

addl('matlab2c(prhs[0]);')
%addl('mexPrintf("matlab2c: done\n");')
addl(['termcode = ' gendata.prefix 'glqdocpip();'])
addl('mexPrintf("Termcode: %i\n",termcode);')
addl('mexEvalString("drawnow;");')

% Performance Test
if gendata.performance_test == 1
    addl(['{'])
    addl('int i;')
    addl('double time;')
    addl('char varname[1024];')
    for i = 1:length(gendata.performance_tests)
        addl(['for(i=1;i<=' num2str(gendata.performance_tests{i}.iterations) ';i++){'])
        addl(['time = ' gendata.prefix 'glqdocpip_performance_test_' gendata.performance_tests{i}.name '();'])
        %addl(['mexPrintf("Test ' gendata.performance_tests{i}.name '(' num2str(gendata.performance_tests{i}.runs) ' Runs), Iteration %d: %9.6f sec\n",i,time);'])

        addl(['sprintf(varname,"Test %20s ()\n","' gendata.performance_tests{i}.name '");'])
        %addl(['mexPrintf(varname);'])
        addl(['mexPrintf("Test %25s (' num2str(gendata.performance_tests{i}.runs) ' Runs): %9.6f ms (avg)\n","' gendata.performance_tests{i}.name '",time);'])
        %addl(['mexPrintf("Test ' gendata.performance_tests{i}.name '(' num2str(gendata.performance_tests{i}.runs) ' Runs): %9.6f sec\n",time);'])
        addl(['termcode = ' gendata.prefix 'glqdocpip();'])
        %addl('mexPrintf("Termcode: %i\n",termcode);')
        addl('mexEvalString("drawnow;");')
        addl('}')
    end
    addl('}')
end

addl('c2matlab(plhs);')

addl('return;')
addl('}')
str = [genstr char(10)];
genstr = [];

%cd(path_orig);

%% Quellcode in Datei schreiben: c-Datei
%cd(gendata.path_target);
fid = fopen(fullfile(gendata.path_target),[gendata.name '_wrap.c']),'wt');
fwrite(fid,str);
fclose(fid);
disp([gendata.name '_wrap.c wurde erstellt.']);
%cd(gendata.path_orig);

end