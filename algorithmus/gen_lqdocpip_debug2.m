function [ funstr ] = gen_lqdocpip_debug2()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;
prec = gendata.prec;

genstr = [];

K  = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;

% Funktionskopf
addc('###########################################')
addc('Diese Funktion speichert Daten zum Debuggen')
addc('     vor dem Durchführen des Schrittes')
addc('###########################################')
addl(['static void ' prefix 'glqdocpip_debug2()' char(10) '{'])

% sigma
addl('')
addc('sigma')
addl([prefix 'debug_sigma[' prefix 'iter] = ' prefix 'sigma[0];'])

% alpha_max
addl('')
addc('alpha_max')
addl([prefix 'debug_alpha_max[' prefix 'iter] = ' prefix 'alpha_max[0];'])

% mehrotra_alpha
addl('')
addc('mehrotra_alpha')
addl([prefix 'debug_mehrotra_alpha[' prefix 'iter] = ' prefix 'mehrotra_alpha[0];'])

% mu_aff
addl('')
addc('mu_aff')
addl([prefix 'debug_mu_aff[' prefix 'iter] = ' prefix 'mu_aff[0];'])

%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

