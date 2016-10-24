function funstr = gen_wrap_var_out(vars)
%Diese Funktion generiert die Konvertierung von c-Variablen in eine
%Matlabstruktur
%
% vars:
%   - name
%   - dims
%   - step (0/1), zeigt an, ob die Variable einmal vorkommt oder in jedem
%     Diskretisierungsschritt existiert
global gendata
global genstr

K = gendata.dim.K;
nx = gendata.dim.n_x;
nu = gendata.dim.n_u;
prec = gendata.prec;

genstr = [];

genstr = 'void c2matlab(mxArray *output[])';
addl('{')
addc('Pointer auf verschiedene Ebenen im Outputstruct')
addl('mxArray *tmpcell, *tmpdata;')
addc('Daten-Pointer')
addl([gendata.prec ' *dptr;'])
addl(['int *dptr_int;'])
addc('Daten-Output-Pointer')
addl([gendata.prec_out ' *doptr;'])
addl('int j;')
addl('int output_dim = 1;')
addl(['int num_fields = ' num2str(length(vars)) ';'])
addl(['int num_cells = ' num2str(K+1) ';'])
addl('int num_cells_single = 1;')
addc('Feldname für auszugebende Variablen')
str = '';
for i=1:length(vars)
    if i ~= 1
        str = [str ', '];
    end
    str = [str '"' vars{i}.name '"'];
end
addl(['const char *field_names[] = {' str '};'])
addl('')
%addl('mexPrintf("asd");')
addl('output[0] = mxCreateStructArray(1,&output_dim,num_fields,field_names);')
addl('')

% Schleife über alle Variablen, die ausgegeben werden sollen
for i = 1:length(vars)
    % Typ von Variable bestimmen:
    %   prec oder int
    %   einzeln oder k Instanzen
    intvar = 0;
    singlevar = 0;
    if isfield(vars{i},'intvar')
        if vars{i}.intvar == 1
            intvar = 1;
        end
    end
    if isfield(vars{i},'singlevar')
        if vars{i}.singlevar == 1
            singlevar = 1;
        end
    end
    %disp([vars{i}.name ' | ' num2str(singlevar) ' | ' num2str(intvar)])
    addc(['copy ' vars{i}.name])
    if singlevar
        % Matrix erstellen
        addl(['tmpdata = mxCreateNumericMatrix(' num2str(vars{i}.dim1) ',' num2str(vars{i}.dim2) ',' gendata.prec_out_mx ',mxREAL);'])
        % erstellte Matrix in entsprechendes Output-Feld eintragen
        addl(['mxSetField(output[0],0,"' vars{i}.name '",tmpdata);'])
        % Daten-Pointer aus dem Solver holen
        if intvar
            addl(['dptr_int = ' gendata.prefix 'get_' vars{i}.name '();'])
        else
            addl(['dptr = ' gendata.prefix 'get_' vars{i}.name '();'])
        end
        % Pointer auf die soeben erstellte Matrix holen
        addl('doptr = mxGetPr(tmpdata);')
        % Schleife über alle Elemente
        addl(['for (j=0;j<' num2str(vars{i}.dim1*vars{i}.dim2) ';j++){'])
        % Daten kopieren
        if intvar
            addl(['doptr[j] = (' gendata.prec_out ')dptr_int[j]; }'])
        else
            addl(['doptr[j] = (' gendata.prec_out ')dptr[j]; }'])
        end
    else
        % Cellarray erstellen (Länge = Anzahl an Diskretisierungsstellen)
        addl('tmpcell = mxCreateCellArray(1,&num_cells);')
        % erstelltes Cellarray in entsprechendes Output-Feld eintragen
        addl(['mxSetField(output[0],0,"' vars{i}.name '",tmpcell);'])
        % Schleife über alle Diskretisierungsstellen
        for k = 0:K
            % Dimensionen der Variable zum aktuellen Zeitschritt bestimmen
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
            % Daten-Matrix erstellen
            addl(['tmpdata = mxCreateNumericMatrix(' num2str(dim1) ',' num2str(dim2) ',' gendata.prec_out_mx ',mxREAL);'])
            % Daten-Matrix in entsprechendes Feld des Cellarrays eintragen
            addl(['mxSetCell(tmpcell,' num2str(k) ',tmpdata);'])
            % Daten-Pointer aus dem Solver holen
            if intvar
                addl(['dptr_int = ' gendata.prefix 'get_' vars{i}.name '(' num2str(k) ');'])
            else
                addl(['dptr = ' gendata.prefix 'get_' vars{i}.name '(' num2str(k) ');'])
            end
            % Pointer auf die soeben erstellte Matrix holen
            addl('doptr = mxGetPr(tmpdata);')
            % Schleife über alle Elemente
            addl(['for (j=0;j<' num2str(dim1*dim2) ';j++) {'])
            % Daten kopieren
            if intvar
                addl(['doptr[j] = (' gendata.prec_out ')dptr_int[j]; }'])
            else
                addl(['doptr[j] = (' gendata.prec_out ')dptr[j]; }'])
            end
        end
        %addl('}')
    end
    
    addl('')
end

addl('')
addl('return;')
addl('}')

funstr = genstr;
genstr = [];
end

% function gen_wrap_var_out_element(var)
% global gendata
% K = gendata.dim.K;
% prec = gendata.prec;
%
% addc(var.name)
% addl(['mxlvl1 = mxGetField(mxlvl0,0,"' var.cat '");'])
% addl(['mxlvl2 = mxGetField(mxlvl1,0,"' var.name '");'])
% addl(['for (i=0; i<=' num2str(K) ';i++)'])
% addl('{')
% addl(['mxlvl3 = mxGetCell(mxlvl2,i);'])
% addl(['ptmp = ' gendata.prefix 'get_' var.name '(i);'])
% addl('dtmp = mxGetPr(mxlvl3);')
% addl(['for(j=0; j<' num2str(var.dim1*var.dim2) '; j++)'])
% addl('{')
% addl(['dtmp[j] = (double)ptmp[j];'])
% addl('}')
% addl('}')
% end