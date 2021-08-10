/* 
  
// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 02 – 27/03/19
// 2017019950 – Ernani Batista Serafim 
//
// Calculo de raizes reais de funcoes reais – metodo x(Posicao Falsa)

 */

#include<bits/stdc++.h> 
using namespace std; 
#define MAX_ITER 1000000 
  
//eemplo  x^3 - x^2  +2  so mudar para funcaod esejada
double func(double x) 
{ 
    return x*x*x - x*x + 2; 
} 
  
// Prints root of func(x) in interval [a, b] 
void regulaFalsi(double a, double b) 
{ 
    if (func(a) * func(b) >= 0) 
    { 
        cout << "Voce nao assumeiu valor para a e b\n"; 
        return; 
    } 
  
    double c = a;  // Initialize result 
  
    for (int i=0; i < MAX_ITER; i++) 
    { 
        // Find the point that touches x axis 
        c = (a*func(b) - b*func(a))/ (func(b) - func(a)); 
  
        // Check if the above found point is root 
        if (func(c)==0) 
            break; 
  
        // Decide the side to repeat the steps 
        else if (func(c)*func(a) < 0) 
            b = c; 
        else
            a = c; 
    } 
    cout << "Valor da raiz e : " << c; 
} 
  

int main() 
{ 
    // Initial values assumed 
    double a =-200, b = 300; 
    regulaFalsi(a, b); 
    return 0; 
} 
