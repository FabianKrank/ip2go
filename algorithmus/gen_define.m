function definestr = gen_define()

global gendata

definestr = [];

for i = 1:length(gendata.define)
    if i~=1
        definestr = [definestr char(10)];
    end
    definestr = [definestr '#DEFINE ' gendata.prefix gendata.define{i}.name ' ' num2str(gendata.define{i}.val)];
end

return
end