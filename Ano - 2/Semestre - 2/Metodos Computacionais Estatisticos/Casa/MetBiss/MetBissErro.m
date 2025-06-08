function [Resultado,NIt] = MetBissErro(a,b,tol)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

Erro = tol + 1;
It = 1;

if(Funcao(a) * Funcao(b) > 0)
    fprintf("Nao tem zeros entre %i e %i \n",a,b);
    return;
end

while(Erro >= tol)
    Medio = (a+b)/2;
     Erro = (b-a)/2;
    if(Funcao(a) * Funcao(Medio) <= 0)
        b = Medio;
    else
        a = Medio;
    end
    fprintf("It %i, Medio = %f , Erro = %f \n",It,Medio,Erro);
    It = It +1 ;
end

Resultado = Medio;
NIt = It;

end

