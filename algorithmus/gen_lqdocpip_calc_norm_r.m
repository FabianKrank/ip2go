function [ funstr ] = gen_lqdocpip_calc_norm_r()
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
addc('#############################################################')
addc('Diese Funktion berechnet die Unendlichnorm der rechten Seiten')
addc('#############################################################')
addl(['static void ' prefix 'glqdocpip_calc_norm_r()' char(10) '{'])
if gendata.mem_type==2
    addl('  int i1;');
end
% norm_r_prev
addc('norm_r_prev bestimmen')
addl(['if(' prefix 'iter > 0){'])
addf('v_copy',1,'norm_r','norm_r_prev')
addl('}')

% Init
addf('v_init0',1,'norm_r')

% Schleife über alle Zeitschritt
k=0;
i1=1;
while k<K+1
    
    [k,kstr]=additer(k,i1);
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    kstr = num2str(k);
    addc(['Zeitschritt ' kstr])
    % Gütefunktion
    addc('Aus Gütefunktion')
    addf('norm_inf',nx,1,['rf0x' kstr],'norm_r','norm_r')
    addf('norm_inf',nu,1,['rf0u' kstr],'norm_r','norm_r')
    if n_s > 0
        addf('norm_inf',n_s,1,['rf0s' kstr],'norm_r','norm_r')
    end
    % GNBs
    addc('Aus Gleichungsnebenbedingung')
    addf('norm_inf',nx,1,['rf' kstr],'norm_r','norm_r')
    % UGNBs
    if n_c > 0
        addc('Aus Ungleichungsnebenbedingung')
        addf('norm_inf',n_c,1,['rc' kstr],'norm_r','norm_r')
        if n_s > 0
            addf('norm_inf',n_s,1,['rs' kstr],'norm_r','norm_r')
        end
    end
    % Komplementaritätsbedingung
    if n_c > 0
        addc('Aus Komplementaritätsbedingung')
        addf('norm_inf',n_c+n_s,1,['rk' kstr],'norm_r','norm_r')
    end
    k=additer_next(k,i1);
    i1=i1+1;
end

% norm_r0
addc('norm_r0 bestimmen')
addl(['if(' prefix 'iter == 0){'])
addf('v_copy',1,'norm_r','norm_r0')
addl('}')

%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

