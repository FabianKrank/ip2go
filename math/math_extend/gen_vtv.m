function output = gen_vtv(n)
% Generiert Code für eine Vektor transponiert Vektor Multiplikation
% Matrix A: n x 1
% Vector B: m x 1
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['vtv_' num2str(n)];

% Funktion-Kopf
funstr = ['static void ' prefix funid '(' prec ' *a, ' prec ' *b, ' prec ' *out)' char(10) '{' char(10)];

if gendata.loopunrolling == 1
    for i= 0:(n-1)
        funstr = [funstr char(10) '  out[0] += a[' num2str(i) '] * b[' num2str(i) '];'];
        output.stat.multadd = output.stat.multadd + 1;
    end
else
% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%out-Skaler zu 0 setzen
%funstr = [funstr char(10) '  out[0] = 0;'];
%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n) ';i++)'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    out[0] += a[i] * b[i];'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

output.stat.multadd = n;
end
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end

