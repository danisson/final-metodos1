#include "aplicacoes.h"
#include <cstdio>
#include <cmath>
#include <cfloat>

using namespace tnw::op;
using namespace tnw;

void tnw::desenha_quadro(std::vector<double> vetorP0, double epsilon){
	int n = vetorP0.size();
	double x0,d,a,b;
	tnw::FuncaoRealP f,phi;
	tnw::FuncaoRealP raiz = newFun(tnw::FuncaoExistente(std::sqrt,"raiz"));
	tnw::FuncaoRealP log = newFun(tnw::FuncaoExistente(std::log,"log"));
	tnw::FuncaoRealP qd2 = newFun(tnw::Polinomio({0,0,4}));
	
	std::cout << center(" ",20) << " | "
			  << center("Ponto Fixo",20) << " | "
			  << center("Newton-Raphson",20) << " | "
			  << center("Newton Modificado",20) << " | \n"
			  << center("p0",20) << " | "	  
	          << center("d",20)  << " | "
	          << center("d",20)  << " | "
	          << center("d",20)  << " | \n ";
    	       

	std::cout << std::string(20*4 + 3*4, '-');

	for(int j=0; j<n; j++) {
		//se aprimora um intervalo aleatório e 
		f   = newFun(tnw::Exponencial(vetorP0[j])) - qd2;
		phi = compose(log,qd2/vetorP0[j]);
		std::tie(a,b) = tnw::bissec (tnw::acharChuteInicialRandom(f), f, 0.001);

		x0 = a+b/2;
		d = tnw::pontoFixo(x0, phi, epsilon).x;
    	std::cout <<"\n"<< prd(vetorP0[j],4,20)	<< " | "
    			  << prd(d,4,20)			<< " | ";
    	d = tnw::newton(x0, f, epsilon).x;
    	std::cout << prd(d,4,20) 			<< " | ";
    	d = tnw::newtonModificado(x0, f, epsilon).x;
    	std::cout << prd(d,4,20);
	}
	std::cout << "\n";
}

void tnw::gerarQuadroComparativo(std::vector<double> p0,double epsilon,std::string nomeArquivo) {
	tnw::FuncaoRealP f,phi,phi2;
	tnw::FuncaoRealP raiz = newFun(tnw::FuncaoExistente(std::sqrt,"raiz"));
	tnw::FuncaoRealP log = newFun(tnw::FuncaoExistente(std::log,"log"));
	tnw::FuncaoRealP qd2 = newFun(tnw::Polinomio({0,0,4}));

	tnw::outputMetodo saidas[4] = {tnw::outputMetodo(0,0),tnw::outputMetodo(0,0),tnw::outputMetodo(0,0),tnw::outputMetodo(0,0)};
	tnw::intervalo a_b;
	double x0;

	FILE* arquivo =	std::fopen(nomeArquivo.c_str(),"w");

	if(arquivo==NULL)
		throw -1;

	std::fprintf(arquivo,
		"p0,a,b,phi,phi2,"
		"Método de Newton(d),Método de Newton(f(d)),Método de Newton(passos),"
		"Método Modificado(d),Método Modificado(f(d)),Método Modificado(passos),"
		"Ponto Fixo(d),Ponto Fixo(f(d)),Ponto Fixo(passos),"
		"Ponto Fixo 2(d),Ponto Fixo 2(f(d)),Ponto Fixo 2(passos)"
		"\n");
	for (unsigned i = 0; i < p0.size(); ++i)
	{
		f    = newFun(tnw::Exponencial(p0[i])) - qd2;
		phi  = compose(log,qd2/p0[i]);
		phi2 = compose(raiz,newFun(tnw::Exponencial(p0[i]/4.0)));
		a_b  = tnw::bissec(tnw::acharChuteInicialRandom(f),f,0.001);
		x0   = (std::get<0>(a_b)+std::get<1>(a_b))/2.0;

		saidas[0] = tnw::newton(x0,f,epsilon);
		saidas[1] = tnw::newtonModificado(x0,f,epsilon);
		saidas[2] = tnw::pontoFixo(x0,phi,epsilon);
		saidas[3] = tnw::pontoFixo(x0,phi2,epsilon);

		std::fprintf(arquivo,
		"%.*lf,%.*lf,%.*lf,%s,%s,",
		LDBL_DIG,p0[i],LDBL_DIG,std::get<0>(a_b),LDBL_DIG,std::get<1>(a_b),phi->toString().c_str(),phi2->toString().c_str());

		for (int j = 0; j < 4; ++j)
			std::fprintf(arquivo,"%.*lf,%.*le,%lld,",LDBL_DIG,saidas[j].x,LDBL_DIG,f->eval(saidas[j].x),saidas[j].i);
		std::fprintf(arquivo,"\n");
	}
	std::fclose(arquivo);
}
