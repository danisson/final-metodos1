#ifndef gerarCSVH
#define gerarCSVH
#include "../matrizes/matrizes.h"
#include "../métodos/metodosNumericos.h"
#include <string>
#include <vector>

using std::string;

namespace tnw
{
	void gerarCSV(Vetor m, string nomeArquivo);
	void gerarCSV(MatrizQuadrada m, string nomeArquivo);

	void gerarJSON(Vetor m, string nomeArquivo);
	void gerarJSON(MatrizQuadrada m, string nomeArquivo);
}
#endif