function [ funstr ] = gen_lqdocpip_max_stepsize()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

K  = gendata.dim.K;

% Funktionskopf
addc('###########################################################')
addc('Diese Funktion berechnet die maximal mögliche Schrittweite,')
addc('bei der y und nu noch positiv bleiben')
addc('###########################################################')
addl(['static void ' prefix 'glqdocpip_max_stepsize()' char(10) '{'])
addl('int i;')
if gendata.mem_type==2
    addl('  int i1;');
end
addl('')
% alpha_max und alpha_tmp initialisieren
if strcmp(gendata.prec,'float')
    addl([prefix 'alpha_max[0] = -FLT_MAX;'])
elseif strcmp(gendata.prec,'double')
    addl([prefix 'alpha_max[0] = -DBL_MAX;'])
else
    error('Fehler in gen_lqdocpip_max_stepsize: Ungültiger Datentyp')
end

addl([prefix 'alpha_tmp[0] = 0;'])
addl('')
%for k=0:K
 %Schleife über alle Zeitschritte
 k=0;
 i1=1;
 while k<K+1
     [k,kstr]=additer(k,i1);
    n_c = gendata.dim.n_c(k+1);
    n_s = gendata.dim.n_s(k+1);
    addc(['Zeitschritt ' num2str(k)])
    if n_c > 0
        kstr = num2str(k);
        % alphamax berechnen, sodass y+alpha_max*dy >= 0 (selbes gilt für nu)
        % Schleife über alle Elemente
        addl(['for(i=0;i<' num2str(n_c+n_s) ';i++)'])
        addl('{')
        addc('dy-check')
        addl(['if( ' prefix assign_mem(['dy' kstr '[i]']) '< 0)'])
        addl('{')
        addf('vv_elediv', 1, ['y' kstr '[i]'], ['dy' kstr '[i]'], 'alpha_tmp')
        addl(['if( ' prefix 'alpha_tmp[0] > ' prefix 'alpha_max[0] )'])
        addl('{')
        addl([prefix 'alpha_max[0] = ' prefix 'alpha_tmp[0];'])
        % Zugehörige Veriablen abspeichern
        addf('v_copy',1,['y' kstr '[i]'],'alpha_min_y[0]')
        addf('v_copy',1,['dy' kstr '[i]'],'alpha_min_dy[0]')
        addf('v_copy',1,['nu' kstr '[i]'],'alpha_min_nu[0]')
        addf('v_copy',1,['dnu' kstr '[i]'],'alpha_min_dnu[0]')
        addl([prefix 'alpha_min_source_y = 1;'])
        addl('}')
        addl('}')
        addc('dnu-check')
        addl(['if( ', prefix, assign_mem(['dnu' kstr '[i]']), ' < 0)'])
        addl('{')
        addf('vv_elediv', 1, ['nu' kstr '[i]'], ['dnu' kstr '[i]'], 'alpha_tmp')
        addl(['if( *' prefix 'alpha_tmp > ' prefix 'alpha_max[0] )'])
        addl('{')
        addl([prefix 'alpha_max[0] = ' prefix 'alpha_tmp[0];'])
        % Zugehörige Veriablen abspeichern
        addf('v_copy',1,['y' kstr '[i]'],'alpha_min_y[0]')
        addf('v_copy',1,['dy' kstr '[i]'],'alpha_min_dy[0]')
        addf('v_copy',1,['nu' kstr '[i]'],'alpha_min_nu[0]')
        addf('v_copy',1,['dnu' kstr '[i]'],'alpha_min_dnu[0]')
        addl([prefix 'alpha_min_source_y = 0;'])
        addl('}')
        addl('}')
        addl('}')
    end
     k=additer_next(k,i1);
    i1=i1+1;

end
addl('')
addf('v_turnsign', 1, 'alpha_max[0]', 'alpha_max[0]')
%addc('TODO: Check, if alpha_max = -FLT_MAX')

%addp('alpha_max','a_max: ')
%Funktionsende
addl(['}'])

funstr = genstr;
%clipboard('copy', genstr);
genstr = [];
end

