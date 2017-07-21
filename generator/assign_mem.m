function [str42, array_type] = assign_mem( arg )
% Function assign_mem controls which memory element is called for input argument,
% the function allows to use code generation with 
global gendata;
global genstore;
global aiter

idtok=0;
if exist('genstore','var')&&(gendata.mem_type==2)&&(isfield(genstore,'v_arr'))
    tokens=regexp(arg,'(.*?)(\d+)\[(\d+)\]\>','tokens');
    idtok=1;
    if isempty(tokens)
    tokens=regexp(arg,'(.*?)(\d+)\[(\w+)\]\>','tokens'); 
    idtok=2;
    end
    if isempty(tokens)
    tokens=regexp(arg,'(.*?)(\d+)\>','tokens'); 
    idtok=3;
    end
    
    if isempty(tokens)
        array_type = 0;
        str42=arg;
    idtok=4;
    else
        
        str=tokens{1}{1};
        index=str2double(tokens{1}{2})+1;
        
        % Überprüft ob Variablenname in Arraystruktur abgelegt wurde
        findex=find(strcmp(str,genstore.names_arr),1);
        
        if isempty(findex)
                    if strcmp(arg(end),']')
                        array_type = 1;
                    else
                       array_type = 0;
                    end  
                    str42=arg;
                    
        else
            
            array_type = 1;
            if isfield(aiter,'open_bracket')&&(aiter.open_bracket==1)
                    k_change=[];
                    element_change=[];
                    if (index-1)~=aiter.k
                        k_change=num2str(index-1-aiter.k);
                    end
                    switch idtok
                        case 1
                            id=str2double(tokens{1}{3});
                            element_change=num2str(id);
                        case 2
                            id=tokens{1}{3};
                            element_change=id;
                    end
                    str22=get_memindex(aiter.id_iter,findex,aiter.kstr,k_change, element_change);
                    str42=['arr_t',num2str(genstore.v_arr{findex}(index,2)),'[',str22, ']'];
            else
            
                switch idtok

                    case 1
                        id=str2double(tokens{1}{3});
                        str42=['arr_t',num2str(genstore.v_arr{findex}(index,2)),'[',num2str(genstore.v_arr{findex}(index,3)+id), ']'];
                    case 2
                        id=tokens{1}{3};
                        str42=['arr_t',num2str(genstore.v_arr{findex}(index,2)),'[',num2str(genstore.v_arr{findex}(index,3)),'+',id, ']'];
                    case 3
                        str42=['arr_t',num2str(genstore.v_arr{findex}(index,2)),'[',num2str(genstore.v_arr{findex}(index,3)) ']'];
                        
                end
            
            end
        end

        
     
     
        
    end

    
else
    
        if strcmp(arg(end),']')
            array_type = 1;
        else
           array_type = 0;
        end  
        
        str42=arg;

end



end

function [strfun]=get_memindex(id_iter,id_name,kstr,k_change, element_change)
global gendata
global genstore

v1=genstore.iter{id_iter}.types_arr(1,id_name);
vdelta=genstore.iter{id_iter}.types_arr(2,id_name);
Iit=gendata.iter{id_iter};
I1=Iit(1)+1;
Iend=Iit(end)+1;
str_kc='';
if ~isempty(k_change)
    str_kc=['+(', k_change ,')'];
end

str_ec='';
if ~isempty(element_change)
    str_ec=['+(', element_change ,')'];
end
kok=1;

% Checks if element of index +1,-1 can be adressed in same fashion as
% elements during iteration
% Information of elements +x,-x are not evaluated and it is assumed that
% they have to be called seperatly
if ~isempty(k_change)
    kok=0;
    if strcmp(k_change,'1')
        if genstore.iter{id_iter}.types_arr(4,id_name)
            kok=1;
        end
    elseif  strcmp(k_change,'-1')
        if genstore.iter{id_iter}.types_arr(3,id_name)
            kok=1;
        end
        
    end   
end


if (v1==1)||~kok
    genstore.ext_var(end+1)=id_name;
    strfun=[gendata.prefix ,'get_index_', genstore.prefix, num2str(genstore.v_arr{id_name}(1,2)), '(', num2str(id_name-1), ',', kstr,str_kc,')',str_ec,''];
elseif v1==2 %Selber Abstand
    strfun=[  num2str(genstore.v_arr{id_name}(I1,3)),'+(',kstr,'-',num2str(I1-1), str_kc,')*',num2str(vdelta), str_ec];
elseif v1==3 % Alle Elemente gleich
    strfun=[  num2str(genstore.v_arr{id_name}(I1,3)), str_ec];
end


end
