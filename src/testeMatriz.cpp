#include <cstdio>
#include "matrizes/matrizes.h"
#define max(a,b) a>b?a:b

int main(int argc, char const *argv[])
{
	printf("Matriz\n");

	tnw::MatrizQuadrada m(4);
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (i==j) m(i,j) = 1;
			else      m(i,j) = max(i-j,j-i)+1;
	printf("%s\n",m.toString().c_str());

	printf("Decomposição\n");
	auto dr = m.DR();
	printf("%s\n",std::get<0>(dr).toString().c_str());
	printf("%s\n",std::get<1>(dr).toString().c_str());

	printf("Vetor\n");

	tnw::Vetor v(4);
	v(1)=1;
	printf("%s\n",v.toString().c_str());

	return 0;
}