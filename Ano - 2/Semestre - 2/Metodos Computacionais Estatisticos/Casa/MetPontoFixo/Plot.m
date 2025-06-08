x = linspace (-1,0);

figure (1);

subplot(1,2,1);
plot(x,Gx(x)); %% Tem de estar entre a e b
title("G(x)");
grid on;

subplot(1,2,2)
plot(x,DGx(x),"*"); %% tem de ser menor que 1
title("G´(x)");
grid on;

