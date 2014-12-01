#include <cstdio>
#include "gerarCSV.h"

void tnw::gerarCSV(tnw::MatrizQuadrada m, std::string nomeArquivo) {
	
	FILE* arquivo =	std::fopen(nomeArquivo.c_str(),"w");

	if(arquivo==NULL)
		throw -1;

	unsigned n = m.getTamanho();

	for (unsigned i = 0; i < n; ++i)
	{
		for (unsigned j = 0; j < n; ++j)
		{
			if(j+1<n) fprintf(arquivo, "%le,", m(i,j));
			else      fprintf(arquivo, "%le\n", m(i,j));
		}
	}

	std::fclose(arquivo);
}

void tnw::gerarCSV(tnw::Vetor m, std::string nomeArquivo) {
	
	FILE* arquivo =	std::fopen(nomeArquivo.c_str(),"w");

	if(arquivo==NULL)
		throw -1;

	unsigned n = m.getTamanho();

	for (unsigned i = 0; i < m.getTamanho(); ++i)
	{
		if(i+1<n) fprintf(arquivo, "%le,", m(i));
		else      fprintf(arquivo, "%le\n", m(i));
	}

	std::fclose(arquivo);
}

void tnw::gerarJSON(tnw::MatrizQuadrada m, std::string nomeArquivo) {
	
	FILE* arquivo =	std::fopen(nomeArquivo.c_str(),"w");

	if(arquivo==NULL)
		throw -1;

	fprintf(arquivo, "%s\n", m.toJSON().c_str());
	std::fclose(arquivo);
}

void tnw::gerarJSON(tnw::Vetor m, std::string nomeArquivo) {
	
	FILE* arquivo =	std::fopen(nomeArquivo.c_str(),"w");

	if(arquivo==NULL)
		throw -1;

	fprintf(arquivo, "%s\n", m.toJSON().c_str());
	std::fclose(arquivo);
}