#include "matrizes.h"

double tnw::MatrizQuadrada::operator()(unsigned i, unsigned j) const {
if (i < tamanho && j <tamanho)
		return m[i*tamanho + j];
	throw -1; //Melhor isso
}
double& tnw::MatrizQuadrada::operator()(unsigned i, unsigned j) {
	if (i < tamanho && j <tamanho)
		return m[i*tamanho + j];
	throw -1; //Melhor isso
}

std::string tnw::MatrizQuadrada::toString() const {
	std::string output,aux;
	for (unsigned i = 0; i < tamanho; ++i)
	{
		output += "| ";
		for (unsigned j = 0; j < tamanho; ++j)
		{
			aux = std::to_string(m[i*tamanho + j]);
			aux.erase(aux.find_last_not_of('0') + 1, std::string::npos);
			if(aux.back() == '.') aux.pop_back();
			output+= aux + " ";
		}
		output += "|\n";
	}
	return output;
}

tnw::MatrizQuadrada::MatrizQuadrada(unsigned n) {
	tamanho = n;
	for (unsigned i = 0; i < (n*n); ++i)
		m.push_back(0);
}