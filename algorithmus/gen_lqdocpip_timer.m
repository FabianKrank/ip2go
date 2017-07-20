function [ funstr, timer_include ] = gen_lqdocpip_timer()
% timer_start() initialisiert den timer
% timer_end() reads the timer value and returns the time difference with configured precision
% zurück
global gendata
global genstr

genstr_save = [];
timer_include = [];

prefix = gendata.prefix;
prec   = gendata.prec;

genstr = [];

%% timer include str
addc('include für Timer (plattformabhängig)')
for ii = 1:length(gendata.timer)
    if ii == 1
        next_char = '#if ';
    else
        next_char = '#elif ';
    end
    
    % Windows
    if strcmp(gendata.timer{ii},'windows')
        addl([next_char 'defined(IP2GO_WIN)'])
        addc('  Windows')
        addl('  #include "windows.h"')
        
    % dSpace
    elseif strcmp(gendata.timer{ii},'dspace')
        addl([next_char 'defined(IP2GO_DS1103)'])
        addc('  dSpace')
        addl('  #include "brtenv.h"')
        
    % none, create dummy timer
    elseif strcmp(gendata.timer{ii},'none')
        addl('#else')
        addc('  No timer')
    % Sonst: Unbekannt --> Fehler
    else
        error(['Unbekannter Timertyp: ' gendata.timer{ii}]);
    end
end
addl('#endif')

% include-str abspeichern und genstr zurücksetzen
timer_include = genstr;
genstr = [];

%% timer start
addc('######################################')
addc('Diese Funktion initialisiert den Timer')
addc('######################################')
addl(['void ' prefix 'glqdocpip_timer_start()' char(10) '{'])

for ii = 1:length(gendata.timer)
    if ii == 1
        next_char = '#if ';
    else
        next_char = '#elif ';
    end
    
    % Windows
    if strcmp(gendata.timer{ii},'windows')
        addl([next_char 'defined(IP2GO_WIN)'])
        addl(['  LARGE_INTEGER ' prefix 'tmp_counter, ' prefix 'tmp_frequency;'])
        addl(['  QueryPerformanceFrequency(&' prefix 'tmp_frequency);'])
        addl(['  QueryPerformanceCounter(&' prefix 'tmp_counter);'])
%         addl(['printf("Time: %i\n",tmp_frequency);'])
        addl(['  ' prefix 'timer_start = (' prec ') ' prefix 'tmp_counter.QuadPart/(' prec ') ' prefix 'tmp_frequency.QuadPart;'])
        
        % dSpace
    elseif strcmp(gendata.timer{ii},'dspace')
        addl([next_char 'defined(IP2GO_DS1103)'])
        addl(['  ' prefix 'timer_start = (' prec ') ds1103_timebase_fltread();'])
        
        % none
    elseif strcmp(gendata.timer{ii},'none')
        addl('#else')
        addc('   do nothing');
        % Sonst: Unbekannt --> Fehler
    else
        error(['Unbekannter Timertyp: ' gendata.timer{ii}]);
    end
end
addl('#endif')

addl('}')

addl('')
addl('')

%% timer get
addc('###################################################')
addc('Diese Funktion gibt die Zeit seit Timerstart zurück')
addc('###################################################')
addl([prec ' ' prefix 'glqdocpip_timer_get()' char(10) '{'])

for ii = 1:length(gendata.timer)
    if ii == 1
        next_char = '#if ';
    else
        next_char = '#elif ';
    end
    
    % Windows
    if strcmp(gendata.timer{ii},'windows')
        addl([next_char 'defined(IP2GO_WIN)'])
        addl(['  LARGE_INTEGER ' prefix 'tmp_counter, ' prefix 'tmp_frequency;'])
        addl(['  QueryPerformanceFrequency(&' prefix 'tmp_frequency);'])
        addl(['  QueryPerformanceCounter(&' prefix 'tmp_counter);'])
        addl(['  return (' prec ') ' prefix 'tmp_counter.QuadPart/(' prec ') ' prefix 'tmp_frequency.QuadPart - ' prefix 'timer_start;'])
        
        % dSpace
    elseif strcmp(gendata.timer{ii},'dspace')
        addl([next_char 'defined(IP2GO_DS1103)'])
        addl(['  return (' prec ') ds1103_timebase_fltread()- ' prefix 'timer_start;'])
        
        % none
    elseif strcmp(gendata.timer{ii},'none')
        addl('#else')
        addl(['  return (' prec ')0.0;'])
        
        % Sonst: Unbekannt --> Fehler
    else
        error(['Unbekannter Timertyp: ' gendata.timer{ii}]);
    end
end
addl('#endif')

addl('}')

funstr = genstr;

genstr = [];
end

