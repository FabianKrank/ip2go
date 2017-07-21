function [] = addc(varargin)
%ADDFUN Summary of this function goes here
%   Detailed explanation goes here
global genstr

comment = varargin{1};

genstr = [genstr char(10) '/* ' comment ' */'];

end

