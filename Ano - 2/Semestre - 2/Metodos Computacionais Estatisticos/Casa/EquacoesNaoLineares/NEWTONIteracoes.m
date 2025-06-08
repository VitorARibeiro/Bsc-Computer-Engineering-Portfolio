function [X, erro] = NEWTONIteracoes(x0 , it)
%NEWTONITERACOES Summary of this function goes here
%   Detailed explanation goes here
n = 0;
while(n < it)
    X = x0 - Jacobiano(x0) \ Func(x0)
    n = n+1;
    erro = norm(X - x0);
    x0 = X ;
end

fprintf("numero de itecaoes = %i e erro = %f",n,erro);

end

