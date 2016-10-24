function [s] = get_sbyname(name,index)
% get_structure_by_name
% gibt eine "Struktur" (Maske) zurück, die anhand des übergebenen Namens in
% allen verfügbaren Strukturen gefunden wurde.
%
% Wenn keine Strukturen verwendet werden sollen (gendata.use_structures == 0),
% dann wird eine leere Struktur zurückgegeben, sodass nicht vor jedem
% Funktionsaufruf überprüft werden muss, ob Strukturausnutzung verwendet
% werden soll oder nicht.
% Die Funktion addf filtert diese leeren Strukturen dann aus.

global gendata

if nargin == 2
    K = gendata.dim.K;
    if index == 0
        name = [name '_0'];
    elseif index == K
        name = [name '_end'];
    elseif (index > 0) && (index < K)
        name = [name '_k'];
    else
        error('Index out of Range [0..K]')
    end
end
s = struct();

if isfield(gendata,'structures')
    for i = 1:length(gendata.structures)
        if strcmp(gendata.structures{i}.name,name)
            s = gendata.structures{i};
            return
        end
    end
end

s = struct('name','no_name','mask',0,'sid',0);
if gendata.use_structures
    error(['Struktur ' name ' wurde nicht gefunden'])
end


end

