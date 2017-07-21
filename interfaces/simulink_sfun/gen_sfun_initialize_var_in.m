function [] = gen_sfun_initialize_var_in(vars)
%Diese Funktion generiert die Initialisierung der Eingangsschnittstellen
%% #############
% # Changelog #
% #############
%
% 22.11.16 Annika Mayer (annika.mayer@isys.uni-stuttgart.de):



global gendata
global pstruc

K = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;
addc(['1.    ','SelectUpdates'])
gen_sfun_single_var_in(0,8,numel(vars))

addc(['2.    ','x0'])
if strcmp(gendata.precision,'double')
    gen_sfun_single_var_in(1,0,nx)
else
    gen_sfun_single_var_in(1,1,nx)
end


for i=1:length(vars)

    intvar = 0;
    if isfield(vars{i},'intvar')
        if vars{i}.intvar == 1
            intvar = 1;
        end
    end
    I2=0:K;
    if (~isempty(pstruc)) && (gendata.mem_type==2)
      fcell=@(x)strcmp(vars{i}.name,x);
      % Findet Index in pstruc Elemente für Eingangselement
      I1=find(cellfun(fcell,pstruc.names)==1,1,'first');
      if ~isempty(I1)
      %Index der unterschiedlichen Elemente    
      I2=pstruc.id_diff_input(1:pstruc.N_diff_input(I1),I1)-1; 
      end
    end  
    adim=0;  
    for k2=1:length(I2)
        k=I2(k2);
        if length(vars{i}.dim1) > 1
            dim1 = vars{i}.dim1(k+1);
        else
            dim1 = vars{i}.dim1;
        end
        if length(vars{i}.dim2) > 1
            dim2 = vars{i}.dim2(k+1);
        else
            dim2 = vars{i}.dim2;
        end
        adim=dim1*dim2+adim;
    end
        addc(['', num2str(i+2),'.    ',vars{i}.name,'; Kunique=',num2str(length(I2)),', dim1=',num2str(dim1),', dim2=',num2str(dim2)])
    if intvar
     gen_sfun_single_var_in(i+1,4,adim)   
    else
        if strcmp(gendata.precision,'double')
            gen_sfun_single_var_in(i+1,0,adim)
        else
            gen_sfun_single_var_in(i+1,1,adim)
        end
    end

end

end


function [] = gen_sfun_single_var_in(index,typeID,N)
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
if N==0
    N=1; % Zum erstmaligen Testen, weil Länge 0 nicht erlaubt ist
end
addl(['        ssSetInputPortWidth(S, ',num2str(index),', ',num2str(N),');']);
addl(['        ssSetInputPortDirectFeedThrough(S, ',num2str(index),', 1);']); 
addl(['        ssSetInputPortDataType(S, ',num2str(index),', ',strType,');']); 

end
