function [Resultado,It] = MetNewtonErro(x0,Tol)
%METNEWTONERRO Summary of this function goes here
%   Detailed explanation goes here
Erro = Tol +1;
It = 0;
while Erro > Tol
    It = It +1;
    x = x0 - Fx(x0)/DFx(x0);
    Erro = abs(x-x0);
    fprintf("It %i, x = %f , Erro = %f \n",It,x,Erro);
    x0 = x;
end
Resultado = x;
end

