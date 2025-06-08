function [Resultado,It] = MetPontoFixoErro(x0,Tol)
%METPONTOFIXOERRO Summary of this function goes here
%   Detailed explanation goes here
Erro = Tol + 1;
It = 0;
while Erro > Tol
It = It + 1;
x = Gx(x0);
Erro = abs(x-x0);
x0 = x;
fprintf("It %i, x = %f , Erro = %f \n",It,x,Erro);
end
Resultado = x;
end

