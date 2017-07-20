function [] = addf(varargin)
%ADDFUN Summary of this function goes here
%   Detailed explanation goes here
global genstr;
global gendata;
global genstore;
global aiter;


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

if function_uses_structures == 1
    if length(structures)~= (length(args)-1)
        error('Anzahl übergebener Argumente stimmt nich mit Anzahl übergebener Strukturen überein!')
    end
    for i = 1:length(structures)
        funname = [funname '_sid' num2str(structures{i}.sid)];
    end
end

%% Check special function calls
switch( call )
	case 'v_copy'
		% Do not try to copy an empty vector
		if dims{1} == 0
			return;
        end
    case 'm_copy'
        % Do not try to copy an empty matrix
		if dims{1} == 0 || dims{2} == 0
			return;
        end
end 

%% Funktionsaufruf erstellen und in Quellcode einfügen einfügen
genstr = [genstr char(10) gendata.prefix funname];

% Dimensionen hinzufügen
for i=1:length(dims)
    genstr = [genstr '_' num2str(dims{i})];
end

genstr = [genstr '('];
if (exist('genstore','var')&&(gendata.mem_type==2))
% Parameter hinzufügen
for i=1:length(args)
    % Fallunterscheidung: Array mit oder ohne Index wird übergeben
    [str42, array_type]=assign_mem(args{i});
    if array_type
        genstr = [genstr '&' gendata.prefix str42];
    else
        genstr = [genstr gendata.prefix str42];
    end
    
    
    if i ~= length(args)
        genstr = [genstr ', '];
    end
end

else
    for i=1:length(args)
        
        if varindex{i}
            genstr = [genstr '&' gendata.prefix args{i}];
        else
            genstr = [genstr gendata.prefix args{i}];
        end
        
        if i ~= length(args)
            genstr = [genstr ', '];
        end
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
        % Wenn Funktion innerhalb von Schleife verwendet wird, erhöhe count
        % entsprechend
        if isfield(aiter,'open_bracket')&&(aiter.open_bracket==1)
            gendata.functions{i}.count = gendata.functions{i}.count + aiter.stat_mult;
        else
            gendata.functions{i}.count = gendata.functions{i}.count + 1;
        end
    end
end
if ~funexists
    index = length(gendata.functions)+1;
    gendata.functions{index}.call = call;
    gendata.functions{index}.funid = thisfunid;
    gendata.functions{index}.dims = dims;
    % Wenn Funktion innerhalb von Schleife verwendet wird, erhöhe count
    % entsprechend
    if isfield(aiter,'open_bracket')&&(aiter.open_bracket==1)
            gendata.functions{index}.count =aiter.stat_mult;
    else
            gendata.functions{index}.count = 1;
    end
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




