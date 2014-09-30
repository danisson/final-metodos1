#include "../funções/funcoesReais.h"
#include <tuple>

namespace tnw {
	typedef std::tuple<double,double> intervalo;
	tnw::intervalo bissec (tnw::intervalo a_b, FuncaoRealP f, double epsilon);
}