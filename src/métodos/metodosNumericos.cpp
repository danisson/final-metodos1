#include "metodosNumericos.h"
#include <cmath>

using namespace tnw;
using namespace tnw::op;


// Função de bissecção para calcular um bom interalo das raízes.
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
		return pontoFixo(inicial,newFun(tnw::Identidade())-(f/newFun(tnw::FuncaoConstante(f->evalDerivada(inicial))),epsilon);
	else
		return NAN;
}