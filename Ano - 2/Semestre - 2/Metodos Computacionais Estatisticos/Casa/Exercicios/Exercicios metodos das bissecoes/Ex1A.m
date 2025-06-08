%% x = exp(-x)

x = linspace(-1,1);
y = x;
y2 = exp(-x) -x;
figure(1);
plot(x,y,x,y2);