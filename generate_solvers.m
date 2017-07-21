%% Default Parameter laden
generation_data = gen_lqdocpip_default_generation_data;

%% Allgemeine Parameter setzen
generation_data.prec = 'float';
generation_data.starting_point_method = 5;
generation_data.calc_macheps = 1;
generation_data.timer = {'windows' 'dspace'};
generation_data.extern_timer_start = 0;

% Debug Funktionen
generation_data.debug = 0;

% Optimierung
generation_data.loopunrolling = 1;
generation_data.use_structures = 0;

% Pfade
generation_data.path_math = [pwd '\math'];
generation_data.path_algorithmus = [pwd '\algorithmus'];
generation_data.path_structures = [pwd '\structures'];
generation_data.path_target = [pwd '\code'];

%% Funktionen für Performance-Tests
if 0
    
    generation_data.performance_test = 1;
    % Load Tests
    cd('performance_test');
    procedure_tests = performance_tests_procedures_load();
    math_tests      = performance_tests_math_load();
    structure_tests = performance_tests_structure_load();
    cd('..');
    
    % Add Tests to generation_data
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
    
    % Overwrite Settings for all Tests
    for i=1:length(generation_data.performance_tests)
        generation_data.performance_tests{i}.iterations = 1;
        generation_data.performance_tests{i}.runs       = 10;
    end
    generation_data.performance_tests{8}.runs = 1000; % structure_mult_m_fx0
    
    clear procedure_tests math_tests structure_tests i    
else
    generation_data.performance_test = 0;
end

%% Dimensionen
generation_data.dim = [];
generation_data.dim.K   = 11;   % Planunghorizont
generation_data.dim.n_x = 6;    % Anzahl Zustände
generation_data.dim.n_u = 1;    % Anzahl Eingänge

%% Solver 0 (modus = 0)
% teachin = 0, handhebel = 0
% n_c = n_s = [2, 4, 4, ... 4, 4, 2];
generation_data.name = 'mpc_dw0';
generation_data.dim.n_c      = 4*ones(generation_data.dim.K+1, 1);
generation_data.dim.n_c(1)   = 2;
generation_data.dim.n_c(end) = 2;
generation_data.dim.n_s      = generation_data.dim.n_c;

if generation_data.use_structures
    load([generation_data.path_structures '\matrix_structures_modus0.mat']);
    generation_data.matrix_structures = matrix_structure;
end

gen_lqdocpip(generation_data);

%% Solver 1 (modus = 1)
% teachin = 0, handhebel = 1
% n_c = n_s = [4, 6, 6, ... 6, 6, 2];
generation_data.name = 'mpc_dw1';
generation_data.dim.n_c      = 6*ones(generation_data.dim.K+1, 1);
generation_data.dim.n_c(1)   = 4;
generation_data.dim.n_c(end) = 2;
generation_data.dim.n_s      = generation_data.dim.n_c;

if generation_data.use_structures
    load([generation_data.path_structures '\matrix_structures_modus1.mat']);
    generation_data.matrix_structures = matrix_structure;
end

gen_lqdocpip(generation_data);

%% Solver 2 (modus = 2)
% teachin = 1, handhebel = 0
% n_c = n_s = [2, 6, 6, ... 6, 6, 4];
generation_data.name = 'mpc_dw2';
generation_data.dim.n_c      = 6*ones(generation_data.dim.K+1, 1);
generation_data.dim.n_c(1)   = 2;
generation_data.dim.n_c(end) = 4;
generation_data.dim.n_s      = generation_data.dim.n_c;

if generation_data.use_structures
    load([generation_data.path_structures '\matrix_structures_modus2.mat']);
    generation_data.matrix_structures = matrix_structure;
end

gen_lqdocpip(generation_data);

%% Solver 3 (modus = 3)
% teachin = 1, handhebel = 1
% n_c = n_s = [4, 8, 8, ... 8, 8, 4];
generation_data.name = 'mpc_dw3';
generation_data.dim.n_c      = 8*ones(generation_data.dim.K+1, 1);
generation_data.dim.n_c(1)   = 4;
generation_data.dim.n_c(end) = 4;
generation_data.dim.n_s      = generation_data.dim.n_c;

if generation_data.use_structures
    load([generation_data.path_structures '\matrix_structures_modus3.mat']);
    generation_data.matrix_structures = matrix_structure;
end

gen_lqdocpip(generation_data);

%% Verwendete Variablen löschen
clear generation_data matrix_structure