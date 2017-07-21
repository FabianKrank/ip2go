function [tmpstr] = addt(varargin)
%ADDFUN Summary of this function goes here
%   Detailed explanation goes here
global gendata

if nargin == 1
    dims = varargin{1};
    thistmpid = num2str(dims);
elseif nargin == 2
    dims = [varargin{1}; varargin{2}];
    thistmpid = [num2str(dims(1)) '_' num2str(dims(2))];
else
    disp('Fehler: Zu viele Parameter für addt.');
    return
end

index = 0;
for i=1:length(gendata.tmps)
    if strcmp(gendata.tmps{i}.tmpid,thistmpid)
        index = i;
    end
end

if index == 0
    index = length(gendata.tmps)+1;
    gendata.tmps{index}.tmpid = thistmpid;
    gendata.tmps{index}.dims = dims;
    gendata.tmps{index}.count = 1;
    gendata.tmps{index}.freeindex = [];
    num = 1;
else
    if(isempty(gendata.tmps{index}.freeindex))
        gendata.tmps{index}.count = gendata.tmps{index}.count + 1;
        num = gendata.tmps{index}.count;
    else
        num = gendata.tmps{index}.freeindex(end);
        gendata.tmps{index}.freeindex = gendata.tmps{index}.freeindex(1:end-1);
    end
    
end
tmpstr = ['tmp' num2str(num) '_' thistmpid];

end

