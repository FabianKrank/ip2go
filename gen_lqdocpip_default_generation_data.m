function [generation_data] = gen_lqdocpip_default_generation_data()
%GET_LQDOCPIP_DEFAULT_GENDATA gibt ein gendata-Struct mit den
%Default-Werten zurück

generation_data = struct();


%% Allgemeines
generation_data.name                    = 'mpc_name';
generation_data.precision               = 'float';
generation_data.debug                   = 0;
generation_data.timer                   = {'windows'};
generation_data.extern_timer_start      = 0;
generation_data.starting_point_methode  = 0;
generation_data.calc_macheps            = 1;


%% Problemdimensionen
generation_data.dim.K       = [];
generation_data.dim.n_x     = [];
generation_data.dim.n_u     = [];
generation_data.dim.n_c     = [];
generation_data.dim.n_s     = [];


%% Parameter
% Allgemeines
generation_data.parameter.tol                   = 10^(-4);
generation_data.parameter.tau                   = 3;
generation_data.parameter.mehrotra_step_gamma   = 0.01;
generation_data.parameter.m_ineq                = [];
generation_data.parameter.tmax                  = 1;
generation_data.parameter.max_iter              = 20;

% Kon-/Divergenzkriterien
generation_data.parameter.termcode_1_factor     = 1e4;
generation_data.parameter.termcode_2_factor     = 1e8;

% Nachiteration
generation_data.parameter.iter_ref_factor_1     = 100;
generation_data.parameter.iter_ref_factor_2     = 1.001;
generation_data.parameter.iter_ref_factor_3     = 0.1;

% MACHEPS Berechnung
generation_data.parameter.calc_macheps_div_init = 1;
generation_data.parameter.calc_macheps_max_iter = 100;


%% Flags
generation_data.flags.keep_iterative_refinements_on                         = 0;
generation_data.flags.iterative_refinements_require_norm_r_is_not_too_small = 0;

%% Optimierung
generation_data.loopunrolling       = 1;
generation_data.use_structures      = 0;
generation_data.matrix_structures   = [];

%% Performance-Tests
generation_data.performance_test    = 0;
generation_data.performance_tests   = [];

%% Pfad(e)
generation_data.path_target         = '';
generation_data.path_algorithmus    = '';
generation_data.path_math           = '';
generation_data.path_structures     = '';

end

