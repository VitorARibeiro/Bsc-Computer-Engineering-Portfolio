function [X,it] = NEWTONErro(x0,tol)
%NEWTON Summary of this function goes here
%   Detailed explanation goes here
erro = tol +1;
it = 0;
while( erro >= tol)
    
    X = x0 - Jacobiano(x0) \ Func(x0);
    erro  = norm((X - x0),inf);
    it = it+1;
    x0 = X;
    
end
fprintf("numero de itecaoes = %i e erro = %f",it,erro);
end

