clc,clear;
x = linspace(-10,10);

y = exp(x);


figure(1);
subplot(1,2,1);
xlim([-5,5]),ylim([-5,5]); %% axis([-3,3,-3,3])
grid on;
hold on;
plot(x,y,"b-");
plot(x,-y,"c-");
plot(-x,y,"g-");
plot(-x,-y,"m-");
legend("x,y","x,-y","-x,y","-x,-y")
y2 = y+2;

subplot(1,2,2)

xlim([-5,5]),ylim([-5,5]); %% axis([-3,3,-3,3])
grid on;
hold on;

plot(x,y2,"r-");
plot(x,-y2,"r-");
plot(-x,y2,"r-");
plot(-x,-y2,"r-");

legend("x,y","x,-y","-x,y","-x,-y");







