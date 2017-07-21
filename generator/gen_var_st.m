function funstr = gen_var_st()
%Diese Funktion generiert die Variablendeklarationen
global gendata;
global genstr;
global genstore;


%% Größen aus gendata holen
K = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;
n_c = gendata.dim.n_c; % Achtung: Vektor
n_s = gendata.dim.n_s; % Achtung: Vektor

prec = gendata.prec;
prefix = gendata.prefix;
max_iter = gendata.parameter.max_iter;

% Für Statistik
gendata.stat.var.num_float = 0;
gendata.stat.var.num_double = 0;
gendata.stat.var.num_int = 0;

%% Variablen Daten erstellen
% Optimierungsvariablen
name = {'x' 'u' 's' 'p' 'y'   'nu' };
dim1 = {nx  nu  n_s  nx  n_c+n_s n_c+n_s};
dim2 = {1   1   1   1   1     1    };
optvar = {};
for i=1:length(name)
    optvar{i}.name = name{i};
    optvar{i}.dim1 = dim1{i};
    optvar{i}.dim2 = dim2{i};
end

% Schritt Variablen
name = {'dx' 'du' 'ds' 'dp' 'dy'   'dnu' };
dim1 = {nx   nu   n_s   nx   n_c+n_s  n_c+n_s };
dim2 = {1    1    1    1    1      1     };
stepvar = {};
for i=1:length(name)
    stepvar{i}.name = name{i};
    stepvar{i}.dim1 = dim1{i};
    stepvar{i}.dim2 = dim2{i};
end

% Gütefunktion Variablen
name = {'Hxx' 'Hxu' 'Huu' 'Hss' 'f0x' 'f0u' 'f0s' };
dim1 = {nx    nx    nu    n_s    nx    nu    n_s    };
dim2 = {nx    nu    nu    n_s    1     1     1     };
Jvar = {};
for i=1:length(name)
    Jvar{i}.name = name{i};
    Jvar{i}.dim1 = dim1{i};
    Jvar{i}.dim2 = dim2{i};
end

% Gleichungsnebenbedingung Variablen
name = {'fx' 'fu' 'f'};
dim1 = {nx   nx   nx };
dim2 = {nx   nu   1  };
eqvar = {};
for i=1:length(name)
    eqvar{i}.name = name{i};
    eqvar{i}.dim1 = dim1{i};
    eqvar{i}.dim2 = dim2{i};
end

% Ungleichungsnebenbedingung Variablen
name = {'gx' 'gu' 'g'};
dim1 = {n_c   n_c   n_c };
dim2 = {nx   nu   1  };
ineqvar = {};
for i=1:length(name)
    ineqvar{i}.name = name{i};
    ineqvar{i}.dim1 = dim1{i};
    ineqvar{i}.dim2 = dim2{i};
end

% rhs Variablen
name = {'rf0x' 'rf0u' 'rf0s' 'rf' 'rc' 'rs' 'rk'};
dim1 = {nx     nu     n_s     nx   n_c   n_s   n_c+n_s};
dim2 = {1      1      1      1    1    1    1};
rhsvar = {};
for i=1:length(name)
    rhsvar{i}.name = name{i};
    rhsvar{i}.dim1 = dim1{i};
    rhsvar{i}.dim2 = dim2{i};
end

% rrhs Variablen
name = {'rrf0x' 'rrf0u' 'rhsxs' 'yny'};
dim1 = {nx      nu      n_s      n_c   };
dim2 = {1       1       1       1    };
rrhsvar = {};
for i=1:length(name)
    rrhsvar{i}.name = name{i};
    rrhsvar{i}.dim1 = dim1{i};
    rrhsvar{i}.dim2 = dim2{i};
end

% Blockeliminationsverfahren Variablen
name = {'Gxx' 'Gxu' 'Guu' 'Rux' 'Vxx' 'Gx' 'Gu' 'Ru' 'Vx'};
dim1 = {nx    nx    nu    nu    nx    nx   nu   nu   nx  };
dim2 = {nx    nu    nu    nx    nx    1    1    1    1   };
bevar = {};
for i=1:length(name)
    bevar{i}.name = name{i};
    bevar{i}.dim1 = dim1{i};
    bevar{i}.dim2 = dim2{i};
end

% Schritt Variablen (iter_ref save)
name = {'dx_ir' 'du_ir' 'ds_ir' 'dp_ir' 'dy_ir'  'dnu_ir' };
dim1 = {nx      nu      n_s      nx      n_c+n_s n_c+n_s };
dim2 = {1       1       1       1       1        1     };
stepvarir = {};
for i=1:length(name)
    stepvarir{i}.name = name{i};
    stepvarir{i}.dim1 = dim1{i};
    stepvarir{i}.dim2 = dim2{i};
end

% rhs Variablen (iter_ref save)
name = {'rf0x_ir' 'rf0u_ir' 'rf0s_ir' 'rf_ir' 'rc_ir' 'rs_ir' 'rk_ir'};
dim1 = {nx        nu        n_s       nx      n_c     n_s     n_c+n_s};
dim2 = {1         1         1         1       1       1       1};
rhsvarir = {};
for i=1:length(name)
    rhsvarir{i}.name = name{i};
    rhsvarir{i}.dim1 = dim1{i};
    rhsvarir{i}.dim2 = dim2{i};
end

%% Anfangsbedingung (Deklaration)
genstr = [];
addc('########################')
addc('# Variablendeklaration #')
addc('########################')

addc('Anfangsbedingung')
addl(gen_var_single('xinit', 0, nx, 1, struct('no_k',1)))

%% Variablendeklaration generieren

if ~(gendata.mem_type==2)

for k=0:K
    addl('')
    addc(['Variablen für Disketisierungsstelle ' num2str(k)])
    
    % Optimierungvariablen
    addc('Optimierungsvariablen')
    for i=1:length(optvar)
        addl(gen_var_single(optvar{i}.name,k,optvar{i}.dim1,optvar{i}.dim2))
    end
    
    % Schritt Variablen
    addc('Schrittvariablen')
    for i=1:length(stepvar)
        addl(gen_var_single(stepvar{i}.name,k,stepvar{i}.dim1,stepvar{i}.dim2))
    end
    
    % Gütefunktion Variablen
    addc('Variablen der Guetefunktion')
    for i=1:length(Jvar)
        addl(gen_var_single(Jvar{i}.name,k,Jvar{i}.dim1,Jvar{i}.dim2))
    end
    
    % Gleichungsnebenbedingungen Variablen
    addc('Variablen der Gleichungsnebenbedingungen')
    for i=1:length(eqvar)
        addl(gen_var_single(eqvar{i}.name,k,eqvar{i}.dim1,eqvar{i}.dim2))
    end
    
    % Ungleichungsnebenbedingungen Variablen
    addc('Variablen der Ungleichungsnebenbedingungen')
    for i=1:length(ineqvar)
        addl(gen_var_single(ineqvar{i}.name,k,ineqvar{i}.dim1,ineqvar{i}.dim2))
    end
    
    % rhs Variablen
    addc('Variablen der rechten Seiten')
    for i=1:length(rhsvar)
        addl(gen_var_single(rhsvar{i}.name,k,rhsvar{i}.dim1,rhsvar{i}.dim2))
    end
    
    % rrhs Variablen
    addc('Variablen der reduzierten rechten Seiten')
    for i=1:length(rrhsvar)
        addl(gen_var_single(rrhsvar{i}.name,k,rrhsvar{i}.dim1,rrhsvar{i}.dim2))
    end
    
    % Blockeliminationsverfahren Variablen
    addc('Variablen fuer das Blockeliminationsverfahren')
    for i=1:length(bevar)
        addl(gen_var_single(bevar{i}.name,k,bevar{i}.dim1,bevar{i}.dim2))
    end
 
    % Schrittvariablen (iter_ref Speicher)
    addc('Variablen fuer iter_ref: Schrittvariablenspeicher')
    for i=1:length(stepvarir)
        addl(gen_var_single(stepvarir{i}.name,k,stepvarir{i}.dim1,stepvarir{i}.dim2))
    end
    
    % rhs Variablen (iter_ref Speicher)
    addc('Variablen fuer iter_ref: rhs-Variablenspeicher')
    for i=1:length(rhsvarir)
        addl(gen_var_single(rhsvarir{i}.name,k,rhsvarir{i}.dim1,rhsvarir{i}.dim2))
    end
end
end
%% Temporäre Variablen
addl('')
addc('Temporäre Variablen')
for i = 1:length(gendata.tmps)
    dim1 = gendata.tmps{i}.dims(1);
    if length(gendata.tmps{i}.dims) > 1
        dim2 = gendata.tmps{i}.dims(2);
    else
        dim2 = 1;
    end
    
    for j = 1:gendata.tmps{i}.count
        tmp_varname = ['tmp' num2str(j) '_' gendata.tmps{i}.tmpid];
        addl(gen_var_single(tmp_varname, 0, dim1, dim2, struct('no_k',1)))
    end
end
%% Cholesky-Zerlegung Variablen
if ~(exist('genstore','var')&&(gendata.mem_type==2))
  
addl('')
addc('Temporäre Variablen für Cholesky Zerlegung')
for k=0:K
    addl(gen_var_single('L',k,nu,nu))
end



end
%% Max-Stepsize Variablen
addl('')
addc('Variablen für max_stepsize')
addl(gen_var_single('alpha_max', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('alpha_tmp', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('alpha_min_y', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('alpha_min_dy', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('alpha_min_nu', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('alpha_min_dnu', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('alpha_min_source_y', 0, 1, 1, struct('no_k',1, 'no_array',1, 'prec','int')))

%% Mehrotra Step Variablen
addl('')
addc('Variablen für mehrotra_step')
addl(gen_var_single('mehrotra_alpha', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('mehrotra_gamma', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('mehrotra_fpd', 0, 1, 1, struct('no_k',1)))

%% Allgemeines
addl('')
addc('Verschiedenes')
addl(gen_var_single('iter', 0, 1, 1, struct('no_array',1, 'no_k',1, 'prec', 'int')))
addl(gen_var_single('max_iter', 0, 1, 1, struct('no_array',1, 'no_k',1, 'prec', 'int')))
addl(gen_var_single('termcode', 0, 1, 1, struct('no_array',1, 'no_k',1, 'prec', 'int')))
addl(gen_var_single('iter_ref', 0, 1, 1, struct('no_array',1, 'no_k',1, 'prec', 'int')))
addl(gen_var_single('error_line', 0, 1, 1, struct('no_array',1, 'no_k',1, 'prec', 'int')))
addl(gen_var_single('error_source', 0, 1, 1, struct('no_array',1, 'no_k',1, 'prec', 'int')))

addl(gen_var_single('m_ineq', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('macheps', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('tau', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('sigma', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('norm_d', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('norm_r', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('norm_r0', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('norm_r_prev', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('mu', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('mu0', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('mu_aff', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('phi', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('minphi', 0, 1, 1, struct('no_k',1)))

% Konvergenz-/Divergenztests
addl(gen_var_single('tol', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('tc1_factor', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('tc2_factor', 0, 1, 1, struct('no_k',1)))
addl(gen_var_single('blowup_t_on', 0, 1, 1, struct('no_k',1, 'prec','int')))
%% Zeiten
addl(gen_var_single('timer_start', 0, 1, 1, struct('no_k',1, 'no_array',1, 'prec','double')))
addl(gen_var_single('time_max', 0, 1, 1, struct('no_k',1, 'no_array',1, 'prec','double')))

%% Duality Gap
addl('')
addc('Variablen für Duality Gap')
addl(gen_var_single('dgap', 0, 1, 1, struct('no_k',1)))

%% Variablen für Starting Point
addl('')
addc('Variablen für Starting Point')
if gendata.starting_point_method == 5
    addl(gen_var_single('starting_point_delta_y', 0, 1, 1, struct('no_k',1)))
    addl(gen_var_single('starting_point_delta_nu', 0, 1, 1, struct('no_k',1)))
    addl(gen_var_single('starting_point_sum', 0, 1, 1, struct('no_k',1)))
    addl(gen_var_single('starting_point_sum_y', 0, 1, 1, struct('no_k',1)))
    addl(gen_var_single('starting_point_sum_nu', 0, 1, 1, struct('no_k',1)))
end

%% Debug
if gendata.debug
    addl('')
    addc('Variablen für Debug')
    % Debug Aufruf 1
    addl(gen_var_single('debug_dgap', 0, max_iter, 1, struct('no_k',1)))
    addl(gen_var_single('debug_phi', 0, max_iter, 1, struct('no_k',1)))
    addl(gen_var_single('debug_minphi', 0, max_iter, 1, struct('no_k',1)))
    addl(gen_var_single('debug_norm_d', 0, 1, 1, struct('no_k',1)))
    addl(gen_var_single('debug_norm_r0', 0, 1, 1, struct('no_k',1)))
    addl(gen_var_single('debug_norm_r', 0, max_iter, 1, struct('no_k',1)))
    addl(gen_var_single('debug_mu0', 0, 1, 1, struct('no_k',1)))
    addl(gen_var_single('debug_mu', 0, max_iter, 1, struct('no_k',1)))
    
    % Debug Aufruf 2
    addl(gen_var_single('debug_mu_aff', 0, max_iter, 1, struct('no_k',1)))
    addl(gen_var_single('debug_sigma', 0, max_iter, 1, struct('no_k',1)))
    addl(gen_var_single('debug_alpha_max', 0, max_iter, 1, struct('no_k',1)))
    addl(gen_var_single('debug_mehrotra_alpha', 0, max_iter, 1, struct('no_k',1)))
end

%% Statistik
addl('')
addc('Variablen für Statistik')
addl(gen_var_single('stat_time', 0, max_iter, 1, struct('no_k',1)))
addl(gen_var_single('stat_iter_ref', 0, max_iter, 1, struct('no_k',1, 'prec','int')))
addl(gen_var_single('stat_num_iter_ref', 0, 1, 1, struct('no_k',1, 'no_array',1, 'prec','int')))
addl(gen_var_single('stat_num_factor', 0, 1, 1, struct('no_k',1, 'no_array',1, 'prec','int')))
addl(gen_var_single('stat_num_solve', 0, 1, 1, struct('no_k',1, 'no_array',1, 'prec','int')))

%% Vektoren 
if (exist('genstore','var')&&(gendata.mem_type==2))
addl('')
addc('Variable für Diskretisierungsstellen')
for i1=1:length(genstore.akt_index)
    if genstore.akt_index(i1)~=0
        addl(gen_var_single('arr_t',i1,genstore.akt_index(i1)+1,1)) 
    end
end
end


%% Rückgabe
funstr = genstr;
genstr = [];


return
end

function varstr = gen_var_single(varname, index, dim1, dim2, attribute)
% Generiert den String zur Deklaration einer Variablen
global gendata

% Zusätzliche Eingabeparameter auswerten
if exist('attribute','var')
    % Precision
    if isfield(attribute,'prec')
        prec = attribute.prec;
    else
        % Default
        prec = gendata.prec;
    end
    % Array ja/nein
    if isfield(attribute,'no_array')
        no_array = attribute.no_array;
    else
        % Default
        no_array = 0;
    end
    % Variable einfach vorhanden?
    if isfield(attribute,'no_k')
        no_k = attribute.no_k;
    else
        % Default
        no_k = 0;
    end
else
    % Default-Werte
    prec        = gendata.prec;
    no_array    = 0;
    no_k        = 0;
end 

% Unterschiedliche Array-Länge bei unterschiedlichen Diskretisierungsstellen möglich, da z.B. n_c(1) <> n_c(2)
if (length(dim1) > 1)
    dim1 = dim1(index+1);
end
if (length(dim2) > 1)
    dim2 = dim2(index+1);    
end

if dim1 == 0
    dim1 = 1;
    %warning([varname ': Dimension_1 = 0']);
end
if dim2 == 0
    dim2 = 1;
    %warning([varname ': Dimension_2 = 0']);
end

% no_k verarbeiten
varname2=varname;
if ~no_k
    varname2 = [varname num2str(index)];
end

if no_array
    varstr = ['static ' prec ' ' gendata.prefix varname2 ';'];
    elements = 1;
else
    varstr = ['static ' prec ' ' gendata.prefix varname2 '[' num2str(dim1*dim2) '];'];
    elements = dim1*dim2;
end

switch prec
    case 'float'
        gendata.stat.var.num_float = gendata.stat.var.num_float + elements;
    case 'double'
        gendata.stat.var.num_double = gendata.stat.var.num_double + elements;
    case 'int'
        gendata.stat.var.num_int = gendata.stat.var.num_int + elements;
end

end

