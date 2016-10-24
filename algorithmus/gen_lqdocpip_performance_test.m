function [cstr, hstr] = gen_lqdocpip_performance_test(ptest)
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

genstr = [];

prefix = gendata.prefix;

K = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;
n_c = gendata.dim.n_c(1);
n_s = gendata.dim.n_s(1);

%% Funktionskopf
str = ['double ' gendata.prefix 'glqdocpip_performance_test_' ptest.name '()'];
addl([str char(10) '{'])
hstr = [str ';'];
addl('int i;')

%% Codezeilen vor Test
for i=1:length(ptest.prelines)
    eval(ptest.prelines{i});
end

addl('')

%% Timer Init
addl([prefix 'glqdocpip_timer_start();'])
%addl(['QueryPerformanceCounter(&' prefix 'hpc_start);'])

%% Test Schleife
addl(['for(i = 0; i < ' num2str(ptest.runs) '; i++){'])
for i = 1:length(ptest.testline)
    eval(ptest.testline{i});
end
addl('}')

%% Timer Auswertung
addl(['return ' prefix 'glqdocpip_timer_get()/' num2str(ptest.runs) '*1000;'])
%addl(['QueryPerformanceCounter(&' prefix 'hpc_now);'])
%addl(['return (double)(' prefix 'hpc_now - ' prefix 'hpc_start)/' prefix 'hpc_freq;'])

%% Funktionsende
addl(['}'])

cstr = genstr;

%% Aufräumen
genstr = [];
end

