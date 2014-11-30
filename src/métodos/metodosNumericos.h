#ifndef METODOS
#define METODOS
#include "../matrizes/matrizes.h"

namespace tnw {
	const double kTempoLimite = 5.0;
	Vetor jacobi(const MatrizQuadrada &a, const Vetor &b, double epsilon);
	Vetor seidel(const MatrizQuadrada &a, const Vetor &b, double epsilon);
	MatrizQuadrada inverterJacobi(MatrizQuadrada m, double epsilon);
	MatrizQuadrada inverterSeidel(MatrizQuadrada m, double epsilon);
	bool parada(const Vetor &atual, const Vetor &anterior, double epsilon);
}
#endif