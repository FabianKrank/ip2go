function [ind] = mem_getindex( arg )
% Function assign_mem controls which memory element is called for input argument,
% the function allows to use code generation with 
global gendata;
global genstore;

ind=[];
if exist('genstore','var')&&(gendata.mem_type==2)&&(isfield(genstore,'v_arr'))
    tokens=regexp(arg,'(.*?)(\d+)\[(\d+)\]\>','tokens');
    if isempty(tokens)
    tokens=regexp(arg,'(.*?)(\d+)\[(\w+)\]\>','tokens'); 
    end
    if isempty(tokens)
    tokens=regexp(arg,'(.*?)(\d+)\>','tokens'); 
    end
    
    if ~isempty(tokens)
        str=tokens{1}{1};
        index=str2double(tokens{1}{2})+1;
        
        % Überprüft ob Variablenname in Arraystruktur abgelegt wurde
        findex=find(strcmp(str,genstore.names_arr),1);
        
        if ~isempty(findex)                
                        ind=genstore.v_arr{findex}(index,3);%+id;   
        end
 
    end 

end



end

