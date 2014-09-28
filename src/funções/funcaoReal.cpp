#include "funcoesReais.h"
using namespace tnw;


// Integral numérica usando regra de Simpson com n subdivisões
double FuncaoReal::evalIntegral(double a, double b, double n) {
	const double h = (b-a)/n;
	double acc = eval(a)+eval(b);
	
	for (int i = 1; i <= n; i=i+2)
		acc+= 4 * eval(a+i*h);
	for (int i = 2; i <= n-1; i=i+2)
		acc+= 2 * eval(a+i*h);

	return (h/3)*acc;
}

double FuncaoReal::evalIntegral(double a, double b) {
	return evalIntegral(a,b,10000);
}