function output = gen_mtr(n,m)
% Generiert Code für eine Matrix Transponierung
% Matrix A:   n x m
% Matrix out: m x n
global gendata
prec = gendata.prec;
prefix = gendata.prefix;
pointer = gendata.math_arg_use_pointer;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['mtr_' num2str(n) '_' num2str(m)];

% Funktion-Kopf
if pointer
	funstr = ['static void ' prefix funid '(' prec ' *A, ' prec ' *out)' char(10) '{' char(10)];
else
	funstr = ['static void ' prefix funid '(' prec ' A[' num2str(m*n) '], ' prec ' out[' num2str(m*n) '])' char(10) '{' char(10)];
end

if gendata.loopunrolling == 1
    for j=0:(n-1)
        for i=0:(m-1)
            funstr = [funstr char(10) '  out[' num2str(i + m*j) '] = A['  num2str(j+n*i) '];'];
            output.stat.copy = output.stat.copy + 1;
        end
    end
else
% Variablen-Deklaration
funstr = [funstr '  int i,j;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(j=0;j<' num2str(n) ';j++)'];
funstr = [funstr char(10) '  {'];
%Zweite Schleife
funstr = [funstr char(10) '    for(i=0;i<' num2str(m) ';i++)'];
funstr = [funstr char(10) '    {'];
%Transponieren
funstr = [funstr char(10) '      out[i + ' num2str(m) '*j] = A[j + '  num2str(n) '*i];'];
%Ende Schleife 2
funstr = [funstr char(10) '    }'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

output.stat.copy = n*m;
end
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end

