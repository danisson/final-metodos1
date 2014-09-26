#include "funcoesReais.h"
#include <iostream>
using namespace tnw;

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

FuncoesReais::FuncoesReais(char op, FuncaoReal* f, FuncaoReal* g) {
	this->op = op;
	this->e = f;
	this->d = g;
}


// Operadores Sobrecarregados
FuncaoReal* tnw::op::add(FuncaoReal* f, FuncaoReal* g){
	return new FuncoesReais('+',f,g);
}
FuncaoReal* tnw::op::sub(FuncaoReal* f, FuncaoReal* g){
	return new FuncoesReais('-',f,g);
}
FuncaoReal* tnw::op::mult(FuncaoReal* f, FuncaoReal* g){
	return new FuncoesReais('*',f,g);
}
FuncaoReal* tnw::op::add(FuncaoReal* f, double v){
	return new FuncoesReais('+',f,new FuncaoConstante(v));
}
FuncaoReal* tnw::op::mult(FuncaoReal* f, double v){
	return new FuncoesReais('*',f,new FuncaoConstante(v));
}
// Destrutor

FuncoesReais::~FuncoesReais(){
	delete e;
	delete d;
};