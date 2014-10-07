#include "funcoes.h"

tnw::FuncaoRealP tnw::op::compose(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g){
	return newFun(FuncoesReais('o',f,g));
}

tnw::FuncaoRealP tnw::op::operator+(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g){
	return newFun(FuncoesReais('+',f,g));
}
tnw::FuncaoRealP tnw::op::operator-(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g){
	return newFun(FuncoesReais('-',f,g));
}
tnw::FuncaoRealP tnw::op::operator*(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g){
	return newFun(FuncoesReais('*',f,g));
}
tnw::FuncaoRealP tnw::op::operator/(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g){
	return newFun(FuncoesReais('/',f,g));
}
tnw::FuncaoRealP tnw::op::pow(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g) {
	return newFun(FuncoesReais('^',f,g));
}

tnw::FuncaoRealP tnw::op::operator+(const tnw::FuncaoRealP& f, double v){
	return newFun(FuncoesReais('+',f,newFun(FuncaoConstante(v))));
}
tnw::FuncaoRealP tnw::op::operator-(const tnw::FuncaoRealP& f, double v){
	return newFun(FuncoesReais('-',f,newFun(FuncaoConstante(v))));
}
tnw::FuncaoRealP tnw::op::operator*(const tnw::FuncaoRealP& f, double v){
	return newFun(FuncoesReais('*',f,newFun(FuncaoConstante(v))));
}

tnw::FuncaoRealP tnw::op::operator/(const tnw::FuncaoRealP& f, double v){
	return newFun(FuncoesReais('/',f,newFun(FuncaoConstante(v))));
}
tnw::FuncaoRealP tnw::op::pow(const tnw::FuncaoRealP& f, double v) {
	return newFun(FuncoesReais('^',f,newFun(FuncaoConstante(v))));
}

tnw::FuncaoRealP tnw::op::operator+(double v, const tnw::FuncaoRealP& g){
	return newFun(FuncoesReais('+',newFun(FuncaoConstante(v)),g));
}
tnw::FuncaoRealP tnw::op::operator-(double v, const tnw::FuncaoRealP& g){
	return newFun(FuncoesReais('-',newFun(FuncaoConstante(v)),g));
}
tnw::FuncaoRealP tnw::op::operator*(double v, const tnw::FuncaoRealP& g){
	return newFun(FuncoesReais('*',newFun(FuncaoConstante(v)),g));
}
tnw::FuncaoRealP tnw::op::operator/(double v, const tnw::FuncaoRealP& g){
	return newFun(FuncoesReais('/',newFun(FuncaoConstante(v)),g));
}
tnw::FuncaoRealP tnw::op::pow(double v, const tnw::FuncaoRealP& g){
	return newFun(FuncoesReais('^',newFun(FuncaoConstante(v)),g));
}