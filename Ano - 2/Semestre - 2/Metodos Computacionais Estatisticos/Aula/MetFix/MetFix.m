function [sol,n] = MetFix(x,tolerancia)
%METFIX Summary of this function goes here
%   Detailed explanation goes here
erro = 1000;
count = 0;

while erro > tolerancia
erro = abs(gx(x)-x); 
x = gx(x);
count = count +1;
end

sol = x;
n = count;

end

