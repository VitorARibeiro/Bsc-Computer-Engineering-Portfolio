clc,clear
n = input("Quantas disciplinas? ");
Notas = zeros(1,n);
ECTS = zeros(1,n);

for i = 1:n
    Notas(1,i) = input ("Nota :");
    ECTS(1,i) = input("ECTS: ");
end

TotalECTS = sum(ECTS);
MediaPonderada = sum((Notas .*ECTS)) / TotalECTS




