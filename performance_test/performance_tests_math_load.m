function [ptests] = performance_tests_math_load()

ptests =cell(0);

%% Test Data
ptest = struct();

ptest.name = 'math_mv';
ptest.runs = 1000000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addf(''mv'',nx,nx, ''Hxx0'',''f0'',''x0'')';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{1} = ptest;


%% Test Data
ptest = struct();

ptest.name = 'math_vtm';
ptest.runs = 1000000;
ptest.iterations = 5;

% Zu testende Funktion
ptest.testline{1} = 'addf(''vtm'',nx,nx, ''f0'',''Hxx0'',''x0'')';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{2} = ptest;


%% Test Data
ptest = struct();

ptest.name = 'math_mm';
ptest.runs = 1000000;
ptest.iterations = 3;

% Zu testende Funktion
ptest.testline{1} = 'addf(''mm'',nx,nx,nx, ''Hxx0'',''Hxx1'',''Gxx0'')';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{3} = ptest;


%% Test Data
ptest = struct();

ptest.name = 'math_mtm';
ptest.runs = 1000000;
ptest.iterations = 3;

% Zu testende Funktion
ptest.testline{1} = 'addf(''mtm'',nx,nx,nx, ''Hxx0'',''Hxx1'',''Gxx0'')';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{4} = ptest;


%% Test Data
ptest = struct();

ptest.name = 'math_norm_inf';
ptest.runs = 1000000;
ptest.iterations = 3;

% Zu testende Funktion
ptest.testline{1} = 'addf(''norm_inf'',nx,nx, ''Hxx0'',''x0'',''x0'')';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';ptest.perlines{2} = '''v_init0'',nx, ''x0''&f';
ptests{5} = ptest;


%% Test Data
ptest = struct();

ptest.name = 'math_vv_elediv';
ptest.runs = 1000000;
ptest.iterations = 3;

% Zu testende Funktion
ptest.testline{1} = 'addf(''vv_elediv'',n_c+n_s, ''y0'',''nu0'',''y1'')';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptest.prelines{2} = 'addf(''v_init1'',n_c+n_s, ''nu0'')';
ptests{6} = ptest;


%% Test Data
ptest = struct();

ptest.name = 'math_mm_reorder';
ptest.runs = 1000000;
ptest.iterations = 3;

% Zu testende Funktion
ptest.testline{1} = 'addf(''mmr'',nx,nx,nx, ''Hxx0'',''Hxx1'',''Gxx0'')';

% Vor dem Test auszuführende Zeilen
ptest.prelines = cell(0);
ptest.prelines{1} = 'addl([prefix ''glqdocpip_init();''])';
ptests{7} = ptest;

end