function [s] = structures_load_default(nx,nu,n_c,n_s)
%STRUCTURES_LOAD Summary of this function goes here
%   Detailed explanation goes here

%% Init
s = cell(0);

%% Voll besetzte Strukturen
% Voll besetzte Matrix nx x nx
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_matrix_nx_nx';
s{end}.mask = ones(nx,nx);

% Voll besetzter Vektor nx x 1
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_vector_nx';
s{end}.mask = ones(nx,1);

% Voll besetzter ZeilenVektor 1 x nx
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_vector_transposed_nx';
s{end}.mask = ones(1,nx);

% Voll besetzte Matrix nu x nu
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_matrix_nu_nu';
s{end}.mask = ones(nu,nu);

% Voll besetzter Vektor nu x 1
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_vector_nu';
s{end}.mask = ones(nu,1);

% Voll besetzter ZeilenVektor 1 x nu
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_vector_transposed_nu';
s{end}.mask = ones(1,nu);

% Voll besetzte Matrix nx x nu
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_matrix_nx_nu';
s{end}.mask = ones(nx,nu);

% Voll besetzte Matrix nu x nx
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_matrix_nu_nx';
s{end}.mask = ones(nu,nx);

% Voll besetzte Matrix nc_0 x nx
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_matrix_nc_0_nx';
s{end}.mask = ones(n_c(1),nx);

% Voll besetzte Matrix nc_k x nx
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_matrix_nc_k_nx';
s{end}.mask = ones(n_c(2),nx);

% Voll besetzte Matrix nc_end x nx
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_matrix_nc_end_nx';
s{end}.mask = ones(n_c(end),nx);

% Voll besetzte Matrix nx x nc_0
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_matrix_nx_nc_0';
s{end}.mask = ones(nx,n_c(1));

% Voll besetzte Matrix nx x nc_k
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_matrix_nx_nc_k';
s{end}.mask = ones(nx,n_c(2));

% Voll besetzte Matrix nx x nc_end
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_matrix_nx_nc_end';
s{end}.mask = ones(nx,n_c(end));

% Voll besetzter Vektor nc_0 x 1
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_vector_nc_0';
s{end}.mask = ones(n_c(1),1);

% Voll besetzter Vektor nc_k x 1
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_vector_nc_k';
s{end}.mask = ones(n_c(2),1);

% Voll besetzter Vektor nc_end x 1
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_vector_nc_end';
s{end}.mask = ones(n_c(end),1);

% Voll besetzter Vektor ns_0 x 1
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_vector_ns_0';
s{end}.mask = ones(n_s(1),1);

% Voll besetzter Vektor ns_k x 1
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_vector_ns_k';
s{end}.mask = ones(n_s(2),1);

% Voll besetzter Vektor ns_end x 1
s{end+1} = struct('name',[],'mask',[],'sid',[]);
s{end}.name = 'full_vector_ns_end';
s{end}.mask = ones(n_s(end),1);



end

