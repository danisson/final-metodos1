#include "../funções/funcoes.h"
#include <tuple>

namespace tnw {
	typedef std::tuple<double,double> intervalo;

	tnw::intervalo acharChuteInicial(FuncaoRealP f);
	tnw::intervalo acharChuteInicialRandom(FuncaoRealP f);
	tnw::intervalo bissec (tnw::intervalo a_b, FuncaoRealP f, double epsilon);
	double pontoFixo(double inicial, FuncaoRealP phi, double epsilon);
	double newton(double inicial, FuncaoRealP f, double epsilon);
	double newtonModificado(double inicial, FuncaoRealP f, double epsilon);
}