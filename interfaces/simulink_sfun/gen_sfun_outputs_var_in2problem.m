function [] = gen_sfun_outputs_var_in2problem(vars)
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

addc(['x0'])
gen_sfun_single_var_in('x0',0,nx)

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
        gen_sfun_single_var_in(vars{i}.name,adim, adim+dim1*dim2,k)
        adim=dim1*dim2+adim;
    end

end

end


function [] = gen_sfun_single_var_in(var_name,start_index, end_index,k)
global gendata
if nargin<4
        addl(['        dptr = ' gendata.prefix 'get_' var_name '();'])

else
        addc(['Zeitschritt ' num2str(k)])
        addl(['        dptr = ' gendata.prefix 'get_' var_name '(' num2str(k) ');'])
end
        
        addl(['        for(j=' num2str(start_index) '; j<' num2str(end_index) '; j++) {'])
        addl(['          dptr[j] = (' gendata.prec ') *uPtr_' var_name '[j];}'])
end
