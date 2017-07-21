function includestr = gen_include(includes)
% Diese Funktion generiert die "include"-str

includestr = [];
includestr = [includestr '/* ########### */' char(10)];
includestr = [includestr '/* # INCLUDE # */' char(10)];
includestr = [includestr '/* ########### */' char(10)];

% includestr = [includestr '#define WIN32' char(10)];

if ~iscell(includes)
    return
end

for i = 1:length(includes)
    if i~=1
        includestr = [includestr char(10)];
    end
    includestr = [includestr '#include "' includes{i} '"'];
end

return
end