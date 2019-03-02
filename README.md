# Regula_falsi
Numerical Analysis Regula Falsi Method

A Dev-C++ Project.

First we must initialize 2 variables for x_1 and x_2.Than we will use tangent equations for calculate a x_new.
We're going to find this equation thanks to triangle equation.
x_new = (x_1*F(x_2)-x_2*F(x_1))/F(x_2)-F(x_1)

After that, we will check the function values(F(x_1) and F(x_2)) . İf multiplication of values is negative,we must check this numarical range. But else we must stop the program because this case we can't find the root of function. 

#1) Control F(x_1)*F(x_2)

#2)İf multiplication of values is negative --> x_new = (x_1*F(x_2)-x_2*F(x_1))/F(x_2)-F(x_1) Generate new X value.

#3)Control F(x_1)*F(x_new) -->>İf that's negative we will equate x_2 to x_new . Else go to 4

#4)Control F(x_2)*F(x_new) -->>İf that's negative we will equate x_1 to x_new .

#5)While F(x_1)*F(x_2)<0 we will loop this sections.

#6)İf function's difference is smaller than Epsilon or (x_1-x_2) smaller than Epsilon we will stop.
