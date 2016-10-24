function [ funstr ] = gen_lqdocpip_debug1()
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
addc('###############################################')
addc('  Diese Funktion speichert Daten zum Debuggen')
addc('vor der Überprüfung der Kon-/Divergenzkriterien')
addc('###############################################')
addl(['static void ' prefix 'glqdocpip_debug1()' char(10) '{'])

% Dualitätslücke
addl('')
addc('dgap')
addl([prefix 'debug_dgap[' prefix 'iter] = ' prefix 'dgap[0];'])

% phi
addl('')
addc('phi')
addl([prefix 'debug_phi[' prefix 'iter] = ' prefix 'phi[0];'])

% minphi
addl('')
addc('minphi')
addl([prefix 'debug_minphi[' prefix 'iter] = ' prefix 'minphi[0];'])

% norm_d
addl('')
addc('norm_d')
addl([prefix 'debug_norm_d[0] = ' prefix 'norm_d[0];'])

% norm_r
addl('')
addc('norm_r')
addl([prefix 'debug_norm_r[' prefix 'iter] = ' prefix 'norm_r[0];'])

% norm_r0
addl('')
addc('norm_r0')
addl([prefix 'debug_norm_r0[0] = ' prefix 'norm_r0[0];'])

% mu
addl('')
addc('mu')
addl([prefix 'debug_mu[' prefix 'iter] = ' prefix 'mu[0];'])

% mu0
addl('')
addc('mu0')
addl([prefix 'debug_mu0[0] = ' prefix 'mu0[0];'])


%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

