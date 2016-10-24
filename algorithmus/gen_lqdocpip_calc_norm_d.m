function [ funstr ] = gen_lqdocpip_calc_norm_d()
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
addc('############################################################')
addc('Diese Funktion berechnet die Unendlichnorm der Eingangsdaten')
addc('############################################################')
addl(['static void ' prefix 'glqdocpip_calc_norm_d()' char(10) '{'])

% Init
% Wenn geschlupfte UGNBs vorhanden sind, ist norm_d mindestens 1 (aus gs-Matrix)
if sum(gendata.dim.n_s)>0
    addf('v_init1',1,'norm_d')
else
    addf('v_init0',1,'norm_d')
end

% Schleife über alle Zeitschritt
for k=0:K
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    kstr = num2str(k);
    % Gütefunktion
    addc('Aus Gütefunktion')
    addf('norm_inf',nx,nx,['Hxx' kstr],'norm_d','norm_d')
    addf('norm_inf',nx,nu,['Hxu' kstr],'norm_d','norm_d')
    addf('norm_inf',nu,nu,['Huu' kstr],'norm_d','norm_d')
    if n_s > 0
        addf('norm_inf',n_s,n_s,['Hss' kstr],'norm_d','norm_d')
    end
    addf('norm_inf',nx, 1,['f0x' kstr],'norm_d','norm_d')
    addf('norm_inf',nu, 1,['f0u' kstr],'norm_d','norm_d')
    if n_s > 0
        addf('norm_inf',n_s, 1,['f0s' kstr],'norm_d','norm_d')
    end
    % GNBs
    addc('Aus Gleichungsnebenbedingungen')
    addf('norm_inf',nx,nx,['fx' kstr],'norm_d','norm_d')
    addf('norm_inf',nx,nu,['fu' kstr],'norm_d','norm_d')
    addf('norm_inf',nx,1 ,['f'  kstr],'norm_d','norm_d')
    % UGNBs
    if n_c > 0
        addc('Aus Ungleichungsnebenbedingungen')
        addf('norm_inf',n_c,nx,['gx' kstr],'norm_d','norm_d')
        addf('norm_inf',n_c,nu,['gu' kstr],'norm_d','norm_d')
        addf('norm_inf',n_c,1 ,['g'  kstr],'norm_d','norm_d')
    end
    
end



%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

