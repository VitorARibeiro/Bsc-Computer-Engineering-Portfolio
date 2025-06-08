function [y1,y2] = MetBiss(a,b,n)
    for i = 1 : n

        if (func(a)*func(b)) < 0
            medio = a+b/2;
            if(func(a)*func(medio)) < 0
                b = medio;
            else
                a = medio;
            end
        else
            disp("Nao tem zeros");
            a = 0;
            b=0;
            break;
        end

    end

    y1 = a;
    y2 = b;

end
