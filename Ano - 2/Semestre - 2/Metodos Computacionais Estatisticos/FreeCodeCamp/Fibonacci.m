%sec e fibonaci 10 primeiros

n = 10;



A = ones(1,n);
A(1,1) = 0;

for i = 3:n
    A(1,i) = A(1,i-1) + A(1,i-2);
end

x = 1:n;



plot(x,A);




