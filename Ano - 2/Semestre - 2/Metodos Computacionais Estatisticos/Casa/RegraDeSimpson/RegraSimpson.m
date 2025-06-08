function [Erro , Resultado] = RegraSimpson(a,b,n)
%REGRASIMPSON Summary of this function goes here
%   Detailed explanation goes here
if(mod(n,2) ~= 0)
fprintf("N tem de ser numero par")
return
end

h = (b-a) / n ;

x = a:h:b;

f = Func(x); 
sumImpar = 0;
sumPar = 0;

for k = 1:length(x)/2 -1
sumImpar = sumImpar + f(2*k +1);
end

for k = 1:length(x)/2 
sumPar = sumPar + f(2*k);
end

Area = (h/3) * ( Func(a) + 2*sumImpar + 4*sumPar + Func(b) )

M = MaxFuncDDDD();
Erro = (h^4 / 180) * (b-a) * M; 
Resultado = Area + Erro;



end

