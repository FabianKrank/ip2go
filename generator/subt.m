function [] = subt(tmpstr)
%ADDFUN Summary of this function goes here
%   Detailed explanation goes here
global gendata

idx = strfind(tmpstr, '_');

if length(idx) == 1
    thistmpid = tmpstr(idx+1:end);
else
    thistmpid = tmpstr(idx(1)+1:end);
end

num = str2double(tmpstr(4:idx(1)-1));

index = 0;
for i=1:length(gendata.tmps)
    if strcmp(gendata.tmps{i}.tmpid,thistmpid)
        index = i;
    end
end

if index == 0
    disp('Fehler: tmp-Variable existiert nicht mehr.')
else
    gendata.tmps{index}.freeindex(end+1) = num;
end

end

