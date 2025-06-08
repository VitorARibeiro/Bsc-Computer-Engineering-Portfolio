%Saber % dos y = cos(x) que sao superiores a 0.8 onde x de 0 a 10

x = linspace(0,2*pi,1000);
y = cos(x);

ResultArr = y > 0;
CasosFavoraveis = sum(ResultArr);

Prob = CasosFavoraveis/ length(y);

Prob %#ok<NOPTS>
