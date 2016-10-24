function [ funstr ] = gen_lqdocpip_calc_mu_aff()
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
addc('###############################')
addc('Diese Funktion berechnet mu_aff')
addc('###############################')
addl(['static void ' prefix 'glqdocpip_calc_mu_aff()' char(10) '{'])

addf('v_init0',1,'mu_aff')

% Schleife über alle Zeitschritt
for k=0:K
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    kstr = num2str(k);
    addc(['Zeitschritt ' kstr])
    
    if n_c > 0
        tmp1 = addt(n_c+n_s);
        tmp2 = addt(n_c+n_s);
        %y
        addc('yady = y + alpha_max*dy')
        addf('v_copy',n_c+n_s,['y' kstr],tmp1)
        addf('sv',n_c+n_s,'alpha_max',['dy' kstr],tmp1)
        
        %nu
        addc('nuadnu = nu + alpha_max*dnu')
        addf('v_copy',n_c+n_s,['nu' kstr],tmp2)
        addf('sv',n_c+n_s,'alpha_max',['dnu' kstr],tmp2)
        
        % mu_aff = mu_aff + yady.*nuadnu
        addc('mu_aff = mu_aff + yady.*nuadnu)')
        addf('vtv',n_c+n_s,tmp1,tmp2,'mu_aff')
        
        subt(tmp1)
        subt(tmp2)
    end
end



%mu_aff /= m_ineq
addf('vv_elediv',1,'mu_aff','m_ineq','mu_aff')

%addp('mu_aff','mu_aff')

%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

