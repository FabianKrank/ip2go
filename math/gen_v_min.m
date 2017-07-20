function output = gen_v_min(n)
% Generiert Code für das Minimum eines Vektors
% Überprüfung mit einem übergebenen Wert
% Vektor A:     n x 1
% Wert B:       1 x 1
% Matrix OUT:   1 x 1
% OUT = min(A,B)
%
global gendata
prec = gendata.prec;
prefix = gendata.prefix;
pointer = gendata.math_arg_use_pointer;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['v_min_' num2str(n)];

% Funktion-Kopf
if pointer
	funstr = ['static void ' prefix funid '(' prec ' *A, ' prec ' *B, ' prec ' *out)' char(10) '{' char(10)];
else
	funstr = ['static void ' prefix funid '(' prec ' A[' num2str(n) '], ' prec ' B[1], ' prec ' out[1])' char(10) '{' char(10)];
end

% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];
% Init-Wert für OUT
funstr = [funstr '  out[0] = B[0];' char(10)];
% Schleife über alle Zeitschritte
funstr = [funstr char(10) '  for(i=0;i<' num2str(n) ';i++)'];
funstr = [funstr char(10) '  {'];
% Überprüfung auf >
funstr = [funstr char(10) '    if (A[i] < out[0])'];
funstr = [funstr char(10) '    {'];
funstr = [funstr char(10) '      out[0] = A[i];'];
funstr = [funstr char(10) '    }'];
funstr = [funstr char(10) '  }'];
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

output.stat.copy = n+1;
output.stat.if = n;

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end