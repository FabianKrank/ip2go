function [ funstr ] = gen_lqdocpip_init()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

genstr = [];

prefix = gendata.prefix;

K = gendata.dim.K;


%% Funktionskopf
addl(['void ' gendata.prefix 'glqdocpip_init()' char(10) '{'])

%% Parameter Init
addc('## Parameter INIT ## ')
% m_ineq
addc('Anzahl Ungleichungsbedingungen')
addl([prefix 'm_ineq[0] = ' num2str(gendata.parameter.m_ineq) ';'])
% Toleranz
addc('Toleranz (Abbruchkriterium)')
addl([prefix 'tol[0] = ' num2str(gendata.parameter.tol) ';'])
% Mehrotra Gamma
addc('Mehrotra Gamma')
addl([prefix 'mehrotra_gamma[0] = ' num2str(gendata.parameter.mehrotra_step_gamma) ';'])
% macheps
addc('Machine Epsilon')
if gendata.calc_macheps == 1
    addc('Init Berechnung')    
    div = addt(1);
    sol = addt(1);
    cnt = addt(1);
    addf('v_init0',1,cnt)
    addl([prefix div '[0] = ' num2str(gendata.parameter.calc_macheps_div_init) ';'])
    addl([prefix sol '[0] = 1.0f - ' prefix div '[0]/2;'])
    addc('Berechnungsschleife: while((1-div/2)!=1){div = div/2}')
    addl(['while(' prefix sol '[0] != 1.0f){'])
    addl([prefix div '[0] = ' prefix div '[0]/2;'])
    addl([prefix sol '[0] = 1.0f - ' prefix div '[0]/2;'])
    addl([prefix cnt '[0] += 1;'])
    %addl(['mexPrintf("%25.23f\n",' prefix div '[0]);'])
    addl(['if(' prefix cnt '[0] > ' num2str(gendata.parameter.calc_macheps_max_iter) '){'])
    addl([prefix 'termcode = 10;'])
    addl('return;')
    addl('}')
    addl('}')
    addl([prefix 'macheps[0] = ' prefix div '[0];'])
    %addl(['mexPrintf("%25.23f\n",' prefix 'macheps[0]);'])
    %addp(cnt)
    subt(div);
    subt(sol);
    subt(cnt);
else
    if strcmp(gendata.prec,'float')
        addl([prefix 'macheps[0] = FLT_EPSILON;'])
    elseif strcmp(gendata.prec,'double')
        addl([prefix 'macheps[0] = DBL_EPSILON;'])
    else
        error('Fehler in gen_lqdocpip_main: Ungültiger Datentyp')
    end
end
% tau
addc('tau')
addl([prefix 'tau[0] = ' num2str(gendata.parameter.tau) ';'])
% Termcode
addc('termcode')
addl([prefix 'termcode = -1;'])
% Error Line
addc('Error Line')
addl([prefix 'error_line = 0;'])
% Error Source
addc('Error Source')
addl([prefix 'error_source = 0;'])
% Termcode1 Faktor
addc('termcode 1 factor')
addl([prefix 'tc1_factor[0] = ' num2str(gendata.parameter.termcode_1_factor) ';'])
% Termcode2 Faktor
addc('termcode 2 factor')
addl([prefix 'tc2_factor[0] = ' num2str(gendata.parameter.termcode_2_factor) ';'])
% Termcode2 Faktor
addc('Blow up termination on if iterative refinement')
addl([prefix 'blowup_t_on[0] = ' num2str(gendata.parameter.blowup_termination_on) ';'])
% Time Limit
addc('tmax')
addl([prefix 'time_max = ' num2str(gendata.parameter.tmax) ';'])
% Max Iter
addc('max_iter')
addl([prefix 'max_iter = ' num2str(gendata.parameter.max_iter) ';'])

% Statistik
addc('num_iter_ref')
addl([prefix 'stat_num_iter_ref = 0;'])
addc('num_factor')
addl([prefix 'stat_num_factor = 0;'])
addc('num_solve')
addl([prefix 'stat_num_solve = 0;'])

addl(['}'])

funstr = genstr;

%% Aufräumen
genstr = [];
end

