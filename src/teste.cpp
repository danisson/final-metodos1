#include "funções/funcoesReais.h"
#include <iostream>
#include <memory>

using namespace tnw::op;

int main(int argc, char const *argv[])
{
	double p0=4;
	auto f = sub(makeFun(tnw::Exponencial(p0)),makeFun(tnw::Polinomio({0,0,4})));

	std::cout << f->eval(1) << std::endl;

	return 0;
}