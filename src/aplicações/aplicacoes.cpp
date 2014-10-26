#include "aplicacoes.h"

using namespace tnw::op;
using namespace tnw;

void tnw::desenha_quadro(int n, std::vector<double> vetorP0, std::vector<tnw::FuncaoRealP> vetorFuncoes, double epsilon){
	double x0,d,a,b;
	tnw::FuncaoRealP phi;
	
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
		std::tie(a,b) = tnw::bissec (tnw::acharChuteInicialRandom(vetorFuncoes[j]), vetorFuncoes[j], epsilon);
		x0 = a+b/2;
		phi = compose(newFun(tnw::FuncaoExistente(std::sqrt,"RaizQuadrada")),(newFun(tnw::Exponencial())*vetorP0[j])/2);
		d = tnw::pontoFixo(x0, phi, epsilon);
    	std::cout <<"\n"<< prd(vetorP0[j],4,20)	<< " | "
    			  << prd(d,4,20)			<< " | ";
    	phi = newFun(tnw::Identidade())-(vetorFuncoes[j]/vetorFuncoes[j]->derivada());
    	d = tnw::newton(x0, phi, epsilon);
    	std::cout << prd(d,4,20) 			<< " | ";
    	phi = newFun(tnw::Identidade())-(vetorFuncoes[j]/newFun(tnw::FuncaoConstante(vetorFuncoes[j]->evalDerivada(x0))));
    	d = tnw::newtonModificado(x0, phi, epsilon);
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

