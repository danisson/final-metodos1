#include "metodosNumericos.h"
#include <cmath>

using namespace tnw;


// Função de bissecção para calcular um bom interalo das raízes.

intervalo tnw::bissec (double a, double b, FuncaoRealP f, double epsilon) {
	double c, fc, fa;
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
