#ifndef REALFUNCTIONS_H
#define REALFUNCTIONS_H
#include <vector>
#include <string>
#include <memory>
#include <tuple>
#include <initializer_list>
#include <ostream>

#define newFun(A) std::shared_ptr<tnw::FuncaoReal>(new A)
#define makeFun(A) std::shared_ptr<tnw::FuncaoReal>(A)

namespace tnw
{
	class FuncaoReal;
	typedef std::shared_ptr<FuncaoReal> FuncaoRealP;
	typedef double (*funcaoReal)(double);
	
	class FuncaoReal
	{
	public:
		virtual double eval(double x) const = 0;
		virtual double evalDerivada(double x) const = 0;
		virtual double evalIntegral(double a, double b) const;
		virtual FuncaoRealP derivada() const = 0;
		double evalIntegral(double a, double b, double n) const;

		virtual std::string toString() const =0;

		virtual ~FuncaoReal(){};
	};

	class FuncoesReais : public FuncaoReal
	{
	private:
		char op;
		FuncaoRealP e;
		FuncaoRealP d;
	public:
		FuncoesReais(char op,const FuncaoRealP& f,const  FuncaoRealP& g);

		double eval(double x) const;
		double evalDerivada(double x) const;
		virtual FuncaoRealP derivada() const;

		std::string toString() const;

		~FuncoesReais();
	};

	class Polinomio :  public FuncaoReal
	{
	private:
		std::vector<double> coeficientes;
		int grau;
	public:
		Polinomio(std::vector<double> coeficientes);
		Polinomio(std::initializer_list<double> coeficientes);
		Polinomio(const Polinomio& p);

		double eval(double x) const;
		double evalDerivada(double x) const;
		virtual FuncaoRealP derivada() const;

		std::string toString() const;
		int getGrau() const;
		const std::vector<double>& getCoeficientes() const;

		tnw::Polinomio& operator=(tnw::Polinomio p);

		~Polinomio();
	};

	class Exponencial :  public FuncaoReal
	{
	private:
		double coeficiente;
	public:
		Exponencial(double coeficiente);
		Exponencial();
		Exponencial(const Exponencial& e);

		double eval(double x) const;
		double evalDerivada(double x) const;
		virtual FuncaoRealP derivada() const;

		std::string toString() const;
		double getCoeficiente() const;

		~Exponencial();
	};

	class Identidade : public FuncaoReal
	{
	public:
		Identidade();

		double eval(double x) const;
		double evalDerivada(double x) const;
		virtual FuncaoRealP derivada() const;

		std::string toString() const;

		~Identidade();
	};

	class FuncaoExistente : public FuncaoReal
	{
	private:
		std::string nome;
		funcaoReal f;
	public:
		FuncaoExistente(funcaoReal f, std::string name);

		virtual double eval(double x) const;
		virtual double evalDerivada(double x) const;
		virtual FuncaoRealP derivada() const;
		
		virtual std::string toString() const;

		~FuncaoExistente();
	};


	class DerivadaNumerica : public FuncaoReal
	{
	private:
		FuncaoRealP f;
	public:
		DerivadaNumerica(FuncaoRealP f);

		virtual double eval(double x) const;
		virtual double evalDerivada(double x) const;
		virtual FuncaoRealP derivada() const;
		
		virtual std::string toString() const;

		~DerivadaNumerica();
	};

	class FuncaoConstante : public FuncaoReal
	{
	private:
		double constante;
	public:
		FuncaoConstante(double constante);

		double eval(double x) const;
		double evalDerivada(double x) const;
		virtual FuncaoRealP derivada() const;

		std::string toString() const;

		~FuncaoConstante();
	};
}
#endif