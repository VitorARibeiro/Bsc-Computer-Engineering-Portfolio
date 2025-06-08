function [X,it] = NEWTONErro(x,tol)
%NEWTON Summary of this function goes here
%   Detailed explanation goes here
erro = tol +1;
it = 0;
while( erro >= tol)
    
    X = x - Jacobiano(x) \ Func(x);
    erro  = norm((X - x),inf);
    it = it+1;
    x = X;
    
end
end

