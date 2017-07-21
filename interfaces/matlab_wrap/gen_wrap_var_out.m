function funstr = gen_wrap_var_out(vars)
%Diese Funktion generiert die Konvertierung von c-Variablen in eine
%Matlabstruktur
%
% vars:
%   - name
%   - dims
%   - step (0/1), zeigt an, ob die Variable einmal vorkommt oder in jedem
%     Diskretisierungsschritt existiert
%% #############
% # Changelog #
% #############
%
% 22.11.16 Annika Mayer (annika.mayer@isys.uni-stuttgart.de):
% Für alle Elemente die dieselbe Dimension haben, kann als
% Ausgangsspeichertyp zwischen Array und Struktur gewählt werden


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
addl('int j1;')
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
        % Schleife über alle Diskretisierungsstellen
        for k = 0:K
            % Dimensionen der Variable zum aktuellen Zeitschritt bestimmen
            if length(vars{i}.dim1) > 1
                vdim1(k+1) = vars{i}.dim1(k+1);
            else
                vdim1(k+1) = vars{i}.dim1;
            end
            if length(vars{i}.dim2) > 1
                vdim2(k+1) = vars{i}.dim2(k+1);
            else
                vdim2(k+1) = vars{i}.dim2;
            end
        end
        if isfield(gendata,'output_type')&& strcmp(gendata.output_type,'ar')&&(length(unique(vdim1))==1)&& (length(unique(vdim2))==1)&&(vdim2(1)==1)
            % Daten-Matrix erstellen
            dim1=vdim1(1);
            addl(['tmpdata = mxCreateNumericMatrix(' num2str(dim1) ',' num2str(K+1) ',' gendata.prec_out_mx ',mxREAL);'])
            % erstelltes Cellarray in entsprechendes Output-Feld eintragen
            addl(['mxSetField(output[0],0,"' vars{i}.name '",tmpdata);'])
            % Pointer auf die soeben erstellte Matrix holen
            addl('doptr = mxGetPr(tmpdata);')
            % Schleife über alle Zeitschritte
            addl(['for (j1=0;j1<' num2str(K+1) ';j1++) {'])
            
            % Daten-Pointer aus dem Solver holen
            if intvar
                addl(['dptr_int = ' gendata.prefix 'get_' vars{i}.name '(' 'j1' ');'])
            else
                addl(['dptr = ' gendata.prefix 'get_' vars{i}.name '(' 'j1'  ');'])
            end
            
            % Schleife über alle Elemente
            addl(['for (j=0;j<' num2str(dim1) ';j++) {'])
            % Daten kopieren
            if intvar
                addl(['doptr[j+j1*' num2str(dim1) '] = (' gendata.prec_out ')dptr_int[j]; }'])
            else
                addl(['doptr[j+j1*' num2str(dim1) '] = (' gendata.prec_out ')dptr[j]; }'])
            end
            addl('}')
        else
            % Cellarray erstellen (Länge = Anzahl an Diskretisierungsstellen)
            addl('tmpcell = mxCreateCellArray(1,&num_cells);')
            % erstelltes Cellarray in entsprechendes Output-Feld eintragen
            addl(['mxSetField(output[0],0,"' vars{i}.name '",tmpcell);'])
            for k = 0:K
                dim1=vdim1(k+1);
                dim2=vdim2(k+1);
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

