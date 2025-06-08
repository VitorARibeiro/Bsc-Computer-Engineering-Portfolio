x = [1 1.5 2 2.5];
y = [1.5 2.1 2.3 2.4];

plot(x,y,"rx","MarkerSize",8)
xlabel("x")
ylabel("y")
hold on;

%A = [sum(x.^2),sum(x) ; sum(x), length(x)]
%B = [sum(x.*y) ; sum(y)]
Y = y.^2;

sol = polyfit(x,Y,1);

a = sqrt(sol(1));
b = - (sol(2) / a.^2);
%c = sol(3);

%reta = @(x) a*exp(b*x);
reta = @(x) a*sqrt(x-b);
%reta = @(x) a*x + b;
%reta = @(x) a*x.^2 + b*x + c;

erro = sqrt(sum((y - reta(x)) .^2)   )

plot(x,reta(x),"b","MarkerSize",8)






