#include <cstdio>
#include <string>
#include "matrizes/matrizes.h"
#include "métodos/metodosNumericos.h"
#define max(a,b) a>b?a:b

void testeUm() {
	printf("Matriz\n");
	tnw::MatrizQuadrada m(4);
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			m(i,j) = max(i-j,j-i)+1;
	printf("%s\n",m.toString().c_str());

	printf("Decomposição\n");
	auto dr = m.DR();
	printf("%s\n",std::get<0>(dr).toString().c_str());
	printf("%s\n",std::get<1>(dr).toString().c_str());

	printf("Multiplicação I*M\n");
	printf("%s\n", (tnw::identidade(4)*m).toString().c_str());

	printf("Vetor\n");
	tnw::Vetor v(4);
	v(1)=1;
	printf("%s\n",v.toString().c_str());

	printf("Multiplicação M*V\n");
	printf("%s\n", (m*v).toString().c_str());
}

void testeDois() {
	printf("Construtores\n");
	tnw::MatrizQuadrada m = {{1,1,1},{2,2,2},{3,3,3}};
	printf("%s\n",m.toString().c_str());

	try {m = {{1,1,1},{2,2,2,2},{3,3,3}};}
	catch (const std::exception& e) {printf("Falha Esperada: %s\n\n", e.what());}

	m = tnw::MatrizQuadrada({tnw::Vetor({1,2,3}),tnw::Vetor({1,2,3}),tnw::Vetor({1,2,3})});
	printf("%s\n",m.toString().c_str());
}

void testeTres(){
	tnw::MatrizQuadrada m = {{5,3,1},{5,6,1},{1,6,7}};
	printf("Matriz considerada\n");
	printf("%s\n", m.toString().c_str());

	double erro = 0.0000001;
	tnw::MatrizQuadrada i = tnw::inverterJacobi(m, erro);
	printf("Matriz invertida por Jacobi com erro %le:\n", erro);
	printf("%s\n",i.toString().c_str());

	tnw::MatrizQuadrada mi = m*i;
	printf("Matriz inicial vezes Jacobi inversa\n");
	printf("%s\n", mi.toString().c_str());

	tnw::MatrizQuadrada j = tnw::inverterSeidel(m, erro);
	printf("Matriz invertida por Seidel com erro %le:\n", erro);
	printf("%s\n",j.toString().c_str());

	tnw::MatrizQuadrada mj = m*j;
	printf("Matriz inicial vezes Seidel inversa\n");
	printf("%s\n", mj.toString().c_str());

}

void testeQuatro(){
	tnw::MatrizQuadrada m = {{2,1,3},{0,-1,1},{1,0,3}};
	printf("Matriz considerada\n");
	printf("%s\n", m.toString().c_str());
	printf("Esta matriz %spassou no critério das linhas\n", m.testeLinhas()==-1?"":"não ");
	if (m.testeLinhas()!=-1)
		printf("E a testemunha é a linha %d\n", m.testeLinhas());
	printf("Esta matriz %spassou no critério de Sassenfeld\n", m.testeSassenfeld()==-1?"":"não ");
	if (m.testeSassenfeld()!=-1)
		printf("E a testemunha é a linha %d\n", m.testeSassenfeld());
	printf("\n");
	m = {{3,0,1},{3,-1,0},{3,1,2}};
	printf("Matriz considerada\n");
	printf("%s\n", m.toString().c_str());
	printf("Esta matriz %spassou no critério das linhas\n", m.testeLinhas()==-1?"":"não ");
	if (m.testeLinhas()!=-1)
		printf("E a testemunha é a linha %d\n", m.testeLinhas());
	printf("Esta matriz %spassou no critério de Sassenfeld\n", m.testeSassenfeld()==-1?"":"não ");
	if (m.testeSassenfeld()!=-1)
		printf("E a testemunha é a linha %d\n", m.testeSassenfeld());

}

int main(int argc, char const *argv[])
{
	if(argc <= 1){printf("Err: Insira o número do teste\n"); return 1;}
	int n = std::stoi(argv[1]);
	switch (n) {
		case 1:
			testeUm();
			break;
		case 2:
			testeDois();
			break;
		case 3:
			testeTres();
		case 4:
			testeQuatro();
		default:
			return 0;
	}
	return 0;
}