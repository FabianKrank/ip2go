function [] = gen_sfun_outputs_var_out(vars)
%Diese Funktion generiert die Initialisierung der Ausgangsschnittstellen
%% #############
% # Changelog #
% #############
%
% 22.11.16 Annika Mayer (annika.mayer@isys.uni-stuttgart.de):


global gendata
global genstr

K = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;
prec = gendata.prec;


% Schleife über alle Variablen, die ausgegeben werden sollen
for i=1:length(vars)
    
    intvar = 0;
    if isfield(vars{i},'intvar')
        if vars{i}.intvar == 1
            intvar = 1;
        end
    end
    if intvar==1
        gen_sfun_single_var_out(i-1,4,vars{i}.name);
    else
        if strcmp(gendata.precision,'double')
            gen_sfun_single_var_out(i-1,0,vars{i}.name);
        else
            gen_sfun_single_var_out(i-1,1,vars{i}.name);
        end
    end
    
end
end

function [] = gen_sfun_single_var_out(index,typeID,name_str)
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
        
        addl(['        double *y_',name_str,' = (ssGetOutputPortSignal(S,',num2str(index),'));']);
    case 1
        addl(['        float *y_',name_str,' = ( (real32_T *) ssGetOutputPortSignal(S,',num2str(index),'));']);
    case 4
        addl(['        int16_T *y_',name_str,' = ((int16_T *)ssGetOutputPortSignal(S,',num2str(index),'));']);
        %int16_T *
    case 8
        addl(['        boolean *y_',name_str,' = ((boolean_T *)ssGetOutputPortSignal(S,',num2str(index),'));']);
        
end
end




