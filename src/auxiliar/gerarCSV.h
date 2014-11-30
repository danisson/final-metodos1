#ifndef gerarCSVH
#define gerarCSVH
#include "../matrizes/matrizes.h"
#include "../métodos/metodosNumericos.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

namespace tnw
{
	void gerarCSV(vector<MatrizQuadrada> ml,vector<Vetor> bl,double epsilon, string nomeArquivo);
}
#endif