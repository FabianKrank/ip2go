%% Problem laden
problemdata = [];
load('structures\matrix_structures_modus3.mat');
problemdata = matrix_structure;
problemdata.xinit= zeros(6,1);

% Alternativ:
%load('structures\problemdata_4.mat');

%% Generation-Data ausfüllen
generation_data = gen_lqdocpip_default_generation_data();

generation_data.name = 'mpc123';

generation_data.timer = {'windows' 'dspace'};

generation_data.starting_point_method = 5;
generation_data.precision = 'float';

generation_data.debug = 1;

% Dimensionen
% Diskretisierungsschritte
generation_data.dim.K           = size(problemdata.Hxx,1)-1;
% Zustände
generation_data.dim.n_x         = size(problemdata.Hxx{1},1);
% Eingänge
generation_data.dim.n_u         = size(problemdata.Huu{1},1);
% UGNBs und Schlupf
generation_data.dim.n_c         = zeros(generation_data.dim.K+1,1);
generation_data.dim.n_s         = zeros(generation_data.dim.K+1,1);
for ii = 1:generation_data.dim.K+1
    generation_data.dim.n_c(ii) = size(problemdata.gx{ii},1);
    generation_data.dim.n_s(ii) = size(problemdata.Hss{ii},1);
end

clear ii

generation_data.loopunrolling = 1;

% DEKSTOP
generation_data.path_target = 'C:\Users\fabia\OneDrive\Documents\Codegenerator\code';
% LAPTOP
% generation_data.path_target = 'C:\Users\neXus\OneDrive\Documents\Codegenerator\code';

%% Strukturausnutzung
if 1
    generation_data.use_structures = 1;
    generation_data.matrix_structures = problemdata;
    
else
    generation_data.use_structures = 0;
end

%% Performancetests
if 1
    cd('performance_test');
    
    generation_data.performance_test = 1;
    procedure_tests = performance_tests_procedures_load();
    math_tests      = performance_tests_math_load();
    structure_tests = performance_tests_structure_load();
    % Add Tests to gendata
    %generation_data.performance_tests = cell(0);
    %generation_data.performance_tests = {generation_data.performance_tests{1:end} math_tests{3}};
    %generation_data.performance_tests = {generation_data.performance_tests{1:end} structure_tests{4}};
    %generation_data.performance_tests = {generation_data.performance_tests{1:end} procedure_tests{2:6} procedure_tests{end-1:end}};
    
    % Tests in Studienarbeit / dSpace
    if 0
        generation_data.performance_tests = cell(0);
        generation_data.performance_tests(end+1) = procedure_tests(22); % 1 iteration
        generation_data.performance_tests(end+1) = procedure_tests(3);  % Factor
        generation_data.performance_tests(end+1) = procedure_tests(4);  % Solve
        generation_data.performance_tests(end+1) = procedure_tests(1);  % affine
        generation_data.performance_tests(end+1) = procedure_tests(2);  % reduced
        generation_data.performance_tests(end+1) = procedure_tests(5);  % dereduce
        generation_data.performance_tests(end+1) = procedure_tests(10); % norm_r
        generation_data.performance_tests(end+1) = structure_tests(4);  % structure_mult_m_fx0
        generation_data.performance_tests(end+1) = procedure_tests(23); % 1 iteration_iterref
        generation_data.performance_tests(end+1) = procedure_tests(6);  % starting Point
    else % Sonst alle Tests
        generation_data.performance_tests = cell(0);
        generation_data.performance_tests = {generation_data.performance_tests{1:end} math_tests{1:end}};
        generation_data.performance_tests = {generation_data.performance_tests{1:end} structure_tests{1:end}};
        generation_data.performance_tests = {generation_data.performance_tests{1:end} procedure_tests{1:end}};
    end
    
    for ii = 1:length(generation_data.performance_tests)
        generation_data.performance_tests{ii}.iterations = 1;
    end
    
    clear ii procedure_tests math_tests structure_tests
    cd('..');
else
    generation_data.performance_test = 0;
end

%% Solver generieren
gen_lqdocpip(generation_data);

%% Matlab-Interface generieren
gen_wrap();

%% Mex
cd([pwd '\code']);
mex mpc123_wrap.c mpc123_glqdocpip.c -v OPTIMFLAGS='-DNDEBUG -O3'
% mex mpc123_wrap.c mpc123_glqdocpip.c

%% Ausführen
mpc123_wrap(problemdata);
cd('..')

% lcc -noregistrylookup -DMX_COMPAT_32   -DMX_COMPAT_32  -DMATLAB_MEX_FILE -I"C:\Program Files (x86)\MATLAB\R2015a\sys\lcc\include" -I"C:\Program Files (x86)\MATLAB\R2015a\extern\include" -I"C:\Program Files (x86)\MATLAB\R2015a\simulink\include" -I"C:\Program Files (x86)\MATLAB\R2015a\sys\lcc\mex"   -I"C:\Program Files (x86)\MATLAB\R2015a\sys\lcc\include"  -DMATLAB_MEX_FILE "C:\Program Files (x86)\MATLAB\R2015a\sys\lcc\mex\lccstub.c" /Fo"mpc123_wraplib2.obj" "C:\Program Files (x86)\MATLAB\R2015a\sys\lcc\bin\lcclnk" -o mpc123_wrap.mexw32  -dll "C:\Program Files (x86)\MATLAB\R2015a\extern\lib\win32\lcc\mexFunction.def" -L"C:\Program Files (x86)\MATLAB\R2015a\sys\lcc\lib" -libpath "C:\Program Files (x86)\MATLAB\R2015a\extern\lib\win32\lcc" -libpath "C:\Program Files (x86)\MATLAB\R2015a\lib\win32" "mpc123_wraplib2.obj" -s C:\Users\fabia\AppData\Local\Temp\mex_64906944992944_8148\mpc123_wrap.obj C:\Users\fabia\AppData\Local\Temp\mex_64906944992944_8148\mpc123_glqdocpip.obj   libmx.lib libmex.lib libmat.lib