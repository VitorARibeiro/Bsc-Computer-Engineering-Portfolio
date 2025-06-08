function [sol,n] = MetNewt(x0,tol)
%METNEWT Summary of this function goes here
%   Detailed explanation goes here
erro = 1000;
count = 0;
while erro > tol
    x =x0-func(x0)/DFunc(x0)
    erro = abs(x-x0)/x;
    count = count +1;
    x0=x;

end
sol = x0;
n = count;
end

