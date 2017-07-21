v=[];
for i=1:71
  tmp_name= gendata.functions{i}.call
  isf=0;
  for i2=1:numel(v)
      if strcmp(tmp_name,v{i2})
          isf=1;
      end
  end
  if isf==0
     v{numel(v)+1}=tmp_name;
  end
  
end

%   Columns 1 through 9

%    'v_copy'    'mv'    'vsub'    'mtv'    'vadd'    'vv_elemult'    'v_init0'    'vv_elediv'    'v_init1'

%  Columns 10 through 19

%    'sv'    'm_copy'    'mtr'    'chol_factor'    'chol_solve'    'm_init0'    'mm_y'    'msub'    'mtm'    'mm'

%  Column 20

%    'mtd'