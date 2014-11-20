#include "matrizes.h"
#define eu(i,j) m[i*tamanho + j]


using std::tuple;
using std::make_tuple;
using tnw::MatrizQuadrada;

double MatrizQuadrada::operator()(unsigned i, unsigned j) const {
if (i < tamanho && j <tamanho)
		return eu(i,j);
	throw -1; //Melhor isso
}
double& MatrizQuadrada::operator()(unsigned i, unsigned j) {
	if (i < tamanho && j <tamanho)
		return eu(i,j);
	throw -1; //Melhor isso
}

tuple<MatrizQuadrada,MatrizQuadrada> MatrizQuadrada::DR() const {
	MatrizQuadrada d(tamanho),r(tamanho);

	for (unsigned i = 0; i < tamanho; ++i) {
		for (unsigned j = 0; j < tamanho; ++j) {
			if(i==j) d(i,i) = eu(i,i);
			else     r(i,j) = eu(i,j);
		}
	}

	return make_tuple(d,r);
}

std::string MatrizQuadrada::toString() const {
	std::string output,aux;
	for (unsigned i = 0; i < tamanho; ++i)
	{
		output += "| ";
		for (unsigned j = 0; j < tamanho; ++j)
		{
			aux = std::to_string(eu(i,j));
			aux.erase(aux.find_last_not_of('0') + 1, std::string::npos);
			if(aux.back() == '.') aux.pop_back();
			output+= aux + " ";
		}
		output += "|\n";
	}
	return output;
}

MatrizQuadrada::MatrizQuadrada(unsigned n) {
	tamanho = n;
	for (unsigned i = 0; i < (n*n); ++i)
		m.push_back(0);
}