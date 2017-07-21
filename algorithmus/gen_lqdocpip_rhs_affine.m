function [ funstr ] = gen_lqdocpip_rhs_affine()
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
addl(['static void ' prefix 'glqdocpip_rhs_affine()' char(10) '{'])
if gendata.mem_type==2
    addl('  int i1;');
end
  k=0;
  i1=1;
while k<K+1
     [k,kstr]=additer(k,i1);
%for k=0:K
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    addc(['Zeitschritt ' num2str(k)])
    kstr = num2str(k);
    k2str = num2str(k+1);
    k3str = num2str(k-1);
    
    %rf0x
    addc('rf0x')
    addf('v_copy',nx,['f0x' kstr],['rf0x' kstr])
    addf('mv',nx,nx,['Hxx' kstr],['x' kstr],['rf0x' kstr],get_sbyname('Hxx',k),get_sbyname('full_vector_nx'))
    addf('mv',nx,nu,['Hxu' kstr],['u' kstr],['rf0x' kstr],get_sbyname('Hxu',k),get_sbyname('full_vector_nu'))
    addf('vsub',nx,['rf0x' kstr],['p' kstr],['rf0x' kstr])
    if k~=K
        addf('mtv',nx,nx,['fx' kstr],['p' k2str],['rf0x' kstr],get_sbyname('fx',k),get_sbyname('full_vector_nx'))
    end
    if n_c > 0
        addf('mtv',n_c,nx,['gx' kstr],['y' kstr],['rf0x' kstr],get_sbyname('gx',k),get_sbyname('full_vector_nc',k))
    end
    
    %rf0u
    addc('rf0u')
    addf('v_copy',nu,['f0u' kstr],['rf0u' kstr])
    addf('mtv',nx,nu,['Hxu' kstr],['x' kstr],['rf0u' kstr],get_sbyname('Hxu',k),get_sbyname('full_vector_nx'))
    addf('mv',nu,nu,['Huu' kstr],['u' kstr],['rf0u' kstr],get_sbyname('Huu',k),get_sbyname('full_vector_nu'))
    if k~=K
        addf('mtv',nx,nu,['fu' kstr],['p' k2str],['rf0u' kstr],get_sbyname('fu',k),get_sbyname('full_vector_nx'))
    end
    if n_c > 0
        addf('mtv',n_c,nu,['gu' kstr],['y' kstr],['rf0u' kstr],get_sbyname('gu',k),get_sbyname('full_vector_nc',k))
    end
    
    %rf0s
    if n_s > 0
        addc('rf0s')
        addf('v_copy',n_s,['f0s' kstr],['rf0s' kstr])
        addf('mv',n_s,n_s,['Hss' kstr],['s' kstr],['rf0s' kstr],get_sbyname('Hss',k),get_sbyname('full_vector_ns',k))
        addf('vsub',n_s,['rf0s' kstr],['y' kstr '[0]'],['rf0s' kstr])
        addf('vsub',n_s,['rf0s' kstr],['y' kstr '[' num2str(n_c) ']'],['rf0s' kstr])
    end
    
    %rf
    addc('rf')
    if k~=0
        addf('v_copy',nx,['f' k3str],['rf' kstr])
        addf('mv',nx,nx,['fx' k3str],['x' k3str],['rf' kstr],get_sbyname('fx',k),get_sbyname('full_vector_nx'))
        addf('mv',nx,nu,['fu' k3str],['u' k3str],['rf' kstr],get_sbyname('fu',k),get_sbyname('full_vector_nu'))
        addf('vsub',nx,['rf' kstr], ['x' kstr],['rf' kstr])
    else
        addf('v_copy',nx,['xinit'],['rf' kstr])
        addf('vsub',nx,['rf' kstr], ['x' kstr],['rf' kstr])
    end
    
    %rc
    if n_c > 0
        addc('rc')
        addf('v_copy',n_c,['g' kstr],['rc' kstr])
        addf('mv',n_c,nx,['gx' kstr],['x' kstr],['rc' kstr],get_sbyname('gx',k),get_sbyname('full_vector_nx'))
        addf('mv',n_c,nu,['gu' kstr],['u' kstr],['rc' kstr],get_sbyname('gu',k),get_sbyname('full_vector_nu'))
        addf('vadd',n_c,['rc' kstr],['nu' kstr],['rc' kstr])
        if n_s > 0
            addf('vsub',n_s,['rc' kstr],['s' kstr],['rc' kstr])
        end
    end
    
    %rs
    if n_s > 0
        addc('rs')
        addf('v_init0',n_s,['rs' kstr])
        addf('vsub',n_s,['nu' kstr '[' num2str(n_c) ']'],['s' kstr],['rs' kstr])
    end
    
    %rk
    if n_c > 0
        addc('rk')
        addf('vv_elemult',n_c+n_s,['y' kstr],['nu' kstr],['rk' kstr])
    end
      k=additer_next(k,i1);
      i1=i1+1;
end

%Funktionsende
addl(['}'])

funstr = genstr;
%clipboard('copy', genstr);
genstr = [];
end

