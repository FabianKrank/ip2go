function output = gen_msub(n,m)
% Generiert Code für eine Matrix Matrix Addition
% Matrix A:     n x m
% Matrix B:     n x m
% Matrix OUT:   n x m
% OUT = A + B
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['msub_' num2str(n) '_' num2str(m)];

% Funktion-Kopf
funstr = ['static void ' prefix funid '(' prec ' *A, ' prec ' *B, ' prec ' *out)' char(10) '{' char(10)];

if gendata.loopunrolling == 1
    for i= 0:(n*m-1)
        funstr = [funstr char(10) '  out[' num2str(i) '] = A[' num2str(i) '] - B[' num2str(i) '];'];
        output.stat.add = output.stat.add + 1;
    end
else
% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n) '*' num2str(m) ';i++)'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    out[i] = A[i] - B[i];'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

output.stat.add = n*m;
end
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end