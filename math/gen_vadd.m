function output = gen_vadd(n)
% Generiert Code für eine Vektor Vektor Addition
% Vector a:     n x 1
% Vector b:     n x 1
% Vector out:   n x 1
global gendata
prec = gendata.prec;
prefix = gendata.prefix;
pointer=gendata.math_arg_use_pointer;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['vadd_' num2str(n)];

% Funktion-Kopf
if pointer
    funstr = ['static void ' prefix funid '(' prec ' *a, ' prec ' *b, ' prec ' *out)' char(10) '{' char(10)];
else
    funstr = ['static void ' prefix funid '(' prec ' a[' num2str(n) '], ' prec ' b[' num2str(n) '], ' prec ' out[' num2str(n) '])' char(10) '{' char(10)];
end
if gendata.loopunrolling == 1
    for i= 0:(n-1)
        funstr = [funstr char(10) '  out[' num2str(i) '] = a[' num2str(i) '] + b[' num2str(i) '];'];
        output.stat.add = output.stat.add + 1;
    end
else
% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n) ';i++)'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    out[i] = a[i] + b[i];'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

output.stat.add = n;
end
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end

