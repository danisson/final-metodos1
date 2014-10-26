#include "aplicacoes.h"

using namespace tnw::op;
using namespace tnw;

void tnw::desenha_quadro()
{
	std::cout << center("p0",20)       << " | "
			  << center("x0",20)       << " | "			  
	          << center("raiz",20)     << " | "
    	      << center("função(raiz)",22) << " | "
    	      << center("erro em x",20) << " | "	      
    	      << center("nº de iterações",23) << "\n"; 

	std::cout << std::string(20*6 + 3*6, '-') << "\n";

	for(double x=1.5; x<200; x +=x*2) {
    	std::cout << prd(x,4,20)       << " | "
        	      << prd(x*x,4,20)     << " | "
        	      << prd(x*x,4,20)     << " | "
            	  << prd(x*x/8.0,4,20) << " | " 
            	  << prd(x*x/16.0,4,20) << " | "
				  << prd(x*x/16.0,4,20) << "\n";
	}

}



void tnw::gera_quadros(){
	/*double x0, epsilon;
	FuncaoRealP phi;*/

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
		vetorFuncoes[i] = (newFun(tnw::Exponencial(p0))-newFun(tnw::Polinomio({0,0,-4})));
	}

	/*std::cout << center("Método do Ponto Fixo",20*6 + 3*6 + 1) << "\n\n"
	desenha_quadro(vetorP0, vetorFuncoes, x0, phi, epsilon);
	std::cout << center("Método de Newton-Raphson",20*6 + 3*6 + 1) << "\n\n"
	desenha_quadro(vetorP0, vetorFuncoes, x0, newFun(tnw::Identidade())-(f/f->derivada()), epsilon);
	std::cout << center("Método de Newton-Raphson Modificado",20*6 + 3*6 + 1) << "\n\n"
	desenha_quadro(vetorP0, vetorFuncoes, x0, newFun(tnw::Identidade())-(f/f->derivada()), epsilon);*/



}
//:(

