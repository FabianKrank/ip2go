function [pdata4sim] = gen_sfun(sfun_version,problemdata)
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
% 22.11.16 (Mayer):
%   - Übergabe Index für wrap_version
%     wrap_version==0 default
%     wrap_version==1 weniger Optimierungsvariablen als Ausgang für Probleme mit hoher Dimension
%     anstelle von (x, u, s, p, y, nu, yny) nur (x,u)

global gendata
global genstr


if isempty(gendata)
    error('Erst Codegenerator für Solver ausführen!');
end

if nargin<1
   sfun_version=0; 
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
switch sfun_version
    case 1
        % Optimierungsvariablen x, u 
        cat     = {'optvars' 'optvars' };
        varname = {'x'       'u'         };
        dim1    = {nx        nu          };
        dim2    = {1         1          };
    otherwise
        cat     = {'optvars' 'optvars' 'optvars' 'optvars' 'optvars' 'optvars'};
        varname = {'x'       'u'       's'       'p'       'y'       'nu'    };
        dim1    = {nx        nu        n_s       nx        n_c+n_s   n_c+n_s   };
        dim2    = {1         1         1         1         1         1       };
        
end

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


% Quellcodegenerierung

%% Header

path_orig = pwd;
cd(gendata.path_algorithmus);

includes = {'simstruc.h' [gendata.name '_glqdocpip.h']};

includestr = gen_include(includes);
genstr=[];
addc(['----------------------------------------------------------------------------',char(10),...
    ' *',char(10),' * ',gendata.name, '_glqdocpip.h',char(10),' *',char(10),...
    ' *----------------------------------------------------------------------------'])
addl('')
addc('Register parameters')
addl(['#define NUMPAR ', num2str(0)])
addl('')
tmp_str=[ 'Input ports:',char(10),' *   1.   SelectUpdates',char(10)];
tmp_str=[tmp_str, ' *   2.    x0',char(10)];
for k=1:numel(var_in)
    tmp_str=[tmp_str, ' *   ', num2str(k+2),'.    ',var_in{k}.name,char(10)];
end


addc(tmp_str)
addl(['#define NUMINPORTS ', num2str(numel(var_in)+2)])
addl('')
tmp_str=[ 'Output ports:',char(10)];
for k=1:numel(var_out)
    tmp_str=[tmp_str, ' *   ', num2str(k),'.    ',var_out{k}.name,char(10)];
end

addc(tmp_str)
addl(['#define NUMOUTPORTS ', num2str(numel(var_out))])
addl('')
addl(['#define S_FUNCTION_NAME ',gendata.name, '_glqdocpip_sfunction'])
addl('#define S_FUNCTION_LEVEL 2')
addl('')
addl(includestr)

% END Header 

%% mdlInitializeSizes
addl('static void mdlInitializeSizes(SimStruct *S)')
addl('{')
addc(' Number of expected parameters ')
addl('    ssSetNumSFcnParams(S, NUMPAR); ')
addc('Festlegen von inneren Zuständen und Speichern ')
addl('    ssSetNumContStates(S, 0);')
addl('    ssSetNumDiscStates(S, 0);')
addl('')
addl('')
%Input Ports

addc('Festlegung der Dimensionen der Blockeingänge sowie der Datentypen.')
addl('    {')
addl('')
addl('        if (!ssSetNumInputPorts(S, NUMINPORTS))')
addl('            return;')
addl('')
gen_sfun_initialize_var_in(var_in)
addl('')
addl('    }')

%Output Ports
addc('Festlegung der Dimensionen der Blockausgänge sowie der Datentypen.')
addl('    {')
addl('')
addl('        if (!ssSetNumOutputPorts(S, NUMOUTPORTS))')
addl('            return;')
addl('')
gen_sfun_initialize_var_out(var_out)
addl('')
addl('    }')


%Weitere Blockeigenschaften
addc('Festlegung weiterer Blockeigenschaften.')
addl('    {')
addl('        ssSetNumSampleTimes(S, 1);')
addl('        ssSetNumModes(S, 0);')
addl('        ssSetNumNonsampledZCs(S, 0);')
addl('        ssSetOptions(S, 0);')
addl('    }')



addl('}')
% END mdlInitializeSizes
addl('')
addl('')

%% mdlInitializeSampleTimes
addl('mdlInitializeSampleTimes(SimStruct *S)')
addl('{')
addl('    ssSetSampleTime(S, 0,INHERITED_SAMPLE_TIME);')
addl('    ssSetOffsetTime(S, 0, 0.0);')
addl('}')

% END mdlInitializeSampleTimes
addl('')
addl('')

%% mdlStart
addl('#define MDL_START')
addl('#if defined(MDL_START)')
addl('static void mdlStart(SimStruct *S)')
addl('{')
addl('}')
addl('#endif /*  MDL_START */')

% END mdlStart
addl('')
addl('')

%% mdlOutputs
addl('static void mdlOutputs(SimStruct *S, int_T tid)')
addl('{')
addl('int j;')
addl('int j1;')
addl('int termcode;')
addl([gendata.prec ' *dptr;'])
addl(['int *dptr_int;'])
addc('Einlesen der Werte')
gen_sfun_outputs_var_in(var_in)
addl('')
addc('Ausgänge vorbereiten')
gen_sfun_outputs_var_out(var_out)
addl('')
%addc('Initialisierung aller Ausgänge mit Default-Werten')
%addl('')
addc('Daten in Optimalsteuerungsproblem schreiben')
gen_sfun_outputs_var_in2problem(var_in)
addl('')
addc('Optimalsteuerungsproblem lösen')
addl(['        termcode = '  gendata.name  '_glqdocpip();'])
addl('')
addc('Ausgänge beschreiben')
gen_sfun_outputs_var_out2problem(var_out)
addl('')
addl('}')

% END mdlOutputs
addl('')
addl('')

%% Sonstiges 
addl('#undef MDL_UPDATE')
addl('#undef MDL_DERIVATIVES')
addl('')
addl('')

%% mdlTerminate
addl('static void mdlTerminate(SimStruct *S)')
addl('{')
addl('}')

% END mdlTerminate
addl('')
addl('')

%% Finishing
addc(['=============================*',char(10),' * Required S-function trailer *',char(10),' *============================='])
addc('Is this file being compiled as a MEX-file? ')
addl('#ifdef  MATLAB_MEX_FILE  ')
addc('MEX-file interface mechanism')
addl('#include "simulink.c"')
addl('#else')
addc('Code generation registration function')
addl('#include "cg_sfun.h" ')
addl('#endif')


str = [genstr char(10)];
genstr = [];

cd(path_orig);

%% Quellcode in Datei schreiben: c-Datei
cd(gendata.path_target);
disp('S-Function-Generierung fertig.');
disp(['Es wurden ' num2str(length(strfind(str,char(10)))+1) ' Zeilen Quellcode erstellt.']);

fid = fopen([gendata.name '_glqdocpip_sfunction.c'],'wt+');
fwrite(fid,str);
fclose(fid);
disp([gendata.name '_glqdocpip_sfunction.c wurde erstellt.']);
cd(gendata.path_orig);

%% Generierung der Simulinkmaske
cd(path_orig);
genstr=[];
addl(['text(.05,.5,''' gendata.name '_glqdocpip_sfunction.c'', ' '''hor'',''left'')'])
gen_sfun_mask_var_in(var_in)
gen_sfun_mask_var_out(var_out)


str = [genstr char(10)];
genstr = [];
%% Quellcode in Datei schreiben: c-Datei
cd(gendata.path_target);
disp('Maskgen-Generierung fertig.');
disp(['Es wurden ' num2str(length(strfind(str,char(10)))+1) ' Zeilen Quellcode erstellt.']);

fid = fopen([gendata.name '_simulink_mask.txt'],'wt+');
fwrite(fid,str);
fclose(fid);
disp([gendata.name 'simulink_mask.txt wurde erstellt.']);
cd(gendata.path_orig)


%% Inputdaten für Simulink

[ pdata4sim ] = problemdata2simulink( problemdata, var_in );


end