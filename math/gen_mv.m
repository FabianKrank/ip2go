function output = gen_mv(n,m,s1,s2)
% Generiert Code f�r eine Matrix Vektor Multiplikation
% Matrix A: n x m
% Vector B: m x 1
global gendata
prec = gendata.prec;
prefix = gendata.prefix;
pointer=gendata.math_arg_use_pointer;

funstr = [];

output.stat = gen_stat_default_struct;

if gendata.use_structures
    if nargin == 2
        function_uses_structures = 0;
    elseif nargin == 4
        function_uses_structures = 1;
    else
        error('gen_mv: Ung�ltige Anzahl an Argumenten')
    end
else
    function_uses_structures = 0;
    if nargin ~= 2
        error('gen_mv: Ung�ltige Anzahl an Argumenten')
    end
end

if function_uses_structures
    funid = ['mv_sid' num2str(s1.sid) '_sid' num2str(s2.sid) '_' num2str(n) '_' num2str(m)];
else
    funid = ['mv_' num2str(n) '_' num2str(m)];
end

% Funktion-Kopf
if pointer
    funstr = ['static void ' prefix funid '(' prec ' *A, ' prec ' *b, ' prec ' *out)' char(10) '{' char(10)];
else
    funstr = ['static void ' prefix funid '(' prec ' A[' num2str(n*m) '], ' prec ' b[' num2str(m) '], ' prec ' out[' num2str(n) '])' char(10) '{' char(10)];
end
if gendata.loopunrolling == 1
    if function_uses_structures
        for i=0:(m-1)
            for j = 0:(n-1)
                if s1.mask(j+1,i+1) && s2.mask(i+1)
                    funstr = [funstr char(10) ...
                        '  out[' num2str(j) '] += A[' num2str(j+n*i) ...
                        '] * b[' num2str(i) '];'];
                    output.stat.multadd = output.stat.multadd + 1;
                end
            end
        end
    else
        for i=0:(m-1)
            for j = 0:(n-1)
                funstr = [funstr char(10) ...
                    '      out[' num2str(j) '] += A[' num2str(j+n*i) ...
                    '] * b[' num2str(i) '];'];
                output.stat.multadd = output.stat.multadd + 1;
            end
        end
    end
else
    % Variablen-Deklaration
    funstr = [funstr '  int i,j;' char(10)];
    
    % %Erste Schleife
    % funstr = [funstr char(10) '  for(i=0;i<' num2str(n) ';i++)'];
    % funstr = [funstr char(10) '  {'];
    % %funstr = [funstr char(10) '    out[i]=0;'];
    % %Zweite Schleife
    % funstr = [funstr char(10) '    for(j=0;j<' num2str(m) ';j++)'];
    % funstr = [funstr char(10) '    {'];
    % %Multiplikation
    % funstr = [funstr char(10) '      out[i] += A[i + '  num2str(n) '*j] * b[j];'];
    % %Ende Schleife 2
    % funstr = [funstr char(10) '    }'];
    % %Ende Schleife 1
    % funstr = [funstr char(10) '  }'];
    
    %Erste Schleife
    funstr = [funstr char(10) '  for(i=0;i<' num2str(m) ';i++)'];
    funstr = [funstr char(10) '  {'];
    %funstr = [funstr char(10) '    out[i]=0;'];
    %Zweite Schleife
    funstr = [funstr char(10) '    for(j=0;j<' num2str(n) ';j++)'];
    funstr = [funstr char(10) '    {'];
    %Multiplikation
    funstr = [funstr char(10) '      out[j] += A[j + '  num2str(n) '*i] * b[i];'];
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

% Statistik Output (Output wird nun struct mit Feldern f�r Code und Statistik)
output.str = funstr;
output.stat.funid = funid;

end

