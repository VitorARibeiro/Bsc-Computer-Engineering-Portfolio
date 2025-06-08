function J = Jacobiano(x)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
J = zeros(2,2);
J(1,1) = -2*x(1) +2;
J(1,2) = 1;
J(2,1) = 2*x(1);
J(2,2) = 8*x(2);

end

