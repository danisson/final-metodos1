#include "aplicações/aplicacoes.h"

int main(int argc, char const *argv[])
{
	std::vector<double> p0 = {1,1.4,155,12};
	double epsilon = 0.0000001;
	
	tnw::desenha_quadro(p0,epsilon);
	printf("Fazendo tabela comparativa:\n");
	tnw::gerarQuadroComparativo(p0,epsilon,"testeQ.csv");
	return 0;
}