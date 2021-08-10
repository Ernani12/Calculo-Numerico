// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 06 – 27/05/2020
// 2017019950 Ernani Batista Serafim
// Interpolacao  Newton mostra polinomio p(x)  a0 a1....
#include <bits/stdc++.h> 
using namespace std; 
  
// funcao que calcula termos
float proterm(int i, float value, float x[]) 
{ 
    float pro = 1; 
    for (int j = 0; j < i; j++) { 
        pro = pro * (value - x[j]); 
    } 
    return pro; 
} 
  
// Funcao
// tabela ODD
void dividedDiffTable(float x[], float y[][10], int n) 
{ 
    for (int i = 1; i < n; i++) { 
        for (int j = 0; j < n - i; j++) { 
            y[j][i] = (y[j][i - 1] - y[j + 1] 
                         [i - 1]) / (x[j] - x[i + j]); 
        } 
    } 
} 
  
// Aplicacao
// Aplicando diferença dividida
float applyFormula(float value, float x[], 
                   float y[][10], int n) 
{ 
    float sum = y[0][0]; 
  
    for (int i = 1; i < n; i++) { 
      sum = sum + (proterm(i, value, x) * y[0][i]); 
    } 
    return sum; 
} 
  
 
// mostrando tabela
void printDiffTable(float y[][10],int n) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n - i; j++) { 
            cout << setprecision(4) <<  
                                 y[i][j] << "\t "; 
        } 
        cout << "\n"; 
    } 
} 
  
// main
int main() 
{ 
    // nuemro de pontos
    int n = 4; 
    float value, sum, y[10][10]; 
    float x[] = { 5, 6, 9, 11 }; 
  
    // y[][] y  valores
    // minha tabela y y[][0] 
    y[0][0] = 12; 
    y[1][0] = 13; 
    y[2][0] = 14; 
    y[3][0] = 16; 
  
    // calcula ODD
    dividedDiffTable(x, y, n); 
  
    // mostrar tabela
    printDiffTable(y,n); 
  
    // Valor a ser interpolado 
    value = 7; 
  
    // mostrando valores
    cout << "\nValue at " << value << " is "
               << applyFormula(value, x, y, n) << endl; 
    return 0; 
} 