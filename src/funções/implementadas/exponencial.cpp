#include "../funcoes.h"
#include <iostream>
#include <cmath>

// ------------------------  Exponencial  -------------------------------- //

// Métodos
double tnw::Exponencial::eval(double x) const{
	return this->coeficiente * exp(x);
}

double tnw::Exponencial::evalDerivada(double x) const{
	return this->coeficiente * exp(x);
}

tnw::FuncaoRealP tnw::Exponencial::derivada() const {
	return newFun(tnw::Exponencial(coeficiente));
}

std::string tnw::Exponencial::toString() const {
	std::string aux;
	if(coeficiente==1)
		aux = "";
	else {
		aux = std::to_string(coeficiente);
		aux.erase(aux.find_last_not_of('0') + 1, std::string::npos);
		if(aux.back() == '.')
			aux.pop_back();
		aux += "*";
	}
	return aux + "e^x";
}

// Construtores
tnw::Exponencial::Exponencial(double coeficiente) {
	this->coeficiente = coeficiente;
}

tnw::Exponencial::Exponencial() {
	this->coeficiente = 1;
}

// Getters & Setters
double tnw::Exponencial::getCoeficiente() const {
	return this->coeficiente;
}

// Desconstrutor
tnw::Exponencial::~Exponencial() {}