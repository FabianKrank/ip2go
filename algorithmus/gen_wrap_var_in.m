function funstr = gen_wrap_var_in(vars)
%Diese Funktion generiert die Variablendeklarationen
global gendata
global genstr

K = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;


genstr = [];

genstr = 'void matlab2c(mxArray *mstruct)';
addl('{')
addl('int j;')
addl('mxArray *mxlvl1, *mxlvl2;')
addl([gendata.prec_in ' *diptr;'])
addl([gendata.prec '*dptr;'])
addl('')

addc('Anfangsbedingung')
addl('mxlvl1 = mxGetField(mstruct,0,"xinit");')
addl(['dptr = ' gendata.prefix 'get_x0();'])
addl('diptr = mxGetPr(mxlvl1);')
addl(['for(j=0; j<' num2str(nx) '; j++)'])
addl('{')
addl(['dptr[j] = (' gendata.prec ')diptr [j];'])
addl('}')

for i=1:length(vars)
    addc(['copy ' vars{i}.name])
    addl(['mxlvl1 = mxGetField(mstruct,0,"' vars{i}.name '");'])
    %addl(['for (i=0;i<=' num2str(K) ';i++){']);
    for k=0:K
        if length(vars{i}.dim1) > 1
            dim1 = vars{i}.dim1(k+1);
        else
            dim1 = vars{i}.dim1;
        end
        if length(vars{i}.dim2) > 1
            dim2 = vars{i}.dim2(k+1);
        else
            dim2 = vars{i}.dim2;
        end
        addc(['Zeitschritt ' num2str(k)])
        addl(['dptr = ' gendata.prefix 'get_' vars{i}.name '(' num2str(k) ');'])
        addl(['mxlvl2 = mxGetCell(mxlvl1,' num2str(k) ');'])
        addl('diptr = mxGetPr(mxlvl2);')
        addl(['for(j=0; j<' num2str(dim1 * dim2) '; j++) {'])
        addl(['  dptr[j] = (' gendata.prec ')diptr [j];}'])
    end
    %addl('}')
end

% addc('Anfangsbedingung')
% addl('mxlvl1 = mxGetField(mstruct,0,"xinit");')
% addl(['ptmp = ' gendata.prefix 'get_x0();'])
% addl('dtmp = mxGetPr(mxlvl1);')
% addl(['for(j=0; j<' num2str(nx) '; j++)'])
% addl('{')
% addl(['ptmp[j] = (' prec ')dtmp[j];'])
% addl('}')
% 
% addl('')
% 
% addc('Gütefunktion')
% for i=1:length(Jvars)
%     gen_wrap_var_in_element(Jvars{i});
% end
% 
% addl('')
% 
% addc('Gleichungsnebenbedingungen')
% for i=1:length(eqvars)
%     gen_wrap_var_in_element(eqvars{i});
% end
% 
% addl('')
% 
% addc('Ungleichungsnebenbedingungen')
% for i=1:length(ineqvars)
%     gen_wrap_var_in_element(ineqvars{i});
% end
% 
% addl('')
% 
% addc('Temporäre Variablen (bis Codegenerator fertig ist)')
% for i=1:length(tmpvars)
%     gen_wrap_var_in_element(tmpvars{i});
% end
% 
addl('')
addl('return;')
addl('}')

funstr = genstr;
genstr = [];
end

function gen_wrap_var_in_element(var)
global gendata
K = gendata.dim.K;
prec = gendata.prec;

addc(var.name)
addl(['mxlvl1 = mxGetField(mstruct,0,"' var.cat '");'])
addl(['mxlvl2 = mxGetField(mxlvl1,0,"' var.name '");'])
addl(['for (i=0; i<=' num2str(K) ';i++)'])
addl('{')
addl(['mxlvl3 = mxGetCell(mxlvl2,i);'])
addl(['ptmp = ' gendata.prefix 'get_' var.name '(i);'])
addl('dtmp = mxGetPr(mxlvl3);')
addl(['for(j=0; j<' num2str(var.dim1*var.dim2) '; j++)'])
addl('{')
addl(['ptmp[j] = (' prec ')dtmp[j];'])
addl('}')
addl('}')
end