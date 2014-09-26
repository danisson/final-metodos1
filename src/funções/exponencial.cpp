#include "funcoesReais.h"
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


// Operadores Sobrecarregados 
std::ostream& tnw::operator<< (std::ostream& os, const tnw::Exponencial& e) {
	os << "f(x) = "<< e.getCoeficiente() <<"*(e^x)";
	return os;
}

// Desconstrutor
tnw::Exponencial::~Exponencial() {}