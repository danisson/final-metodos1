#include <cstdio>
#include <string>
#include "matrizes/matrizes.h"
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
		default:
			return 0;
	}
	return 0;
}