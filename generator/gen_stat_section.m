function [] = gen_stat_section(name)
%GET_STAT_GET Summary of this function goes here
%   Detailed explanation goes here
global gendata

% if isfield(gendata,'stat')
%     if isfield(gendata.stat,'op')
%         if ~isfield(gendata.stat.op, 'tmp')
%             error('Gendata Struct nicht/falsch initialisiert');
%         end
%     else
%         error('Gendata Struct nicht/falsch initialisiert');
%     end        
% else
%     error('Gendata Struct nicht/falsch initialisiert');
% end
% 
% fields = {'add' 'mult' 'multadd' 'div' 'copy' 'init' 'if'};
% 
% tmp = [];
% 
% for i = 1:length(fields)
%     last = getfield(gendata.stat.op.tmp, fields{i});
%     now  = getfield(gendata.stat.op, fields{i});
%     tmp  = setfield(tmp, fields{i}, now - last);
%     
%     gendata.stat.op.tmp = setfield(gendata.stat.op.tmp, fields{i}, getfield(gendata.stat.op, fields{i}));
% end
% eval(['gendata.stat.op.' name ' = tmp']);

statfields = {'add' 'mult' 'multadd' 'div' 'copy' 'init' 'if'};

tmp = gendata.functions;

for i = 1:length(gendata.stat.op.tmp.functions)
    tmp{i}.count = tmp{i}.count - gendata.stat.op.tmp.functions{i}.count;
    %eval(['gendata.stat.op.' name '.functions = gendata.functions;']);
end

gendata.stat.op = setfield(gendata.stat.op, name, struct('functions',[]));
eval(['gendata.stat.op.' name '.functions = tmp;']);

gendata.stat.op.tmp.functions = gendata.functions;

end

