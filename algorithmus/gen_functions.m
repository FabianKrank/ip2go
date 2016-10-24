function [funstr] = gen_functions()
%GEN_FUNCTIONS Summary of this function goes here
%   Detailed explanation goes here
global gendata
global genstr

nlc = gendata.nlc;

genstr = [];
funstr = [];

% Statistik initialisieren
gendata.stat.op.functions(1:length(gendata.functions)) = struct('funid',[],...
    'add',[],...
    'mult',[],...
    'multadd',[],...
    'div',[],...
    'copy',[],...
    'init',[],...
    'if',[]);

% Verzeichnis wechseln
path_orig = pwd;
cd(gendata.path_math);

% Funktionsliste durchlaufen und entsprechende mathematische Funktion
% generieren
for i = 1:length(gendata.functions)
    % Aufruf erzeugen
    tmpstr = ['gen_' gendata.functions{i}.call '('];
    % Argumente erzeugen
    % Dimensionen
    for j=1:length(gendata.functions{i}.dims)
        if j ~= 1
           tmpstr = [tmpstr ',']; 
        end
        tmpstr = [tmpstr num2str(gendata.functions{i}.dims{j})];
    end
    % Strukturen (falls vorhanden)
    if gendata.functions{i}.function_uses_structures
        %disp(i);
        %disp(gendata.functions{i}.funid);
        for j = 1:length(gendata.functions{i}.structures)
            %disp(gendata.functions{i}.structures{j})
            tmpstr = [tmpstr ', gendata.functions{' num2str(i) '}.structures{' num2str(j) '}'];
        end
    end
    %tmpstr = [tmpstr ', ''' gendata.prec ''');'];
    tmpstr = [tmpstr ');'];
    if i ~= 1
        funstr = [funstr nlc nlc];
    end
    
    % Funktionsquellcode generieren und anhängen
    stat = [];
    tmp_out = eval(tmpstr);
    % Output ist entweder String (C-code) oder struct mit String und
    % Statistik
    if ischar(tmp_out)
        tmp_str = tmp_out;
        stat = [];
    elseif isstruct(tmp_out)
        tmp_str = tmp_out.str;
        stat = tmp_out.stat;
    else
        error('Ungültiger Funktions-Output')
    end
    
    % C-Code anhängen
    funstr = [funstr tmp_str];
    
    % Statistik abspeichern
    if isempty(stat)
        stat = gen_stat_default_struct;
        stat.funid = gendata.functions{i}.funid;
        warning(['Function "' gendata.functions{i}.funid '" (' num2str(i) '): no stats recorded!']);
    end
    gendata.stat.op.functions(i) = stat;
    gendata.stat.op.functions(i).add     = gendata.stat.op.functions(i).add;
    gendata.stat.op.functions(i).mult    = gendata.stat.op.functions(i).mult;
    gendata.stat.op.functions(i).multadd = gendata.stat.op.functions(i).multadd;
    gendata.stat.op.functions(i).div     = gendata.stat.op.functions(i).div;
    gendata.stat.op.functions(i).copy    = gendata.stat.op.functions(i).copy;
    gendata.stat.op.functions(i).init    = gendata.stat.op.functions(i).init;
    gendata.stat.op.functions(i).if      = gendata.stat.op.functions(i).if;
end

statfields = {'add' 'mult' 'multadd' 'div' 'copy' 'init' 'if'};

fields = fieldnames(gendata.stat.op);

for i = 1:length(fields)
    if ~strcmp(fields{i}, 'tmp') && ~strcmp(fields{i}, 'functions')
        tmp = getfield(gendata.stat.op, fields{i});
        for j = 1:length(tmp.functions)
            count = tmp.functions{j}.count;
            for k = 1:length(statfields)
                if isfield(tmp, statfields{k})
                    tmp3 = getfield(tmp, statfields{k});
                else
                    tmp3 = 0;
                end
                tmp2 = getfield(gendata.stat.op.functions(j),statfields{k});
                tmp = setfield(tmp, statfields{k}, tmp3 + count * tmp2);
            end
        end
        gendata.stat.op = setfield(gendata.stat.op, fields{i}, tmp);
    end
end

gendata.stat.op = rmfield(gendata.stat.op, 'tmp');
%gendata.stat.op = rmfield(gendata.stat.op, 'functions');


cd(path_orig);
end

