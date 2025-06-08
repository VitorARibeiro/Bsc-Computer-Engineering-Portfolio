function y = Func(x)
%FUNC Summary of this function goes here
%   Detailed explanation goes here
y = zeros(2,1);
y(1) = x(2) -x(1)^2 +2*x(1) -0.5;
y(2) = x(1)^2 +4*x(2)^2-4;
end

