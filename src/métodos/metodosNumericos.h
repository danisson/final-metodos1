#include "../funções/funcoes.h"
#include <tuple>

namespace tnw {
	typedef std::tuple<double,double> intervalo;
	struct outputMetodo
	{
		outputMetodo(double x1, long long i1) {x=x1;i=i1;}
		double x;
		long long i;
	};

	tnw::intervalo acharChuteInicial(FuncaoRealP f);
	tnw::intervalo acharChuteInicialRandom(FuncaoRealP f);
	tnw::intervalo bissec (tnw::intervalo a_b, FuncaoRealP f, double epsilon);
	tnw::outputMetodo pontoFixo(double inicial, FuncaoRealP phi, double epsilon);
	tnw::outputMetodo newton(double inicial, FuncaoRealP f, double epsilon);
	tnw::outputMetodo newtonModificado(double inicial, FuncaoRealP f, double epsilon);
}