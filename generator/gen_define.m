function definestr = gen_define(defines)

definestr = [];
definestr = [definestr '/* ########### */' char(10)];
definestr = [definestr '/* # DEFINE # */' char(10)];
definestr = [definestr '/* ########### */' char(10)];

% definestr = [definestr '#define WIN32' char(10)];

if ~iscell(defines)
    return
end

for i = 1:length(defines)
    if i~=1
        definestr = [definestr char(10)];
    end
    definestr = [definestr '#define ' defines{i} ''];
end

return
end