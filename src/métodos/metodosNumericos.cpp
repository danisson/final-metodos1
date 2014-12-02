#include "metodosNumericos.h"
#include "../auxiliar/tempo.h"
#include <stdexcept>
#include <cmath>
#include <vector>

using namespace tnw;

Vetor tnw::jacobi(const MatrizQuadrada &a, const Vetor &b, double epsilon){
	if (a.getTamanho() != b.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");

	unsigned n = a.getTamanho();
	Vetor xAtual(n);
	Vetor xAnterior(n);
	double soma;

	timestamp_t t0 = get_timestamp(),t1;
	double secs=0;

	while(!parada(xAtual, xAnterior, epsilon)){
		xAnterior = xAtual;
		for (unsigned i=0; i<n; i++){
			soma = 0;
			for (unsigned j=0; j<n; j++)
				if (i!=j) 
					soma += a(i,j)*xAnterior(j);
			xAtual(i) = (b(i)-soma)/a(i,i); 
		}

		t1 = get_timestamp();
		secs = (t1 - t0) / 1000000.0L;
		if (secs > kTempoLimite) {
			printf("err: Tempo Limite Excedido\n");
			break;
		}
	}

	return xAtual;
}

Vetor tnw::seidel(const MatrizQuadrada &a, const Vetor &b, double epsilon){
	if (a.getTamanho() != b.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = a.getTamanho();
	Vetor xAtual(n);
	Vetor xAnterior(n);
	double soma;

	timestamp_t t0 = get_timestamp(),t1;
	double secs=0;

	while(!parada(xAtual, xAnterior, epsilon)){
		xAnterior = xAtual;
		for (unsigned i=0; i<n; i++){
			soma = 0;
			for (unsigned j=0; j<n; j++){
				if (i!=j){
					if (j<i){
						soma += a(i,j)*xAtual(j);
					} else {
						soma += a(i,j)*xAnterior(j);
					}
				}
			}
			xAtual(i) = (b(i)-soma)/a(i,i);
		}
		
		t1 = get_timestamp();
		secs = (t1 - t0) / 1000000.0L;
		if (secs > kTempoLimite) {
			printf("err: Tempo Limite Excedido\n");
			break;
		}
	}

	return xAtual;
}

bool tnw::parada(const Vetor &atual,const Vetor &anterior, double epsilon){
	if (atual.getTamanho() != anterior.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = atual.getTamanho();

	double maxDiff = 0;
	double atualDiff;
	double maxValue = 0;
	double atualValue;

	for (unsigned i=0; i<n; i++){
		atualDiff = std::abs(atual(i)-anterior(i));
		atualValue = std::abs(atual(i));
		if (atualDiff > maxDiff)
			maxDiff = atualDiff;
		if (atualValue > maxValue)
			maxValue = atualValue;
	}
	
	return (maxDiff/maxValue) <= epsilon;
}

MatrizQuadrada tnw::inverterJacobi(MatrizQuadrada m, double epsilon){
	unsigned n = m.getTamanho();
	std::vector<Vetor> v;

	for (unsigned i=0; i<n; i++){
		Vetor c(n);
		c(i) = 1;
		v.push_back(jacobi(m, c, epsilon));
	}

	MatrizQuadrada res(v);
	return res;
}

MatrizQuadrada tnw::inverterSeidel(MatrizQuadrada m, double epsilon){
	unsigned n = m.getTamanho();
	std::vector<Vetor> v;

	for (unsigned i=0; i<n; i++){
		Vetor c(n);
		c(i) = 1;
		v.push_back(seidel(m, c, epsilon));
	}

	MatrizQuadrada res(v);
	return res;
}  