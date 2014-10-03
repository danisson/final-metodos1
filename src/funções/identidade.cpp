#include "funcoesReais.h"
using namespace tnw;

Identidade::Identidade(){}

double Identidade::eval(double x) const {
	return x;
}
double Identidade::evalDerivada(double x) const {
	return 1;
}

std::string Identidade::toString() const {
	return "x";
}

Identidade::~Identidade(){}