#include "funções/funcoes.h"
#include "métodos/metodosNumericos.h"
#include "auxiliar/tempo.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <cmath>

using namespace tnw::op;

int main(int argc, char const *argv[])
{
	printf("Teste de Sanidade!\n");
	printf("Função f(x) = x²-3\n");
	printf("Raíz: √3 e -√3\n");
	auto f = newFun(tnw::Polinomio({-3,0,1}));
	fflush(stdout);
	timestamp_t t0 = get_timestamp();
	auto ab = tnw::acharChuteInicial(f);
	timestamp_t t1 = get_timestamp();
	double secs = (t1 - t0) / 1000000.0L;
	printf("Teorema: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::bissec(ab,f,0.001);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Bissec: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicialRandom(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("TeoremaR: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::bissec(ab,f,0.001);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Bissec: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	printf("\n");

	printf("Função f(x) = e^x\n");
	printf("Raíz: nenhuma\n");
	f = newFun(tnw::Exponencial());
	fflush(stdout);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicial(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Teorema: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	fflush(stdout);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicialRandom(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("TeoremaR: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	printf("Problema: f(a) = %le e f(b) = %le\n",f->eval(std::get<0>(ab)),f->eval(std::get<1>(ab)));
	printf("\n");

	printf("Função f(x) = x-30000000000\n");
	printf("Raíz: 30000000000\n");
	f = newFun(tnw::Polinomio({-30000000000,1}));
	fflush(stdout);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicial(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Teorema: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::bissec(ab,f,0.001);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Bissec: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	fflush(stdout);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicialRandom(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("TeoremaR: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::bissec(ab,f,0.001);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Bissec: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	printf("\n");

	printf("Função f(x) = x^2\n");
	printf("Raíz: 0\n");
	f = newFun(tnw::Polinomio({0,0,1}));
	fflush(stdout);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicial(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Teorema: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::bissec(ab,f,0.001);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Bissec: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	fflush(stdout);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicialRandom(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("TeoremaR: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::bissec(ab,f,0.001);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Bissec: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	printf("\n");

	printf("Função f(x) = (x-50)^2\n");
	printf("Raíz: 0\n");
	f = pow(newFun(tnw::Identidade())-50,2);
	fflush(stdout);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicial(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Teorema: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::bissec(ab,f,0.001);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Bissec: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	fflush(stdout);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicialRandom(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("TeoremaR: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::bissec(ab,f,0.001);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Bissec: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	printf("\n");

	printf("\nFunção f(x) = sin(x)\n");
	printf("Raíz: n*pi\n");
	f = newFun(tnw::FuncaoExistente(std::sin,"sin"));
	fflush(stdout);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicial(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Teorema: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::bissec(ab,f,0.001);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Bissec: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	fflush(stdout);
	t0 = get_timestamp();
	ab = tnw::acharChuteInicialRandom(f);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("TeoremaR: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	t0 = get_timestamp();
	ab = tnw::bissec(ab,f,0.001);
	t1 = get_timestamp(); secs = (t1 - t0) / 1000000.0L;
	printf("Bissec: [%lf,%lf] %lfs\n",std::get<0>(ab),std::get<1>(ab),secs);
	printf("\n");

	return 0;
}