n_epochs=2000;
alpha = 0.9;

SSE = Zeros(1,n_epochs);

X = [0 0 1 ;
    0 1 1;
    1 0 1 ;
    1 1 1 ];
%Saida que queremos atingir
T = [ 0
    1
    1
    0 ];