x=[88.6,93.3,84.3,80.6,75.2,69.7,82,69.4,83.3,79.6,82.6,80.6,83.5,76.3];
y=[20,19.8,18.4,17.1,15.5,14.7,17.1,15.4,16.3,15,17.2,16,17,14.4];
plot(x,y,"rx","MarkerSize",8)
xlabel("Intensidade do canto dos grilos")
ylabel("Temperatura")
% definicao da matriz A das equacoes normais
format long
n=length(x);
A=[x;ones(1,n)];
B=inv(A*(A'));
sol=B*A*y';
a=sol(1)
b=sol(2)
erro=sqrt(sum((y-(a.*x+b)).^2))
newy=a*x+b;
hold on;
plot(x,newy)
hold off;
legend("Dados", "Regressao Linear ")