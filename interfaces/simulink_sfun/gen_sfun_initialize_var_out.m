function [] = gen_sfun_initialize_var_out(vars)
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
for i = 1:length(vars)
    
    % Typ von Variable bestimmen:
    %   prec oder int
    %   einzeln oder k Instanzen
    intvar = 0;
    singlevar = 0;
    if isfield(vars{i},'intvar')
        if vars{i}.intvar == 1
            intvar = 1;
        end
    end
    if isfield(vars{i},'singlevar')
        if vars{i}.singlevar == 1
            singlevar = 1;
        end
    end
    %disp([vars{i}.name ' | ' num2str(singlevar) ' | ' num2str(intvar)])
    adim=0;
    if singlevar
        K2=0;
    else
        K2=K;
    end
    % Schleife über alle Diskretisierungsstellen
    vdim1=[];
    vdim2=[];
    for k = 0:K2
        % Dimensionen der Variable zum aktuellen Zeitschritt bestimmen
        if length(vars{i}.dim1) > 1
            vdim1(k+1) = vars{i}.dim1(k+1);
        else
            vdim1(k+1) = vars{i}.dim1;
        end
        if length(vars{i}.dim2) > 1
            vdim2(k+1) = vars{i}.dim2(k+1);
        else
            vdim2(k+1) = vars{i}.dim2;
        end
    end
    adim=sum(vdim1.*vdim2);
    addc(['', num2str(i+1),'.    ',vars{i}.name,'; Kunique=',num2str(K2+1),', dim1=',num2str(vdim1(1)),', dim2=',num2str(vdim2(1))])
    if intvar
        gen_sfun_single_var_out(i-1,4,adim)
    else
        if strcmp(gendata.precision,'double')
            gen_sfun_single_var_out(i-1,0,adim)
        else
            gen_sfun_single_var_out(i-1,1,adim)
        end
    end
end

    function [] = gen_sfun_single_var_out(index,typeID,N)
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
        addl(['        ssSetOutputPortWidth(S, ',num2str(index),', ',num2str(N),');']);
        addl(['        ssSetOutputPortDataType(S, ',num2str(index),', ',strType,');']);
        
    end


end

