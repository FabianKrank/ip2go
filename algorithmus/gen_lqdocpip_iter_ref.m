function [ funstr ] = gen_lqdocpip_iter_ref()
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
addc('######################################################')
addc('Diese Funktion berechnet führt die Nachiteration durch')
addc('######################################################')
addl(['static void ' prefix 'glqdocpip_iter_ref()' char(10) '{'])

% Iter_ref Bedingung?
addl(['if(' prefix 'iter_ref == 1){'])

% Eintrag in Statistik
% Gesamtanzahl erhöhen
addl([prefix 'stat_num_iter_ref++;'])
% Eintrag bei Iterarion
addl([prefix 'stat_iter_ref[' prefix 'iter] = 1;'])

addc('Lösung sichern')
for k=0:K
    kstr = num2str(k);
    n_s = gendata.dim.n_s(k+1);
    n_c = gendata.dim.n_c(k+1);
    addf('v_copy',nx,['dx' kstr],['dx_ir' kstr])
    addf('v_copy',nu,['du' kstr],['du_ir' kstr])
    if n_s > 0
        addf('v_copy',n_s,['ds' kstr],['ds_ir' kstr])
    end
    addf('v_copy',nx,['dp' kstr],['dp_ir' kstr])
    addf('v_copy',n_c+n_s,['dy' kstr],['dy_ir' kstr])
    addf('v_copy',n_c+n_s,['dnu' kstr],['dnu_ir' kstr])
end

addc('rhs sichern')
for k=0:K
    kstr = num2str(k);
    n_s = gendata.dim.n_s(k+1);
    n_c = gendata.dim.n_c(k+1);
    addf('v_copy',nx,['rf0x' kstr],['rf0x_ir' kstr])
    addf('v_copy',nu,['rf0u' kstr],['rf0u_ir' kstr])
    if n_s > 0
        addf('v_copy',n_s,['rf0s' kstr],['rf0s_ir' kstr])
    end
    addf('v_copy',nx,['rf' kstr],['rf_ir' kstr])
    addf('v_copy',n_c+n_s,['rc' kstr],['rc_ir' kstr])
    addf('v_copy',n_s,['rs' kstr],['rs_ir' kstr])
    addf('v_copy',n_c+n_s,['rk' kstr],['rk_ir' kstr])
end

addc('Residuum berechnen')
addl([prefix 'glqdocpip_rhs_iter_ref();'])
addl(['if(' prefix 'termcode > -1){return;}'])
addl([prefix 'glqdocpip_rhs_reduced();'])
addl(['if(' prefix 'termcode > -1){return;}'])

addc('GLS mit Residuum als rechte Seite lösen')
addl([prefix 'glqdocpip_solve();'])
addl(['if(' prefix 'termcode > -1){return;}'])
addl([prefix 'glqdocpip_dereduce();'])
addl(['if(' prefix 'termcode > -1){return;}'])

addc('Lösung aktualisieren')
for k=0:K
    kstr = num2str(k);
    n_s = gendata.dim.n_s(k+1);
    n_c = gendata.dim.n_c(k+1);
    addf('vadd',nx,['dx_ir' kstr],['dx' kstr],['dx' kstr])
    addf('vadd',nu,['du_ir' kstr],['du' kstr],['du' kstr])
    if n_s > 0
        addf('vadd',n_s,['ds_ir' kstr],['ds' kstr],['ds' kstr])
    end
    addf('vadd',nx,['dp_ir' kstr],['dp' kstr],['dp' kstr])
    addf('vadd',n_c+n_s,['dy_ir' kstr],['dy' kstr],['dy' kstr])
    addf('vadd',n_c+n_s,['dnu_ir' kstr],['dnu' kstr],['dnu' kstr])
end
  
addc('rhs wiederherstellen')
for k=0:K
    kstr = num2str(k);
    n_s = gendata.dim.n_s(k+1);
    n_c = gendata.dim.n_c(k+1);
    addf('v_copy',nx,['rf0x_ir' kstr],['rf0x' kstr])
    addf('v_copy',nu,['rf0u_ir' kstr],['rf0u' kstr])
    if n_s > 0
        addf('v_copy',n_s,['rf0s_ir' kstr],['rf0s' kstr])
    end
    addf('v_copy',nx,['rf_ir' kstr],['rf' kstr])
    addf('v_copy',n_c+n_s,['rc_ir' kstr],['rc' kstr])
    addf('v_copy',n_s,['rs_ir' kstr],['rs' kstr])
    addf('v_copy',n_c+n_s,['rk_ir' kstr],['rk' kstr])
end

% Ende iter_ref Bedingung
addl('}')

%Funktionsende
addl(['}'])

funstr = genstr;

genstr = [];
end

