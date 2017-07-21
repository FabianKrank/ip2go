function [] = addp( varargin )
global genstr
global gendata

varname = varargin{1};
if ~strcmp(varname(end),']')
    varname = [varname '[0]'];
end
if length(varargin) == 2
    dispname = [varargin{2} ': '];
else    
    dispname = '';
end
genstr = [genstr char(10) 'mexPrintf("' dispname '%f\n",' gendata.prefix varname ');'];

end

