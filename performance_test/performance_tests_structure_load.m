function [ptests] = performance_tests_structure_load()

ptests =cell(0);


%% Test Data
ptest = struct();

ptest.name = 'structure_mult_fx0_v';
ptest.runs = 1000000;
ptest.iterations = 3;

% Zu testende Funktion
ptest.testline{1} = 'addf(''mv'',nx,nx, ''fx0'',''x0'',''dx0'',get_sbyname(''fx'',0),get_sbyname(''full_vector_nx''))';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{1} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'structure_mult_fx0T_v';
ptest.runs = 1000000;
ptest.iterations = 3;

% Zu testende Funktion
ptest.testline{1} = 'addf(''mtv'',nx,nx, ''fx0'', ''x0'', ''dx0'',get_sbyname(''fx'',0),get_sbyname(''full_vector_nx''))';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{2} = ptest;

%% Test Data
ptest = struct();

ptest.name = 'structure_mult_vT_fx0';
ptest.runs = 1000000;
ptest.iterations = 3;

% Zu testende Funktion
ptest.testline{1} = 'addf(''vtm'',nx,nx, ''x0'', ''fx0'', ''dx0'',get_sbyname(''full_vector_nx''),get_sbyname(''fx'',0))';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{3} = ptest;


%% Test Data
ptest = struct();

ptest.name = 'structure_mult_m_fx0';
ptest.runs = 1000000;
ptest.iterations = 3;

% Zu testende Funktion
ptest.testline{1} = 'addf(''mm'',nx,nx,nx, ''Hxx0'',''fx0'',''Gxx0'',get_sbyname(''full_matrix_nx_nx''),get_sbyname(''fx'',0))';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{4} = ptest;


%% Test Data
ptest = struct();

ptest.name = 'structure_mult_fx0T_m';
ptest.runs = 1000000;
ptest.iterations = 3;

% Zu testende Funktion
ptest.testline{1} = 'addf(''mtm'',nx,nx,nx, ''fx0'',''Hxx0'',''Gxx0'',get_sbyname(''fx'',0),get_sbyname(''full_matrix_nx_nx''))';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{5} = ptest;




end