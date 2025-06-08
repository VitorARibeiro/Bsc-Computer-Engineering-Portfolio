function [Resultado,Erro] = MetBiss(a,b,it)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
if(Funcao(a) * Funcao(b) > 0)
    fprintf("Nao tem zeros entre %i e %i \n",a,b);
    return;
end
for i = 1:it
   
    Medio = (a+b)/2;
    Erro = (b-a)/2;
    if(Funcao(a) * Funcao(Medio) <= 0)
        b = Medio;
    else
        a = Medio;
    end
    fprintf("It %i, Medio = %f , Erro = %f \n",i,Medio,Erro);
 
end

Resultado = Medio;


end

