#include <cstdio>
#include "matrizes/matrizes.h"

int main(int argc, char const *argv[])
{
	printf("Matriz\n");

	tnw::MatrizQuadrada m(4);
	for (int i = 0; i < 4; ++i)
		m(i,i)=1;
	printf("%s\n",m.toString().c_str());

	printf("Vetor\n");

	tnw::Vetor v(4);
	v(1)=1;
	printf("%s\n",v.toString().c_str());

	return 0;
}