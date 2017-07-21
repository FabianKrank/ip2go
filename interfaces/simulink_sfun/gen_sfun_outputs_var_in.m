function [] = gen_sfun_outputs_var_in(vars)
%Diese Funktion generiert die Initialisierung der Eingangsschnittstellen
%% #############
% # Changelog #
% #############
%
% 22.11.16 Annika Mayer (annika.mayer@isys.uni-stuttgart.de):



global gendata


K = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;
gen_sfun_single_var_in(0,8,'bUpdateSig');
if strcmp(gendata.precision,'double')
    gen_sfun_single_var_in(1,0,'x0');
else
    gen_sfun_single_var_in(1,1,'x0');
end
for i=1:length(vars)

    intvar = 0;
    if isfield(vars{i},'intvar')
        if vars{i}.intvar == 1
            intvar = 1;
        end
    end
    if intvar==1
        gen_sfun_single_var_in(i+1,4,vars{i}.name);    
    else
        if strcmp(gendata.precision,'double')
            gen_sfun_single_var_in(i+1,0,vars{i}.name);    
        else
            gen_sfun_single_var_in(i+1,1,vars{i}.name);    
        end
    end
    
end

end


function [] = gen_sfun_single_var_in(index,typeID,name_str)
vstr_type{0+1}='SS_DOUBLE'; %https://de.mathworks.com/help/simulink/sfg/sssetinputportdatatype.html
vstr_type{1+1}='SS_SINGLE';
vstr_type{2+1}='SS_INT8';
vstr_type{3+1}='SS_UINT8';
vstr_type{4+1}='SS_INT16';
vstr_type{5+1}='SS_UINT16';
vstr_type{6+1}='SS_INT32';
vstr_type{7+1}='SS_UINT32';
vstr_type{8+1}='SS_BOOLEAN';
strType=vstr_type{typeID+1};
% Matlab Example sfun_dtype_io.c
switch typeID
    case 0

addl(['        InputRealPtrsType uPtr_',name_str,' = (ssGetInputPortRealSignalPtrs(S,',num2str(index),'));']);
    case 1
addl(['        InputReal32PtrsType uPtr_',name_str,' = ((InputReal32PtrsType)ssGetInputPortRealSignalPtrs(S,',num2str(index),'));']);
    case 4
addl(['        InputInt16PtrsType uPtr_',name_str,' = ((InputInt16PtrsType)ssGetInputPortSignalPtrs(S,',num2str(index),'));']);
         
    case 8
addl(['        InputBooleanPtrsType uPtr_',name_str,' = ((InputBooleanPtrsType)ssGetInputPortSignalPtrs(S,',num2str(index),'));']);
        
end
end
