function [] = addl(varargin)
%ADDFUN Summary of this function goes here
%   Detailed explanation goes here
global genstr

linestr = varargin{1};

genstr = [genstr char(10) linestr];

end

