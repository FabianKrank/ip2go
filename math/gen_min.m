function output = gen_min()
% Generates code for scalar argument min-operator
% Skalar A: 1 x 1
% Scalar B: 1 x 1
global gendata
prec = gendata.prec;
prefix = gendata.prefix;
pointer = gendata.math_arg_use_pointer;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['min'];

% Funktion-Kopf
if pointer
	funstr = ['static void ' prefix funid '(' prec ' *a, ' prec ' *b, ' prec ' *out)' char(10) '{' char(10)];
else
	funstr = ['static void ' prefix funid '(' prec ' a[1], ' prec ' b[1], ' prec ' out[1])' char(10) '{' char(10)];
end

% Variablen-Deklaration
%funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  if  (a[0] < b[0])'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    out[0] = a[0];'];
%Ende Schleife 1
funstr = [funstr char(10) '  } else {'];
funstr = [funstr char(10) '    out[0] = b[0];'];
funstr = [funstr char(10) '  }'];
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

output.stat.if = 1;
output.stat.copy = 1;

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end