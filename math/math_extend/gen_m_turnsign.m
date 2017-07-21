function funstr = gen_m_turnsign(n,m)
% Generiert Code f�r eine Funktion, die alle Vorzeichen aller Elemente
% einer Matrix umdreht
% Matrix A:     n x m
% Matrix out:   n x m
% out = -A
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

% Beschreibung

% Funktion-Kopf
funstr = ['static void ' prefix 'm_turnsign_' num2str(n) '_' num2str(m) '(' prec ' *a, ' prec ' *out)' char(10) '{' char(10)];

% Variablen-Deklaration
funstr = [funstr '  int i;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n*m) ';i++)'];
funstr = [funstr char(10) '  {'];
%Multiplikation
funstr = [funstr char(10) '    out[i] = -a[i];'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

end

