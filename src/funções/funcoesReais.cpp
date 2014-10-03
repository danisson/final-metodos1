#include "funcoesReais.h"
#include <iostream>
#include <cmath>
#include <limits>
using namespace tnw;

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
std::string FuncaoExistente::toString() const {
	return "( "+nome+"(x)"+" )";
}
FuncaoExistente::~FuncaoExistente(){};


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
			// f[x]^(-1 + g[x]) (g[x] f'[x] + f[x] Log[f[x]] g'[x])
			return std::pow(e->eval(x),-1+d->eval(x)) *
			       ((d->eval(x) * e->evalDerivada(x)) +
			       	(e->eval(x) * std::log(e->eval(x)) * d->evalDerivada(x)));
		default:
			return 0;
	}
}

std::string FuncoesReais::toString() const{
	std::string out = "( ";
	out += e->toString()+" ";
	out += op;
	out += " "+d->toString();
	out += " )";

	return out;
}

// Construtor

FuncoesReais::FuncoesReais(char op,const FuncaoRealP& f,const FuncaoRealP& g){
	this->op = op;
	this->e = f;
	this->d = g;
}


// Operadores Sobrecarregados

FuncaoRealP tnw::op::compose(const FuncaoRealP& f, const FuncaoRealP& g){
	return newFun(FuncoesReais('o',f,g));
}

FuncaoRealP tnw::op::operator+(const FuncaoRealP& f, const FuncaoRealP& g){
	return newFun(FuncoesReais('+',f,g));
}
FuncaoRealP tnw::op::operator-(const FuncaoRealP& f, const FuncaoRealP& g){
	return newFun(FuncoesReais('-',f,g));
}
FuncaoRealP tnw::op::operator*(const FuncaoRealP& f, const FuncaoRealP& g){
	return newFun(FuncoesReais('*',f,g));
}
FuncaoRealP tnw::op::operator/(const FuncaoRealP& f, const FuncaoRealP& g){
	return newFun(FuncoesReais('/',f,g));
}
FuncaoRealP tnw::op::pow(const FuncaoRealP& f, const FuncaoRealP& g) {
	return newFun(FuncoesReais('^',f,g));
}

FuncaoRealP tnw::op::operator+(const FuncaoRealP& f, double v){
	return newFun(FuncoesReais('+',f,newFun(FuncaoConstante(v))));
}
FuncaoRealP tnw::op::operator-(const FuncaoRealP& f, double v){
	return newFun(FuncoesReais('-',f,newFun(FuncaoConstante(v))));
}
FuncaoRealP tnw::op::operator*(const FuncaoRealP& f, double v){
	return newFun(FuncoesReais('*',f,newFun(FuncaoConstante(v))));
}

FuncaoRealP tnw::op::operator/(const FuncaoRealP& f, double v){
	return newFun(FuncoesReais('/',f,newFun(FuncaoConstante(v))));
}
FuncaoRealP tnw::op::pow(const FuncaoRealP& f, double v) {
	return newFun(FuncoesReais('^',f,newFun(FuncaoConstante(v))));
}

FuncaoRealP tnw::op::operator+(double v, const FuncaoRealP& g){
	return newFun(FuncoesReais('+',newFun(FuncaoConstante(v)),g));
}
FuncaoRealP tnw::op::operator-(double v, const FuncaoRealP& g){
	return newFun(FuncoesReais('-',newFun(FuncaoConstante(v)),g));
}
FuncaoRealP tnw::op::operator*(double v, const FuncaoRealP& g){
	return newFun(FuncoesReais('*',newFun(FuncaoConstante(v)),g));
}
FuncaoRealP tnw::op::operator/(double v, const FuncaoRealP& g){
	return newFun(FuncoesReais('/',newFun(FuncaoConstante(v)),g));
}
FuncaoRealP tnw::op::pow(double v, const FuncaoRealP& g){
	return newFun(FuncoesReais('^',newFun(FuncaoConstante(v)),g));
}
// Destrutor

FuncoesReais::~FuncoesReais(){};