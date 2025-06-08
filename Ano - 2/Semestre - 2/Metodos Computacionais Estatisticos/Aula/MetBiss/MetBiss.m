function [ymedio,erro] = MetBiss(a,b,n)

    for i = 1 : n

        if (func(a)*func(b)) <= 0
            medio = (a+b)/2;
            fprintf("Medio - %f \n",medio)
            if(func(a)*func(medio)) <= 0
                b = medio;
            else
                a = medio;
            end
        else
            disp("Nao tem zeros");
            a = 0;
            b = 0;
            break;
        end

    end
    ymedio = medio;
    erro = (b-a)/2;
    

end
