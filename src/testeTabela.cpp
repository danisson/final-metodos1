#include "aplicações/aplicacoes.h"

int main(int argc, char const *argv[])
{
	std::vector<double> p0 = {0.5,1,0.2,9,10};
	double epsilon = 0.00001;
	
	tnw::desenha_quadro(p0,epsilon);
	tnw::gerarQuadroComparativo(p0,epsilon,"testeQ.csv");
	return 0;
}