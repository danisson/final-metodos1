#include "funcoesReais.h"
#include <iostream>

// ------------------------  Polinomios  --------------------------------- //

// Métodos
double tnw::Polinomio::eval(double x) const{
	double bi = coeficientes[grau];
	for (int i = grau-1; i >= 0; --i)
	{
		bi = coeficientes[i] + bi * x;
	}
	return bi;
}

double tnw::Polinomio::evalDerivada(double x) const{
	double bi = coeficientes[this->grau],ci = 0;
	for (int i = this->grau-1; i >= 0; --i)
	{
		ci = bi + ci * x;
		bi = coeficientes[i] + bi * x;
	}
	return ci;
}

// Construtores
tnw::Polinomio::Polinomio(std::vector<double> coeficientes) {
	grau = coeficientes.size()-1;
	this->coeficientes = coeficientes;
}

tnw::Polinomio::Polinomio(std::initializer_list<double> coeficientes) {
	grau = coeficientes.size()-1;
	this->coeficientes = std::vector<double>(coeficientes);
}

tnw::Polinomio::Polinomio(const Polinomio& p) {
	grau = p.getGrau();
	this->coeficientes = std::vector<double>(p.getCoeficientes());
}

// Getters & Setters
int tnw::Polinomio::getGrau() const {
	return this->grau;
}

const std::vector<double>& tnw::Polinomio::getCoeficientes() const{
	return this->coeficientes;
}

// Operadores Sobrecarregados 
tnw::Polinomio& tnw::Polinomio::operator=(tnw::Polinomio p) {
	this->grau = p.grau;
	this->coeficientes = std::vector<double>(p.getCoeficientes());
	return *this;
}

std::ostream& tnw::operator<< (std::ostream& os, const tnw::Polinomio& p) {
	os << "f(x) = ";
	for (int i = 0; i <= p.getGrau(); ++i)
	{
		if(p.getCoeficientes()[i]==1){
			os << "(x^" << i << ")";
			if(i< p.getGrau()) {
				os << " + ";
			}
		}
		else if (p.getCoeficientes()[i]!=0)
		{
			os << p.getCoeficientes()[i] << "*(x^" << i << ")";
			if(i< p.getGrau()) {
				os << " + ";
			}
		}
	}
	return os;
}

// Desconstrutor
tnw::Polinomio::~Polinomio() {}