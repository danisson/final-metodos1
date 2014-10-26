#include "aplicações/aplicacoes.h"

int main(int argc, char const *argv[])
{

	printf("              _____ _           _                      _        _____         _   _         _          \n");
	printf("             |   __|_|_____ _ _| |___ ___ ___ ___    _| |___   |  _  |___ ___| |_|_|___ _ _| |___ ___  \n");
	printf("             |__   | |     | | | | .'|  _| .'| . |  | . | -_|  |   __| .'|  _|  _| |  _| | | | .'|_ -| \n");
	printf("             |_____|_|_|_|_|___|_|__,|___|__,|___|  |___|___|  |__|  |__,|_| |_| |_|___|___|_|__,|___| \n");
	printf("\n\n");
	printf("                 +------------------------------------------------------------------------------+ \n");
	printf("                 |                                                                              | \n");
	printf("                 |   As funções que terão as raízes calculadas serão da forma p0*(e^d) - 4d².   | \n");
	printf("                 |    Insira os valores de p0 seguidos de enter. Para prosseguir, digite 0.     | \n");
	printf("                 |                                                                              | \n");
	printf("                 +------------------------------------------------------------------------------+ \n");
	std::vector<double> p0;
	std::string nomeArquivo;
	double aux;
	double epsilon;
	std::cin >> aux;
	while(aux != 0){
		p0.push_back(aux);
	    std::cin >> aux;
  	};
	printf("                 +------------------------------------------------------------------------------+ \n");
	printf("                 |                                                                              | \n");
	printf("                 |                     Insira agora uma precisão (épsilon).                     | \n");
	printf("                 |                                Menor é melhor.                               | \n");
	printf("                 |                                                                              | \n");
	printf("                 +------------------------------------------------------------------------------+ \n\n\n");
	std::cin >> epsilon;
	tnw::desenha_quadro(p0,epsilon);
	printf("\n\n\n");
	printf("                 +------------------------------------------------------------------------------+ \n");
	printf("                 |                                                                              | \n");
	printf("                 |                Digite o nome de um arquivo .csv para guardar.                | \n");
	printf("                 |                         o quadro comparativo completo.                       | \n");
	printf("                 |                                                                              | \n");
	printf("                 +------------------------------------------------------------------------------+ \n\n\n");
	std::cin >> nomeArquivo;
	tnw::gerarQuadroComparativo(p0,epsilon,nomeArquivo);
	return 0;
}