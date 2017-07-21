function [ pdata4sim ] = problemdata2simulink( problemdata, vars )
%problemdata2simulink 
global gendata
global pstruc

K = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;

pdata4sim.x0=problemdata.xinit;

for i=1:length(vars)
tmp=[];
tmp_name=vars{i}.name;
tmp_struc=getfield(problemdata,tmp_name);
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
        tmp=[tmp;tmp_struc{k+1}];
    end
    
    if adim==0
        adim=1;
    end

    pdata4sim=setfield(pdata4sim,tmp_name,reshape(tmp,adim,1));
    
end

end




