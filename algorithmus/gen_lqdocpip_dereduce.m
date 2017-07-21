function [ funstr ] = gen_lqdocpip_dereduce()
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
addl(['static void ' prefix 'glqdocpip_dereduce()' char(10) '{'])
if gendata.mem_type==2
    addl('  int i1;');
end
% Fehlerquelle: DEREDUCE
addl([prefix 'error_source = 4;'])

 k=0;
 i1=1;
 while k<K+1
     [k,kstr]=additer(k,i1);
%for k=0:K
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    
    kstr = num2str(k);
    addc(['Zeitschritt ' kstr])
    
    
    
    if n_c > 0
        addc('dy')
        % Hilfsvektor
        addc('Hilfsvektor')
        tmp1 = addt(n_c,1);
        % sicherheitshalber mit 0 initialisieren
        addf('v_init0',n_c,tmp1)
        % tmp1 = [rhsxs;rc_u]
        addf('m_copy',n_s,1,['rhsxs' kstr],tmp1)
        if (n_c-n_s) > 0
            addf('m_copy',n_c-n_s,1,['rc' kstr '[' num2str(n_s) ']'],[tmp1 '[' num2str(n_s) ']'])
        end
        % tmp = tmp + gx*dx
        addf('mv',n_c,nx,['gx' kstr],['dx' kstr],tmp1,get_sbyname('gx',k),get_sbyname('full_vector_nx'))
        % tmp = tmp + gu*du
        addf('mv',n_c,nu,['gu' kstr],['du' kstr],tmp1,get_sbyname('gu',k),get_sbyname('full_vector_nu'))
        
        % dy_u
        if (n_c-n_s) > 0
            addc('dy_u')
            tmp5 = addt(n_c-n_s,1);
            % tmp5 = r4_u./y_u
            addf('vv_elediv',n_c-n_s,['rk' kstr '[' num2str(n_s) ']'],['y' kstr '[' num2str(n_s) ']'],tmp5)
            % tmp_u = tmp_u - tmp5
            addf('vsub',n_c-n_s,[tmp1 '[' num2str(n_s) ']'],tmp5,[tmp1 '[' num2str(n_s) ']'])
            subt(tmp5)
        end
        % dy[1:nc] = yny.*tmp1
        addf('vv_elemult',n_c,['yny' kstr],tmp1,['dy' kstr])

        subt(tmp1)        
        
        % dy_ss, Weitere Hilfsvektoren:
        % Zähler = tmp2
        % tmp2 = ones(ns,ns)
        if n_s > 0
            addc('dy_ss')
            tmp2 = addt(n_s,1);
            tmp3 = addt(n_s,1);
            tmp4 = addt(n_s,1);
            
            addf('v_init1',n_s,tmp2)
            % tmp3 = Hss*tmp2
            
            addf('v_init0',n_s,tmp3)
            addf('mv',n_s,n_s,['Hss' kstr],tmp2,tmp3)
            % tmp2 = r4ss./yss
            addf('vv_elediv',n_s,['rk' kstr '[' num2str(n_c) ']'],['y' kstr '[' num2str(n_c) ']'],tmp2)
            % tmp2 = rs - tmp2
            addf('vsub',n_s,['rs' kstr],tmp2,tmp2)
            % tmp2 = tmp3.*tmp2
            addf('vv_elemult',n_s,tmp3,tmp2,tmp2)
            % tmp2 = rf0s + tmp2
            addf('vadd',n_s,tmp2,['rf0s' kstr],tmp2);
            % tmp2 = tmp2 - dy_s
            addf('vsub',n_s,tmp2,['dy' kstr],tmp2)
            %Nenner tmp3
            % tmp4 = nu_ss./y_ss
            
            addf('v_init0',n_s,tmp4)
            % tmp4 = nu_ss./y_ss
            addf('vv_elediv',n_s,['nu' kstr '[' num2str(n_c) ']'],['y' kstr '[' num2str(n_c) ']'],tmp4)
            % tmp3 = tmp3.*tmp4
            addf('vv_elemult',n_s,tmp3,tmp4,tmp3)
            % tmp4 = ones
            addf('v_init1',n_s,tmp4)
            % tmp3 = tmp3+tmp4
            addf('vadd',n_s,tmp3,tmp4,tmp3)
            % dy_ss = tmp2./tmp3
            addf('vv_elediv',n_s,tmp2,tmp3,['dy' kstr '[' num2str(n_c) ']'])
            
            subt(tmp2)
            subt(tmp3)
            subt(tmp4)
        end
    end
    
    
    % dnu
    if n_c > 0
        % dnu = nu.*dy
        addc('dnu')
        addf('vv_elemult',n_c+n_s,['nu' kstr],['dy' kstr],['dnu' kstr])
        % dnu = dnu + r4
        addf('vadd',n_c+n_s,['dnu' kstr],['rk' kstr],['dnu' kstr])
        % dnu = dnu./y
        addf('vv_elediv',n_c+n_s,['dnu' kstr],['y' kstr],['dnu' kstr])
        % dnu = -dnu
        addf('v_turnsign',n_c+n_s,['dnu' kstr],['dnu' kstr])
    end
    
    if n_s > 0
        % ds = rs + dnu_ss
        addc('ds')
        addf('v_init0',n_s,['ds' kstr])
        addf('vadd',n_s,['rs' kstr],['dnu' kstr '[' num2str(n_c) ']'],['ds' kstr])
    end
    
    
    
     k=additer_next(k,i1);
     i1=i1+1;
end

% Fehlerquelle zurücksetzen
addl([prefix 'error_source = 0;'])

%Funktionsende
addl([char(10) '}'])

funstr = genstr;
genstr = [];
end

