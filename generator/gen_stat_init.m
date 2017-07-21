function [] = gen_stat_init()
%GEN_STAT_INIT Summary of this function goes here
%   Detailed explanation goes here

global gendata

if ~isfield(gendata,'stat')
    gendata.stat = [];
    %error('Gendata Struct nicht/falsch initialisiert');
end

if ~isfield(gendata.stat,'op')
    gendata.stat.op = [];
    %error('Gendata Struct nicht/falsch initialisiert');
end

if ~isfield(gendata.stat.op,'tmp')
    gendata.stat.op.tmp = [];
    %error('Gendata Struct nicht/falsch initialisiert');
end 

gendata.stat.op.tmp.functions = [];

end

