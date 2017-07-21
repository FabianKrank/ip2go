function [ ] = test_run()
%% Problem beschreiben
clear mex;
do_generate=1;
pname='mpc123';

addpath(genpath(fullfile(pwd,'..','..')));

problemdata = [];
load(fullfile(pwd,'..','..','structures','matrix_structures_modus3.mat'));
problemdata = matrix_structure;

%% Dimensionen
% Diskretisierungsschritte
problemdata.dim.K           = numel(problemdata.Hxx)-1;
% % Zustände
% problemdata.dim.n_x         = size(problemdata.Hxx{1},1);
% % Eingänge
% problemdata.dim.n_u         = size(problemdata.Huu{1},1);
% % UGNBs und Schlupf
% problemdata.dim.n_c         = cellfun( @(x) size(x,1), problemdata.g );
% problemdata.dim.n_s         = cellfun( @(x) size(x,1), problemdata.Hss );


%% Anfangswert
problemdata.xinit= zeros(6,1);

%% Generieren des Problems
if 1==do_generate
    [struct_in] = generate_default( problemdata,pname );
end

%% Ausführen
addpath('.\Code')
tic
% output_c=eval([pname,'_wrap(problemdata);']);
output_c = feval([pname,'_wrap'],problemdata);
toc
rmpath('.\Code')
%% Ergebnisse plotten
x=output_c.x;
u=output_c.u;
t=0:problemdata.dim.K;
figure(100); clf;
% subplot(3,1,1)
% h = plot(t+1, x(9,:));
% set(h(end), 'LineWidth', 2)
% grid on
% hold on;
% plot([t(1),t(end)]+1,[x0(end) x0(end)],'r')
% xlabel('Zeit [s]')
% ylabel('Population Erwachsene Bäume')
% title('Thrinax radiata')
% y = @(x) x+c;
% subplot(2,1,1)
% h = plot(t(:), y(x).');
% set(h(end), 'LineWidth', 2)
% grid on
% xlabel('Zeit [s]')
% ylabel('Temperature derivation x')
% 
subplot(2,1,1)
plot(t(:),x.');

subplot(2,1,2)
stairs(t(:), u.', 'LineWidth', 2)
grid on
xlabel('Time [s]')
end
% 
% for i=1:numel(output_c.Hxx)
%    
%     output_c.u{i}
%     
% end
