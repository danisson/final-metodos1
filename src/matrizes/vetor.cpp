#include "matrizes.h"

double tnw::Vetor::operator()(unsigned i) const {
	if (i < tamanho)
		return m[i];
	throw -1; //Melhor isso
}
double& tnw::Vetor::operator()(unsigned i) {
	if (i < tamanho)
		return m[i];
	throw -1; //Melhor isso
}

std::string tnw::Vetor::toString() const {
	std::string output,aux;
	for (unsigned i = 0; i < tamanho; ++i)
	{
		output += "| ";
		aux = std::to_string(m[i]);
		aux.erase(aux.find_last_not_of('0') + 1, std::string::npos);
		if(aux.back() == '.') aux.pop_back();
		output+= aux + " ";
		output += "|\n";
	}
	return output;
}

tnw::Vetor::Vetor(unsigned n) {
	tamanho = n;
	for (unsigned i = 0; i < n; ++i)
		m.push_back(0);
}