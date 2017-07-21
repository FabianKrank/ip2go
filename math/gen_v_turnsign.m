function output = gen_v_turnsign(n)
% Generiert Code für eine Funktion, die alle Vorzeichen aller Elemente
% einer Matrix umdreht
% Vaktor a:     n x 1
% Vektor out:   n x 1
% out = -a
global gendata
prec = gendata.prec;
prefix = gendata.prefix;
pointer = gendata.math_arg_use_pointer;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['v_turnsign_' num2str(n)];

% Funktion-Kopf
if pointer
	funstr = ['static void ' prefix funid '(' prec ' *a, ' prec ' *out)' char(10) '{' char(10)];
else
	funstr = ['static void ' prefix funid '(' prec ' a[' num2str(n) '], ' prec ' out[' num2str(n) '])' char(10) '{' char(10)];
end

if gendata.loopunrolling == 1
    for i=0:(n-1)
        funstr = [funstr char(10) '    out[' num2str(i) '] = -a[' num2str(i) '];'];
        output.stat.mult = output.stat.mult + 1;
    end
else

% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n) ';i++)'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    out[i] = -a[i];'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

output.stat.mult = n;
end
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end

