function funstr = gen_sm(n,m)
% Generiert Code für eine Skalar Matrix Multiplikation
% Skalar A: 1 x 1
% Matrix B: n x m
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

% Beschreibung

% Funktion-Kopf
funstr = ['static void ' prefix 'sm_' num2str(n) '_' num2str(m) '(' prec ' *a, ' prec ' *b, ' prec ' *out)' char(10) '{' char(10)];

% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n*m) ';i++)'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    out[i] += a[0] * b[i];'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

end