// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 08– 18/06/2020
// 2017919950 – Ernani batista Serafim
// Aproximação de curvas pelo método dos mínimos quadrados Exponencial
#include<stdio.h>
#include<math.h>
#include<iostream>


using namespace std;
/*****
Function that calculates and returns the slope of the best fit line
Parameters:
N: no. of data-points
x[N]: array containing the x-axis points
y[N]: array containing the corresponding y-axis points
*****/
double slope(int N, double x[], double y[]){
    double m;
    int i;
    double sumXY=0;
    double sumX=0;
    double sumX2=0;
    double sumY=0;
    for(i=0;i<N;i++){
        sumXY=sumXY+x[i]*y[i];
        sumX=sumX+x[i];
        sumY=sumY+y[i];
        sumX2=sumX2+x[i]*x[i];
    }
    sumXY=sumXY/N;
    sumX=sumX/N;
    sumY=sumY/N;
    sumX2=sumX2/N;
    m=(sumXY-sumX*sumY)/(sumX2-sumX*sumX);
    return m;
}
/*****
Function that calculates and returns the intercept of the best fit line
Parameters:
N: no. of data-points
x[N]: array containing the x-axis points
y[N]: array containing the corresponding y-axis points
*****/
double intercept(int N, double x[], double y[]){
    double c;
    int i;
    double sumXY=0;
    double sumX=0;
    double sumX2=0;
    double sumY=0;
    for(i=0;i<N;i++){
        sumXY=sumXY+x[i]*y[i];
        sumX=sumX+x[i];
        sumY=sumY+y[i];
        sumX2=sumX2+x[i]*x[i];
    }
    sumXY=sumXY/N;
    sumX=sumX/N;
    sumY=sumY/N;
    sumX2=sumX2/N;
    c=(sumX2*sumY-sumXY*sumX)/(sumX2-sumX*sumX);
    return c;
}
main(){
    int N;
    cout<< "Enter the no. of data-points:\n";
    cin>>N;
    double x[N], y[N], Y[N];
    cout<<"Enter the x-axis values:\n";
    int i;
    for(i=0;i<N;i++){
        cin>>x[i];
    }
    cout<<"Enter the y-axis values:\n";
    for(i=0;i<N;i++){
        cin>>y[i];
    }
    for(i=0;i<N;i++){
        Y[i]=log(y[i]);
    }
    cout<<"The exponential fit is given by the equation:\n";
    double m=slope(N,x,Y);
    double c=intercept(N,x,Y);
    double A, b; //y=Ae^bx
    A=exp(c);
    b=m;
    cout<<A <<endl;
    cout<<b;
}