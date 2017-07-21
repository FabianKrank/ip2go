function output = gen_norm_inf(n,m)
% Generiert Code f�r eine Unendlichnorm einer Matrix mit zus�tzlicher
% �berpr�fung mit einem �bergebenen Wert
% Matrix A:     n x m
% Wert B:       1 x 1
% Wert OUT:   1 x 1
% OUT = max(abs(A),B)
%
% ACHTUNG: Es ist nicht m�glich einen Pointer auf das nicht erste Element
% in einer MATRIX zu �bergeben (bzw. das Ergebnis ist unbrauchbar)
% Bei VEKTOREN m�glich.
%
% annika.mayer@isys.uni-stuttgart.de 05.12.16
%   - Zeile 33, Korrektur out[0]=-A[], Minus hinzugef�gt
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['norm_inf_' num2str(n) '_' num2str(m)];

% Funktion-Kopf
funstr = ['static void ' prefix funid '(' prec ' *A, ' prec ' *B, ' prec ' *out)' char(10) '{' char(10)];

if gendata.loopunrolling == 1
    funstr = [funstr '  out[0] = B[0];' char(10)];
    output.stat.copy = output.stat.copy + 1;
    for i=0:(n*m-1)
        funstr = [funstr char(10) '  if (A[' num2str(i) '] > out[0]) out[0] = A[' num2str(i) '];'];
        funstr = [funstr char(10) '  if (-A[' num2str(i) '] > out[0]) out[0] = -A[' num2str(i) '];'];
        output.stat.copy = output.stat.copy + 1;
        output.stat.if = output.stat.if + 1;
    end
else
    % Variablen-Deklaration
    funstr = [funstr '  int i;' char(10)];
    % Init-Wert f�r OUT
    
    % Schleife �ber alle Elemente
    funstr = [funstr char(10) '  for(i=0;i<' num2str(n*m) ';i++)'];
    funstr = [funstr char(10) '  {'];
    % �berpr�fung auf >
    funstr = [funstr char(10) '    if (A[i] > out[0])'];
    funstr = [funstr char(10) '    {'];
    funstr = [funstr char(10) '      out[0] = A[i];'];
    funstr = [funstr char(10) '    }'];
    % �berpr�fung betragsm��ig >
    funstr = [funstr char(10) '    if (-A[i] > out[0])'];
    funstr = [funstr char(10) '    {'];
    funstr = [funstr char(10) '      out[0] = -A[i];'];
    funstr = [funstr char(10) '    }'];
    funstr = [funstr char(10) '  }'];
    
    output.stat.copy = n*m;
    output.stat.if = n*m;
end

%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern f�r Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end