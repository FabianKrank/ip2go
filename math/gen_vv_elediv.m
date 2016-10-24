function output = gen_vv_elediv(n)
% Generiert Code für eine elementweise Vektor Vektor Division
% out = a./b
% Vektor a:     n x 1
% Vektor b:     n x 1
% Vektor out:   n x 1
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['vv_elediv_' num2str(n)];

% Funktion-Kopf
funstr = ['static void ' prefix funid '(' prec ' *a, ' prec ' *b, ' prec ' *out)' char(10) '{' char(10)];
if gendata.loopunrolling == 1
    for i= 0:(n-1)
        funstr = [funstr char(10) '  if(b[' num2str(i) '] == 0){ ' prefix 'termcode = 8; ' prefix 'error_line = __LINE__; return;}'];
        funstr = [funstr char(10) '  out[' num2str(i) '] = a[' num2str(i) '] / b[' num2str(i) '];'];
        output.stat.div = output.stat.div + 1;
    end
else
    % Variablen-Deklaration
    funstr = [funstr '  int i;' char(10)];
    
    %Erste Schleife
    funstr = [funstr char(10) '  for(i=0;i<' num2str(n) ';i++)'];
    funstr = [funstr char(10) '  {'];
    % Div0 check
    funstr = [funstr char(10) '    if(b[i] == 0){'];
    funstr = [funstr char(10) '      ' prefix 'termcode = 8;'];
    funstr = [funstr char(10) '      ' prefix 'error_line = __LINE__;'];
    funstr = [funstr char(10) '      return;'];
    funstr = [funstr char(10) '    }'];
    %Division
    funstr = [funstr char(10) '    out[i] = a[i] / b[i];'];
    %Ende Schleife 1
    funstr = [funstr char(10) '  }'];
    
    output.stat.div = n;
end

%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end