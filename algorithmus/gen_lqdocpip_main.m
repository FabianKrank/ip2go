function [ funstr ] = gen_lqdocpip_main()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

genstr = [];

prefix = gendata.prefix;

K = gendata.dim.K;


%% Funktionskopf
addl(['int ' gendata.prefix 'glqdocpip()' char(10) '{'])

%% Init

% Timer Start (ausser, wenn Timer von extern gestartet wird
if gendata.extern_timer_start
    
else
    addl('')
    addc('High Performance Timer (Windows)')
    addl([gendata.prefix 'glqdocpip_timer_start();'])
end

addl('')
addc('Init')
addl([gendata.prefix 'glqdocpip_init();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

addl('')
addc('Anfangsnorm bestimmen (norm_d)')
addl([gendata.prefix 'glqdocpip_calc_norm_d();'])

addl('')
addc('starting point')
addl([gendata.prefix 'glqdocpip_starting_point();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

%% Main Iteration Loop
addl('')
addc('Main Iteration Loop')
addl(['for(' prefix 'iter = 0; ' prefix 'iter < ' prefix 'max_iter; ' prefix 'iter++){'])
%addl(['mexPrintf("Iteration %d\n",' prefix 'iter);'])

addl('')
addc('Predictor rhs berechnen')
addl([gendata.prefix 'glqdocpip_rhs_affine();'])
addl([gendata.prefix 'glqdocpip_rhs_reduced();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

addl('')
addc('Konvergenz- und Divergenztests, inkl. Berechnung der dafür nötigen Parameter')
addl([gendata.prefix 'glqdocpip_calc_norm_r();'])
addl([gendata.prefix 'glqdocpip_calc_mu();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])
addl([gendata.prefix 'glqdocpip_calc_duality_gap();'])
addl([gendata.prefix 'glqdocpip_calc_phi();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])
if gendata.debug == 1
    addl([gendata.prefix 'glqdocpip_debug1();'])
end
addl([gendata.prefix 'glqdocpip_stat();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])
addl([gendata.prefix 'glqdocpip_check_condiv();'])
addc('Bei entsprechendem Termcode Funktion beenden')
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

addl('')
addc('Predictor GLS faktorisieren')
addl([gendata.prefix 'glqdocpip_factor();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

addl('')
addc('Predictor GLS lösen')
addl([gendata.prefix 'glqdocpip_solve();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])
addl([gendata.prefix 'glqdocpip_dereduce();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

addl([gendata.prefix 'glqdocpip_iter_ref();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

addl('')
addc('Korrekturfaktor für CorrectorGLS berechnen,')
addc('inkl der dafür nötigen Parameter')
addl([gendata.prefix 'glqdocpip_max_stepsize();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])
addl([gendata.prefix 'glqdocpip_calc_mu_aff();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])
addl([gendata.prefix 'glqdocpip_calc_sigma();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

%addl('if (mpc123_iter == 0){return mpc123_termcode;}')

addl('')
addc('Corrector rhs berechnen')
addl([gendata.prefix 'glqdocpip_rhs_corrector();'])
addl([gendata.prefix 'glqdocpip_rhs_reduced();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

addl('')
addc('Corrector GLS lösen')
addl([gendata.prefix 'glqdocpip_solve();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])
addl([gendata.prefix 'glqdocpip_dereduce();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

addl([gendata.prefix 'glqdocpip_iter_ref();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])

addl('')
addc('Schritt berechnen und durchführen')
addl([gendata.prefix 'glqdocpip_max_stepsize();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])
addl([gendata.prefix 'glqdocpip_calc_mu_aff();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])
addl([gendata.prefix 'glqdocpip_mehrotra_step();'])
addl(['if(' prefix 'termcode > -1){return ' prefix 'termcode;}'])
if gendata.debug == 1
    addl([gendata.prefix 'glqdocpip_debug2();'])
end
addl([gendata.prefix 'glqdocpip_step();'])

addl('')
addc('Ende - Main Iteration Loop')
addl(['}'])
addl('')

%% Funktionsende
addl('')
addc('Termcode 3: Max Iterations exceeded')
addl([prefix 'termcode = 3;'])
addl(['return ' prefix 'termcode;'])
addl(['}'])

funstr = genstr;

%% Aufräumen
genstr = [];
end

