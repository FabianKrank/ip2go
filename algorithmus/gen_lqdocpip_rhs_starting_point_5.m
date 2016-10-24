function [ funstr ] = gen_lqdocpip_rhs_starting_point_5()
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
addl(['static void ' prefix 'glqdocpip_rhs_starting_point_5()' char(10) '{'])

for k=0:K
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    addc(['Zeitschritt ' num2str(k)])
    kstr = num2str(k);
    
    % rf0x = f0x
    %addf('v_copy',nx,['f0x' kstr],['rf0x' kstr])
    addf('v_init0',nx,['rf0x' kstr])
    % rf0u = f0u
    %addf('v_copy',nu,['f0u' kstr],['rf0u' kstr])
    addf('v_init0',nu,['rf0u' kstr])
    % rf0s = f0s
    if n_s > 0
        addf('v_copy',n_s,['f0s' kstr],['rf0s' kstr])
    end
    
    % rf = f[k-1], rf[0] = x0
    if k == 0
        addf('v_copy',nx,['xinit'],['rf' kstr])
    else
        addf('v_copy',nx,['f' num2str(k-1)],['rf' kstr])
    end
    
    % rc = g
    if n_c > 0
        addf('v_copy',n_c,['g' kstr],['rc' kstr])
    end
    
    % rs = nu_ss - s
    if n_s > 0
        addf('v_init0',n_s,['rs' kstr])
        addf('vsub',n_s,['nu' kstr '[' num2str(n_c) ']'],['s' kstr],['rs' kstr])
    end
    
    % rk = y.*nu
    if n_c > 0
        addf('vv_elemult',n_c+n_s,['y' kstr],['nu' kstr],['rk' kstr])
    end
    
end

%Funktionsende
addl(['}'])

funstr = genstr;
%clipboard('copy', genstr);
genstr = [];
end

