x = linspace(-1,0);

figure(1);

subplot(2,2,1)
plot(x,Fx(x))
grid on;
title("Fx");


subplot(2,2,2)
plot(x,DFx(x))
grid on;
title("DFx");

subplot(2,2,3)
plot(x,DDFx(x))
grid on;
title("DDFx");