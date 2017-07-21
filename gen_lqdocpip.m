function [] = gen_lqdocpip(generation_data)
% Diese Funktion generiert C-Quellcode zur Lösung von
% Optimalsteuerungsproblemen mit
%   - linear-quadratischer Gütefunktion     J(z) = 1/2 * z' * H * z + f0' * z
%   - linearen GLeichungsnebenbedingungen   f(z) = f * z + f = 0
%   - linearen Ungleichungsnebenbedingungen g(z) = g * z + g <= 0
%
% Dabei besteht der Vektor z = [x' u' s'] aus
%   - Zustandsvektor x
%   - Eingangsvektor u
%   - Schlupfvariablenvektor s
%
% ---------------------------------------
%
% Programmiert 2014-2016 von Fabian Krank
% Kontakt: fabian.krank@googlemail.com
%

% #############
% # Changelog #
% #############
%
% 22.11.16 Annika Mayer (annika.mayer@isys.uni-stuttgart.de):
%   - Platformdefinition über eigene Definitionsparameter z.B.
%   "IP2GO_DS1103", da die Platformparameter nicht von allen
%   Compilern gesetzt werden.
%   Wenn Timerfunktion nicht korrekt funktioniert, steigt Solver mit Termcode 7
%   Zeitlimit überschritten aus
global gendata;

gendata = generation_data;

gendata.prec = gendata.precision;
gendata.parameter.m_ineq = sum(generation_data.dim.n_c + generation_data.dim.n_s);

if isempty(gendata.path_target)
    gendata.path_target = pwd;
end

if isempty(gendata.path_algorithmus)
    gendata.path_algorithmus = [pwd '\algorithmus'];
end

if isempty(gendata.path_math)
    gendata.path_math = [pwd '\math'];
end

if isempty(gendata.path_structures)
    gendata.path_structures = [pwd '\structures'];
end

gendata.path_orig = pwd;

%% Parameter setzen
% Allgemein
gendata.prefix = [gendata.name '_'];
gendata.filename = [gendata.prefix 'glqdocpip'];

% newline-char:
gendata.nlc = char(10);

% Abzusichernde Funktionen
gendata.safefuns{1} = 'vv_elediv';
gendata.safefuns{2} = 'mm_elediv';
gendata.safefuns{3} = 'chol_factor';
gendata.safefuns{4} = 'chol_solve';

% Für Matlab Interface: Datentypen der übergebenen Variablen
% SINGLE
%gendata.prec_out = 'float';
%gendata.prec_out_mx = 'mxSINGLE_CLASS';
%gendata.prec_in = 'float';
% DOUBLE
gendata.prec_out = 'double';
gendata.prec_out_mx = 'mxDOUBLE_CLASS';
gendata.prec_in = 'double';

% Maxima des jeweiligen Datentyps
if strcmp(gendata.prec,'float')
    gendata.prec_max = 'FLT_MAX';
elseif strcmp(gendata.prec,'double')
    gendata.prec_max = 'DBL_MAX';
else
    error('Ungültige Prec')
end

% Loop unrolling
if ~isfield(gendata,'loopunrolling')
    gendata.loopunrolling = 0;
end

%% Variablen, für die ein Interface erstellt werden soll
% &nok --> Variable kommt nur einmal vor (nicht für jedes k)
% &int --> Variable hat Typ "int" und nicht wie in "prec" definiert
inoutvars = {...
    ... Optimierungsvariablen
    'x' 'u' 's' 'p' 'y' 'nu' ...
    ... Gütefunktion:
    'Hxx' 'Hxu' 'Huu'  'Hss' ...
    'f0x' 'f0u' 'f0s' ...
    ... GNBs:
    'fx'  'fu'  'f' ...
    ... UGNBs:
    'gx'  'gu'  'g' ...
    ... Statistik
    'stat_time&nok' 'stat_iter_ref&nok&int' ...
    'stat_num_factor&nok&int' 'stat_num_solve&nok&int' 'stat_num_iter_ref&nok&int'...
    ... Sonstiges
    'iter&int&nok' 'termcode&int&nok'...
    'error_line&nok&int' 'error_source&nok&int'...
    'norm_d&nok' ...
    };
if gendata.debug == 1
    inoutvars = {inoutvars{1:end} ...
    ... Schrittvariablen
    'dx'  'du' 'ds' 'dp' 'dy' 'dnu' ...    
    ... rhs-Variablen
    'rf0x' 'rf0u' 'rf0s' 'rf' 'rc' 'rk' 'rs'...
    ... rrhs-Variablen
    'rrf0x' 'rrf0u' 'rhsxs' 'yny' ...
    ... Blockeleminations-Variablen
    'Gxx' 'Gxu' 'Guu' 'Rux' 'Vxx' 'L'  'Gx'  'Gu'  'Vx'  'Ru' ...
    ... Debug Aufruf 1:
    'debug_dgap&nok' 'debug_phi&nok' 'debug_minphi&nok' ...
    'debug_norm_r0&nok' 'debug_norm_r&nok' 'debug_norm_d&nok' ...
    'debug_mu0&nok' 'debug_mu&nok' ...
    ... Debug Aufruf 2:
    'debug_sigma&nok' 'debug_mu_aff&nok' ...
    'debug_alpha_max&nok' 'debug_mehrotra_alpha&nok' ...
    };
end

%% Strukturen für Strukturausnutzung
if isfield(gendata, 'use_structures') && gendata.use_structures == 1
    cd(gendata.path_structures);
    matrix_structures = gendata.matrix_structures;
    
    gendata.structures = cell(0);
    
    % Voll besetzte Strukturen laden
    full_structures = structures_load_default(gendata.dim.n_x,gendata.dim.n_u,gendata.dim.n_c,gendata.dim.n_s);
    
    % Spezielle Strukutren erstellen
    custom_structures = cell(0);
    % Gütefunktion - quad
    custom_structures{end+1} = structures_gen_custom('Hxx_0',matrix_structures.Hxx{1});
    custom_structures{end+1} = structures_gen_custom('Hxx_k',matrix_structures.Hxx{2});
    custom_structures{end+1} = structures_gen_custom('Hxx_end',matrix_structures.Hxx{end});
    custom_structures{end+1} = structures_gen_custom('Hxu_0',matrix_structures.Hxu{1});
    custom_structures{end+1} = structures_gen_custom('Hxu_k',matrix_structures.Hxu{2});
    custom_structures{end+1} = structures_gen_custom('Hxu_end',matrix_structures.Hxu{end});
    custom_structures{end+1} = structures_gen_custom('Huu_0',matrix_structures.Huu{1});
    custom_structures{end+1} = structures_gen_custom('Huu_k',matrix_structures.Huu{2});
    custom_structures{end+1} = structures_gen_custom('Huu_end',matrix_structures.Huu{end});
    custom_structures{end+1} = structures_gen_custom('Hss_0',matrix_structures.Hss{1});
    custom_structures{end+1} = structures_gen_custom('Hss_k',matrix_structures.Hss{2});
    custom_structures{end+1} = structures_gen_custom('Hss_end',matrix_structures.Hss{end});
    % Gütefunktion - lin
    custom_structures{end+1} = structures_gen_custom('f0x_0',matrix_structures.f0x{1});
    custom_structures{end+1} = structures_gen_custom('f0x_k',matrix_structures.f0x{2});
    custom_structures{end+1} = structures_gen_custom('f0x_end',matrix_structures.f0x{end});
    custom_structures{end+1} = structures_gen_custom('f0u_0',matrix_structures.f0u{1});
    custom_structures{end+1} = structures_gen_custom('f0u_k',matrix_structures.f0u{2});
    custom_structures{end+1} = structures_gen_custom('f0u_end',matrix_structures.f0u{end});
    custom_structures{end+1} = structures_gen_custom('f0s_0',matrix_structures.f0s{1});
    custom_structures{end+1} = structures_gen_custom('f0s_k',matrix_structures.f0s{2});
    custom_structures{end+1} = structures_gen_custom('f0s_end',matrix_structures.f0s{end});
    % GNBs
    custom_structures{end+1} = structures_gen_custom('fx_0',matrix_structures.fx{1});
    custom_structures{end+1} = structures_gen_custom('fx_k',matrix_structures.fx{2});
    custom_structures{end+1} = structures_gen_custom('fx_end',matrix_structures.fx{end});
    custom_structures{end+1} = structures_gen_custom('fu_0',matrix_structures.fu{1});
    custom_structures{end+1} = structures_gen_custom('fu_k',matrix_structures.fu{2});
    custom_structures{end+1} = structures_gen_custom('fu_end',matrix_structures.fu{end});
    custom_structures{end+1} = structures_gen_custom('f_0',matrix_structures.f{1});
    custom_structures{end+1} = structures_gen_custom('f_k',matrix_structures.f{2});
    custom_structures{end+1} = structures_gen_custom('f_end',matrix_structures.f{end});
    % UGNBs
    custom_structures{end+1} = structures_gen_custom('gx_0',matrix_structures.gx{1});
    custom_structures{end+1} = structures_gen_custom('gx_k',matrix_structures.gx{2});
    custom_structures{end+1} = structures_gen_custom('gx_end',matrix_structures.gx{end});
    custom_structures{end+1} = structures_gen_custom('gu_0',matrix_structures.gu{1});
    custom_structures{end+1} = structures_gen_custom('gu_k',matrix_structures.gu{2});
    custom_structures{end+1} = structures_gen_custom('gu_end',matrix_structures.gu{end});
    custom_structures{end+1} = structures_gen_custom('g_0',matrix_structures.g{1});
    custom_structures{end+1} = structures_gen_custom('g_k',matrix_structures.g{2});
    custom_structures{end+1} = structures_gen_custom('g_end',matrix_structures.g{end});
    
    gendata.structures = {full_structures{1:end} custom_structures{1:end}};
    
    % IDs zuweisen
    for i = 1:length(gendata.structures)
        gendata.structures{i}.sid = i;
    end
    cd(gendata.path_orig);
end

%% Generierung Quellcode
cd(gendata.path_algorithmus);

disp(' ');
disp('Quellcode wird generiert...');

gen_stat_init();

cinclude = {'float.h' 'math.h'};
hinclude = {};

cdefine={};
if strcmp(gendata.platform,'WIN')
  cdefine={'IP2GO_WIN'};
elseif strcmp(gendata.platform ,'DS1103')
  cdefine={'IP2GO_DS1103'};
end
  


gendata.functions = [];
gendata.tmps = [];

% GLS aufstellen
gendata.str.c.rhs_affine = gen_lqdocpip_rhs_affine();
gen_stat_section('rhs_affine');
gendata.str.c.rhs_reduced = gen_lqdocpip_rhs_reduced();
gen_stat_section('rhs_reduced');
gendata.str.c.rhs_corrector = gen_lqdocpip_rhs_corrector();
gen_stat_section('rhs_corrector');

% GLS lösen
gendata.str.c.factor = gen_lqdocpip_factor();
gen_stat_section('factor');
gendata.str.c.solve = gen_lqdocpip_solve();
gen_stat_section('solve');
gendata.str.c.dereduce = gen_lqdocpip_dereduce();
gen_stat_section('dereduce');

% Nachiteration
gendata.str.c.iter_ref = gen_lqdocpip_iter_ref();
gen_stat_section('iter_ref');
gendata.str.c.rhs_iter_ref = gen_lqdocpip_rhs_iter_ref();
gen_stat_section('rhs_iter_ref');

% Werte berechnen
gendata.str.c.calc_duality_gap = gen_lqdocpip_calc_duality_gap();
gen_stat_section('calc_duality_gap');
gendata.str.c.calc_mu = gen_lqdocpip_calc_mu();
gen_stat_section('calc_mu');
gendata.str.c.calc_mu_aff = gen_lqdocpip_calc_mu_aff();
gen_stat_section('calc_mu_aff');
gendata.str.c.calc_phi = gen_lqdocpip_calc_phi();
gen_stat_section('calc_phi');
gendata.str.c.calc_sigma = gen_lqdocpip_calc_sigma();
gen_stat_section('calc_sigma');

% Divergenz- und Konvergenztests, Timer
gendata.str.c.check_condiv = gen_lqdocpip_check_condiv();
gen_stat_section('check_condiv');
[gendata.str.c.timer, gendata.str.c.include_timer]    = gen_lqdocpip_timer();
gen_stat_section('timer');

% Statistik
gendata.str.c.stat = gen_lqdocpip_stat();
gen_stat_section('stat');

% Debug
if gendata.debug == 1
    gendata.str.c.debug1 = gen_lqdocpip_debug1();
    gendata.str.c.debug2 = gen_lqdocpip_debug2();
    gen_stat_section('debug');
end

% Schritt
gendata.str.c.max_stepsize = gen_lqdocpip_max_stepsize();
gen_stat_section('max_stepsize');
gendata.str.c.mehrotra_step = gen_lqdocpip_mehrotra_step();
gen_stat_section('mehrotra_step');
gendata.str.c.step = gen_lqdocpip_step();
gen_stat_section('step');

% Normen
gendata.str.c.calc_norm_d = gen_lqdocpip_calc_norm_d();
gen_stat_section('norm_d');
gendata.str.c.calc_norm_r = gen_lqdocpip_calc_norm_r();
gen_stat_section('norm_r');
%gendata.str.c.calc_norm_h = gen_lqdocpip_calc_norm_h();
%gendata.str.c.calc_norm_c = gen_lqdocpip_calc_norm_c();

% Starting Point
gendata.str.c.starting_point = gen_lqdocpip_starting_point();
if gendata.starting_point_method == 5
    gendata.str.c.rhs_starting_point_5 = gen_lqdocpip_rhs_starting_point_5();
end
gen_stat_section('starting_point');

% Includes
gendata.str.c.include = gen_include(cinclude);
gendata.str.h.include = gen_include(hinclude);

% Defines
gendata.str.c.define = gen_define(cdefine);

% Schnittstellen
[gendata.str.c.inputoutput, gendata.str.h.inputoutput] = gen_get_pointers(inoutvars);

% Main-Function
gendata.str.c.init = gen_lqdocpip_init();
gen_stat_section('init');
gendata.str.c.main = gen_lqdocpip_main();
gendata.str.h.main = ['double ' gendata.prefix 'glqdocpip_timer_get();' char(10) ...
    'void ' gendata.prefix 'glqdocpip_timer_start();' char(10) ...
    'int ' gendata.prefix 'glqdocpip();'];

% Performance Test Function(s)
if gendata.performance_test == 1
    gendata.str.performance_test = cell(0);
    for i = 1:length(gendata.performance_tests)
         [cstr, hstr] = gen_lqdocpip_performance_test(gendata.performance_tests{i});
         gendata.str.c.performance_test{i} = cstr;
         gendata.str.h.performance_test{i} = hstr;         
    end
end

% Variablen Deklaration
gendata.str.c.vars = gen_var();

% Mathematische Funktionen (muss als letztes ausgeführt werden)
gendata.str.c.mathfunctions = gen_functions();

cd(gendata.path_orig);

%% Quellcode zusammenfügen
% c-Datei
cstr = [];
% Header
cstr = [cstr '/* ' gendata.filename '.c */' char(10)];
cstr = [cstr '/* Generiert: ' datestr(now) ' */' char(10) char(10) char(10)];
% Include
cstr = [cstr gendata.str.c.include char(10)];
% Define Platform
cstr = [cstr char(10) gendata.str.c.define char(10)];
% Include Timer
cstr = [cstr gendata.str.c.include_timer char(10) char(10)];

% Globale Variablen
cstr = [cstr gendata.str.c.vars char(10) char(10)];
% Input / Output
cstr = [cstr char(10) char(10) gendata.str.c.inputoutput];
% Timer
cstr = [cstr char(10) char(10) gendata.str.c.timer];
% evtl Output (mex)
%if gendata.generateoutput cstr = [cstr gendata.str.c.savevars]; end
% Mathematische Funktionen
cstr = [cstr char(10) char(10) gendata.str.c.mathfunctions];
% calc_mu
cstr = [cstr char(10) char(10) gendata.str.c.calc_mu];
% calc_mu_aff
cstr = [cstr char(10) char(10) gendata.str.c.calc_mu_aff];
% calc_phi
cstr = [cstr char(10) char(10) gendata.str.c.calc_phi];
% calc_sigma
cstr = [cstr char(10) char(10) gendata.str.c.calc_sigma];
% Max Stepsize
cstr = [cstr char(10) char(10) gendata.str.c.max_stepsize];
% Mehrotra Step
cstr = [cstr char(10) char(10) gendata.str.c.mehrotra_step];
% Duality Gap
cstr = [cstr char(10) char(10) gendata.str.c.calc_duality_gap];
% calc_norm_d
cstr = [cstr char(10) char(10) gendata.str.c.calc_norm_d];
% calc_norm_r
cstr = [cstr char(10) char(10) gendata.str.c.calc_norm_r];
% step
cstr = [cstr char(10) char(10) gendata.str.c.step];
% check_condiv
cstr = [cstr char(10) char(10) gendata.str.c.check_condiv];
% stat
cstr = [cstr char(10) char(10) gendata.str.c.stat];
if gendata.debug == 1
    % debug1
    cstr = [cstr char(10) char(10) gendata.str.c.debug1];
    % debug2
    cstr = [cstr char(10) char(10) gendata.str.c.debug2];
end
% Funktion: factor
cstr = [cstr char(10) char(10) gendata.str.c.factor];
% Funktion: solve
cstr = [cstr char(10) char(10) gendata.str.c.solve];
% Funktion: rhs_starting_point_5
if gendata.starting_point_method == 5
    cstr = [cstr char(10) char(10) gendata.str.c.rhs_starting_point_5];
end
% Funktion: rhs_affine
cstr = [cstr char(10) char(10) gendata.str.c.rhs_affine];
% Funktion: rhs_acorrector
cstr = [cstr char(10) char(10) gendata.str.c.rhs_corrector];
% Funktion: rhs_reduced
cstr = [cstr char(10) char(10) gendata.str.c.rhs_reduced];
% Funktion: rhs_iter_ref
cstr = [cstr char(10) char(10) gendata.str.c.rhs_iter_ref];
% Funktion: dereduce
cstr = [cstr char(10) char(10) gendata.str.c.dereduce];
% iter_ref
cstr = [cstr char(10) char(10) gendata.str.c.iter_ref];
% starting_point
cstr = [cstr char(10) char(10) gendata.str.c.starting_point];
% Funktion: init
cstr = [cstr char(10) char(10) gendata.str.c.init];
% Funktion: Main
cstr = [cstr char(10) char(10) gendata.str.c.main];
% Performance Test
if gendata.performance_test == 1
    for i=1:length(gendata.performance_tests)
        cstr = [cstr char(10) char(10) gendata.str.c.performance_test{i}];
    end
end
% Ende
cstr = [cstr char(10)];

% h-Datei
hstr = [];
% Include
hstr = [hstr gendata.str.h.include];
% Input / Output
hstr = [hstr char(10) char(10) gendata.str.h.inputoutput];
% Funktion: Main
hstr = [hstr char(10) char(10) gendata.str.h.main char(10)];
% Performance Test
if gendata.performance_test == 1
    for i=1:length(gendata.performance_tests)
        hstr = [hstr char(10) gendata.str.h.performance_test{i}];
    end
    hstr = [hstr char(10)];
end

disp('Generierung fertig.');
disp(['Es wurden ' num2str(length(strfind(cstr,char(10)))+1+length(strfind(hstr,char(10)))+1) ' Zeilen Quellcode erstellt.']);

%% Quellcode in Datei schreiben: c-Datei
cd(gendata.path_target);
filename  = gendata.filename;
fid = fopen([filename '.c'],'wt');
fwrite(fid,cstr);
fclose(fid);
disp([filename '.c wurde erstellt.']);

%% Quellcode in Datei schreiben: h-Datei
filename  = gendata.filename;
fid=fopen([filename '.h'],'wt');
fwrite(fid,hstr);
fclose(fid);
disp([filename '.h wurde erstellt.']);
cd(gendata.path_orig);

%% Statistik
% Variablen
float_size  = 4;
double_size = 8;
int_size    = 4;
gendata.stat.var.size_total = float_size * gendata.stat.var.num_float ...
    + double_size * gendata.stat.var.num_double ...
    + int_size * gendata.stat.var.num_int;

%% Ende
end