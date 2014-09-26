#include "funções/funcoesReais.h"
#include <cstdio>
#include <iostream>
#include <memory>

using namespace tnw::op;

int main(int argc, char const *argv[])
{
	printf("\nTeste de Sanidade!\n");
	printf("Função f(x) = x²-3\n");

	tnw::FuncaoRealP f = newFun(tnw::Polinomio({-3,0,1}));

	printf("f(1) = %lf\n", f->eval(1));
	printf("f(2) = %lf\n", f->eval(2));
	printf("f(1.7320508) = %le ~= 0\n", f->eval(1.7320508));

	printf("\nFunção f(x) = e^(x^2)\n");
	f = compose(newFun(tnw::Exponencial(1)),newFun(tnw::Polinomio({0,0,1})));

	printf("f(1) = %lf ~= 2.7182\n", f->eval(1));
	printf("f(2) = %lf ~= 54.5981\n", f->eval(2));

	printf("\nFunção f(x) = e^(2x+3x^2)\n");
	f = compose(newFun(tnw::Exponencial(1)),newFun(tnw::Polinomio({0,2,3})));

	printf("f(0.4) = %lf ~= 3.59664\n", f->eval(0.4));
	printf("f'(0.4) = %lf ~= 15.8252\n", f->evalDerivada(0.4));

	return 0;
}