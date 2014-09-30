#include "../funções/funcoesReais.h"
#include <tuple>

namespace tnw {
	typedef std::tuple<double,double> intervalo;
	tnw::intervalo bissec (double a, double b, FuncaoRealP f, double epsilon);
}