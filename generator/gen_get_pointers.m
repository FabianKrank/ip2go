function [cstr,hstr] = gen_get_pointers(vars)
%Diese Funktion generiert die Variablendeklarationen
global gendata;
global genstr;
global genstore;
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
addl([prec ' *' prefix 'get_time_max()'])
addl('{')
addl(['return &' prefix 'time_max;'])
addl('}')
addl('')
addl(['void ' prefix 'set_time_max(' prec ' tmax)'])
addl('{')
addl([prefix 'time_max = tmax;'])
addl('}')

cstr = genstr;

% hstr um tmax-Schnittstellen ergänzen
genstr = hstr;
addl([prec ' *' prefix 'get_time_max();'])
addl(['void ' prefix 'set_time_max(' prec ' tmax);'])
hstr = genstr;

% Funktion zum Aufruf der Arrayindizes erstellen
if  (exist('genstore','var')&&(gendata.mem_type==2))&&(isfield(genstore,'v_arr'))

if length(genstore.ext_var)>1
% cstr ergänzen
genstr = cstr;
for i=1:length(genstore.akt_index)
   if genstore.akt_index(i)~=0 
addl(['int ' prefix 'get_index_' genstore.prefix num2str(i) '(int i1, int i2)'])
addl('{')
addl(['int id[' num2str(size(genstore.names_arr,2)) '][' num2str(gendata.dim.K+1) '] ={'])
for i2=0:(length(genstore.names_arr)-1)
    str42=['{' num2str(genstore.v_arr{i2+1}(1,3))];
    for k1=2:gendata.dim.K++1
        str42=[str42,', ', num2str(genstore.v_arr{i2+1}(k1,3))];
    end
    str42=[str42,'}' ];
    if i2<(length(genstore.names_arr)-1)
        str42=[str42,',' ];
    end
    addc([genstore.names_arr{i2+1} ' #Index ' num2str(i2)]);
    addl(str42);
end
addl('};');
addl(['return id[i1][i2];'])
addl('}')

   end
end

cstr = genstr;

% hstr ergänzen
genstr = hstr;
for i=1:length(genstore.akt_index)
   if genstore.akt_index(i)~=0 
addl(['int ' prefix 'get_index_' genstore.prefix num2str(i) '(int i1, int i2);'])
   end
end
hstr = genstr;  
end   
end

genstr = [];
return
end