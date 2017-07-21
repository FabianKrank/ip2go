function funstr = gen_dm(n,m,p)
% NICHT FERTIG
% Generiert Code für eine Matrix Matrix Multiplikation
% Matrix A: n x m
% Matrix B: m x p
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

% Beschreibung

% Funktion-Kopf
funstr = ['static void ' prefix 'dm_' num2str(n) '_' num2str(m) '_' num2str(p) '(' prec ' *A, ' prec ' *B, ' prec ' *out)' char(10) '{' char(10)];

% Variablen-Deklaration
funstr = [funstr '  int i,j,k;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(k=0;k<' num2str(p) ';k++)'];
funstr = [funstr char(10) '  {'];
%Zweite Schleife
funstr = [funstr char(10) '    for(i=0;i<' num2str(n) ';i++)'];
funstr = [funstr char(10) '    {'];
funstr = [funstr char(10) '      out[i + ' num2str(n) '*k]=0;'];
%Dritte Schleife
funstr = [funstr char(10) '      for(j=0;j<' num2str(m) ';j++)'];
funstr = [funstr char(10) '      {'];
%Multiplikation
funstr = [funstr char(10) '        out[i + ' num2str(n) '*k] += A[i + '  num2str(n) '*j] * B[j + ' num2str(m) '*k];'];
%Ende Schleife 3
funstr = [funstr char(10) '      }'];
%Ende Schleife 2
funstr = [funstr char(10) '    }'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

end

