function [ funstr ] = gen_lqdocpip_calc_norm_h()
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
addc('###########################################################')
addc('Diese Funktion berechnet die Unendlichnorm der H**-Matrizen')
addc('###########################################################')
addl(['static void ' prefix 'glqdocpip_calc_norm_h()' char(10) '{'])
if gendata.mem_type==2
    addl('  int i1;');
end
% Init
addf('v_init0',1,'norm_h')

% Schleife über alle Zeitschritt
k=0;
i1=1;
while k<K+1
        [k,kstr]=additer(k,i1);
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    kstr = num2str(k);
    % Gütefunktion
    addc('Aus Gütefunktion')
    addf('norm_inf',nx,nx,['Hxx' kstr],'norm_h','norm_h')
    addf('norm_inf',nx,nu,['Hxu' kstr],'norm_h','norm_h')
    addf('norm_inf',nu,nu,['Huu' kstr],'norm_h','norm_h')
    if n_s > 0
        addf('norm_inf',n_s,n_s,['Hss' kstr],'norm_h','norm_h')
    end
    k=additer_next(k,i1);
    i1=i1+1;
end



%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

