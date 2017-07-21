function funstr = gen_madd(n,m)
% Generiert Code für eine Matrix Matrix Addition
% Matrix A:     n x m
% Matrix B:     n x m
% Matrix OUT:   n x m
% OUT = A + B
global gendata
prec = gendata.prec;
prefix = gendata.prefix;
funstr = [];

% Beschreibung

% Funktion-Kopf
funstr = ['static void ' prefix 'madd_' num2str(n) '_' num2str(m) '(' prec ' *A, ' prec ' *B, ' prec ' *OUT)' char(10) '{' char(10)];

if gendata.loopunrolling == 1
    for i= 0:(n*m-1)
        funstr = [funstr char(10) '  OUT[' num2str(i) '] = A[' num2str(i) '] + B[' num2str(i) '];'];
    end
else
% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n) '*' num2str(m) ';i++)'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    OUT[i] = A[i] + B[i];'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];
end
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

end