function [ funstr ] = gen_lqdocpip_rhs_corrector()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

K  = gendata.dim.K; 
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;

%Funktionskopf
addl(['static void ' prefix 'glqdocpip_rhs_corrector()' char(10) '{'])

for k=0:K
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    addc(['Zeitschritt ' num2str(k)])
    kstr = num2str(k);
    
    %rk_corr
    addc('rk_corr')
    tmpstr1 = addt(n_c+n_s);
    tmpstr2 = addt(n_c+n_s);
    tmpstr3 = addt(1);
    
    % rk = rk + dy.*dnu
    addf('vv_elemult', n_c+n_s, ['dy' kstr], ['dnu' kstr], tmpstr1)
    addf('vadd', n_c+n_s, ['rk' kstr], tmpstr1, ['rk' kstr])
    
    
    % rk = rk - sigma*mu*ones()
    addf('v_init1', n_c+n_s, tmpstr1)
    addf('v_init0', n_c+n_s, tmpstr2)
    addf('vv_elemult',1,'sigma','mu',tmpstr3)
    addf('sv',n_c+n_s, tmpstr3, tmpstr1, tmpstr2)
    addf('vsub', n_c+n_s, ['rk' kstr], tmpstr2, ['rk' kstr])
    
    subt(tmpstr1);
    subt(tmpstr2);
    subt(tmpstr3);
end


%Funktionsende
addl(['}'])

funstr = genstr;
%clipboard('copy', genstr); 
genstr = [];
end

