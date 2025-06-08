close all;
clear all;

% Variáveis do programa
It = 3000;    % Número máximo de iterações
ItInternas = 10;
StepMax = 0.02;      % Passo máximo
Temp = 1000.0;          % Temperatura inicial
TempDecay = 0.99;    % Taxa de decaimento da temperatura

% Inicialização para guardar todos os pontos percorridos
todos_pontos = zeros(2, It*ItInternas);
Probabilidade = zeros(1, It*ItInternas);
DeltaEnergia = zeros(1, It*ItInternas);
contador = 1;

% Variáveis para armazenar o maior ponto encontrado
maiorX = 0;
maiorY = -Inf;

% Função e dados para o gráfico
f = @(x) 4 * (sin(5 * pi * x + 0.5)).^6 .* exp(log2((x - 0.8).^2));
x = linspace(0, 1.6, 200);
y = f(x);

% Criar figura com subplots para exibir todos os gráficos lado a lado
figure;

% Subplot 1: Plot da função e pontos percorridos
subplot(3,1 , 1); % 1 row, 3 columns, position 1
plot(x, y, 'b');
hold on;
title('Simulated Annealing - Pontos Percorridos');
xlabel('x');
ylabel('f(x)');

% Ponto inicial aleatório
xProbe = rand * 1.6;

for i = 1:It
    for j = 1:ItInternas
        % Calcular f(x) no ponto atual
        currentValue = f(xProbe);
    
        % Armazenar o ponto atual na matriz de todos os pontos percorridos
        todos_pontos(1, contador) = xProbe;
        todos_pontos(2, contador) = currentValue;
        contador = contador + 1;
    
        % Atualizar o maior ponto encontrado
        if currentValue > maiorY
            maiorX = xProbe;
            maiorY = currentValue;
        end
    
        % Passo aleatório para a direita e esquerda
        xStep = (rand * 2 - 1) * StepMax;
        xNew = xProbe + xStep;
    
        % Garantir que xNew está dentro do intervalo [0, 1.6]
        xNew = max(0, min(1.6, xNew));
    
        % Calcular f(x) no novo ponto e a diferença de energia
        newValue = f(xNew);
        deltaE = newValue - currentValue;
        Probabilidade(contador) = exp(-abs(deltaE)/ Temp ); %Adicionar a vetor
        DeltaEnergia(contador) = deltaE; %% adicionar a Vetor

        % Aceitar novo ponto com base na temperatura
        if deltaE > 0 || (exp(deltaE / Temp) > rand)
            xProbe = xNew; % Mover para o novo ponto
        end
    end

    % Reduzir a temperatura
    Temp = Temp * TempDecay;
end

% Exibir a matriz de todos os pontos percorridos
disp('Todos os pontos percorridos:');
disp(todos_pontos(:, 1:contador-1));

% Plot dos pontos percorridos
plot(todos_pontos(1, 1:contador-1), todos_pontos(2, 1:contador-1), 'go');
% Destacar o maior ponto encontrado
plot(maiorX, maiorY, 'ro', 'MarkerSize', 8, 'LineWidth', 2);
hold off;

% Subplot 2: Evolução dos valores de Y ao longo do tempo
subplot(3, 1, 2); % 1 row, 3 columns, position 2
plot(1:contador-1, todos_pontos(2, 1:contador-1), 'b.-');
title('Evolução dos valores de Y ao longo do tempo');
xlabel('Iteração');
ylabel('f(x)');

% Subplot 3: Evolução dos valores de X ao longo do tempo
subplot(3, 1, 3); % 1 row, 3 columns, position 3
plot(1:contador-1, todos_pontos(1, 1:contador-1), 'r.-');
title('Evolução dos valores de X ao longo do tempo');
xlabel('Iteração');
ylabel('x');

figure;

% Subplot 2: Evolução dos valores de Probabilidade ao longo de tempo
subplot(2, 1, 1); % 1 row, 3 columns, position 2
plot(1:contador-1, Probabilidade(1:contador-1), 'b.-');
title('Evolução dos valores de Probabilidade ao longo do tempo');
xlabel('Iteração');
ylabel('Probabilidade');

% Subplot 3: Evolução dos valores de DeltaE ao longo do tempo
subplot(2, 1, 2); % 1 row, 3 columns, position 3
plot(1:contador-1, DeltaEnergia(1:contador-1), 'r.-');
title('Evolução dos valores de DeltaE ao longo do tempo');
xlabel('DeltaE');
ylabel('x');

