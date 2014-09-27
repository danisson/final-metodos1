#include "funcoesReais.h"
#include <iostream>
using namespace tnw;

//#define makeFun(A) std::shared_ptr<tnw::FuncaoReal>(A)

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
	std::string out = ""+this->constante;
	return out;
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
			return ( e->evalDerivada(x)*d->eval(x) - e->eval(x)*d->evalDerivada(x) ) / (d->eval(x)*d->eval(x));
		case 'o':
			return e->evalDerivada(d->eval(x)) * d->evalDerivada(x);
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

FuncoesReais::FuncoesReais(char op,const FuncaoRealP& f,const FuncaoRealP& g) {
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
// Destrutor

FuncoesReais::~FuncoesReais(){};