function output = gen_m_copy(n,m)
% Generiert Code für eine Funktion, die alle Elemente einer Matrix zu 0
% setzt
% Matrix A:     n x m
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['m_copy_' num2str(n) '_' num2str(m)];

% Funktion-Kopf
funstr = ['static void ' prefix funid '(' prec ' *a, ' prec ' *out)' char(10) '{' char(10)];

if gendata.loopunrolling == 1
    for i= 0:(n*m-1)
        funstr = [funstr char(10) '  out[' num2str(i) '] = a[' num2str(i) '];'];
        output.stat.copy = output.stat.copy + 1;
    end
else
% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n*m) ';i++)'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    out[i] =a[i];'];
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

