#include<iostream>
#include<conio.h>

// CIC250 – Cálculo Numérico para Computação
// Exercicio Pratico 06 – 27/05/2020
// 2017019950 Ernani Batista Serafim
// Interpolacao  Lagrange   https://www.onlinegdb.com/online_c++_compiler


using namespace std;

int main()
{
	 float x[100], y[100], xp, yp=0, p;
	 int i,j,n;

	 /* Input Section */
	 cout<<"Enter number of valoes: ";
	 cin>>n;
	 cout<<"Enter valores xi e yi:"<< endl;
	 for(i=1;i<=n;i++)
	 {
		  cout<<"x["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"y["<< i<<"] = ";
		  cin>>y[i];
	 }
	 cout<<"coloque  o ponto de interpolaçao: ";
	 cin>>xp;

	 /* Implementing Lagrange Interpolation */
	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	 cout<< endl<<"Valor de interpolacao  "<< xp<< " e "<< yp;

	 return 0;
}