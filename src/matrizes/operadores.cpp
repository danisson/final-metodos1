#include "matrizes.h"
#include <stdexcept>
#include <cmath>

using tnw::Vetor;
using tnw::MatrizQuadrada;


double abs(const Vetor& v) {
	unsigned n = v.getTamanho();
	double out=0;
	for (unsigned i = 0; i < n; ++i)
		out+= v(i)*v(i);
	return sqrt(out);
}

Vetor operator* (const MatrizQuadrada& m,const Vetor& v) {
	if (m.getTamanho() != v.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = m.getTamanho();
	Vetor o(n);
	for (unsigned i = 0; i < n; ++i)
			for (unsigned k = 0; k < n; ++k)
				o(i)+=m(i,k)*v(k);
	return o;
}

MatrizQuadrada operator* (const MatrizQuadrada& e,const MatrizQuadrada& d) {
	if (e.getTamanho() != d.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = e.getTamanho();
	MatrizQuadrada o(n);
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < n; ++j)
			for (unsigned k = 0; k < n; ++k)
				o(i,j)+=e(i,k)*d(k,j);
	return o;
}

bool operator==(const MatrizQuadrada& e,const MatrizQuadrada& d) {
	if (e.getTamanho() != d.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = e.getTamanho();
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < n; ++j)
			if (e(i,j)!=d(i,j)) return false;
	return true;
}

bool operator==(const Vetor& e,const Vetor& d) {
	if (e.getTamanho() != d.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = e.getTamanho();
	for (unsigned i = 0; i < n; ++i)
			if (e(i)!=d(i)) return false;
	return true;
}