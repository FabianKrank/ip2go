function funstr = gen_mm_elediv(n,m)
% Generiert Code für eine elementweise Matrix Matrix Division
% out = A.*B
% Matrix A:     n x m
% Matrix B:     n x m
% Vektor out:   n x m
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

% Beschreibung

% Funktion-Kopf
funstr = ['static void ' prefix 'mm_elediv_' num2str(n) '_' num2str(m) '(' prec ' *a, ' prec ' *b, ' prec ' *out)' char(10) '{' char(10)];

% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n*m) ';i++)'];
funstr = [funstr char(10) '  {'];
%Division
% Div0 check
funstr = [funstr char(10) '    if(b[i] == 0){'];
funstr = [funstr char(10) '      ' prefix 'termcode = 8;'];
funstr = [funstr char(10) '      ' prefix 'error_line = __LINE__;'];
funstr = [funstr char(10) '      return;'];
funstr = [funstr char(10) '    }'];
funstr = [funstr char(10) '    out[i] = a[i] / b[i];'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

end