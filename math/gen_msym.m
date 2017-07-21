function output = gen_msym(n)
% Generiert Code für eine Matrix Transponierung
% Matrix A:   n x n
% Matrix out: n x n =0.5*(A^T+A);
global gendata
prec = gendata.prec;
prefix = gendata.prefix;

isfloat_cc=0;
if strcmp(gendata.prec,'float')
    isfloat_cc=1;
end
funstr = [];

output.stat = gen_stat_default_struct;

funid = ['msym_' num2str(n)];

% Funktion-Kopf
funstr = ['static void ' prefix funid '(' prec ' *A, ' prec ' *out)' char(10) '{' char(10)];

if gendata.loopunrolling == 1
    if isfloat_cc
        for j=0:(n-1)
            for i=(j+1):(n-1)
                funstr = [funstr char(10) '  out[' num2str(i + n*j) '] = out[' num2str(n*i + j) '] = 0.5f*( A['  num2str(n*j+i) ']+A['  num2str(j+n*i) ']);'];
                output.stat.copy = output.stat.copy + 1;
                output.stat.add = output.stat.add + 1;
                output.stat.mult = output.stat.mult + 1;
            end
        end   
    else
        for j=0:(n-1)
            for i=(j+1):(n-1)
                funstr = [funstr char(10) '  out[' num2str(i + n*j) '] = out[' num2str(n*i + j) '] = 0.5*( A['  num2str(n*j+i) ']+A['  num2str(j+n*i) ']);'];
                output.stat.copy = output.stat.copy + 1;
                output.stat.add = output.stat.add + 1;
                output.stat.mult = output.stat.mult + 1;
            end
        end        
    end
else
% Variablen-Deklaration
funstr = [funstr '  int i,j;' char(10)];

%Erste Schleife
funstr = [funstr char(10) '  for(j=0;j<' num2str(n) ';j++)'];
funstr = [funstr char(10) '  {'];
%Zweite Schleife
funstr = [funstr char(10) '    for(i=0;i<' num2str(n) ';i++)'];
funstr = [funstr char(10) '    {'];
%Transponieren und Addieren
if isfloat_cc
    funstr = [funstr char(10) '      out[i+' num2str(n) '*j] = out[j+' num2str(n) '*i] = 0.5f*( A[i+' num2str(n) '*j]+A[j+' num2str(n) '*i]);'];
else
    funstr = [funstr char(10) '      out[i+' num2str(n) '*j] = out[j+' num2str(n) '*i] = 0.5*( A[i+' num2str(n) '*j]+A[j+' num2str(n) '*i]);'];
end
%Ende Schleife 2
funstr = [funstr char(10) '    }'];
%Ende Schleife 1
funstr = [funstr char(10) '  }'];

output.stat.copy = n*n;
output.stat.add = n*n;
output.stat.mult = n*n;
end
%Return
funstr = [funstr char(10) '  return;'];
%Ende Funktion
funstr = [funstr char(10) '}'];

% Statistik Output (Output wird nun struct mit Feldern für Code und Statistik)
output.str = funstr;
output.stat.funid = funid;
end

