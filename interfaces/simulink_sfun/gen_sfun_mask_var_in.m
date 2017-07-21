function [] = gen_sfun_mask_var_in(vars)
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
gen_sfun_single_var_in('SelectUpdates',0,8,numel(vars))
if strcmp(gendata.precision,'double')
    gen_sfun_single_var_in('x0',1,0,nx)
else
    gen_sfun_single_var_in('x0',1,1,nx)
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
    if intvar
     gen_sfun_single_var_in(vars{i}.name,i+1,4,adim)   
    else
        if strcmp(gendata.precision,'double')
            gen_sfun_single_var_in(vars{i}.name,i+1,0,adim)
        else
            gen_sfun_single_var_in(vars{i}.name,i+1,1,adim)
        end
    end

end

end


function [] = gen_sfun_single_var_in(var_name,index,typeID,N)
        vstr_type{0+1}='d'; %https://de.mathworks.com/help/simulink/sfg/sssetinputportdatatype.html
        vstr_type{1+1}='s';
        vstr_type{2+1}='i8';
        vstr_type{3+1}='ui8';
        vstr_type{4+1}='i16';
        vstr_type{5+1}='ui16';
        vstr_type{6+1}='i32';
        vstr_type{7+1}='ui32';
        vstr_type{8+1}='n';
        strType=vstr_type{typeID+1};
if N==0
    N=1; % Zum erstmaligen Testen, weil Länge 0 nicht erlaubt ist
end
addl(['port_label( ''input'',' num2str(index+1) ', ''' var_name ' ' num2str(N) ' ' strType ''')']);       

end
