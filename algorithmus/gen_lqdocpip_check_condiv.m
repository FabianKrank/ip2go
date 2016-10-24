function [ funstr ] = gen_lqdocpip_check_condiv()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

addc('#########################################################')
addc('Diese Funktion führt Konvergenz- und Divergenztests durch')
addc('#########################################################')
%Funktionskopf
addl(['static void ' prefix 'glqdocpip_check_condiv()' char(10) '{'])
tmp=addt(1);
tmp2=addt(1);

% termcode 0
addc('Termcode 0 - Success')
addl(['if(' prefix 'mu[0] <= ' prefix 'tol[0]){'])
addf('vv_elemult',1,'tol','norm_d',tmp)
addl(['  if(' prefix 'norm_r[0] <= ' prefix tmp '[0]){'])
addl(['  ' prefix 'termcode = 0;'])
addl('  return;')
addl('  }')
addl('}')

% termcode 1
addl('')
addc('Termcode 1 - infeasible')
addl(['if(' prefix 'phi[0] > ' prefix 'tol[0]){'])
addf('vv_elemult',1,'tc1_factor','minphi',tmp)
addl(['  if(' prefix 'phi[0] >= ' prefix tmp '[0]){'])
addl(['  ' prefix 'termcode = 1;'])
addl('  return;')
addl('  }')
addl('}')

% termcode 2
addl('')
addc('Termcode 2 - slow convergence')
addf('vv_elemult',1,'tol','norm_d',tmp)
addl(['if(' prefix 'norm_r[0] > ' prefix tmp '[0]){'])
addf('vv_elediv',1,'norm_r','mu',tmp)
addf('vv_elediv',1,'norm_r0','mu0',tmp2)
addf('vv_elemult',1,'tc2_factor',tmp2,tmp2)
addl(['  if(' prefix tmp '[0] >= ' prefix tmp2 '[0]){'])
addl(['  ' prefix 'termcode = 2;'])
addl('  return;')
addl('  }')
addl('}')

subt(tmp);
subt(tmp2);

% termcode 7
addl('')
addc('Termcode 7 - calculation time limit exceeded')
addl(['if(' prefix 'iter > 0){'])
addl(['  if(' prefix 'glqdocpip_timer_get()*(double)' prefix 'iter/ (double) (' prefix 'iter + 1) > ' prefix 'time_max){'])
addl(['    ' prefix 'termcode = 7;'])
addl('    return;')
addl('  }')
addl('}')



% iter_ref
addl('')
addc('iterative refinement')
addc('### FLAGS ###')
addc(['# keep_iterative_refinements_on = ' num2str(gendata.flags.keep_iterative_refinements_on)])
addc(['# iterative_refinements_require_norm_r_is_not_too_small = ' num2str(gendata.flags.iterative_refinements_require_norm_r_is_not_too_small)])
addc('#############')

% iter_ref mit 0 initialisieren, außer: Flag: keep_iterative_refinements_on
if gendata.flags.keep_iterative_refinements_on == 0
    addl([prefix 'iter_ref = 0;'])
end

tmp = addt(1);
tmpf = addt(1);

addl(['if(' prefix 'iter > 0){'])
% Bedingung 1: norm_r_prev > iter_ref_factor_1 * tol * norm_d
addl([prefix tmpf '[0] = ' num2str(gendata.parameter.iter_ref_factor_1) ';'])
addf('vv_elemult',1,tmpf,['tol'],tmp)
addf('vv_elemult',1,['norm_d'],tmp,tmp)
addl(['if(' prefix 'norm_r_prev[0] > ' prefix tmp '[0]){'])
% Bedingung 2: norm_r > iter_ref_factor_2 *norm_r_prev
addl([prefix tmpf '[0] = ' num2str(gendata.parameter.iter_ref_factor_2) ';'])
addf('vv_elemult',1,tmpf,['norm_r_prev'],tmp)
addl(['if(' prefix 'norm_r[0] > ' prefix tmp '[0]){'])

% Bedingung 3(optional): norm_r > iter_ref_factor_3*tol*norm_d
if gendata.flags.iterative_refinements_require_norm_r_is_not_too_small == 1
    addl([prefix tmpf '[0] = ' num2str(gendata.parameter.iter_ref_factor_3) ';'])
    addf('vv_elemult',1,tmpf,['tol'],tmp)
    addf('vv_elemult',1,['norm_d'],tmp,tmp)
    addl(['if(' prefix 'norm_r[0] > ' prefix tmp '[0]){'])
end

% iter_ref = 1
addl([prefix 'iter_ref = 1;'])

if gendata.flags.iterative_refinements_require_norm_r_is_not_too_small == 1
    addl('}')
end

addl('}')
addl('}')
addl('}')

subt(tmp);
subt(tmpf);
%addl(['mexPrintf("%d\n",' prefix 'iter_ref);'])
addl('')

%Funktionsende
addl('}')



funstr = genstr;
%clipboard('copy', genstr); 
genstr = [];
end

