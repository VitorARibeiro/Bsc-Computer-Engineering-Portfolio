function [n,Resultado] = RegraDosTrapeziosErro(a,b,Tol)
%REGRADOSTRAPEZIOSERRO Summary of this function goes here
%   Detailed explanation goes here



%a + b

n = 0;
Erro  = Tol + 1;

while Erro > Tol
    n = n +1 ; 
    h = (b-a) / n ;

    M = MaxFuncDD();
    Erro = (h^2 / 12) * (b-a) * M; 


end

x = a+h:h:b-h;
Area = (h/2) * ( Func(a) + 2*sum(Func(x)) + Func(b) );

Resultado = Area + Erro;
end

