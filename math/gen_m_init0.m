function output = gen_m_init0(n,m)
% Generiert Code für eine Funktion, die alle Elemente einer Matrix zu 0
% setzt
% Matrix A:     n x m
global gendata
prec = gendata.prec;
prefix = gendata.prefix;
pointer=gendata.math_arg_use_pointer;

funstr = [];

output.stat = gen_stat_default_struct;

funid = ['m_init0_' num2str(n) '_' num2str(m)];

% Funktion-Kopf
if pointer
    funstr = ['static void ' prefix funid '(' prec ' *a)' char(10) '{' char(10)];
else
    funstr = ['static void ' prefix funid '(' prec ' a[' num2str(n*m) '])' char(10) '{' char(10)];
end
if gendata.loopunrolling == 1
    for i= 0:(n*m-1)
        funstr = [funstr char(10) '  a[' num2str(i) '] =0;'];
        output.stat.init = output.stat.init + 1;
    end
else

% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n*m) ';i++)'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    a[i] =0;'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

output.stat.init = n*m;
end
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end

