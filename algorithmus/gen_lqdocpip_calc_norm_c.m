function [ funstr ] = gen_lqdocpip_calc_norm_c()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

K  = gendata.dim.K;
nx = gendata.dim.nx;
nu = gendata.dim.nu;

% Funktionskopf
addc('##########################################################')
addc('Diese Funktion berechnet die Unendlichnorm der g*-Matrizen')
addc('##########################################################')
addl(['static void ' prefix 'glqdocpip_calc_norm_c()' char(10) '{'])

% Init
% Wenn geschlupfte UGNBs vorhanden sind, ist norm_d mindestens 1 (aus gs-Matrix)
if sum(gendata.dim.n_s)>0
    addf('v_init1',1,'norm_c')
else
    addf('v_init0',1,'norm_c')
end

% Schleife über alle Zeitschritt
for k=0:K
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    kstr = num2str(k);
    % UGNBs
    if n_c > 0
        addc('Aus Ungleichungsnebenbedingungen')
        addf('norm_inf',n_c,nx,['gx' kstr],'norm_c','norm_c')
        addf('norm_inf',n_c,nu,['gu' kstr],'norm_c','norm_c')
        %addf('norm_inf',n_c,1 ,['g'  kstr],'norm_c','norm_c')
    end
    
end



%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

