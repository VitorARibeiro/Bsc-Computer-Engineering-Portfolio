function [Resultado,Erro] = MetNewton(x0,It)
%METNEWTON Summary of this function goes here
%   Detailed explanation goes here
for i = 1:It
x = x0 - Fx(x0)/DFx(x0);
Erro = abs(x - x0);
fprintf("It %i, x = %.7f , Erro = %f \n",i,x,Erro);
x0 = x;
end
Resultado = x;
end

