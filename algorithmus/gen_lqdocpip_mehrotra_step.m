function [ funstr ] = gen_lqdocpip_mehrotra_step()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

% Funktionskopf
addc('#######################################################')
addc('Diese Funktion berechnet die Schrittweite nach Mehrotra')
addc('#######################################################')
addl(['static void ' prefix 'glqdocpip_mehrotra_step()' char(10) '{'])

addl('')

% FPD-Berechnung
addc('FPD')
tmp = addt(1);

% Fallunterscheidung alpha_min_source_y
%addl('mexPrintf("y_source: %i\n",mpc123_alpha_min_source_y);')
addl(['if (' prefix 'alpha_min_source_y == 1) {'])
%alpha_max durch y verursacht
addc('alpha_max durch y verursacht')

% Zähler
addf('vv_elemult',1,'alpha_max','alpha_min_dnu','mehrotra_fpd')
addf('vadd',1,'mehrotra_fpd','alpha_min_nu','mehrotra_fpd')
addf('vv_elediv',1,'mu_aff','mehrotra_fpd','mehrotra_fpd')
addf('vv_elemult',1,'mehrotra_fpd','mehrotra_gamma','mehrotra_fpd')
addf('vsub',1,'mehrotra_fpd','alpha_min_y','mehrotra_fpd')

% Nenner
addf('vv_elemult',1,'alpha_max','alpha_min_dy',tmp)

% fpd
addf('vv_elediv',1,'mehrotra_fpd',tmp,'mehrotra_fpd')

addl('} else {')
%alpha_max durch nu verursacht
addc('alpha_max durch nu verursacht')

% Zähler
addf('vv_elemult',1,'alpha_max','alpha_min_dy','mehrotra_fpd')
addf('vadd',1,'mehrotra_fpd','alpha_min_y','mehrotra_fpd')
addf('vv_elediv',1,'mu_aff','mehrotra_fpd','mehrotra_fpd')
addf('vv_elemult',1,'mehrotra_fpd','mehrotra_gamma','mehrotra_fpd')
addf('vsub',1,'mehrotra_fpd','alpha_min_nu','mehrotra_fpd')

% Nenner
addf('vv_elemult',1,'alpha_max','alpha_min_dnu',tmp)

% fpd
addf('vv_elediv',1,'mehrotra_fpd',tmp,'mehrotra_fpd')

addl(['}'])

subt(tmp);

% Schrittweite berechnen und begrenzen
addc('Schrittweitenfaktor begrenzen')
tmp = addt(1);
addc('Nach unten limitieren (1-gamma)')
addf('v_init1',1,tmp)
addf('vsub',1,tmp,'mehrotra_gamma',tmp)
addf('max','mehrotra_fpd',tmp,'mehrotra_fpd')
addc('nach oben limitieren (1-macheps)')
addf('v_init1',1,tmp)
addf('vsub',1,tmp,'macheps',tmp)
addf('min','mehrotra_fpd',tmp,'mehrotra_fpd')

addc('Schrittweite berechnen')
addf('vv_elemult',1,'mehrotra_fpd','alpha_max','mehrotra_alpha')

addc('Schritt begrenzen 0 =< alpha =< 1')
addf('v_init0',1,tmp)
addf('max','mehrotra_alpha',tmp,'mehrotra_alpha')
addf('v_init1',1,tmp)
addf('min','mehrotra_alpha',tmp,'mehrotra_alpha')

%addp('mehrotra_alpha','mehrotra_alpha')

subt(tmp);
%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

