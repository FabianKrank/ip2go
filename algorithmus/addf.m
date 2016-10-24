function [] = addf(varargin)
%ADDFUN Summary of this function goes here
%   Detailed explanation goes here
global genstr;
global gendata;

%% Variablen deklarieren
dims = [];
args = [];
structures = cell(0);
varindex = [];
%% Input verarbeiten
funname = varargin{1};
call = varargin{1};
safefun = 0;
function_uses_structures = 0;

if isfield(gendata,'safefuns')
    for i=1:length(gendata.safefuns)
        if strcmp(funname,gendata.safefuns{i})
            safefun = 1;
        end
    end
end

for i=2:nargin
    if isnumeric(varargin{i})
        dims{length(dims)+1} = varargin{i};
    elseif ischar(varargin{i})
        args{length(args)+1} = varargin{i};
        if strcmp(args{end}(end),']')
            varindex{length(args)} = 1;
        else
            varindex{length(args)} = 0;
        end
    elseif isstruct(varargin{i})
        function_uses_structures = 1;
        structures{end+1} = varargin{i};
    end
end

if gendata.use_structures == 0
    function_uses_structures = 0;
end

%% Bei strukturausnutzenden Funktionen funname anpassen
% funname = funname + structure_id
if function_uses_structures == 1
    if length(structures)~= (length(args)-1)
        error('Anzahl �bergebener Argumente stimmt nich mit Anzahl �bergebener Strukturen �berein!')
    end
    for i = 1:length(structures)
        funname = [funname '_sid' num2str(structures{i}.sid)];
    end
end

%% Funktionsaufruf erstellen und in Quellcode einf�gen einf�gen
genstr = [genstr char(10) gendata.prefix funname];

% Dimensionen hinzuf�gen
for i=1:length(dims)
    genstr = [genstr '_' num2str(dims{i})];
end

genstr = [genstr '('];

% Parameter hinzuf�gen
for i=1:length(args)
    % Fallunterscheidung: Array mit oder ohne Index wird �bergeben
    if varindex{i}
        genstr = [genstr '&' gendata.prefix args{i}];
    else
        genstr = [genstr gendata.prefix args{i}];
    end
    
    if i ~= length(args)
        genstr = [genstr ', '];
    end
end

genstr = [genstr ');'];

%% Funktion in die Funktionsliste aufnehmen
thisfunid = funname;
for i=1:length(dims)
    thisfunid = [thisfunid '_' num2str(dims{i})];
end
funexists = false;
for i=1:length(gendata.functions)
    if strcmp(gendata.functions{i}.funid,thisfunid)
        funexists = true;
        gendata.functions{i}.count = gendata.functions{i}.count + 1;
    end
end
if ~funexists
    index = length(gendata.functions)+1;
    %gendata.functions{index}.name = funname;
    gendata.functions{index}.call = call;
    gendata.functions{index}.funid = thisfunid;
    gendata.functions{index}.dims = dims;
    gendata.functions{index}.count = 1;
    %gendata.functions{index}.args = args;
    if function_uses_structures == 1
        gendata.functions{index}.function_uses_structures = length(structures);
        gendata.functions{index}.structures = cell(0);
        for i = 1:length(structures)
            gendata.functions{index}.structures{i} = structures{i};
        end
    else
        gendata.functions{index}.function_uses_structures = 0;
    end
end

%% Div0-Funktionen absichern
if safefun == 1
    addl(['if(' gendata.prefix 'termcode > -1){return;}'])
end
end

