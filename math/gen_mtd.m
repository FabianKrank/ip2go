function output = gen_mtd(n,m,s1,s2)
% Generiert Code für eine Matrix Matrix(diag) Multiplikation
% Matrix A:   n x m
% Matrix B:   n x n (Diagonalmatrix)
% Matrix out: m x n
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
        error('gen_mtm: Ungültige Anzahl an Argumenten')
    end
else
    function_uses_structures = 0;
    if nargin ~= 2
        error('gen_mtm: Ungültige Anzahl an Argumenten')
    end
end


% Funktion-Kopf
if function_uses_structures
    funid = ['mtd_sid' num2str(s1.sid) '_sid' num2str(s2.sid) '_' num2str(n) '_' num2str(m)];
    %funstr = ['static void ' prefix 'mtd_sid' num2str(s1.sid) '_sid' num2str(s2.sid) '_' num2str(n) '_' num2str(m) '(' prec ' *A, ' prec ' *B, ' prec ' *out)' char(10) '{' char(10)];
else
    funid = ['mtd_' num2str(n) '_' num2str(m)];
    %funstr = ['static void ' prefix 'mtd_' num2str(n) '_' num2str(m) '(' prec ' *A, ' prec ' *B, ' prec ' *out)' char(10) '{' char(10)];
end

funstr = ['static void ' prefix funid '(' prec ' *A, ' prec ' *B, ' prec ' *out)' char(10) '{' char(10)];

if gendata.loopunrolling == 1
    if function_uses_structures
        for i=0:(n-1)
            for j = 0:(m-1)
                if s1.mask(i+1,j+1) && s2.mask(i+1)
                    funstr = [funstr char(10) '      out[' num2str(j+m*i) '] += A[' num2str(i+n*j) '] * B[' num2str(i) '];'];
                    output.stat.multadd = output.stat.multadd + 1;
                end
            end
        end
    else
        for i=0:(n-1)
            for j = 0:(m-1)
                funstr = [funstr char(10) '      out[' num2str(j+m*i) '] += A[' num2str(i+n*j) '] * B[' num2str(i) '];'];
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
%Zweite Schleife
funstr = [funstr char(10) '    for(j=0;j<' num2str(m) ';j++)'];
funstr = [funstr char(10) '    {'];
%Multiplikation
funstr = [funstr char(10) '      out[j + ' num2str(m) '*i] += A[i + '  num2str(n) '*j] * B[i];'];
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

