function [ funstr ] = gen_lqdocpip_rhs_iter_ref()
% Diese Funktion generiert den Quellcode zum Berechnen der rechten Seite
% des GLS für die Nachiteration
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

K  = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;

%Funktionskopf
addl(['static void ' prefix 'glqdocpip_rhs_iter_ref()' char(10) '{'])

for k=0:K
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    addc(['Zeitschritt ' num2str(k)])
    kstr = num2str(k);
    
    %rf0x
    addc('rf0x')
    %addf('vadd',nx,['rf0x' kstr],['f0x' kstr],['rf0x' kstr])
    addf('mv',nx,nx,['Hxx' kstr],['dx' kstr],['rf0x' kstr],get_sbyname('Hxx',k),get_sbyname('full_vector_nx'))
    addf('mv',nx,nu,['Hxu' kstr],['du' kstr],['rf0x' kstr],get_sbyname('Hxu',k),get_sbyname('full_vector_nu'))
    addf('vsub',nx,['rf0x' kstr],['dp' kstr],['rf0x' kstr])
    if k~=K
        addf('mtv',nx,nx,['fx' kstr],['dp' num2str(k+1)],['rf0x' kstr],get_sbyname('fx',k),get_sbyname('full_vector_nx'))
    end
    if n_c > 0
        addf('mtv',n_c,nx,['gx' kstr],['dy' kstr],['rf0x' kstr],get_sbyname('gx',k),get_sbyname('full_vector_nc',k))
    end
    
    %rf0u
    addc('rf0u')
    %addf('vadd',nu,['rf0u' kstr],['f0u' kstr],['rf0u' kstr])
    addf('mtv',nx,nu,['Hxu' kstr],['dx' kstr],['rf0u' kstr],get_sbyname('Hxu',k),get_sbyname('full_vector_nx'))
    addf('mv',nu,nu,['Huu' kstr],['du' kstr],['rf0u' kstr],get_sbyname('Huu',k),get_sbyname('full_vector_nu'))
    if k~=K
        addf('mtv',nx,nu,['fu' kstr],['dp' num2str(k+1)],['rf0u' kstr],get_sbyname('fu',k),get_sbyname('full_vector_nx'))
    end
    if n_c > 0
        addf('mtv',n_c,nu,['gu' kstr],['dy' kstr],['rf0u' kstr],get_sbyname('gu',k),get_sbyname('full_vector_nc',k))
    end
    
    %rf0s
    if n_s > 0
        addc('rf0s')
        %addf('vadd',n_s,['rf0s' kstr],['f0s' kstr],['rf0s' kstr])
        addf('mv',n_s,n_s,['Hss' kstr],['ds' kstr],['rf0s' kstr],get_sbyname('Hss',k),get_sbyname('full_vector_ns',k))
        addf('vsub',n_s,['rf0s' kstr],['dy' kstr '[0]'],['rf0s' kstr])
        addf('vsub',n_s,['rf0s' kstr],['dy' kstr '[' num2str(n_c) ']'],['rf0s' kstr])
    end
    
    %rf
    addc('rf')
    if k~=0
        %addf('vadd',nx,['rf' kstr],['f' num2str(k-1)],['rf' kstr])
        addf('mv',nx,nx,['fx' num2str(k-1)],['dx' num2str(k-1)],['rf' kstr],get_sbyname('fx',k),get_sbyname('full_vector_nx'))
        addf('mv',nx,nu,['fu' num2str(k-1)],['du' num2str(k-1)],['rf' kstr],get_sbyname('fu',k),get_sbyname('full_vector_nu'))
        addf('vsub',nx,['rf' kstr], ['dx' kstr],['rf' kstr])
    else
        %addf('vadd',nx,['rf' kstr],['xinit'],['rf' kstr])
        addf('vsub',nx,['rf' kstr], ['dx' kstr],['rf' kstr])
    end
    
    %rc
    if n_c > 0
        addc('rc')
        %addf('vadd',n_c,['rc' kstr],['g' kstr],['rc' kstr])
        addf('mv',n_c,nx,['gx' kstr],['dx' kstr],['rc' kstr],get_sbyname('gx',k),get_sbyname('full_vector_nx'))
        addf('mv',n_c,nu,['gu' kstr],['du' kstr],['rc' kstr],get_sbyname('gu',k),get_sbyname('full_vector_nu'))
        addf('vadd',n_c,['rc' kstr],['dnu' kstr],['rc' kstr])
        if n_s > 0
            addf('vsub',n_s,['rc' kstr],['ds' kstr],['rc' kstr])
        end
    end
    
    %rs
    if n_s > 0
        addc('rs')
        % rs = rs + dnu_ss - ds
        addf('vadd',n_s,['rs' kstr],['dnu' kstr '[' num2str(n_c) ']'],['rs' kstr])
        addf('vsub',n_s,['rs' kstr],['ds' kstr],['rs' kstr])
    end
    
    %rk
    if n_c > 0
        addc('rk')
        % rk = rk + dy.*nu + dnu.*y
        tmp = addt(n_c+n_s);
        addf('vv_elemult',n_c+n_s,['dy' kstr],['nu' kstr],tmp)
        addf('vadd',n_c+n_s,['rk' kstr],tmp,['rk' kstr])
        addf('vv_elemult',n_c+n_s,['dnu' kstr],['y' kstr],tmp)
        addf('vadd',n_c+n_s,['rk' kstr],tmp,['rk' kstr])
        subt(tmp);
    end
end

%Funktionsende
addl(['}'])

funstr = genstr;
%clipboard('copy', genstr);
genstr = [];
end

