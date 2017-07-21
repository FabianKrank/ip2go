function [ mask_input ] = generate_default( problemdata,name_str )
%cg_generate_problemwrapper Generates Wrapper for Optimization Problem with
%ip2go, different problemcases may be distinguished


generation_data.data_target = fullfile(pwd,'Code');


setVersion = 3;
cpath      = pwd;

%Code erstellen
global pstruc

%% Generation-Data ausfüllen
generation_data = gen_lqdocpip_default_generation_data();

generation_data.name                   = name_str;        % Problem prefix
generation_data.mem_type               = 2;               % C-Code data structure: 1 = save data in separate arrays - 2 = save data in a single array
generation_data.simple_struct          = 0;               % Wenn simple_struc als 1 definiert ist muss pstruc empty sein
generation_data.output_type            = 'ar';            % Return type from mex-interface "ar" = array - else = struct

generation_data.loopunrolling          = 1;               % true = don't use for-loops, instead unroll them where applicable
generation_data.use_structures         = 1;               % true = use sparsity information for given problem matrices, i.e. skip operators with 0 or 1 if applicable (only with loopunrolling == true)
generation_data.provide_get_interface  = 1;               % false = don't export functions to set problem matrices (should be used with initialize_data == true)
generation_data.initialize_data        = 0;               % true = Statically initialize data in C-code with problem data (ONLY usable if mem_type == 2)
generation_data.matrix_structures      = problemdata;     % Apply problem matrices here
generation_data.math_arg_use_pointer   = false;            % true = Export C-code with pointers in arguments - false = use fixed with arrays (FPGA HLS)

generation_data.starting_point_method         = 5;        % 0 = very cold start - 5 = warm start
generation_data.parameter.mehrotra_step_gamma = 0.01;     % Mehrotra step parameter
generation_data.parameter.max_iter            = 100;
generation_data.parameter.tmax                = 20;
generation_data.parameter.termcode_2_factor   = 1e6;
generation_data.parameter.tol                 = 1e-5;

generation_data.timer     = {'windows' 'dspace' 'none'};  % Specify for which platforms timers should be generated. Valid values are: 'windows', 'dspace', 'none'
generation_data.precision = 'double';                     % Choose either 'double' or 'float' precision
generation_data.platform  = 'WIN';                        % Choose your platform. Valid values are: 'WINDOWS', 'DSPACE', 'XILINX'

generation_data.debug     = 1;                            % true = Output additional debugging values


% Dimensionen
% Diskretisierungsschritte
generation_data.dim.K           = problemdata.dim.K ;
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
%% Problemstruktur
if setVersion==3
	generation_data.iter={[0] [1:(generation_data.dim.K-1) ]  [generation_data.dim.K ]};
   pstruc=[];
   [pstruc]=analyse_problemdata(problemdata);
end

generation_data.path_target = fullfile(pwd,'code');

%% Solver generieren
gen_lqdocpip(generation_data);

%% Matlab-Interface generieren     
if generation_data.provide_get_interface
	gen_wrap();
else
	gen_wrap_fpga();
end

global req_input
mask_input=req_input;

%% Mex
cd(generation_data.path_target);
try
	eval(['mex -v -g ' generation_data.name '_wrap.c ' generation_data.name '_glqdocpip.c'])
end
cd(cpath);

clearvars -global aiter genstore genstr pstruc req_input gendata

end

