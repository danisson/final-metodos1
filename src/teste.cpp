#include "funções/funcoes.h"
#include "métodos/metodosNumericos.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <cmath>

using namespace tnw::op;

int main(int argc, char const *argv[])
{
	printf("Teste de Sanidade!\n");

	printf("Função f(x) = x²-3\n");
	tnw::FuncaoRealP f = newFun(tnw::Polinomio({-3,0,1}));
	tnw::intervalo a_b = std::make_tuple(0,2);
	tnw::intervalo inter = tnw::bissec(a_b,f,0.001);
	printf("Intervalo = %lf, %lf\n",std::get<0>(inter),std::get<1>(inter));
	printf("Newton: x = %lf em %lld passos\n\n", tnw::newton(1,f,0.001).x,tnw::newton(1,f,0.001).i);

	printf("f(1) = %lf\n", f->eval(1));
	printf("f(2) = %lf\n", f->eval(2));
	printf("f(1.7320508) = %le ~= 0\n", f->eval(1.7320508));
	printf("∫f(x) dx;[1,2] = %lf ~= -0.66667\n", f->evalIntegral(1,2));
	printf("f'(2) = %lf\n", f->evalDerivada(2));
	printf("f'(2) = %lf\n", f->derivada()->eval(2));
	printf("f'(x) = %s\n", f->derivada()->toString().c_str());
	printf("f(x) = %s\n", f->toString().c_str());

	printf("\nFunção f(x) = x²-3\n");
	f = pow(newFun(tnw::Identidade()),2)-3;

	printf("f(1) = %lf\n", f->eval(1));
	printf("f(2) = %lf\n", f->eval(2));
	printf("f(1.7320508) = %le ~= 0\n", f->eval(1.7320508));
	printf("∫f(x) dx;[1,2] = %lf ~= -0.66667\n", f->evalIntegral(1,2));
	printf("f'(2) = %lf\n", f->evalDerivada(2));
	printf("f'(2) = %lf\n", f->derivada()->eval(2));
	printf("f'(x) = %s\n", f->derivada()->toString().c_str());
	printf("f(x) = %s\n", f->toString().c_str());

	printf("\nFunção f(x) = e^(x^2)\n");
	f = compose(newFun(tnw::Exponencial()),newFun(tnw::Polinomio({0,0,1})));

	printf("f(1) = %lf ~= 2.7182\n", f->eval(1));
	printf("f(2) = %lf ~= 54.5981\n", f->eval(2));
	printf("∫f(x) dx;[1,2] = %lf ~= 14.99\n", f->evalIntegral(1,2));
	printf("f'(x) = %s\n", f->derivada()->toString().c_str());
	printf("f(x) = %s\n", f->toString().c_str());

	printf("\nFunção f(x) = e^(2x+3x^2)\n");
	f = compose(newFun(tnw::Exponencial()),newFun(tnw::Polinomio({0,2,3})));

	printf("f(0.4) = %lf ~= 3.59664\n", f->eval(0.4));
	printf("f'(0.4) = %lf ~= 15.8252\n", f->evalDerivada(0.4));
	printf("f'(x) = %s\n", f->derivada()->toString().c_str());
	printf("f(x) = %s\n", f->toString().c_str());

	printf("\nFunção f(x) = sin(x)\n");
	f = newFun(tnw::FuncaoExistente(std::sin,"sin"));

	a_b = std::make_tuple(3,4);
	inter = tnw::bissec(a_b,f,0.001);
	printf("Intervalo = %1f, %1f\n",std::get<0>(inter),std::get<1>(inter));
	printf("f(2) = %lf\n",f->eval(2));
	printf("f'(2) = %lf ~= -0.416147\n", f->evalDerivada(2));
	printf("∫f(x) dx;[0,pi] = %lf ~= 2\n", f->evalIntegral(0,3.1416));
	printf("f'(x) = %s\n", f->derivada()->toString().c_str());
	printf("f(x) = %s\n", f->toString().c_str());


	printf("\nFunção f(x) = x^3-9x+3\n");
	f = newFun(tnw::Polinomio({3,-9,0,1}));
	printf("f(0) = %lf\n", f->eval(0));

	printf("Função phi(x) = (x^3)/9+(1/3)\n");	
	tnw::FuncaoRealP phi = newFun(tnw::Polinomio({1/3.0,0,0,1/9.0}));
	printf("phi(0) = %lf\n", phi->eval(0));

	auto result = tnw::pontoFixo(0.5, phi, 0.0005);
	printf("Para f(x) = 0, temos x = %lf em %lld passos\n", result.x,result.i);
	printf("f(x) = %lf\n",f->eval(result.x));

	return 0;
}