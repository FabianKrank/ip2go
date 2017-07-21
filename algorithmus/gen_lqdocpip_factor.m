function [ funstr ] = gen_lqdocpip_factor()
%GEN_BLOCKELE Summary of this function goes here
%   Detailed explanation goes here
%  annika.mayer@isys.uni-stuttgart.de 01.12.16
%  mm_y statt mm an zwei Stellen ergänzt, (mm_y ist Matrix-Matrix-Multiplikation die
%  symmetrische Matrix ausgibt)
% Guu = Guu + fu'*Vxx(k+1)*fu
% Guu = Guu + gu'*diag(yny)*gu
global gendata
global genstr

prefix = gendata.prefix;

genstr = [];

K  = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;

%Funktionskopf
addl(['static void ' prefix 'glqdocpip_factor()' char(10) '{'])
if gendata.mem_type==2
    addl('  int i1;');
end
% Fehlerquelle: FACTOR
addl([prefix 'error_source = 1;'])
% Statistik
addl([prefix 'stat_num_factor++;'])

%Rückwärtsiteration
addc('Factor: Rückwärtsiteration')

%Zeitschritte K bis 0
%for k=K:-1:0
k=K;
i1=length(gendata.iter);
while k>=0
    [k,kstr]=additer(k,i1,1);
    kstr = num2str(k);
    n_c = gendata.dim.n_c(k+1);
    addc(['Zeitschritt ' kstr])
    
    % Gxx und Gxu
    addc('Gxx und Gxu')
    addf('m_copy',nx,nx,['Hxx' kstr],['Gxx' kstr])
    addf('m_copy',nx,nu,['Hxu' kstr],['Gxu' kstr])
    
    % Gxx = Gxx + fx'*Vxx(k+1)*fx
    % Gxu = Gxu + fx'*Vxx(k+1)*fu
    tmpstr = addt(nx,nx);
    % Im K-ten Zeitschritt Terme mit Vxx(k+1) weglassen
    if k ~= K
        addf('m_init0',nx,nx,tmpstr)
        addf('mtm',nx,nx,nx,['fx' kstr],['Vxx' num2str(k+1)],tmpstr,get_sbyname('fx',k),get_sbyname('full_matrix_nx_nx'))
        % Gxx
%         addf('mm',nx,nx,nx,tmpstr,['fx' kstr],['Gxx' kstr],get_sbyname('full_matrix_nx_nx'),get_sbyname('fx',k))
        addf('mm_y',nx,nx,nx,tmpstr,['fx' kstr],['Gxx' kstr],get_sbyname('full_matrix_nx_nx'),get_sbyname('fx',k))
        % Gxu
        addf('mm',nx,nx,nu,tmpstr,['fu' kstr],['Gxu' kstr],get_sbyname('full_matrix_nx_nx'),get_sbyname('fu',k))
    end
    subt(tmpstr);
    
    % Gxx = Gxx + gx'*diag(yny)*gx
    % Gxu = Gxu + gx'*diag(yny)*gu
    if n_c > 0
        tmpstr = addt(nx,n_c);
        addf('m_init0',nx,n_c,tmpstr)
        addf('mtd',n_c,nx,['gx' kstr],['yny' kstr],tmpstr,get_sbyname('gx',k),get_sbyname('full_vector_nc',k))
        % Gxx
%         addf('mm',nx,n_c,nx,tmpstr,['gx' kstr],['Gxx' kstr],get_sbyname(['full_matrix_nx_nc'],k),get_sbyname('gx',k))
        addf('mm_y',nx,n_c,nx,tmpstr,['gx' kstr],['Gxx' kstr],get_sbyname(['full_matrix_nx_nc'],k),get_sbyname('gx',k))
        % Gxu
        addf('mm',nx,n_c,nu,tmpstr,['gu' kstr],['Gxu' kstr],get_sbyname(['full_matrix_nx_nc'],k),get_sbyname('gu',k))        
        subt(tmpstr);
    end
    % Guu
    addc('Guu')
    addf('m_copy',nu,nu,['Huu' kstr],['Guu' kstr])
    % Guu = Guu + fu'*Vxx(k+1)*fu
    tmpstr = addt(nu,nx);
    % Im K-ten Zeitschritt Terme mit Vxx(k+1) weglassen
    if k ~= K
        addf('m_init0',nu,nx,tmpstr)
        addf('mtm',nx,nu,nx,['fu' kstr],['Vxx' num2str(k+1)],tmpstr,get_sbyname('fu',k),get_sbyname('full_matrix_nx_nx'))
        % mm_y statt mm #AM
        addf('mm_y',nu,nx,nu,tmpstr,['fu' kstr],['Guu' kstr],get_sbyname('full_matrix_nu_nx'),get_sbyname('fu',k))
    end
    subt(tmpstr);
    
    % Guu = Guu + gu'*diag(yny)*gu
    if n_c > 0
        tmpstr = addt(nu,n_c);
        addf('m_init0',nu,n_c,tmpstr)
        addf('mtd',n_c,nu,['gu' kstr],['yny' kstr],tmpstr,get_sbyname('gu',k),get_sbyname('full_vector_nc',k))
        % mm_y statt mm #AM
        addf('mm_y',nu,n_c,nu,tmpstr,['gu' kstr],['Guu' kstr])
        subt(tmpstr);
    end
%     %Guu=0.5*(Guu+Guu^T)
%     if nu>1 && isfield(gendata,'msym') && msym==1
%         addf('msym',nu,['Guu' kstr],['Guu' kstr])
%     end
    % Rux = Guu^-1 * GxuT
    % Guu * Rux = GxuT     nach Rux lösen
    addc('Rux')
    tmpstr = addt(nu,nx);
    addf('mtr',nx,nu,['Gxu' kstr],tmpstr)
    addf('chol_factor',nu,['Guu' kstr],['L' kstr])
    addf('chol_solve',nu,nx,['L' kstr],tmpstr,['Rux' kstr])
    subt(tmpstr);
    
    addf('m_init0',nx,nx,['Vxx' kstr])
    addf('mm_y',nx,nu,nx,['Gxu' kstr],['Rux' kstr],['Vxx' kstr])
    addf('msub',nx,nx,['Gxx' kstr],['Vxx' kstr],['Vxx' kstr])
    k=additer_next(k,i1,1);
    i1=i1-1;
end

% Fehlerquelle zurücksetzen
addl([prefix 'error_source = 0;'])

%Funktionsende
addl([char(10) '}'])

funstr = genstr;
genstr = [];
end

