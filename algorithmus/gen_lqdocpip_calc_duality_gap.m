function [ funstr ] = gen_lqdocpip_calc_duality_gap()
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
addc('###########################################')
addc('Diese Funktion berechnet die Dualitätslücke')
addc('###########################################')
addl(['static void ' prefix 'glqdocpip_calc_duality_gap()' char(10) '{'])
if gendata.mem_type==2
    addl('  int i1;');
end
% Init
addf('v_init0',1,'dgap')

tmpx = addt(nx,1);
tmpu = addt(nu,1);
tmp  = addt(1,1);

% Schleife über alle Zeitschritt
k=0;
i1=1;
while k<K+1
    [k,kstr]=additer(k,i1);
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    
    kstr = num2str(k);
    addc(['Zeitschritt ' kstr])
    % Quadratischer Anteil
    addc('Quadratischer Anteil')
    % dgap = dgap + x'*Hxx*x
    addf('v_init0',nx,tmpx)
    addf('mv',nx,nx,['Hxx' kstr],['x' kstr],tmpx,get_sbyname('Hxx',k),get_sbyname('full_vector_nx'))
    addf('vtv',nx,['x' kstr],tmpx,'dgap')
    % dgap = dgap + 2*(x'*Hxu*u)
    addf('v_init0',nx,tmpx)
    addf('mv',nx,nu,['Hxu' kstr],['u' kstr],tmpx,get_sbyname('Hxu',k),get_sbyname('full_vector_nu'))
    addf('vtv',nx,['x' kstr],tmpx,'dgap')
    addf('vtv',nx,['x' kstr],tmpx,'dgap')
    %dgap = dgap + u'*Huu*u
    addf('v_init0',nu,tmpu)
    addf('mv',nu,nu,['Huu' kstr],['u' kstr],tmpu,get_sbyname('Huu',k),get_sbyname('full_vector_nu'))
    addf('vtv',nu,['u' kstr],tmpu,'dgap')
    % dgap = dgap + s'*Hss*s
    if n_s > 0
        tmps = addt(n_s,1);
        addf('v_init0',n_s,tmps)
        addf('mv',n_s,n_s,['Hss' kstr],['s' kstr],tmps)
        addf('vtv',n_s,['s' kstr],tmps,'dgap')
        subt(tmps);
    end
    
    % Linearer Anteil
    addc('Linearer Anteil')
    % dgap = dgap + f0x'*x
    addf('vtv',nx,['f0x' kstr],['x' kstr],'dgap')
    % dgap = dgap + f0u'*u
    addf('vtv',nu,['f0u' kstr],['u' kstr],'dgap')
    if n_s > 0
        tmps = addt(n_s,1);
        % dgap = dgap + f0s'*s
        addf('vtv',n_s,['f0s' kstr],['s' kstr],'dgap')
        subt(tmps);
    end
    
    % Anteil durch Gleichungsnebenbedingungen
    addc('Anteil durch Gleichungsnebenbedingungen')
    % dgap = dgap - f[k-1]'p
    addf('v_init0',1, tmp)
    if k == 0
        addf('vtv',nx,['xinit'],['p' kstr],tmp)
        addf('vsub',1,'dgap',tmp,'dgap')
    else
        addf('vtv',nx,['f' num2str(k-1)],['p' kstr],tmp)
        addf('vsub',1,'dgap',tmp,'dgap')
    end
    
    % Anteil durch Ungleichungsnebenbedingungen
    if n_c > 0
        addc('Anteil durch Ungleichungsnebenbedingungen')
        % dgap = dgap + g'y
        addf('v_init0',1, tmp)
        addf('vtv',n_c,['g' kstr],['y' kstr],tmp)
        addf('vsub',1,'dgap',tmp,'dgap')
    end
    k=additer_next(k,i1);
    i1=i1+1;
end

subt(tmpx)
subt(tmpu)
subt(tmp)

% gap = |gap|
addc('dgap = abs(dgap)')
addl(['if(' prefix 'dgap[0] < 0){'])
addl([prefix 'dgap[0] = -' prefix 'dgap[0];}'])

%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

