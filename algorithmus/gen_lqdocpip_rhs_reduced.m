function [ funstr ] = gen_lqdocpip_rhs_reduced()
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
addl(['static void ' prefix 'glqdocpip_rhs_reduced()' char(10) '{'])
if gendata.mem_type==2
    addl('  int i1;');
end
% Fehlerquelle: REDUCED
addl([prefix 'error_source = 3;'])
 k=0;
 i1=1;
 while k<K+1
     [k,kstr]=additer(k,i1);
%for k=0:K
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    
    ncstr = num2str(n_c);
    nsstr = num2str(n_s);
    
    addc(['Zeitschritt ' num2str(k)])
    kstr = num2str(k);
    
    %rhsxs
    if n_s > 0
        addc('rhsxs')
        tmpstr1 = addt(n_s,1);
        tmpstr2 = addt(n_s,1);
        tmpstr3 = addt(n_s,1);
        
%         % rhsxs = rc-rs
%         addf('v_init0',n_s,['rhsxs' kstr])
%         addf('vsub',n_s,['rc' kstr],['rs' kstr],['rhsxs' kstr])
%         % tmpstr1 = rkss/yss
%         addf('vv_elediv',n_s,['rk' kstr '[' ncstr ']'],['y' kstr '[' ncstr ']'],tmpstr1)
%         % rhsxs = rc - rs + rkss/yss
%         addf('vadd',n_s,['rhsxs' kstr],tmpstr1,['rhsxs' kstr])
%         % tmpstr1 = rks/ys
%         addf('vv_elediv',n_s,['rk' kstr '[0]'],['y' kstr '[0]'],tmpstr1)
%         % rhsxs = rc - rs + rkss/yss - rks/ys
%         addf('vsub',n_s,['rhsxs' kstr],tmpstr1,['rhsxs' kstr])
%         % tmpstr2 = rs - rks/ys
%         addf('vsub',n_s,['rs' kstr],tmpstr1,tmpstr2)
%         % tmpstr1 = rf0s + Hss * (rs - rks/ys)
%         addf('v_copy',n_s,['rf0s' kstr],tmpstr1)
%         addf('mv',n_s,n_s,['Hss' kstr],tmpstr2,tmpstr1)
%         % tmpstr2 = ones(ns,1)
%         addf('v_init1',n_s,tmpstr2)
%         % tmpstr3 = Hss * ones(ns,1) --> Vektor
%         addf('v_init0',n_s,tmpstr3)
%         addf('mv',n_s,n_s,['Hss' kstr],tmpstr2,tmpstr3)
%         % tmpstr2 = ys/nus
%         addf('vv_elediv',n_s,['y' kstr '[0]'],['nu' kstr '[0]'],tmpstr2)
%         % tmpstr2 = Hss * ones(ns,1) + ys/nus
%         addf('vadd',n_s,tmpstr3,tmpstr2,tmpstr2)
%         % tmpstr1 = (rf0s + Hss * (rs - rks/ys))/(Hss * ones(ns,1) + ys/nus)
%         addf('vv_elediv',n_s,tmpstr1,tmpstr2,tmpstr1)
%         % rhsxs = rhsxs + tmpstr1
%         addf('vadd',n_s,['rhsxs' kstr],tmpstr1,['rhsxs' kstr])

        % rhsxs = rc-rs
        addf('v_init0',n_s,['rhsxs' kstr])
        addf('vsub',n_s,['rc' kstr],['rs' kstr],['rhsxs' kstr])
        % tmpstr1 = rks/ys
        addf('vv_elediv',n_s,['rk' kstr '[0]'],['y' kstr '[0]'],tmpstr1)
        % rhsxs = rc - rs - rks/ys
        addf('vsub',n_s,['rhsxs' kstr],tmpstr1,['rhsxs' kstr])
        % tmpstr1 = rkss/yss
        addf('vv_elediv',n_s,['rk' kstr '[' ncstr ']'],['y' kstr '[' ncstr ']'],tmpstr1)
        % rhsxs = rc - rs - rks/ys + rkss/yss
        addf('vadd',n_s,['rhsxs' kstr],tmpstr1,['rhsxs' kstr])      
        % tmpstr2 = rs - rkss/yss
        addf('v_init0',n_s,tmpstr2)
        addf('vsub',n_s,['rs' kstr],tmpstr1,tmpstr2)
        % tmpstr1 = rf0s + Hss * (rs - rkss/yss)
        addf('v_copy',n_s,['rf0s' kstr],tmpstr1)
        addf('mv',n_s,n_s,['Hss' kstr],tmpstr2,tmpstr1)
        % tmpstr2 = ones(ns,1)
        addf('v_init1',n_s,tmpstr2)
        % tmpstr3 = Hss * ones(ns,1) --> Vektor
        addf('v_init0',n_s,tmpstr3)
        addf('mv',n_s,n_s,['Hss' kstr],tmpstr2,tmpstr3)
        % tmpstr2 = yss/nuss
        addf('vv_elediv',n_s,['y' kstr '[' ncstr ']'],['nu' kstr '[' ncstr ']'],tmpstr2)
        % tmpstr2 = Hss * ones(ns,1) + ys/nus
        addf('vadd',n_s,tmpstr3,tmpstr2,tmpstr2)
        % tmpstr1 = (rf0s + Hss * (rs - rks/ys))/(Hss * ones(ns,1) + ys/nus)
        addf('vv_elediv',n_s,tmpstr1,tmpstr2,tmpstr1)
        % rhsxs = rhsxs + tmpstr1
        addf('vadd',n_s,['rhsxs' kstr],tmpstr1,['rhsxs' kstr])
        
        subt(tmpstr1);
        subt(tmpstr2);
        subt(tmpstr3);
    end
    
    %yny
    if n_c > 0
        addc('yny')
        
        %yny = zeros(nc,1)
        addf('v_init0',n_c,['yny' kstr])
        
        if n_s > 0
            % geschlupfter Anteil
            tmpstr1 = addt(n_s,1);
            tmpstr2 = addt(n_s,1);
            
            % tmpstr1 = ones(ns,1)
            addf('v_init1',n_s,tmpstr1)
            % tmpstr2 = zeros(ns,1)
            addf('v_init0',n_s,tmpstr2)
            % tmpstr2 = Hss * ones(ns,1) --> Vektor
            addf('mv',n_s,n_s,['Hss' kstr],tmpstr1,tmpstr2)
            % tmpstr1 = yss/nuss
            addf('vv_elediv',n_s,['y' kstr '[' ncstr ']'],['nu' kstr '[' ncstr ']'],tmpstr1)
            % tmpstr2 = Hss * ones(ns,1) + yss/nuss
            addf('vadd',n_s,tmpstr2,tmpstr1,tmpstr2)
            % tmpstr1 = ones(ns,1)
            addf('v_init1',n_s,tmpstr1)
            % tmpstr2 = ones(ns,1)/(Hss * ones(ns,1) + yss/nuss)
            addf('vv_elediv',n_s,tmpstr1,tmpstr2,tmpstr2)
            % tmpstr1 = nus/ys
            addf('vv_elediv',n_s,['nu' kstr '[0]'],['y' kstr '[0]'],tmpstr1)
            % tmpstr2 = nus/ys + ones(ns,1)/(Hss * ones(ns,1) + yss/nuss)
            addf('vadd',n_s,tmpstr1,tmpstr2,tmpstr2)
            % tmpstr1 = ones(ns,1)
            addf('v_init1',n_s,tmpstr1)
            % ynys = ones(ns,1)/(nus/ys + ones(ns,1)/(Hss * ones(ns,1) + yss/nuss))
            addf('vv_elediv',n_s,tmpstr1,tmpstr2,['yny' kstr '[0]'])
            
            subt(tmpstr1);
            subt(tmpstr2);
        end
        
        if (n_c-n_s)>0
            % ungeschlupfter Anteil
            % ynyu = yu/nuu
            addf('vv_elediv',n_c-n_s,['y' kstr '[' nsstr ']'],['nu' kstr '[' nsstr ']'],['yny' kstr '[' nsstr ']'])
        end
    end
    
    
    %v1 = yny.*[rhsxs; rcu - rku/yu]
    if n_c > 0
        addc('v1')
        tmpstr1 = addt(n_c,1);
        tmpstr2 = addt(n_c-n_s,1);
        
        % geschlupften Anteil berechnen
        addf('v_copy',n_s,['rhsxs' kstr],tmpstr1)
        %addf('vv_elemult',ns,['yny' kstr '[0]'],['rhsxs' kstr '[0]'],[tmpstr1 '[0]'])
        % ungeschlupften Anteil berechnen
        if (n_c - n_s) > 0
            addf('vv_elediv',n_c-n_s,['rk' kstr '[' nsstr ']'],['y' kstr '[' nsstr ']'],tmpstr2)
            % tmpstr1 = rcu - rku/yu
            addf('vsub',n_c-n_s,['rc' kstr '[' nsstr ']'],tmpstr2,[tmpstr1 '[' nsstr ']'])
        end
        % v1 = yny*tmpstr1
        addf('vv_elemult',n_c,['yny' kstr],tmpstr1,tmpstr1)
        
        subt(tmpstr2);
        
        % rrf0x = rf0x + gxT * v1
        % rrf0u = rf0u + guT * v1
        addc('rrf0x')
        addf('v_copy',nx,['rf0x' kstr],['rrf0x' kstr])
        addf('mtv',n_c,nx,['gx' kstr],tmpstr1,['rrf0x' kstr],get_sbyname('gx',k),get_sbyname('full_vector_nc',k))
        addc('rrf0u')
        addf('v_copy',nu,['rf0u' kstr],['rrf0u' kstr])
        addf('mtv',n_c,nu,['gu' kstr],tmpstr1,['rrf0u' kstr],get_sbyname('gu',k),get_sbyname('full_vector_nc',k))
        
        subt(tmpstr1);
    end
     k=additer_next(k,i1);
     i1=i1+1;
 end

% Fehlerquelle zurücksetzen
addl([prefix 'error_source = 0;'])

%Funktionsende
addl(['}'])

funstr = genstr;
%clipboard('copy', genstr);
genstr = [];
end

