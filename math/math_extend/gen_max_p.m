function funstr = gen_max_p(n,m)
% Generiert Code f�r eine Unendlichnorm einer Matrix mit zus�tzlicher
% �berpr�fung mit einem �bergebenen Wert
% Matrix A:     n x m
% Wert B:       1 x 1
% Matrix OUT:   1 x 1
% OUT = max(A)
%
% ACHTUNG: Es ist nicht m�glich einen Pointer auf das nicht erste Element
% in einer Matrix zu �bergeben (bzw. das Ergebnis ist unbrauchbar)
%
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

% Beschreibung

% Funktion-Kopf
funstr = ['static void ' prefix 'max_p_' num2str(n) '_' num2str(m) '(' prec ' *A, ' prec ' *B, ' prec ' *OUT)' char(10) '{' char(10)];

% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];
% Init-Wert f�r OUT
funstr = [funstr '  OUT[0] = B[0];' char(10)];
% Schleife �ber alle Zeitschritte
funstr = [funstr char(10) '  for(i=0;i<' num2str(n*m) ';i++)'];
funstr = [funstr char(10) '  {'];
% �berpr�fung auf >
funstr = [funstr char(10) '    if (A[i] > OUT[0])'];
funstr = [funstr char(10) '    {'];
funstr = [funstr char(10) '      OUT[0] = A[i];'];
funstr = [funstr char(10) '    }'];
funstr = [funstr char(10) '  }'];
% �berpr�fung �bergebenes Element
%funstr = [funstr char(10) 'if (B[0] > OUT[0])'];
%funstr = [funstr char(10) '  {'];
%funstr = [funstr char(10) '    OUT[0] = B[0];'];
%funstr = [funstr char(10) '  }'];
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

end