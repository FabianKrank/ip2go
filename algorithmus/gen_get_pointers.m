function [cstr,hstr] = gen_get_pointers(vars)
%Diese Funktion generiert die Variablendeklarationen
global gendata;
global genstr;
genstr = [];
prec = gendata.prec;
prefix = gendata.prefix;

% vars = {'Hxx' 'Hxu' 'Huu'  'Hss' ...
%     'f0x' 'f0u' 'f0s' ...
%     'fx'  'fu'  'f' ...
%     'gx'  'gu'  'g' ...
%     };

cstr = [prec ' *' prefix 'get_x0()' char(10) '{' char(10) 'return ' prefix 'xinit;' char(10) '}'];
hstr = [prec ' *' prefix 'get_x0();'];

for i = 1:length(vars)
    cstr = [cstr char(10)];
    hstr = [hstr char(10)];
    [cstrtmp,hstrtmp] = gen_get_pointer(vars{i});
    cstr = [cstr cstrtmp];
    hstr = [hstr hstrtmp];
end

% cstr um tmax-Schnittstellen ergänzen
genstr = cstr;
addl(['double *' prefix 'get_time_max()'])
addl('{')
addl(['return &' prefix 'time_max;'])
addl('}')
addl('')
addl(['void ' prefix 'set_time_max(double tmax)'])
addl('{')
addl([prefix 'time_max = tmax;'])
addl('}')

cstr = genstr;

% hstr um tmax-Schnittstellen ergänzen
genstr = hstr;
addl(['double *' prefix 'get_time_max();'])
addl(['void ' prefix 'set_time_max(double tmax);'])
hstr = genstr;
genstr = [];
return
end