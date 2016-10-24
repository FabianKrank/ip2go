function output = gen_v_copy(n)
% Generiert Code für eine Funktion, die alle Elemente eines Vektors zu 0
% setzt
% Vektor a:     n x 1
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['v_copy_' num2str(n)];

% Funktion-Kopf
funstr = ['static void ' prefix funid '(' prec ' *a, ' prec ' *out)' char(10) '{' char(10)];

if gendata.loopunrolling == 1
    for i= 0:(n-1)
        funstr = [funstr char(10) '  out[' num2str(i) '] = a[' num2str(i) '];'];
        output.stat.copy = output.stat.copy + 1;
    end
else
% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n) ';i++)'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    out[i] =a[i];'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

output.stat.copy = n;
end
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end

