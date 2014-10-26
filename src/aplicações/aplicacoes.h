#ifndef APLICACOES_H
#define APLICACOES_H
#include "../funções/funcoes.h"
#include "../métodos/metodosNumericos.h"
#include "../auxiliar/tabela.h"
#include <cmath>
namespace tnw {
	void desenha_quadro(int n, std::vector<double> vetorP0, std::vector<tnw::FuncaoRealP> vetorFuncoes, double epsilon);
	void gera_quadros();
}
#endif