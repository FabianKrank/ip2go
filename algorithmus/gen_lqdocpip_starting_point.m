function [ funstr ] = gen_lqdocpip_starting_point()
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
addc('#######################################')
addc('Diese Funktion berechnet den Startpunkt')
addc(['          Startpunktmethode: ' num2str(gendata.starting_point_method) '         '])
addc('#######################################')
addl(['static void ' prefix 'glqdocpip_starting_point()' char(10) '{'])
if gendata.mem_type==2
    addl('  int i1;');
end
% Pre Init
addc('Very Cold Start')
k=0;
i1=1;
while k<K+1
    [k,kstr]=additer(k,i1);
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    kstr = num2str(k);
    addc(['Zeitschritt ' kstr])
    addf('v_init0',nx,['x' kstr])
    addf('v_init0',nu,['u' kstr])
    if n_s > 0
        addf('v_init0',n_s,['s' kstr])
        for i=0:(n_s-1)
            addf('max',['s' kstr '[' num2str(i) ']'],['g' kstr '[' num2str(i) ']'],['s' kstr '[' num2str(i) ']'])
        end
    end
    addf('v_init0',nx,['p' kstr])
    if n_c > 0
        addf('v_init1',n_c+n_s,['y' kstr])
        addf('v_init1',n_c+n_s,['nu' kstr])
    end
    k=additer_next(k,i1);
    i1=i1+1;
end

if gendata.starting_point_method == 0
    %% Methode 0: Very Cold Start
    % Schon fertig
elseif gendata.starting_point_method == 5
    %% Methode 5
    addc('Methode 5')
    addc('Calc one step')
    addl([prefix 'glqdocpip_rhs_starting_point_5();'])
    addl(['if(' prefix 'termcode > -1){return;}'])
    addl([prefix 'glqdocpip_rhs_reduced();'])
    addl(['if(' prefix 'termcode > -1){return;}'])
    addl([prefix 'glqdocpip_factor();'])
    addl(['if(' prefix 'termcode > -1){return;}'])
    addl([prefix 'glqdocpip_solve();'])
    addl(['if(' prefix 'termcode > -1){return;}'])
    addl([prefix 'glqdocpip_dereduce();'])
    addl(['if(' prefix 'termcode > -1){return;}'])
    
 k=0;
i1=1;
while k<K+1
    [k,kstr]=additer(k,i1);
        kstr = num2str(k);
        n_s = gendata.dim.n_s(k+1);
        n_c = gendata.dim.n_c(k+1);
        % Copy d* -> *
        addf('v_copy',nx,['dx' kstr],['x' kstr])
        addf('v_copy',nu,['du' kstr],['u' kstr])
        if n_s > 0
            % s[k,i] = max(ds[k,i],max(g[k,i],0))
            addf('v_copy',n_s,['ds' kstr],['s' kstr])
            tmp0 = addt(1);
            for i=0:(n_s-1)
                addf('v_init0',1,tmp0)
                addf('max',['g' kstr '[' num2str(i) ']'],tmp0,tmp0)
                addf('max',['s' kstr '[' num2str(i) ']'],tmp0,['s' kstr '[' num2str(i) ']'])
            end
            subt(tmp0);
        end
        addf('v_copy',nx, ['dp' kstr], ['p' kstr])
        % dy = dy + y, dnu = dnu + nu
        if n_c > 0
            addf('vadd',n_c+n_s,['y' kstr], ['dy' kstr], ['dy' kstr])
            addf('vadd',n_c+n_s,['nu' kstr],['dnu' kstr],['dnu' kstr])
        end
    k=additer_next(k,i1);
    i1=i1+1;
end
    
    addc('Init delta_y and delta_nu')
    addf('v_init0',1,'starting_point_delta_y')
    addf('v_init0',1,'starting_point_delta_nu')
    % delta_* = max(-1.5*min(d*),delta_*)
    tmp_m15 = addt(1);
    tmpmax = addt(1);
    addl([prefix tmp_m15 '[0] = -1.5;'])
    %for k = 0:K
    
 k=0;
i1=1;
while k<K+1
    [k,kstr]=additer(k,i1);    
        kstr = num2str(k);
        n_s = gendata.dim.n_s(k+1);
        n_c = gendata.dim.n_c(k+1);
        if n_c > 0
            %dy
            addl([prefix tmpmax '[0] = ' gendata.prec_max ';'])
            addf('v_min',n_s+n_c,['dy' kstr],tmpmax,tmpmax)
            addf('vv_elemult',1,tmpmax,tmp_m15,tmpmax)
            addf('max',tmpmax,'starting_point_delta_y','starting_point_delta_y')
            %dnu
            addl([prefix tmpmax '[0] = ' gendata.prec_max ';'])
            addf('v_min',n_s+n_c,['dnu' kstr],tmpmax,tmpmax)
            addf('vv_elemult',1,tmpmax,tmp_m15,tmpmax)
            addf('max',tmpmax,'starting_point_delta_nu','starting_point_delta_nu')
        end
    k=additer_next(k,i1);
    i1=i1+1;
end
    subt(tmp_m15);
    subt(tmpmax);

    
    % Sums
    addf('v_init0',1,'starting_point_sum')
    addf('v_init0',1,'starting_point_sum_y')
    addf('v_init0',1,'starting_point_sum_nu')
k=0;
i1=1;
while k<K+1
    [k,kstr]=additer(k,i1);
        kstr = num2str(k);
        n_s = gendata.dim.n_s(k+1);
        n_c = gendata.dim.n_c(k+1);
        if n_c > 0
            tmp_y  = addt(n_c+n_s);
            tmp_y2  = addt(n_c+n_s);
            tmp_nu = addt(n_c+n_s);
            tmp_nu2 = addt(n_c+n_s);
            % tmp_y  = ones(n_c+n_s,1)*delta_y  + dy
            % tmp_nu = ones(n_c+n_s,1)*delta_nu + dnu
            % sum = sum + tmp1'*tmp2
            % sum_y  = sum_y + v_sum(tmp_y)
            % sum_nu = sum_y + v_sum(tmp_nu)
            addf('v_init1',n_c+n_s,tmp_y)
            addf('v_copy',n_c+n_s,['dy' kstr],tmp_y2)
            addf('sv',n_c+n_s,'starting_point_delta_y',tmp_y,tmp_y2)
            
            addf('v_init1',n_c+n_s,tmp_nu)
            addf('v_copy',n_c+n_s,['dnu' kstr],tmp_nu2)
            addf('sv',n_c+n_s,'starting_point_delta_nu',tmp_nu,tmp_nu2)
            
            addf('vtv',n_c+n_s,tmp_y2,tmp_nu2,'starting_point_sum')
            addf('vsum',n_c+n_s,tmp_y2,'starting_point_sum_y')
            addf('vsum',n_c+n_s,tmp_nu2,'starting_point_sum_nu')
            
            subt(tmp_y);
            subt(tmp_y2);
            subt(tmp_nu);
            subt(tmp_nu2);
        end
    k=additer_next(k,i1);
    i1=i1+1;
    end
    
    % ACHTUNG: y und nu umgekehrt!!
    % delta_y += 0.5*sum/sum_nu
    % delta_nu += 0.5*sum/sum_y
    
    tmp = addt(1);
    tmp05 = addt(1);
    addl([prefix tmp05 '[0] = 0.5;'])
    addf('vv_elediv',1,'starting_point_sum','starting_point_sum_nu',tmp)
    addf('vv_elemult',1,tmp05,tmp,tmp)
    addf('vadd',1,'starting_point_delta_y',tmp,'starting_point_delta_y')
    addf('vv_elediv',1,'starting_point_sum','starting_point_sum_y',tmp)
    addf('vv_elemult',1,tmp05,tmp,tmp)
    addf('vadd',1,'starting_point_delta_nu',tmp,'starting_point_delta_nu')
    subt(tmp05);
    subt(tmp);  
    
    % y und nu bestimmen
k=0;
i1=1;
while k<K+1
    [k,kstr]=additer(k,i1);
        n_s = gendata.dim.n_s(k+1);
        n_c = gendata.dim.n_c(k+1);
        kstr = num2str(k);
        if n_c > 0
            tmp = addt(n_c+n_s);
            tmp2 = addt(n_c+n_s);
            
            addf('v_init1',n_c+n_s,tmp)
            addf('v_init0',n_c+n_s,tmp2)
            addf('sv',n_c+n_s,'starting_point_delta_y',tmp,tmp2)
            addf('vadd',n_c+n_s,['dy' kstr],tmp2,['y' kstr])
            
            addf('v_init1',n_c+n_s,tmp)
            addf('v_init0',n_c+n_s,tmp2)
            addf('sv',n_c+n_s,'starting_point_delta_nu',tmp,tmp2)
            addf('vadd',n_c+n_s,['dnu' kstr],tmp2,['nu' kstr])
            
            subt(tmp);
            subt(tmp2);
        end
         k=additer_next(k,i1);
    i1=i1+1;
    end
    
    %addp('starting_point_delta_y')
    %addp('starting_point_delta_nu') 
    
else
    error('Ungültige Startpunktmethodennummer')
end


%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

