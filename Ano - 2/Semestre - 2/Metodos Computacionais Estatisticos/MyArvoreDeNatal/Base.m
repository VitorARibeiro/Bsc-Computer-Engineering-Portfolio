function y = Base(x,y)
%FUNC Summary of this function goes here
%   Detailed explanation goes here

if(length(x) > 1)
    y = (Base( x(2 : length(x)) , y(2 : length(y) ) ) - Base(x(1:length(x) -1) , y(1:length(y) -1 )) )/( x(length(x)) - x(1))
    return;
end

if(length(x) == 1)
    y;
    return;
end











end

