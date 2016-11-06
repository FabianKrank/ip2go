% Skript zum Erstellen des generierten Codes zum Vergleich mit anderen
% Solvern
K = 35;

%% Problem laden (für Strukturausnutzung)
load(['structures/linflp_ip2go_structures' num2str(K) '.mat']); % -> problemdata

%% Generation-Data ausfüllen
generation_data = gen_lqdocpip_default_generation_data();

generation_data.name = ['linflp_k' num2str(K)];

generation_data.timer = {'windows'};

generation_data.starting_point_method = 0;
generation_data.precision = 'double';

generation_data.parameter.max_iter = 100;
generation_data.parameter.tol = 1e-4;

generation_data.debug = 0;

% Dimensionen
% Diskretisierungsschritte
generation_data.dim.K           = K;
% Zustände
generation_data.dim.n_x         = 3;
% Eingänge
generation_data.dim.n_u         = 2;
% UGNBs und Schlupf
generation_data.dim.n_c         = 10*ones(generation_data.dim.K+1,1);
generation_data.dim.n_s         = zeros(generation_data.dim.K+1,1);


generation_data.loopunrolling = 1;

generation_data.use_structures = 1;
generation_data.matrix_structures = problemdata;

generation_data.performance_test = 0;

generation_data.path_target = [pwd '/code'];

%% Solver generieren
gen_lqdocpip(generation_data);

%% Matlab-Interface generieren
gen_wrap();

%% Mex
cd('code');
eval(['mex ' generation_data.name '_wrap.c ' generation_data.name '_glqdocpip.c'])
cd('..');

