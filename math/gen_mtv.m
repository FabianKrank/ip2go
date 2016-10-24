function output = gen_mtv(n,m,s1,s2)
% Generiert Code für eine Matrix transponiert Vektor Multiplikation
% Matrix A: n x m
% Vector B: n x 1
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

output.stat = gen_stat_default_struct;

if gendata.use_structures
    if nargin == 2
        function_uses_structures = 0;
    elseif nargin == 4
        function_uses_structures = 1;
    else
        error('gen_mv: Ungültige Anzahl an Argumenten')
    end
else
    function_uses_structures = 0;
    if nargin ~= 2
        error('gen_mv: Ungültige Anzahl an Argumenten')
    end
end

if function_uses_structures
    funid = ['mtv_sid' num2str(s1.sid) '_sid' num2str(s2.sid) '_' num2str(n) '_' num2str(m)];
else
    funid = ['mtv_' num2str(n) '_' num2str(m)];
end

% Funktion-Kopf
if function_uses_structures
    funstr = ['static void ' prefix funid '(' prec ' *A, ' prec ' *b, ' prec ' *out)' char(10) '{' char(10)];
else
    funstr = ['static void ' prefix funid '(' prec ' *A, ' prec ' *b, ' prec ' *out)' char(10) '{' char(10)];
end
%funstr = ['static void ' prefix 'mtv_' num2str(n) '_' num2str(m) '(' prec ' *a, ' prec ' *b, ' prec ' *out)' char(10) '{' char(10)];

if gendata.loopunrolling == 1
    if function_uses_structures
        for i=0:(n-1)
            for j=0:(m-1)
                if s1.mask(i+1,j+1) && s2.mask(i+1)
                funstr = [funstr char(10) ...
                        '  out[' num2str(j) '] += A[' num2str(i+n*j) ...
                        '] * b[' num2str(i) '];'];
                    output.stat.multadd = output.stat.multadd + 1;
                end
            end
        end
    else
        for i=0:(n-1)
            for j=0:(m-1)
                funstr = [funstr char(10) ...
                        '  out[' num2str(j) '] += A[' num2str(i+n*j) ...
                        '] * b[' num2str(i) '];'];
                    output.stat.multadd = output.stat.multadd + 1;
            end
        end
    end
else
% Variablen-Deklaration
funstr = [funstr '  int i,j;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(i=0;i<' num2str(n) ';i++)'];
funstr = [funstr char(10) '  {'];
%funstr = [funstr char(10) '    out[i]=0;'];
%Zweite Schleife
funstr = [funstr char(10) '    for(j=0;j<' num2str(m) ';j++)'];
funstr = [funstr char(10) '    {'];
%Multiplikation
funstr = [funstr char(10) '      out[j] += A[i + '  num2str(n) '*j] * b[i];'];
%Ende Schleife 2
funstr = [funstr char(10) '    }'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

output.stat.multadd = n*m;
end

%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;

end

