x = linspace(0,1);

figure(1);

subplot(2,2,1)
plot(x,func(x));
grid on;
title("func(x)");


subplot(2,2,2)
plot(x,DFunc(x));
grid on;
title("Dfunc(x)");


subplot(2,2,3)
plot(x,DDFunc(x));
grid on;
title("DDfunc(x)");