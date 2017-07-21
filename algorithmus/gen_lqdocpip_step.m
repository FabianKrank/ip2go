function [ funstr ] = gen_lqdocpip_step()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

K  = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;

% Funktionskopf
addc('######################################')
addc('Diese Funktion führt einen Schritt aus')
addc('######################################')
addl(['static void ' prefix 'glqdocpip_step()' char(10) '{'])
if gendata.mem_type==2
    addl('  int i1;');
end
% var = var + mehrotra_alpha * dvar

% Schleife über alle Zeitschritt
 k=0;
 i1=1;
 while k<K+1
     [k,kstr]=additer(k,i1);
%for k=0:K
    kstr = num2str(k);
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    addf('sv',nx,'mehrotra_alpha',['dx' kstr],['x' kstr])
    addf('sv',nu,'mehrotra_alpha',['du' kstr],['u' kstr])
    if n_s > 0
        addf('sv',n_s,'mehrotra_alpha',['ds' kstr],['s' kstr])
    end
    addf('sv',nx,'mehrotra_alpha',['dp' kstr],['p' kstr])
    if n_c > 0
        addf('sv',n_c+n_s,'mehrotra_alpha',['dy' kstr],['y' kstr])
        addf('sv',n_c+n_s,'mehrotra_alpha',['dnu' kstr],['nu' kstr])
    end
     k=additer_next(k,i1);
     i1=i1+1;
end

%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

