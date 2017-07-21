namelist=fieldnames(res);

for i=1:numel(namelist)
    eq=eval(['isequal(res.',namelist{i},',res3.',namelist{i}, ')']);
    if ~eq
     display(namelist{i})    
    end
end