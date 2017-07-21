function output = gen_norm_inf(n,m)
% Generiert Code für eine Unendlichnorm einer Matrix mit zusätzlicher
% Überprüfung mit einem übergebenen Wert
% Matrix A:     n x m
% Wert B:       1 x 1
% Wert OUT:   1 x 1
% OUT = max(abs(A),B)
%
% ACHTUNG: Es ist nicht möglich einen Pointer auf das nicht erste Element
% in einer MATRIX zu übergeben (bzw. das Ergebnis ist unbrauchbar)
% Bei VEKTOREN möglich.
%
% annika.mayer@isys.uni-stuttgart.de 05.12.16
%   - Zeile 33, Korrektur out[0]=-A[], Minus hinzugefügt
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
    % Init-Wert für OUT
    
    % Schleife über alle Elemente
    funstr = [funstr char(10) '  for(i=0;i<' num2str(n*m) ';i++)'];
    funstr = [funstr char(10) '  {'];
    % Überprüfung auf >
    funstr = [funstr char(10) '    if (A[i] > out[0])'];
    funstr = [funstr char(10) '    {'];
    funstr = [funstr char(10) '      out[0] = A[i];'];
    funstr = [funstr char(10) '    }'];
    % Überprüfung betragsmäßig >
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

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end