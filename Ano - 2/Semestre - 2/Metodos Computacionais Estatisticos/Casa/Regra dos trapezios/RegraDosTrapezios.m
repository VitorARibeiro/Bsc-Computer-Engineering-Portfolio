function [Resultado,Erro] = RegraDosTrapezios(a,b,n)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
h = (b-a) / n ;

x = a+h:h:b-h;


Area = (h/2) * ( Func(a) + 2*sum(Func(x)) + Func(b) )

M = MaxFuncDD();
Erro = (h^2 / 12) * (b-a) * M; 
Resultado = Area + Erro;
end

