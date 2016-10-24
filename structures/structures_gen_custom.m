function [s] = structures_gen_custom(name, var)
%STRUCTURES_GEN_CUSTOM Summary of this function goes here
%   Detailed explanation goes here
s = struct('name',[],'mask',[],'sid',[]);
s.name = name;

% Voll besetzte Maske
s.mask = ones(size(var));

% 0 Elemente in "var" in der Maske streichen
for i = 1:size(var,1)
    for j = 1:size(var,2)
        if var(i,j) == 0
            s.mask(i,j) = 0;
        end
    end
end
end

