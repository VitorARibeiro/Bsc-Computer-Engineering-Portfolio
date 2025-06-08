clc             % Clear screen
clear all;      % Clear all variables from workspace
close all;      % Close all figures

%------------------------------------------------------------------------
% Loading 30 cities in Portugal 
%pt_nt_sul_30;
%pt_nt_sul_20;
pt_nt;
set_id = 2;

% Input Settings
cities = swapcities_24(cities , size(cities,2));
inputcities = cities;

% Configurações do Simulated Annealing
T = 10000;        % Temperatura inicial
T_min = 0.001;    % Temperatura mínima
alpha = 0.99;     % Taxa de resfriamento
max_iter = 10;  % Iterações máximas por temperatura

% Inicializar solução inicial
current_cities = inputcities;
best_cities = current_cities;
best_distance = distance_24(current_cities);

% Arrays para armazenar dados das iterações
temperatures = [];
distances = [];
acceptance_probs = [];
deltaE_values = [];

% Definicao do Plot
figure;
hold off
plotcities_2024(best_cities, set_id);
title('Melhor rota encontrada com Simulated Annealing');

% Algoritmo de Simulated Annealing
iter = 1; % Contador de iterações
while T > T_min
    for i = 1:max_iter
        % Gera uma nova rota trocando duas cidades
        new_cities = swapcities_24(current_cities, 2); % Troca 2 cidades aleatoriamente
        
        % Calcula a diferença de custo (distância)
        current_distance = distance_24(current_cities);
        new_distance = distance_24(new_cities);
        delta = new_distance - current_distance;
        
        % Probabilidade de aceitação
        prob = exp(-delta / T);
        
        % Armazenar dados da iteração
        temperatures(end + 1) = T;
        distances(end + 1) = best_distance;
        acceptance_probs(end + 1) = max(0, min(prob, 1)); % Garantir que esteja no intervalo [0, 1]
        deltaE_values(end + 1) = delta;
        
        % Critério de aceitação
        if delta < 0 || rand() < prob
            current_cities = new_cities;
            
            % Atualiza a melhor solução encontrada
            if new_distance < best_distance
                best_cities = new_cities;
                best_distance = new_distance;
            end
        end
        iter = iter + 1; % Incrementa o contador
    end
    
    % Resfriamento
    T = T * alpha;
end

% Resultados finais
fprintf(1, 'A melhor rota encontrada para %d cidades tem uma distância total de %4.2f Km\n', length(inputcities), best_distance);

% Plot da melhor rota encontrada
plotcities_2024(best_cities, set_id);

% Figura com evolução de métricas
figure;
subplot(2, 2, 1);
plot(temperatures);
title('Temperatura');
xlabel('Iterações');
ylabel('Temperatura');

subplot(2, 2, 2);
plot(distances);
title('Melhor Distância');
xlabel('Iterações');
ylabel('Distância');

subplot(2, 2, 3);
plot(acceptance_probs);
title('Probabilidade de Aceitação');
xlabel('Iterações');
ylabel('Probabilidade');

subplot(2, 2, 4);
plot(deltaE_values);
title('DeltaE (Variação de Distância)');
xlabel('Iterações');
ylabel('DeltaE');
