function [] = gen_wrap(wrap_version)
% Diese Funktion generiert den C-Code für ein Matlab-Interface für einen
% mit gen_lqdocpip generierten Solver.
% 
% Zu beachten:
%   - Diese Funktion muss nach dem Generieren des Solver-Quellcodes durch
%   gen_lqdocpip aufgerufen werden, da die Daten aus der globalen
%   Variablen "gendata" benötigt werden.
%   - Beim Benutzen muss das an das Interface übergebene Struct folgende
%   Felder besitzen:
%      - Hxx, Hxu, Huu, Hss,
%      - f0x, f0u, f0s,
%      - fx, fu, f,
%      - gx, gu, g,
%      - xinit (= x0, Startzustand)
%   Fehlt eines dieser Felder (oder die Dimension entspricht nicht dem bei
%   der Erstellung des Quellcodes angegeben Werts), stürzt MATLAB ab;
%   entsprechende Sicherungsfunktionen sind geplant aber momentan noch
%   nicht enthalten.
% ---------------------------------------
%
% Programmiert 2014-2016 von Fabian Krank
% Kontakt: fabian.krank@googlemail.com
%

% #############
% # Changelog #
% #############
%
% 22.11.16 (Mayer):
%   - Übergabe Index für wrap_version
%     wrap_version==0 default
%     wrap_version==1 weniger Optimierungsvariablen als Ausgang für Probleme mit hoher Dimension
%     anstelle von (x, u, s, p, y, nu, yny) nur (x,u)

global gendata
global genstr


if isempty(gendata)
    error('Erst Codegenerator für Solver ausführen!');
end

if nargin<1
   wrap_version=0; 
end

nx = gendata.dim.n_x;
nu = gendata.dim.n_u;
n_c = gendata.dim.n_c;
n_s = gendata.dim.n_s;
max_iter = gendata.parameter.max_iter;

%% Generierung Daten für Input - Ouput
% Gütefunktion
cat     = {'J'   'J'   'J'   'J'   'J'   'J'   'J'   };
varname = {'Hxx' 'Hxu' 'Huu' 'Hss' 'f0x' 'f0u' 'f0s' };
dim1    = {nx    nx    nu    n_s    nx    nu    n_s    };
dim2    = {nx    nu    nu    n_s    1     1     1     };

Jvars = {};
for i=1:length(cat)
    Jvars{i}.cat     = cat{i};
    Jvars{i}.name    = varname{i};
    Jvars{i}.dim1    = dim1{i};
    Jvars{i}.dim2    = dim2{i};
end

% Gleichungenebenbedingungen
cat     = {'eq' 'eq' 'eq'};
varname = {'fx' 'fu' 'f' };
dim1    = {nx   nx   nx  };
dim2    = {nx   nu   1   };

eqvars = {};
for i=1:length(cat)
    eqvars{i}.cat     = cat{i};
    eqvars{i}.name    = varname{i};
    eqvars{i}.dim1    = dim1{i};
    eqvars{i}.dim2    = dim2{i};
end

% Ungleichungsnebenbedingungen
cat     = {'ineq' 'ineq' 'ineq'};
varname = {'gx'   'gu'   'g'   };
dim1    = {n_c     n_c     n_c    };
dim2    = {nx     nu     1     };

ineqvars = {};
for i=1:length(cat)
    ineqvars{i}.cat     = cat{i};
    ineqvars{i}.name    = varname{i};
    ineqvars{i}.dim1    = dim1{i};
    ineqvars{i}.dim2    = dim2{i};
end


var_in = {Jvars{1:end} eqvars{1:end} ineqvars{1:end}};

%% Quellcodegenerierung
varinstr = gen_wrap_var_in(var_in);

end