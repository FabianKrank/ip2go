function output = gen_mm(n,m,p,s1,s2)
% Generiert Code für eine Matrix Matrix Multiplikation
% Matrix A: n x m
% Matrix B: m x p
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

funstr = [];

output.stat = gen_stat_default_struct;

if gendata.use_structures
    if nargin == 3
        function_uses_structures = 0;
    elseif nargin == 5
        function_uses_structures = 1;
    else
        error('gen_mm: Ungültige Anzahl an Argumenten')
    end
else
    function_uses_structures = 0;
    if nargin ~= 3
        error('gen_mm: Ungültige Anzahl an Argumenten')
    end
end

if function_uses_structures
    funid = ['mm_sid' num2str(s1.sid) '_sid' num2str(s2.sid) '_' num2str(n) '_' num2str(m) '_' num2str(p)];
else
    funid = ['mm_' num2str(n) '_' num2str(m) '_' num2str(p)];
end

% Funktion-Kopf
% if function_uses_structures
%     % funstr = ['static void ' prefix 'mm_sid' num2str(s1.sid) '_sid' num2str(s2.sid) '_' num2str(n) '_' num2str(m) '_' num2str(p) '(' prec ' *A, ' prec ' *B, ' prec ' *out)' char(10) '{' char(10)];
%     funstr = ['static void ' prefix 'mm_sid' num2str(s1.sid) '_sid' num2str(s2.sid) '_' num2str(n) '_' num2str(m) '_' num2str(p) '(' prec ' *restrict A, ' prec ' *restrict B, ' prec ' *restrict out)' char(10) '{' char(10)];
% else
%     funstr = ['static void ' prefix 'mm_' num2str(n) '_' num2str(m) '_' num2str(p) '(' prec ' *A, ' prec ' *B, ' prec ' *out)' char(10) '{' char(10)];
% end

funstr = ['static void ' prefix funid '(' prec ' *A, ' prec ' *B, ' prec ' *out)' char(10) '{' char(10)];

if gendata.loopunrolling == 1
    if function_uses_structures
        for j=0:(m-1) % for k=0:(p-1)
            for k=0:(p-1) % for i=0:(n-1)
                for i=0:(n-1) % for j=0:(m-1)
                    if s1.mask(i+1,j+1) && s2.mask(j+1,k+1)
%                     if s1.mask(j+1,k+1) && s2.mask(k+1,i+1)
                        funstr = [funstr char(10) 'out[' num2str(i+n*k) '] += A[' num2str(i+n*j) '] * B[' num2str(j+m*k) '];'];
%                         funstr = [funstr char(10) 'out[' num2str(j+n*i) '] += A[' num2str(j+n*k) '] * B[' num2str(k+m*i) '];'];
                        output.stat.multadd = output.stat.multadd + 1;
                    end
                end
            end
        end
    else
        for j=0:(m-1) % for k=0:(p-1)
            for k=0:(p-1) % for i=0:(n-1)
                for i=0:(n-1) % for j=0:(m-1)
                    funstr = [funstr char(10) 'out[' num2str(i+n*k) '] += A[' num2str(i+n*j) '] * B[' num2str(j+m*k) '];'];
%                     funstr = [funstr char(10) 'out[' num2str(j+n*i) '] += A[' num2str(j+n*k) '] * B[' num2str(k+m*i) '];'];
                    output.stat.multadd = output.stat.multadd + 1;
                end
            end
        end
    end
else
    % Variablen-Deklaration
    funstr = [funstr '  int i,j,k;' char(10)];
    
    %Erste Schleife
    funstr = [funstr char(10) '  for(k=0;k<' num2str(p) ';k++)'];
    funstr = [funstr char(10) '  {'];
    %Zweite Schleife
    funstr = [funstr char(10) '    for(i=0;i<' num2str(n) ';i++)'];
    funstr = [funstr char(10) '    {'];
    %funstr = [funstr char(10) '      out[i + ' num2str(n) '*k]=0;'];
    %Dritte Schleife
    funstr = [funstr char(10) '      for(j=0;j<' num2str(m) ';j++)'];
    funstr = [funstr char(10) '      {'];
    %Multiplikation
    funstr = [funstr char(10) '        out[i + ' num2str(n) '*k] += A[i + '  num2str(n) '*j] * B[j + ' num2str(m) '*k];'];
    %Ende Schleife 3
    funstr = [funstr char(10) '      }'];
    %Ende Schleife 2
    funstr = [funstr char(10) '    }'];
    %Ende Schleife 1
    funstr = [funstr char(10) '  }'];
    
    output.stat.multadd = n*m*p;
end



%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;

end

