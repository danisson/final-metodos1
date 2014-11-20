#ifndef MATRIZES_H
#define MATRIZES_H
#include <vector>
#include <string>
#include <tuple>

namespace tnw
{
	class MatrizQuadrada
	{
	private:
		unsigned tamanho;
		std::vector<double> m;
	public:
		double operator()(unsigned i, unsigned j) const;
		double& operator()(unsigned i, unsigned j);

		std::tuple<MatrizQuadrada,MatrizQuadrada> DR() const;

		std::string toString() const;

		MatrizQuadrada(unsigned n);
	};

	class Vetor
	{
	private:
		unsigned tamanho;
		std::vector<double> m;
	public:
		double operator()(unsigned i) const;
		double& operator()(unsigned i);

		std::string toString() const;

		Vetor(unsigned n);
	};
}

#endif