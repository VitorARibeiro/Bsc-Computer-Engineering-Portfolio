close all;
clear all;

% Variáveis do programa
It = 300;           % Número máximo de iterações
StepMax = 0.02;     % Passo máximo inicial
StepMin = 0.001;    % Passo mínimo para evitar passos muito pequenos

% Inicialização da matriz para guardar todos os pontos percorridos
todos_pontos = zeros(2, It);
contador = 1;

% Variáveis para armazenar o maior ponto
maiorX = 0;
maiorY = -Inf;

% Função e dados para o gráfico
f = @(x) 4 * (sin(5 * pi * x + 0.5)).^6 .* exp(log2((x - 0.8).^2));
x = linspace(0, 1.6, 200);
y = f(x);

% Plot da função
figure;
subplot(1, 3, 1); % 1 row, 3 columns, position 2
plot(x, y, 'b');
hold on;
title('Subida de Colina (Hill Climbing) - Máximos Locais Encontrados');
xlabel('x');
ylabel('f(x)');

% Ponto inicial aleatório
xProbe = rand * 1.6;

for i = 1:It
    % Passo aleatório para direita e esquerda com passo adaptativo
    xStep = max(StepMin, rand * StepMax);
    xProbeR = xProbe + xStep;
    xProbeL = xProbe - xStep;

    % Garantir que xProbeR e xProbeL fiquem dentro do intervalo [0, 1.6]
    xProbeR = max(0, min(1.6, xProbeR));
    xProbeL = max(0, min(1.6, xProbeL));

    % Avaliar os valores de f(x) no ponto atual e nas direções direita e esquerda
    currentValue = f(xProbe);
    valueR = f(xProbeR);
    valueL = f(xProbeL);

    % Guardar o ponto atual na matriz de todos os pontos percorridos
    todos_pontos(1, contador) = xProbe;
    todos_pontos(2, contador) = currentValue;
    contador = contador + 1;

    % Determinar a direção da subida
    if (valueR > currentValue)
        xProbe = xProbeR;
    elseif (valueL > currentValue)
        xProbe = xProbeL;
    elseif (valueL == valueR)
        xProbe = xProbeR;  % Em caso de empate, move-se para a direita
    else
        % Se nenhum passo aumenta f(x), um máximo local é alcançado
        if currentValue > maiorY
            maiorX = xProbe;
            maiorY = currentValue;
        end
    end
end

% Exibir a matriz de todos os pontos percorridos
disp('Topo da Colina:');
maiorX
maiorY

% Plot de todos os pontos percorridos
plot(todos_pontos(1, 1:contador-1), todos_pontos(2, 1:contador-1), 'go');

% Destacar o maior ponto com uma cor diferente
plot(maiorX, maiorY, 'ro', 'MarkerSize', 8, 'LineWidth', 2);

hold off;

% Plot dos valores de Y (f(x)) ao longo do tempo

subplot(1, 3, 2); % 1 row, 3 columns, position 2
plot(1:contador-1, todos_pontos(2, 1:contador-1), 'b.-');
title('Evolução dos valores de Y ao longo do tempo');
xlabel('Iteração');
ylabel('f(x)');

% Plot dos valores de X ao longo do tempo
subplot(1, 3, 3); % 1 row, 3 columns, position 2
plot(1:contador-1, todos_pontos(1, 1:contador-1), 'r.-');
title('Evolução dos valores de X ao longo do tempo');
xlabel('Iteração');
ylabel('x');