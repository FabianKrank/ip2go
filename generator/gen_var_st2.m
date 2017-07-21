function  gen_var_st2()
%Diese Funktion generiert die Variablendeklarationen
global gendata;
global genstore;

%% Größen aus gendata holen
K = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;
n_c = gendata.dim.n_c; % Achtung: Vektor
n_s = gendata.dim.n_s; % Achtung: Vektor

prec = gendata.prec;
prefix = gendata.prefix;
max_iter = gendata.parameter.max_iter;

% Für Statistik
genstore.akt_index=[0,0,0];
genstore.names=[];
genstore.v=[];
genstore.prefix='arr_t';
genstore.ext_var=[];

%% Variablen Daten erstellen
% Optimierungsvariablen
name = {'x' 'u' 's' 'p' 'y'   'nu' };
dim1 = {nx  nu  n_s  nx  n_c+n_s n_c+n_s};
dim2 = {1   1   1   1   1     1    };
optvar = {};
for i=1:length(name)
    optvar{i}.name = name{i};
    optvar{i}.dim1 = dim1{i};
    optvar{i}.dim2 = dim2{i};
end

% Schritt Variablen
name = {'dx' 'du' 'ds' 'dp' 'dy'   'dnu' };
dim1 = {nx   nu   n_s   nx   n_c+n_s  n_c+n_s };
dim2 = {1    1    1    1    1      1     };
stepvar = {};
for i=1:length(name)
    stepvar{i}.name = name{i};
    stepvar{i}.dim1 = dim1{i};
    stepvar{i}.dim2 = dim2{i};
end

% Gütefunktion Variablen
name = {'Hxx' 'Hxu' 'Huu' 'Hss' 'f0x' 'f0u' 'f0s' };
dim1 = {nx    nx    nu    n_s    nx    nu    n_s    };
dim2 = {nx    nu    nu    n_s    1     1     1     };
Jvar = {};
for i=1:length(name)
    Jvar{i}.name = name{i};
    Jvar{i}.dim1 = dim1{i};
    Jvar{i}.dim2 = dim2{i};
end

% Gleichungsnebenbedingung Variablen
name = {'fx' 'fu' 'f'};
dim1 = {nx   nx   nx };
dim2 = {nx   nu   1  };
eqvar = {};
for i=1:length(name)
    eqvar{i}.name = name{i};
    eqvar{i}.dim1 = dim1{i};
    eqvar{i}.dim2 = dim2{i};
end

% Ungleichungsnebenbedingung Variablen
name = {'gx' 'gu' 'g'};
dim1 = {n_c   n_c   n_c };
dim2 = {nx   nu   1  };
ineqvar = {};
for i=1:length(name)
    ineqvar{i}.name = name{i};
    ineqvar{i}.dim1 = dim1{i};
    ineqvar{i}.dim2 = dim2{i};
end

% rhs Variablen
name = {'rf0x' 'rf0u' 'rf0s' 'rf' 'rc' 'rs' 'rk'};
dim1 = {nx     nu     n_s     nx   n_c   n_s   n_c+n_s};
dim2 = {1      1      1      1    1    1    1};
rhsvar = {};
for i=1:length(name)
    rhsvar{i}.name = name{i};
    rhsvar{i}.dim1 = dim1{i};
    rhsvar{i}.dim2 = dim2{i};
end

% rrhs Variablen
name = {'rrf0x' 'rrf0u' 'rhsxs' 'yny'};
dim1 = {nx      nu      n_s      n_c   };
dim2 = {1       1       1       1    };
rrhsvar = {};
for i=1:length(name)
    rrhsvar{i}.name = name{i};
    rrhsvar{i}.dim1 = dim1{i};
    rrhsvar{i}.dim2 = dim2{i};
end

% Blockeliminationsverfahren Variablen
name = {'Gxx' 'Gxu' 'Guu' 'Rux' 'Vxx' 'Gx' 'Gu' 'Ru' 'Vx'};
dim1 = {nx    nx    nu    nu    nx    nx   nu   nu   nx  };
dim2 = {nx    nu    nu    nx    nx    1    1    1    1   };
bevar = {};
for i=1:length(name)
    bevar{i}.name = name{i};
    bevar{i}.dim1 = dim1{i};
    bevar{i}.dim2 = dim2{i};
end

% Schritt Variablen (iter_ref save)
name = {'dx_ir' 'du_ir' 'ds_ir' 'dp_ir' 'dy_ir'  'dnu_ir' };
dim1 = {nx      nu      n_s      nx      n_c+n_s n_c+n_s };
dim2 = {1       1       1       1       1        1     };
stepvarir = {};
for i=1:length(name)
    stepvarir{i}.name = name{i};
    stepvarir{i}.dim1 = dim1{i};
    stepvarir{i}.dim2 = dim2{i};
end

% rhs Variablen (iter_ref save)
name = {'rf0x_ir' 'rf0u_ir' 'rf0s_ir' 'rf_ir' 'rc_ir' 'rs_ir' 'rk_ir'};
dim1 = {nx        nu        n_s       nx      n_c     n_s     n_c+n_s};
dim2 = {1         1         1         1       1       1       1};
rhsvarir = {};
for i=1:length(name)
    rhsvarir{i}.name = name{i};
    rhsvarir{i}.dim1 = dim1{i};
    rhsvarir{i}.dim2 = dim2{i};
end


%% Variablendeklaration generieren
for k=0:K   
       % Gütefunktion Variablen

    for i=1:length(Jvar)
        gen_var_single_st(Jvar{i}.name,k,Jvar{i}.dim1,Jvar{i}.dim2);
    end
    
    % Gleichungsnebenbedingungen Variablen

    for i=1:length(eqvar)
        gen_var_single_st(eqvar{i}.name,k,eqvar{i}.dim1,eqvar{i}.dim2);
    end
    
    % Ungleichungsnebenbedingungen Variablen

    for i=1:length(ineqvar)
        gen_var_single_st(ineqvar{i}.name,k,ineqvar{i}.dim1,ineqvar{i}.dim2);
    end 
end

for k=0:K    
    % Optimierungvariablen

    for i=1:length(optvar)
        gen_var_single_st(optvar{i}.name,k,optvar{i}.dim1,optvar{i}.dim2);
    end
    
    % Schritt Variablen

    for i=1:length(stepvar)
        gen_var_single_st(stepvar{i}.name,k,stepvar{i}.dim1,stepvar{i}.dim2);
    end
        
    % rhs Variablen

    for i=1:length(rhsvar)
        gen_var_single_st(rhsvar{i}.name,k,rhsvar{i}.dim1,rhsvar{i}.dim2);
    end
    
    % rrhs Variablen

    for i=1:length(rrhsvar)
        gen_var_single_st(rrhsvar{i}.name,k,rrhsvar{i}.dim1,rrhsvar{i}.dim2);
    end
    
    % Blockeliminationsverfahren Variablen

    for i=1:length(bevar)
        gen_var_single_st(bevar{i}.name,k,bevar{i}.dim1,bevar{i}.dim2);
    end
 
    % Schrittvariablen (iter_ref Speicher)

    for i=1:length(stepvarir)
        gen_var_single_st(stepvarir{i}.name,k,stepvarir{i}.dim1,stepvarir{i}.dim2);
    end
    
    % rhs Variablen (iter_ref Speicher)

    for i=1:length(rhsvarir)
        gen_var_single_st(rhsvarir{i}.name,k,rhsvarir{i}.dim1,rhsvarir{i}.dim2);
    end
end


for k=0:K
    gen_var_single_st('L',k,nu,nu);
end


ic=1;
for i1=1:size(genstore.v,2)
  if(size(genstore.v{i1},1)~=1)  
    
    genstore.names_arr{ic}=genstore.names{i1};
    genstore.v_arr{ic}=genstore.v{i1};
    ic=ic+1;
    
  end

end
%test_verteilung;

%{
    
vtest=zeros(genstore.akt_index(1),1);

for i1=1:size(genstore.v,2)

  for i2=1:size(genstore.v{i1},1)

  temp=genstore.v{i};
  k1=temp(i2,3);
  k2=temp(i2,4);
  vtest(k1:k2)=vtest(k1:k2)+1;

  end

end


%}

return
end

function test_verteilung
global genstore
vtest1=zeros(genstore.akt_index(1),1);
vtest2=zeros(genstore.akt_index(2),1);
vtest3=zeros(genstore.akt_index(3),1);
for i1=1:size(genstore.v,2)

  for i2=1:size(genstore.v{i1},1)
  
  temp=genstore.v{i1};
  k1=temp(i2,3);
  k2=temp(i2,4);
  if temp(i2,2)==1
  vtest1(k1:k2)=vtest1(k1:k2)+1;
  end
    if temp(i2,2)==2
  vtest2(k1:k2)=vtest2(k1:k2)+1;
    end
    if temp(i2,2)==3
  vtest3(k1:k2)=vtest3(k1:k2)+1;
  end
  end

end
subplot(1,3,1)
stairs(vtest1);hold all;
sum(vtest1)
subplot(1,3,2)
stairs(vtest2);hold all;
sum(vtest2)
subplot(1,3,3)
stairs(vtest3);hold all;
sum(vtest3)
tmp_name_list=[];




end


function varstr = gen_var_single_st(varname, index, dim1, dim2, attribute)
% Generiert den String zur Deklaration einer Variablen
global gendata
global genstore
global pstruc

varstr='*';
% Zusätzliche Eingabeparameter auswerten
if exist('attribute','var')
    % Precision
    if isfield(attribute,'prec')
        prec = attribute.prec;
    else
        % Default
        prec = gendata.prec;
    end
    % Array ja/nein
    if isfield(attribute,'no_array')
        no_array = attribute.no_array;
    else
        % Default
        no_array = 0;
    end
    % Variable einfach vorhanden?
    if isfield(attribute,'no_k')
        no_k = attribute.no_k;
    else
        % Default
        no_k = 0;
    end
else
    % Default-Werte
    prec        = gendata.prec;
    no_array    = 0;
    no_k        = 0;
end 

% Unterschiedliche Array-Länge bei unterschiedlichen Diskretisierungsstellen möglich, da z.B. n_c(1) <> n_c(2)
if (length(dim1) > 1)
    dim1 = dim1(index+1);
end
if (length(dim2) > 1)
    dim2 = dim2(index+1);    
end

if dim1 == 0
    dim1 = 1;
    %warning([varname ': Dimension_1 = 0']);
end
if dim2 == 0
    dim2 = 1;
    %warning([varname ': Dimension_2 = 0']);
end

if no_array
    elements = 1;
else
    elements = dim1*dim2;
end
% Durchsuche alle bereits generierten Variablennamen, falls Variable noch
% nicht angelegt ist, lege dies an.

k1=0;
varfound=0;
while k1<size(genstore.names,2)&&(varfound==0)
    k1=k1+1;
    if strcmp(genstore.names{k1},varname)
       
        varfound=k1;
        
    end  
    
end

switch prec
    case 'float'
        prec_ind=1;
    case 'double'
        prec_ind=2;
    case 'int'
        prec_ind=3;
end
if varfound==0
      genstore.names{size(genstore.names,2)+1}=varname;
      ind1=index+1;
      genstore.v{size(genstore.names,2)}(ind1,1)=index;
      genstore.v{size(genstore.names,2)}(ind1,2)=prec_ind;
      genstore.v{size(genstore.names,2)}(ind1,3)=genstore.akt_index(prec_ind)+1;
      genstore.v{size(genstore.names,2)}(ind1,4)=genstore.akt_index(prec_ind)+ elements;
      genstore.v{size(genstore.names,2)}(ind1,5)=dim1;
      genstore.v{size(genstore.names,2)}(ind1,6)=dim2;   
      genstore.akt_index(prec_ind)=genstore.akt_index(prec_ind)+ elements;      
else
    

      ind1=index+1;
      genstore.v{varfound}(ind1,1)=index;
      genstore.v{varfound}(ind1,2)=prec_ind;

      genstore.v{varfound}(ind1,5)=dim1;
      genstore.v{varfound}(ind1,6)=dim2;   
      
      if (~isempty(pstruc))    
      fcell=@(x)strcmp(varname,x);
      I1=find(cellfun(fcell,pstruc.names)==1,1,'first');
          if isempty(I1)||any(pstruc.id_diff_input(:,I1)==ind1)

          genstore.v{varfound}(ind1,3)=genstore.akt_index(prec_ind)+1;
          genstore.v{varfound}(ind1,4)=genstore.akt_index(prec_ind)+ elements;            
          genstore.akt_index(prec_ind)=genstore.akt_index(prec_ind)+ elements;          
          else
          indx=pstruc.index_diff_input(ind1,I1);
          genstore.v{varfound}(ind1,3)=genstore.v{varfound}(indx,3);
          genstore.v{varfound}(ind1,4)=genstore.v{varfound}(indx,4);        
          end
      
      else
      genstore.v{varfound}(ind1,3)=genstore.akt_index(prec_ind)+1;
      genstore.v{varfound}(ind1,4)=genstore.akt_index(prec_ind)+ elements;
      genstore.akt_index(prec_ind)=genstore.akt_index(prec_ind)+ elements;     
      end
      

     
end


end