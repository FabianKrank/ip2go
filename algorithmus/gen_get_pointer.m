function [cstr,hstr] = gen_get_pointer(varname)
% helptext
global gendata;
global genstr;

if ~ischar(varname)
    disp('Kein String an gen_get_pointer übergeben')
    cstr = [];
    hstr = [];
    return
end
K = gendata.dim.K;
prec = gendata.prec;
prefix = gendata.prefix;

% Optionen herausfiltern
singlevar = 0;
intvar = 0;
doublevar = 0;

while strfind(varname,'&')
    % nok
    if length(varname) > 4
        if strcmp(varname(end-3:end),'&nok')
            varname = varname(1:end-4);
            singlevar = 1;
        end
    end
    % int
    if length(varname) > 4
        if strcmp(varname(end-3:end),'&int')
            varname = varname(1:end-4);
            intvar = 1;
        end
    end
%     % double
%     if length(varname) > 7
%         if strcmp(varname(end-6:end),'&double')
%             varname = varname(end-6:end);
%             doublevar = 1;
%         end
%     end
end

genstr = [];


if ~singlevar
    if intvar
        % int und k-Diskretisierungsschritte
        addl(['int *' prefix 'get_' varname '(int k)'])
        addl('{')
        addl('  switch(k)')
        addl('  {')
        for i=0:K
            addl(['    case ' num2str(i) ': return &' prefix varname num2str(i) ';'])
        end
        addl('    default: return 0;')
        addl('  }')
    else
        % prec und k-Diskretisierungsschritte
        addl([prec ' *' prefix 'get_' varname '(int k)'])
        addl('{')
        addl('  switch(k)')
        addl('  {')
        for i=0:K
            addl(['    case ' num2str(i) ': return ' prefix varname num2str(i) ';'])
        end
        addl('    default: return 0;')
        addl('  }')
    end
else
    if intvar
        % int (byValue) und ein Wert insgesamt
        addl(['int *' prefix 'get_' varname '()'])
        addl('{')
        addl(['return &' prefix varname ';']);
    else
        % prec und ein Wert insgesamt
        addl([prec ' *' prefix 'get_' varname '()'])
        addl('{')
        addl(['return ' prefix varname ';']);
    end
    
end
addl('}')

if singlevar
    if intvar
        hstr = ['int *' prefix 'get_' varname '();'];
    elseif doublevar
        hstr = ['double *' prefix 'get_' varname '();'];
    else
        hstr = [prec ' *' prefix 'get_' varname '();'];
    end
else
    if intvar
        hstr = ['int *' prefix 'get_' varname '(int k);'];
    else
        hstr = [prec ' *' prefix 'get_' varname '(int k);'];
    end
end
cstr = genstr;
genstr = [];
return
end