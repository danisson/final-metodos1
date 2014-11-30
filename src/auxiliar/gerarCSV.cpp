#include <cstdio>
#include "gerarCSV.h"

void tnw::gerarCSV(std::vector<tnw::MatrizQuadrada> ml,std::vector<tnw::Vetor> bl,double epsilon, std::string nomeArquivo) {
	
	FILE* arquivo =	std::fopen(nomeArquivo.c_str(),"w");
	int aux;

	if(arquivo==NULL)
		throw -1;

	std::fprintf(arquivo,
		"M;b;"
		"Solução Jacobi;Inversa Jacobi;"
		"Solução Seidel;Inversa Seidel;"
		"Passou teste das Linhas?;"
		"Passou teste de Sassenfeld?;"
		"\n");
	for (unsigned k = 0; k < ml.size(); ++k)
	{
		// M
		std::fprintf(arquivo, "%s;",ml[k].toJSON().c_str());
		// b
		std::fprintf(arquivo, "%s;",bl[k].toJSON().c_str());
		// Solução Jacobi
		std::fprintf(arquivo, "%s;",tnw::jacobi(ml[k],bl[k],epsilon).toJSON().c_str());
		// Inversa Jacobi
		std::fprintf(arquivo, "%s;",tnw::inverterJacobi(ml[k],epsilon).toJSON().c_str());
		// Solução Seidel
		std::fprintf(arquivo, "%s;",tnw::seidel(ml[k],bl[k],epsilon).toJSON().c_str());
		// Inversa Seidel
		std::fprintf(arquivo, "%s;",tnw::inverterJacobi(ml[k],epsilon).toJSON().c_str());
		// Passou teste das Linhas?
		aux = ml[k].testeLinhas();
		if (aux==-1) std::fprintf(arquivo, "passou;");
		else         std::fprintf(arquivo, "não pela linha %d;",aux);
		// Passou teste de Sassenfeld?
		aux = ml[k].testeSassenfeld();
		if (aux==-1) std::fprintf(arquivo, "passou;");
		else         std::fprintf(arquivo, "não pela linha %d;",aux);
		std::fprintf(arquivo, "\n");
	}
	std::fclose(arquivo);
}