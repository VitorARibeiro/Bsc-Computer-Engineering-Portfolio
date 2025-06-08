x=[88.6,93.3,84.3,80.6,75.2,69.7,82,69.4,83.3,79.6,82.6,80.6,83.5,76.3];
y=[20,19.8,18.4,17.1,15.5,14.7,17.1,15.4,16.3,15,17.2,16,17,14.4];

plot(x,y,"rx","MarkerSize",8)
xlabel("Intensidade do canto dos grilos")
ylabel("Temperatura")
hold on;

A=[sum(x.^2),sum(x);sum(x),length(x)];
B = [sum(y.*x) ; sum(y)];
sol = A\B
erro=sqrt(sum((y-(sol(1).*x+sol(2))).^2))

reta = @(x) sol(1)*x + sol(2);
plot(x,reta(x),"b","MarkerSize",8)






