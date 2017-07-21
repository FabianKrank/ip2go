function [ funstr ] = gen_lqdocpip_solve()
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
addl(['static void ' prefix 'glqdocpip_solve()' char(10) '{'])
if gendata.mem_type==2
    addl('  int i1;');
end
% Fehlerquelle: SOLVE
addl([prefix 'error_source = 2;'])
% Statistik
addl([prefix 'stat_num_solve++;'])

%Rückwärtsiteration
addc('Solve: Rückwärtsiteration')

% Zeitschritte K bis 0
%for k=K:-1:0
k=K;
i1=length(gendata.iter);
while k>=0
    [k,kstr]=additer(k,i1,1);
    kstr = num2str(k);
    addc(['Zeitschritt ' kstr])
    
    %Gx = rrf0x + fx*[Vx(k+1) + Vxx(k+1) * rf(k+1)]
    %Gu = rrf0u + fu*[Vx(k+1) + Vxx(k+1) * rf(k+1)]    
    addc('Gx und Gu')
    addf('v_copy',nx,['rrf0x' kstr],['Gx' kstr])
    addf('v_copy',nu,['rrf0u' kstr],['Gu' kstr])
    tmpstr = addt(nx);
    if k~=K
        addf('v_copy',nx,['Vx' num2str(k+1)],tmpstr)
        addf('mv',nx,nx,['Vxx' num2str(k+1)],['rf' num2str(k+1)],tmpstr)
        % Gx
        addf('mtv',nx,nx,['fx' kstr],tmpstr,['Gx' kstr],get_sbyname('fx',k),get_sbyname('full_vector_nx'))
        % Gu
        addf('mtv',nx,nu,['fu' kstr],tmpstr,['Gu' kstr],get_sbyname('fu',k),get_sbyname('full_vector_nx'))
    end
    subt(tmpstr);
    %Ru = Guu^-1 * Gu
    addc('Ru')
    addf('chol_solve',nu,1,['L' kstr],['Gu' kstr],['Ru' kstr])
    
    %Vx  = Gx - Gxu * Ru
    addc('Vx')
    addf('v_init0',nx,tmpstr)
    tmpstr = addt(nx);
    addf('v_init0',nx,tmpstr)
    addf('mv',nx,nu,['Gxu' kstr],['Ru' kstr],tmpstr)
    addf('vsub',nx,['Gx' kstr],tmpstr,['Vx' kstr])
    subt(tmpstr);
    k=additer_next(k,i1,1);
    i1=i1-1;
end

% Vorwärtsiteration
addc('Solve: Vorwärtsiteration')
addc('dx0')
addf('v_copy',nx,['rf0'],['dx0'])
k=0;
i1=1;
while k<K+1
    [k,kstr]=additer(k,i1);
%for k=0:K
    kstr = num2str(k);
    addc(['Zeitschritt ' kstr])
    
    %dp
    addc('dp')
    addf('v_copy',nx,['Vx' kstr],['dp' kstr])
    addf('mv',nx,nx,['Vxx' kstr],['dx' kstr],['dp' kstr])

    %du
    addc('du')
    addf('v_copy',nu,['Ru' kstr],['du' kstr])
    addf('mv',nu,nx,['Rux' kstr],['dx' kstr],['du' kstr])
    addf('v_turnsign',nu,['du' kstr],['du' kstr])

    %dx  
    addc('dx')
    if k~=K
        addf('v_copy',nx,['rf' num2str(k+1)],['dx' num2str(k+1)])
        addf('mv',nx,nx,['fx' kstr],['dx' kstr],['dx' num2str(k+1)],get_sbyname('fx',k),get_sbyname('full_vector_nx'))
        addf('mv',nx,nu,['fu' kstr],['du' kstr],['dx' num2str(k+1)],get_sbyname('fu',k),get_sbyname('full_vector_nu'))
    end
    k=additer_next(k,i1);
    i1=i1+1;
end


% Fehlerquelle zurücksetzen
addl([prefix 'error_source = 0;'])

%Funktionsende
addl([char(10) '}'])

funstr = genstr;
%clipboard('copy',funstr);
genstr = [];
end

