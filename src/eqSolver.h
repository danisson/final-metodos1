#ifndef IEQSOLVER_H
#define IEQSOLVER_H
#include "funções/funcoesReais.h"

namespace tnw
{
	class EqSolver
	{
	private:
		double epsilon;
	public:
		virtual double resolverEquação(realFunction* f) =0;
	};
}
#endif