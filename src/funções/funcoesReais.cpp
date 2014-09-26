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

FuncaoConstante::~FuncaoConstante(){};

// ------------------------  Funções Reais  ------------------------------ //

// Métodos
double FuncoesReais::eval(double x) const{
	switch (op){
		case '+':
			return e->eval(x) + d->eval(x);
		case '*':
			return e->eval(x) * d->eval(x);
		case '-':
			return e->eval(x) - d->eval(x);
		default:
			return 0;
	}
}

double FuncoesReais::evalDerivada(double x) const{
	if(op=='+')
		return e->evalDerivada(x) + d->evalDerivada(x);
	if (op=='*')
		return e->evalDerivada(x) * d->eval(x) +
		       d->evalDerivada(x) * e->eval(x);
	return 0;
}
// Construtor

FuncoesReais::FuncoesReais(char op,const FuncaoRealP& f,const FuncaoRealP& g) {
	this->op = op;
	this->e = f;
	this->d = g;
}


// Operadores Sobrecarregados
FuncaoRealP tnw::op::add(const FuncaoRealP& f, const FuncaoRealP& g){
	return makeFun(FuncoesReais('+',f,g));
}
FuncaoRealP tnw::op::sub(const FuncaoRealP& f, const FuncaoRealP& g){
	return makeFun(FuncoesReais('-',f,g));
}
FuncaoRealP tnw::op::mult(const FuncaoRealP& f, const FuncaoRealP& g){
	return makeFun(FuncoesReais('*',f,g));
}
FuncaoRealP tnw::op::add(const FuncaoRealP& f, double v){
	return makeFun(FuncoesReais('+',f,makeFun(FuncaoConstante(v))));
}
FuncaoRealP tnw::op::mult(const FuncaoRealP& f, double v){
	return makeFun(FuncoesReais('*',f,makeFun(FuncaoConstante(v))));
}
// Destrutor

FuncoesReais::~FuncoesReais(){};