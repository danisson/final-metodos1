#include "funções/funcoesReais.h"
#include <iostream>
#include <memory>
#define makeFun(A) std::shared_ptr<tnw::FuncaoReal>(A)

using namespace tnw::op;

int main(int argc, char const *argv[])
{
	double p0=4;
	auto f = makeFun(sub(new tnw::Exponencial(p0),new tnw::Polinomio({0,0,4})));

	std::cout << f->eval(1) << std::endl;

	return 0;
}