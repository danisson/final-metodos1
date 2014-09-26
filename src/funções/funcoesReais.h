#ifndef REALFUNCTIONS_H
#define REALFUNCTIONS_H
#include <vector>
#include <tuple>
#include <initializer_list>
#include <ostream>

namespace tnw
{
	class FuncaoReal
	{
	public:
		virtual double eval(double x) const = 0;
		virtual double evalDerivada(double x) const = 0;
		virtual ~FuncaoReal(){};
	};


	class FuncaoConstante : public FuncaoReal
	{
	private:
		int constante;
	public:
		FuncaoConstante(double constante);
		double eval(double x) const;
		double evalDerivada(double x) const;
		~FuncaoConstante();
	};

	class FuncoesReais : public FuncaoReal
	{
	private:
		char op;
		FuncaoReal* e;
		FuncaoReal* d;
	public:
		// Métodos
		double eval(double x) const;
		double evalDerivada(double x) const;
		FuncaoReal* copy();

		// Construtor
		FuncoesReais(char op, FuncaoReal* f, FuncaoReal* g);

		// Operadores Sobrecarregados

		// Desconstrutor
		~FuncoesReais();
	};
	namespace op {
		FuncaoReal*  add(FuncaoReal* f, FuncaoReal* g);
		FuncaoReal*  sub(FuncaoReal* f, FuncaoReal* g);
		FuncaoReal* mult(FuncaoReal* f, FuncaoReal* g);
		FuncaoReal*  add(FuncaoReal* f, double v);
		FuncaoReal* mult(FuncaoReal* f, double v);
	}

	class Polinomio :  public FuncaoReal
	{
	private:
		std::vector<double> coeficientes;
		int grau;
	public:
		// Métodos
		double eval(double x) const;
		double evalDerivada(double x) const;

		// Construtores
		// Construtor Principal
		Polinomio(std::vector<double> coeficientes);
		// Bracket-initialzer
		Polinomio(std::initializer_list<double> coeficientes);
		// Copiador
		Polinomio(const Polinomio& p);

		// Getter & Setters
		int getGrau() const;
		const std::vector<double>& getCoeficientes() const;

		//Operadores Sobrecarregados
		tnw::Polinomio& operator=(tnw::Polinomio p);

		// Desconstrutor
		~Polinomio();
	};
	std::ostream& operator<< (std::ostream& os, const Polinomio& p);

	class Exponencial :  public FuncaoReal
	{
	private:
		double coeficiente;
	public:
		// Métodos
		double eval(double x) const;
		double evalDerivada(double x) const;
		FuncaoReal* copy();

		// Construtores
		// Construtor principal
		Exponencial(double coeficiente);
		// Coeficiente = 1
		Exponencial();
		// Copiador
		Exponencial(const Exponencial& e);

		// Getter & Setters
		double getCoeficiente() const;

		//Operadores Sobrecarregados

		// Desconstrutor
		~Exponencial();
	};
	std::ostream& operator<< (std::ostream& os, const Exponencial& e);
}
#endif