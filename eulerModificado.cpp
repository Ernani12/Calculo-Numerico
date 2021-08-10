
/* CPP  Program to find approximation 
   of a ordinary differential equation 
   using euler method.*/
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <iostream>
#include <math.h>       /* pow */

using namespace std; 

  
// Consider a differential equation 
// dy/dx=(x + y + xy) 
float func(float x, float y) 
{ 
    return (y*(pow(x,2))-1.1*y); 
} 
  
// Function for Euler formula 
void euler(float x0, float y, float h, float x) 
{ 
    float temp = -0; 
    float step=0.25;
  
    // Iterating till the point at which we 
    // need approximation 
    while (x0 < x) { 
        temp = y; 
        y = y + h * func(x0, y)+(pow(h,2)/2)*func(x0, y); 
        x0 = x0 + h; 
        // Printing approximation 
        cout << "Approximate solution at x = "
         <<  std::setprecision(2)<< step ;
         cout << "  is  " << std::setprecision(5)<< y << endl; 
         step+=0.25;
    } 
  
    
} 
  
// Driver program 
int main() 
{ 
    // Initial Values 
    float x0 = 0; 
    float y0 = 1; 
    float h = 0.25; 
  
    // Value of x at which we need approximation 
    float x = 1; 
  
    euler(x0, y0, h, x); 
    return 0; 
} 
