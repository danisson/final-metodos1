#include "../funcoes.h"
#include <iostream>
#include <cmath>
#include <limits>
using namespace tnw;
using namespace tnw::op;

// ------------------------  Funções Existentes -------------------------- //

FuncaoExistente::FuncaoExistente(funcaoReal f,std::string name) {
	this->f = f;
	this->nome = name;
}
double FuncaoExistente::eval(double x) const {
	return f(x);
}
// Derivada é cálculada numéricamente
double FuncaoExistente::evalDerivada(double x) const {
	const double epsilon = sqrt(std::numeric_limits<double>::epsilon())*x;
	return (f(x+epsilon)-f(x-epsilon))/(2*epsilon);
}

FuncaoRealP FuncaoExistente::derivada() const {
	return newFun(DerivadaNumerica(newFun(FuncaoExistente(f,nome))));
}

std::string FuncaoExistente::toString() const {
	return "("+nome+"(x)"+")";
}
FuncaoExistente::~FuncaoExistente(){};

// ------------------------  Derivada de Função -------------------------- //

DerivadaNumerica::DerivadaNumerica(FuncaoRealP f) {
	this->f = f;
}
double DerivadaNumerica::eval(double x) const {
	return f->evalDerivada(x);
}
// Derivada é cálculada numéricamente
double DerivadaNumerica::evalDerivada(double x) const {
	const double epsilon = sqrt(std::numeric_limits<double>::epsilon())*x;
	return (eval(x+epsilon)-eval(x-epsilon))/(2*epsilon);
}

FuncaoRealP DerivadaNumerica::derivada() const {
	return newFun(DerivadaNumerica(newFun(DerivadaNumerica(f))));
}

std::string DerivadaNumerica::toString() const {
	return "(d"+f->toString()+"/dx)";
}
DerivadaNumerica::~DerivadaNumerica(){};


// ------------------------  Funções Constante  -------------------------- //

FuncaoConstante::FuncaoConstante(double constante) {
	this->constante = constante;
}

double FuncaoConstante::eval(double x) const{
	return constante;
}

double FuncaoConstante::evalDerivada(double x) const{
	return 0;
}

FuncaoRealP FuncaoConstante::derivada() const {
	return newFun(FuncaoConstante(0));
}

std::string FuncaoConstante::toString() const{
	std::string aux;
	aux = std::to_string(constante);
	aux.erase(aux.find_last_not_of('0') + 1, std::string::npos);
	if(aux.back() == '.')
		aux.pop_back();
	return aux;
}

FuncaoConstante::~FuncaoConstante(){};

// ------------------------  Funções Reais  ------------------------------ //

// Métodos
double FuncoesReais::eval(double x) const{
	switch (op){
		case '+':
			return e->eval(x) + d->eval(x);
		case '-':
			return e->eval(x) - d->eval(x);
		case '*':
			return e->eval(x) * d->eval(x);
		case '/':
			return e->eval(x) / d->eval(x);
		case 'o':
			return e->eval(d->eval(x));
		case '^':
			return std::pow(e->eval(x),d->eval(x));
		default:
			return 0;
	}
}

double FuncoesReais::evalDerivada(double x) const{
	switch(op){
		case '+':
			return e->evalDerivada(x) + d->evalDerivada(x);
		case '-':
			return e->evalDerivada(x) - d->evalDerivada(x);
		case '*':
			return e->evalDerivada(x) * d->eval(x) +
				   d->evalDerivada(x) * e->eval(x);
		case '/':
			return  (e->evalDerivada(x)*d->eval(x)  -
			         e->eval(x)*d->evalDerivada(x)) /
			        (d->eval(x)*d->eval(x));
		case 'o':
			return e->evalDerivada(d->eval(x)) * d->evalDerivada(x);
		case '^':
			return std::pow(e->eval(x),-1+d->eval(x)) *
			       ((d->eval(x) * e->evalDerivada(x)) +
			       	(e->eval(x) * std::log(e->eval(x)) * d->evalDerivada(x)));
		default:
			return 0;
	}
}

FuncaoRealP FuncoesReais::derivada() const{
	switch(op){
		case '+':
			return e->derivada() + d->derivada();
		case '-':
			return e->derivada() - d->derivada();
		case '*':
			return e->derivada() * d +
				   d->derivada() * e;
		case '/':
			return  (e->derivada()*d  -
			         e*d->derivada()) /
			        (d*d);
		case 'o':
			return e->derivada() * d->derivada();
		case '^':
			return op::pow(e,d-1) *
			       ((d * e->derivada()) +
			       	(e * op::compose(newFun(FuncaoExistente(std::log,"log")),e)) * d->derivada());
		default:
			return 0;
	}
}

std::string FuncoesReais::toString() const{
	std::string out;
	out += "("+e->toString()+") ";
	out += op;
	out += " ("+d->toString()+")";

	return out;
}

// Construtor

FuncoesReais::FuncoesReais(char op,const FuncaoRealP& f,const FuncaoRealP& g){
	this->op = op;
	this->e = f;
	this->d = g;
}

// Destrutor

FuncoesReais::~FuncoesReais(){};