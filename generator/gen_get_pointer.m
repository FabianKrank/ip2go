function [cstr,hstr] = gen_get_pointer(varname)
% helptext
global gendata;
global genstr;
global genstore;
genstore.prefix='arr_t';
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
        if  (exist('genstore','var')&&(gendata.mem_type==2))
            
        else
            addl('  switch(k)')
            addl('  {')
            for i=0:K
                addl(['    case ' num2str(i) ': return &' prefix varname num2str(i) ';'])
            end
            addl('    default: return 0;') 
        end
        addl('  }')
   
    else
        % prec und k-Diskretisierungsschritte
        addl([prec ' *' prefix 'get_' varname '(int k)'])
        addl('{')
        isstradd=0;
        if  (exist('genstore','var')&&(gendata.mem_type==2))&&(isfield(genstore,'v_arr'))
            k1=0;
                varfound=0;
                while k1<size(genstore.names_arr,2)&&(varfound==0)
                    k1=k1+1;
                    if strcmp(genstore.names_arr{k1},varname)

                        varfound=k1;

                    end  

                end
            if varfound ~=0    
                
                delta=unique(diff(genstore.v_arr{k1}(:,3)));
            if length(delta)>1
            str42=['int vindex[',num2str(size(genstore.v_arr{k1},1)) ,']={' num2str(genstore.v_arr{k1}(1,3))];
            for i=2:K+1
                str42=[str42,', ', num2str(genstore.v_arr{k1}(i,3))];
            end
            str42=[str42,'};' ];
            addl(str42);
            addl([' return &' prefix genstore.prefix num2str(genstore.v_arr{k1}(1,2)) '[vindex[k]]' ';'])
            elseif delta==0
             addl([' return &' prefix genstore.prefix num2str(genstore.v_arr{k1}(1,2)) '[' num2str(genstore.v_arr{k1}(1,3)) ']' ';'])   
            else
            addl([' return &' prefix genstore.prefix num2str(genstore.v_arr{k1}(1,2)) '[' num2str(genstore.v_arr{k1}(1,3)) '+k*' num2str(delta) ']' ';'])   

            end            
            isstradd=1;
            end
        end
        if isstradd==0
            addl('  switch(k)')
            addl('  {')
            for i=0:K
                addl(['    case ' num2str(i) ': return ' prefix varname num2str(i) ';'])
            end
            addl('    default: return 0;')
            addl('  }')
        end
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