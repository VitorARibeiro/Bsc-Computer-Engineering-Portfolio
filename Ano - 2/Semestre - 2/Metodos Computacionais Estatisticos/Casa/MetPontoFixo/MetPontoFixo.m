function [Resultado,Erro] = MetPontoFixo(x0,it)
%METPONTOFIXO Summary of this function goes here
%   Detailed explanation goes here
for i = 1:it
    x = Gx(x0);
    Erro = abs(x-x0);
    fprintf("It %i, x = %f , Erro = %f \n",i,x,Erro);
    x0 = x;
end
    Resultado = x0;
end

