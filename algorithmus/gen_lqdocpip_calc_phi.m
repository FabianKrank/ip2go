function [ funstr ] = gen_lqdocpip_calc_phi()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

% Funktionskopf
addc('############################')
addc('Diese Funktion berechnet phi')
addc('############################')
addl(['static void ' prefix 'glqdocpip_calc_phi()' char(10) '{'])

% phi = (norm_r + dgap)/norm_d
addf('vadd',1,'norm_r','dgap','phi')
addf('vv_elediv',1,'phi','norm_d','phi')

% minphi = min(phi[0...iter])
addl(['if (' prefix 'iter > 0) {' char(10)])
addf('min','minphi','phi','minphi')
addl('}else{')
addf('v_copy',1,'phi','minphi')
addl('}')

%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

