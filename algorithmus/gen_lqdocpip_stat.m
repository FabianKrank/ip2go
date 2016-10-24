function [ funstr ] = gen_lqdocpip_stat()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;
prec = gendata.prec;

genstr = [];

% Funktionskopf
addc('################################################')
addc('Diese Funktion speichert Daten für die Statistik')
addc('################################################')
addl(['static void ' prefix 'glqdocpip_stat()' char(10) '{'])

% Zeit
addc('Zeit')
%addl(['QueryPerformanceCounter(&' prefix 'hpc_now);'])
%addl(['if(' prefix 'hpc_freq == 0){'])
%addl([prefix 'termcode = 8;'])
%addl([prefix 'error_line = __LINE__;']);
%addl('return;')
%addl('}')
%addl([prefix 'stat_time[' prefix 'iter] = (' prec ')(' prefix 'hpc_now - ' prefix 'hpc_start)/' prefix 'hpc_freq;'])
addl([prefix 'stat_time[' prefix 'iter] = ' prefix 'glqdocpip_timer_get();'])

%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

