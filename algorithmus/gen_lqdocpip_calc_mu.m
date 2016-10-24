function [ funstr ] = gen_lqdocpip_calc_mu()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

K  = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;

% Funktionskopf
addc('###########################')
addc('Diese Funktion berechnet mu')
addc('###########################')
addl(['static void ' prefix 'glqdocpip_calc_mu()' char(10) '{'])

addf('v_init0',1,'mu')
addc('mu = mu + y*nu')

% Schleife über alle Zeitschritt
for k=0:K
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    kstr = num2str(k);
    addc(['Zeitschritt ' kstr])
    % mu = mu_pl + yady.*nuadnu
    if n_c > 0
        addf('vtv',n_c+n_s,['y' kstr],['nu' kstr],'mu')
    end
end
%mu_pl /= m_ineq
addf('vv_elediv',1,'mu','m_ineq','mu')

% mu0 bestimmen
addl('')
addc('mu0 bestimmen')
addl(['if(' prefix 'iter == 0){'])
addf('v_copy',1,'mu','mu0')
addl('}')

%addp('mu','mu')

%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

