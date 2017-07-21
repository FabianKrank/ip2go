function [ptests] = performance_tests_procedures_load()

ptests =cell(0);

%% Test Data
ptest = struct();

ptest.name = 'affine';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_rhs_affine();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';

ptests{1} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'reduced';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';

ptests{2} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'factor';
ptest.starting_point_method = 0;
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_factor();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptests{3} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'solve';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_solve();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_factor();''])';
ptests{4} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'dereduce';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_solve();''])';
ptests{5} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'starting';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_starting_point();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{6} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'rhs_iter_ref';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_rhs_iter_ref();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.prelines{7} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptests{7} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'iter_ref';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_iter_ref();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.prelines{7} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptest.prelines{8} = 'addl([prefix ''iter_ref = 1;''])';
ptests{8} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'norm_d';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_calc_norm_d();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{9} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'norm_r';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_calc_norm_r();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptests{10} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'mu';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_calc_mu();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptests{11} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'duality_gap';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_calc_duality_gap();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptests{12} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'calc_phi';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_calc_phi();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_calc_norm_r();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_calc_mu();''])';
ptest.prelines{7} = 'addl([prefix ''glqdocpip_calc_duality_gap();''])';
ptests{13} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'check_condiv';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_check_condiv();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_calc_norm_r();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_calc_mu();''])';
ptest.prelines{7} = 'addl([prefix ''glqdocpip_calc_duality_gap();''])';
ptest.prelines{8} = 'addl([prefix ''glqdocpip_calc_phi();''])';
ptests{14} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'max_stepsize';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_max_stepsize();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.prelines{7} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptests{15} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'mu_aff';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_calc_mu_aff();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.prelines{7} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptest.prelines{8} = 'addl([prefix ''glqdocpip_max_stepsize();''])';
ptests{16} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'sigma';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_calc_sigma();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.prelines{7} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptest.prelines{8} = 'addl([prefix ''glqdocpip_max_stepsize();''])';
ptest.prelines{9} = 'addl([prefix ''glqdocpip_calc_mu_aff();''])';
ptest.prelines{10}= 'addl([prefix ''glqdocpip_calc_mu();''])';
ptests{17} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'corrector';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_rhs_corrector();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.prelines{7} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptest.prelines{8} = 'addl([prefix ''glqdocpip_max_stepsize();''])';
ptest.prelines{9} = 'addl([prefix ''glqdocpip_calc_mu_aff();''])';
ptest.prelines{10}= 'addl([prefix ''glqdocpip_calc_mu();''])';
ptest.prelines{11}= 'addl([prefix ''glqdocpip_calc_sigma();''])';
ptests{18} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'mehrotra_step';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_mehrotra_step();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.prelines{7} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptest.prelines{8} = 'addl([prefix ''glqdocpip_max_stepsize();''])';
ptest.prelines{9} = 'addl([prefix ''glqdocpip_calc_mu_aff();''])';
ptests{19} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'step';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_step();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.prelines{4} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.prelines{5} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.prelines{6} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.prelines{7} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptest.prelines{8} = 'addl([prefix ''glqdocpip_max_stepsize();''])';
ptest.prelines{9} = 'addl([prefix ''glqdocpip_calc_mu_aff();''])';
ptest.prelines{10}= 'addl([prefix ''glqdocpip_mehrotra_step();''])';
ptests{20} = ptest;


%% Test Data
ptest = struct();

ptest.name = 'startup';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_init();''])';
%ptest.testline{2} = 'addl([prefix ''glqdocpip_timer_start();''])';
ptest.testline{2} = 'addl([prefix ''glqdocpip_starting_point();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);

ptests{21} = ptest;


%% Test Data
ptest = struct();

ptest.name = '1_iteration';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_norm_r();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_mu();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_duality_gap();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_phi();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_stat();''])';
%ptest.testline{end+1} = 'addl([prefix ''glqdocpip_check_condiv();''])';
ptest.testline{end+1} = 'addl([prefix ''termcode = -1;''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_max_stepsize();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_mu_aff();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_sigma();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_rhs_corrector();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_max_stepsize();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_mu_aff();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_mehrotra_step();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_calc_norm_d();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{4} = 'addl([prefix ''iter = 1;''])';

ptests{22} = ptest;


%% Test Data
ptest = struct();

ptest.name = '1_iteration_iterref';
ptest.runs = 10000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addl([prefix ''glqdocpip_rhs_affine();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_norm_r();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_mu();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_duality_gap();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_phi();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_stat();''])';
%ptest.testline{end+1} = 'addl([prefix ''glqdocpip_check_condiv();''])';
ptest.testline{end+1} = 'addl([prefix ''termcode = -1;''])';
ptest.testline{end+1} = 'addl([prefix ''iter_ref = 1;''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_factor();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_iter_ref();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_max_stepsize();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_mu_aff();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_sigma();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_rhs_corrector();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_rhs_reduced();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_solve();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_dereduce();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_iter_ref();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_max_stepsize();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_calc_mu_aff();''])';
ptest.testline{end+1} = 'addl([prefix ''glqdocpip_mehrotra_step();''])';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addl([prefix ''glqdocpip_calc_norm_d();''])';
ptest.prelines{3} = 'addl([prefix ''glqdocpip_starting_point();''])';
ptest.prelines{4} = 'addl([prefix ''iter = 1;''])';

ptests{23} = ptest;

end