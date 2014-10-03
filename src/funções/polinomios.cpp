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

tnw::FuncaoRealP tnw::Polinomio::derivada() const {
	std::vector<double> coeficientesD;
	for (int i = 1; i <= grau; ++i)
	{
		coeficientesD.push_back(coeficientes[i]*i);
	}
	return newFun(tnw::Polinomio(coeficientesD));
}

std::string tnw::Polinomio::toString() const {
	std::string out = "";
	std::string aux;
	if (coeficientes[0]!=0)
	{
		aux = std::to_string(coeficientes[0]);
		aux.erase(aux.find_last_not_of('0') + 1, std::string::npos);
		if(aux.back() == '.')
			aux.pop_back();
		out+= aux;
		if(0< this->getGrau())
			out += " + ";
	}

	for (int i = 1; i <= this->getGrau(); ++i)
	{
		if(this->getCoeficientes()[i]==1){
			out += "x^" + std::to_string(i);
			if(i< this->getGrau()) {
				out += " + ";
			}
		}
		else if (this->getCoeficientes()[i]!=0)
		{
			aux = std::to_string(coeficientes[i]);
			aux.erase(aux.find_last_not_of('0') + 1, std::string::npos);
			if(aux.back() == '.')
				aux.pop_back();
			out+= aux + "*x^" + std::to_string(i);
			if(i< this->getGrau())
				out += " + ";
		}
	}
	return out;
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

// Desconstrutor
tnw::Polinomio::~Polinomio() {}