function [] = gen_sfun_outputs_var_out2problem(vars)
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


for i=1:length(vars)
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
   if singlevar
       end_index=1;
   else
       end_index=K+1;
   end
   proddim=vars{i}.dim1(1)*vars{i}.dim2(1);
   gen_sfun_single_var_out(vars{i}.name,intvar, end_index,proddim)
end

end


function [] = gen_sfun_single_var_out(var_name,intvar, end_index,ndim)
global gendata
if end_index==1
    if intvar
        addl(['        dptr_int = ' gendata.prefix 'get_' var_name '();'])
        addl(['        for(j=0; j<' num2str(ndim) '; j++) {'])
        addl(['          y_' var_name '[j]= (int16_T) dptr_int[j];}'])
    else
        addl(['        dptr = ' gendata.prefix 'get_' var_name '();'])
        addl(['        for(j=0; j<' num2str(ndim) '; j++) {'])
        addl(['          y_' var_name '[j] = (' gendata.prec ') dptr[j];}'])
    end

else
    if intvar
        addl(['        for(j1=0; j1<' num2str(end_index) '; j1++) {'])
        addl(['                dptr_int = ' gendata.prefix 'get_' var_name '(j1);'])
        addl(['                for(j=0; j<' num2str(ndim) '; j++) {'])
        addl(['                  y_' var_name '[j+j1*' num2str(ndim) ']= (int16_T) dptr_int[j];}'])
        addl(['        }'])
    else
        addl(['        for(j1=0; j1<' num2str(end_index) '; j1++) {'])
        addl(['                dptr = ' gendata.prefix 'get_' var_name '(j1);'])
        addl(['                for(j=0; j<' num2str(ndim) '; j++) {'])
        addl(['                  y_' var_name '[j+j1*' num2str(ndim) '] = (' gendata.prec ') dptr[j];}'])
        addl(['        }'])
    end
end

end
