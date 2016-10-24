function output = gen_chol_solve(n,m)
% Generiert Code für das Lösen eines LGS mit Cholesky bei vorhandener
% Cholesky-Zerlegung (L * L')
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['chol_solve_' num2str(n) '_' num2str(m)];

% Funktion-Kopf
funstr = ['static void ' prefix funid '(' prec ' *l, ' prec ' *b, ' prec ' *out)' char(10) '{'];

if n == 1
    funstr = [funstr char(10) '  int i;'];
    funstr = [funstr char(10) '  for(i=0; i<' num2str(m) '; i++)'];
    funstr = [funstr char(10) '  {'];
    funstr = [funstr char(10) '    out[i] = b[i] * l[0];'];
    funstr = [funstr char(10) '  }'];
    output.stat.mult = m;
else

% Variablen-Deklaration
funstr = [funstr  char(10) '  int i,j,k;' char(10) '  ' prec ' sum;' char(10)];

% Vorwärtseinsetzen
%Erste Schleife
funstr = [funstr char(10) '  for(k=0; k<' num2str(m) '; k++)'];
funstr = [funstr char(10) '  {'];
%Zweite Schleife
funstr = [funstr char(10) '    for(i=0; i<' num2str(n) '; i++)'];
funstr = [funstr char(10) '    {'];
funstr = [funstr char(10) '      sum = b[i+' num2str(n) '*k];'];
%Dritte Schleife
funstr = [funstr char(10) '      for(j=0; j<i; j++)'];
funstr = [funstr char(10) '      {'];
%Summe berechnen
funstr = [funstr char(10) '        sum = sum - out[j+' num2str(n) '*k]*l[i+' num2str(n) '*j];'];
%Ende dritte Schleife
funstr = [funstr char(10) '      }'];
%Durch Diagonalelement teilen
% Div0 check
funstr = [funstr char(10) '      if(l[i+' num2str(n) '*i] == 0){'];
funstr = [funstr char(10) '        ' prefix 'termcode = 8;'];
funstr = [funstr char(10) '        ' prefix 'error_line = __LINE__;'];
funstr = [funstr char(10) '        return;'];
funstr = [funstr char(10) '      }'];
funstr = [funstr char(10) '      out[i+' num2str(n) '*k] = sum / l[i+' num2str(n) '*i];'];
%Ende Schleife 2
funstr = [funstr char(10) '    }'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

% Rückwärtseinsetzen
%Erste Schleife
funstr = [funstr char(10) '  for(k=0; k<' num2str(m) '; k++)'];
funstr = [funstr char(10) '  {'];
%Zweite Schleife
funstr = [funstr char(10) '    for(i=' num2str(n-1) '; i>=0; i--)'];
funstr = [funstr char(10) '    {'];
funstr = [funstr char(10) '      sum = out[i+' num2str(n) '*k];'];
%Dritte Schleife
funstr = [funstr char(10) '      for(j=' num2str(n-1) '; j>i; j--)'];
funstr = [funstr char(10) '      {'];
%Summe berechnen
funstr = [funstr char(10) '        sum = sum - out[j+' num2str(n) '*k]*l[' num2str(n) '*i+j];'];
%Ende dritte Schleife
funstr = [funstr char(10) '      }'];
%Durch Diagonalelement teilen
% Div0 check
funstr = [funstr char(10) '      if(l[' num2str(n) '*i+i] == 0){'];
funstr = [funstr char(10) '        ' prefix 'termcode = 8;'];
funstr = [funstr char(10) '        return;'];
funstr = [funstr char(10) '      }'];
funstr = [funstr char(10) '        out[i+' num2str(n) '*k] = sum / l[' num2str(n) '*i+i];'];
%Ende Schleife 2
funstr = [funstr char(10) '    }'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];
end

%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end

