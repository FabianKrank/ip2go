function output = gen_chol_factor(n)
% Generiert Code für eine Cholesky-Zerlegung
funstr = [];

global gendata
prec = gendata.prec;
prefix = gendata.prefix;

% Beschreibung

output.stat = gen_stat_default_struct;

funid = ['chol_factor_' num2str(n)];

% Funktion-Kopf
funstr = ['static void ' prefix funid '(' prec ' *a, ' prec ' *out)' char(10) '{'];

if n == 1
    % Div0 check
    funstr = [funstr char(10) '  if(a[0] == 0){'];
    funstr = [funstr char(10) '    ' prefix 'termcode = 8;'];
    funstr = [funstr char(10) '    ' prefix 'error_line = __LINE__;'];
    funstr = [funstr char(10) '    return;'];
    funstr = [funstr char(10) '  }'];
    funstr = [funstr char(10) '  out[0] = 1/a[0];'];
    output.stat.div = output.stat.div + 1;
else

% Variablen-Deklaration
funstr = [funstr  char(10) '  int i,j,k;' char(10) prec ' sum;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0; i<' num2str(n) '; i++)'];
funstr = [funstr char(10) '  {'];
%Zweite Schleife
funstr = [funstr char(10) '    for(j=0; j<=i; j++)'];
funstr = [funstr char(10) '    {'];
funstr = [funstr char(10) '      sum = a[i+' num2str(n) '*j];'];
%Dritte Schleife
funstr = [funstr char(10) '      for(k=0; k<j; k++)'];
%Summe berechnen
funstr = [funstr char(10) '        sum = sum - out[i+' num2str(n) '*k]*out[j+' num2str(n) '*k];'];
%Fallunterscheidung Diagonalelement / Subdiagonalelement (untere Dreiecksmatrix)
funstr = [funstr char(10) '      if (i > j)'];
funstr = [funstr char(10) '      {'];
% Div0 check
funstr = [funstr char(10) '        if(out[j+' num2str(n) '*j] == 0){'];
funstr = [funstr char(10) '          ' prefix 'termcode = 8;'];
funstr = [funstr char(10) '          ' prefix 'error_line = __LINE__;'];
funstr = [funstr char(10) '          return;'];
funstr = [funstr char(10) '        }'];

funstr = [funstr char(10) '        out[i+' num2str(n) '*j] = sum / out[j+' num2str(n) '*j];'];
funstr = [funstr char(10) '      }'];
funstr = [funstr char(10) '      else'];
funstr = [funstr char(10) '      {'];
% sqrt(-x) check
funstr = [funstr char(10) '        if(sum < 0){'];
funstr = [funstr char(10) '          ' prefix 'termcode = 9;'];
funstr = [funstr char(10) '          ' prefix 'error_line = __LINE__;'];
funstr = [funstr char(10) '          return;'];
funstr = [funstr char(10) '        }'];
funstr = [funstr char(10) '        out[i+' num2str(n) '*i] = (' prec ')sqrt(sum);'];
funstr = [funstr char(10) '      }'];
%Ende Schleife 2
funstr = [funstr char(10) '    }'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

end
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];



% 
% for (i=0; i<n; i++)
%     {
%         for (j=0; j<=i; j++)
%         {
%             sum = Hxx1[i+n*j];
%             for (k=0; k<j; k++)
%                 sum = sum - tmp3[i+n*k]*tmp3[j+n*k];
%             if (i > j)
%             {
%                 tmp3[i+n*j] = sum / tmp3[j+n*j];
%             }
%             else
%             {
%                 tmp3[i+n*i] = sqrt(sum);
%             }
%         }
%     }

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end

