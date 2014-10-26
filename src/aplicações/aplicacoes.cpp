#include "aplicacoes.h"
#include <cstdio>
#include <cmath>

using namespace tnw::op;
using namespace tnw;

void tnw::desenha_quadro(int n, std::vector<double> vetorP0, double epsilon){
	double x0,d,a,b;
	tnw::FuncaoRealP f,phi;
	tnw::FuncaoRealP raiz = newFun(tnw::FuncaoExistente(std::sqrt,"raiz"));
	tnw::FuncaoRealP qd2 = newFun(tnw::Polinomio({0,0,4}));
	
	std::cout << center(" ",20)   
			  << center("Ponto Fixo",20)
			  << center("Newton-Raphson",20)
			  << center("Newton-Raphson Modificado",20) << "\n\n"
			  << center("p0",20) << " | "	  
	          << center("d",20)  << " | "
	          << center("d",20)  << " | "
	          << center("d",20)  << " \n ";
    	       

	std::cout << std::string(20*4 + 3*4, '-') << "\n";

	for(int j=0; j<n; j++) {
		//se aprimora um intervalo aleatório e 
		f   = newFun(tnw::Exponencial(p0[i])) - qd2;
		phi = compose(raiz,newFun(tnw::Exponencial(p0[i])))/2;
		std::tie(a,b) = tnw::bissec (tnw::acharChuteInicialRandom(vetorFuncoes[j]), f, 0.001);

		x0 = a+b/2;
		d = tnw::pontoFixo(x0, phi, epsilon).x;
    	std::cout <<"\n"<< prd(vetorP0[j],4,20)	<< " | "
    			  << prd(d,4,20)			<< " | ";
    	d = tnw::newton(x0, f, epsilon).x;
    	std::cout << prd(d,4,20) 			<< " | ";
    	d = tnw::newtonModificado(x0, f, epsilon).x;
    	std::cout << prd(d,4,20)			<< " \n";
	}
}



void tnw::gera_quadros(){
	double epsilon;

	int n;
	printf("Quantas particulas?\n");
	scanf("%d",&n);
	double p0;
	std::vector<tnw::FuncaoRealP> vetorFuncoes(n,0);
	std::vector<double> vetorP0(n,0);


	printf("escreva os deslocamentos parciais (p0)\n");
	for (int i=0; i<n; i++){
		scanf ("%lf",&p0);
		vetorP0[i] = p0;
		vetorFuncoes[i] = (newFun(tnw::Exponencial(p0))-newFun(tnw::Polinomio({0,0,4})));
	}
	scanf("%lf",&epsilon);
	desenha_quadro(n,vetorP0, vetorFuncoes, epsilon);
	/*std::cout << center("Método do Ponto Fixo",20*6 + 3*6 + 1) << "\n\n"
	desenha_quadro(vetorP0, vetorFuncoes, x0, phi, epsilon);
	std::cout << center("Método de Newton-Raphson",20*6 + 3*6 + 1) << "\n\n"
	desenha_quadro(vetorP0, vetorFuncoes, x0, newFun(tnw::Identidade())-(f/f->derivada()), epsilon);
	std::cout << center("Método de Newton-Raphson Modificado",20*6 + 3*6 + 1) << "\n\n"
	desenha_quadro(vetorP0, vetorFuncoes, x0, newFun(tnw::Identidade())-(f/f->derivada()), epsilon);*/
}
//:(

void tnw::gerarQuadroComparativo(std::vector<double> p0,double epsilon,std::string nomeArquivo) {
	tnw::FuncaoRealP f,phi;
	tnw::FuncaoRealP raiz = newFun(tnw::FuncaoExistente(std::sqrt,"raiz"));
	tnw::FuncaoRealP qd2 = newFun(tnw::Polinomio({0,0,4}));

	tnw::outputMetodo saidas[3] = {tnw::outputMetodo(0,0),tnw::outputMetodo(0,0),tnw::outputMetodo(0,0)};
	tnw::intervalo a_b;
	double x0;

	FILE* arquivo =	std::fopen(nomeArquivo.c_str(),"w");

	if(arquivo==NULL)
		throw -1;

	std::fprintf(arquivo,
		"p0,a,b,phi,"
		"Método de Newton(d),Método de Newton(f(d)),Método de Newton(passos),"
		"Método Modificado(d),Método Modificado(f(d)),Método Modificado(passos),"
		"Ponto Fixo(d),Ponto Fixo(f(d)),Ponto Fixo(passos)"
		"\n");
	for (unsigned i = 0; i < p0.size(); ++i)
	{
		f   = newFun(tnw::Exponencial(p0[i])) - qd2;
		phi = compose(raiz,newFun(tnw::Exponencial(p0[i])))/2;
		a_b = tnw::bissec(tnw::acharChuteInicialRandom(f),f,0.001);
		x0  = (std::get<0>(a_b)+std::get<1>(a_b))/2.0;

		saidas[0] = tnw::newton(x0,f,epsilon);
		saidas[1] = tnw::newtonModificado(x0,f,epsilon);
		saidas[2] = tnw::pontoFixo(x0,phi,epsilon);

		std::fprintf(arquivo,
		"%lf,%lf,%lf,%s,",
		p0[i],std::get<0>(a_b),std::get<1>(a_b),phi->toString().c_str());

		for (int j = 0; j < 3; ++j)
		{
			if(j==2) std::fprintf(arquivo,"%lf,%le,%lld,", saidas[j].x,f->eval(saidas[j].x),saidas[j].i);
			else     std::fprintf(arquivo,"%lf,%le,%lld,", saidas[j].x,f->eval(saidas[j].x),saidas[j].i);
		}
		std::fprintf(arquivo,"\n");
	}
	std::fclose(arquivo);
}
