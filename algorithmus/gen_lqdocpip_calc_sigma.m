function [ funstr ] = gen_lqdocpip_calc_sigma()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

% Funktionskopf
addc('########################################################')
addc('Diese Funktion berechnet den Zentrierungsparameter sigma')
addc('########################################################')
addl(['static void ' prefix 'glqdocpip_calc_sigma()' char(10) '{'])

tmp=addt(1);

% sigma = (mu_aff/mu)^tau
addf('vv_elediv',1,'mu_aff','mu',tmp)

addl([prefix 'sigma[0] = pow(*' prefix tmp ', *' prefix 'tau);'])

subt(tmp);

% Hier würde noch die Berechnung des Zentrierungsfaktor von Terlaky
% reinkommen

%addp('sigma','sigma = ')

%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

