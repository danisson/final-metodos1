#include "metodosNumericos.h"
#include "../auxiliar/tempo.h"
#include <cmath>
#include <algorithm>
#include <random>

using namespace tnw;
using namespace tnw::op;


tnw::intervalo tnw::acharChuteInicial(FuncaoRealP f) {
	long long areaDeBusca = 10000;
	double epsilon = 1.0;
	double intervalo[] = {NAN,NAN};

	timestamp_t t0 = get_timestamp(),t1;
	double secs = 0;
	for (int limite = 0; true; ++limite)
	{
		for (double i = -areaDeBusca; i < areaDeBusca; i=i+epsilon)
		{
			if(f->eval(i) > 0)
				intervalo[0] = i;
			if(f->eval(i) < 0)
				intervalo[1] = i;
			if(f->eval(i) == 0)
				return std::make_tuple(i,i);
		}
		t1 = get_timestamp();
		secs = (t1 - t0) / 1000000.0L;

		if (std::isnan(intervalo[0]) || std::isnan(intervalo[1]))
		{
			areaDeBusca *= 10;
		}
		else {
			double min = std::min(intervalo[0],intervalo[1]), max = std::max(intervalo[0],intervalo[1]);
			return std::make_tuple(min,max);
		}

		if (secs > 2.0)
			break;
	}
	printf("err: Tempo Limite de Achar Raíz Excedido\n");
	return std::make_tuple(NAN,NAN);
}

tnw::intervalo tnw::acharChuteInicialRandom(FuncaoRealP f) {
	long long areaDeBusca = 10000;
	double intervalo[] = {NAN,NAN};
	double i;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(-areaDeBusca, areaDeBusca);

	timestamp_t t0 = get_timestamp(),t1;
	double secs = 0;
	for (int limite = 0; true; ++limite)
	{
		i = dis(gen);
		if(f->eval(i) > 0)
			intervalo[0] = i;
		if(f->eval(i) < 0)
			intervalo[1] = i;
		if(f->eval(i) == 0)
			return std::make_tuple(i,i);

		if(limite%100==0) {
			areaDeBusca*=10;
			dis = std::uniform_real_distribution<>(-areaDeBusca, areaDeBusca);
		}

		if (!std::isnan(intervalo[0]) && !std::isnan(intervalo[1])) {
			double min = std::min(intervalo[0],intervalo[1]), max = std::max(intervalo[0],intervalo[1]);
			return std::make_tuple(min,max);
		}

		t1 = get_timestamp();
		secs = (t1 - t0) / 1000000.0L;
		if (secs > 2.0)
			break;
	}
	printf("err: Tempo Limite de Achar Raíz Excedido\n");
	return std::make_tuple(NAN,NAN);
}

// Função de bissecção para calcular um bom intervalo das raízes.
intervalo tnw::bissec (tnw::intervalo a_b, FuncaoRealP f, double epsilon) {
	double a, b, c, fc, fa;
	std::tie(a,b) = a_b;
	
	while (std::abs(a-b) > epsilon) {
		c = 0.5*(a+b);
		fc = (f->eval(c));
		fa = (f->eval(a));

		if (fc*fa > 0)
			a = c;
		else if (fc*fa < 0)
			b = c;
		else {
			a = c-epsilon;
			b = c+epsilon;
		}
	}

	return std::make_tuple(a,b);
}

//Função que calcula o valor com base no método do ponto fixo. A precisão, o valor inicial de chute e a função phi são passadas como parâmetro.
double tnw::pontoFixo(double inicial, FuncaoRealP phi, double epsilon) {
	
	double prox,ant;

	ant = inicial;
	prox = phi->eval(ant);

	while(std::abs(prox - ant) > epsilon){
		ant = prox;
		prox = phi->eval(ant);
	}

	return prox;
}

double tnw::newton(double inicial, FuncaoRealP f, double epsilon) {
	return pontoFixo(inicial,newFun(tnw::Identidade())-(f/f->derivada()),epsilon);
}

double newtonModificado(double inicial, FuncaoRealP f, double epsilon) {
	if (f->evalDerivada(inicial) == 0)
		return pontoFixo(inicial,newFun(tnw::Identidade())-(f/newFun(tnw::FuncaoConstante(f->evalDerivada(inicial)))),epsilon);
	else
		return NAN;
}