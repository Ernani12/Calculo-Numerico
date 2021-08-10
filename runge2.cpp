// C program to implement Runge 
// Kutta method 
// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 11 – EP11 – 09/07/2020
// 2017019950 – Ernani Batista Serafim
// Resolução de equações diferenciais pelo método de Runge 2 ordem
  
// C program to implement Runge 
// Kutta method 
  
#include <stdio.h> 
#include <conio.h>
#include <math.h>//necessária para usar as funções matemáticas
  
// A sample differential equation 
// "dy/dx = (x - y)/2" 


float f(float x, float y) 
{ 
    return (cos(x)+ 1); 
} 
  
// Finds value of y for a given x 
// using step size h 
// and initial value y0 at x0. 
float rungeKutta(float x0, float y0, 
                 float x, float h) 
{ 
    // Count number of iterations 
    // using step size or 
    // step height h 
    int n = (int)((x - x0) / h); 
  
    float k1, k2; 
  
    // Iterate for number of iterations 
    float y = y0; 
    for (int i = 1; i <= n; i++) { 
        // Apply Runge Kutta Formulas 
        // to find next value of y 
        k1 = h * f(x0, y); 
        k2 = h * f(x0 + 0.5 * h, 
                      y + 0.5 * k1); 
  
        // Update next value of y 
        y = y + h/2*( f(x0,y0) +f(x0+h, y0+h*(x0,y0))); 
  
     printf ("y %i  ", i);
     printf ("y(x)= %f  \n", y);


        // Update next value of x 
        x0 = x0 + h; 
    } 
  
    return y; 
} 
  
// Driver Code 
int main() 
{ 
    float x0 = 0, y = -1, 
          x = 2, h = 0.2; 
  
    printf("y(x) = %f", 
           rungeKutta(x0, y, x, h)); 
    return 0; 
} 