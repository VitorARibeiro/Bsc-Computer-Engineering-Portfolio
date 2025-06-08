function [X, erro] = NEWTONIteracoes(x , it)
%NEWTONITERACOES Summary of this function goes here
%   Detailed explanation goes here
n = 0;
while(n < it)
    X = x - Jacobiano(x) \ Func(x);
    n = n+1;
    erro = norm(X - x);
    x = X ;
end

fprintf("numero de itecaoes = %i e erro = %f",n,erro);

end

