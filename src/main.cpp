#include "matrizes/matrizes.h"
#include "métodos/metodosNumericos.h"
#include "auxiliar/gerarCSV.h"
#include "auxiliar/terminal.h"
#include <iostream>
#include <string>
#include <stdexcept>

tnw::MatrizQuadrada lerMatriz(int n);
tnw::Vetor lerVetor(int n);

int main(int argc, char const *argv[])
{
	int n,linhas;
	char resposta;
	std::string nomeArquivo;
	double epsilon;

	clean();
	printf("Bem-vindo ao trabalho\n"
		   "Qual o tamanho da matriz?\n");
	std::cin >> n;
	std::cin.ignore();

	tnw::Vetor b(n),sol(n);
	tnw::MatrizQuadrada m(n),inversa(n);
	
	printf("Insira a matriz agora:\n");
	try {m=lerMatriz(n);}
	catch (std::invalid_argument e) {
		printf("\nValor Invalido!\n");
		return 1;
	}


	printf("Entre agora o vetor b\n");
	try {b=lerVetor(n);}
	catch (std::invalid_argument e) {
		printf("\nValor Invalido!\n");
		return 1;
	}

	printf("Entre a precisão que você deseja usar:\n");
	std::cin >> epsilon;
	std::cin.ignore();
	printf("\n");

	printf("Qual método você deseja usar,\n"
		   "  (S)eidel ou (J)acobi?\n");
	std::cin >> resposta;
	std::cin.ignore();
	switch(resposta) {
		case 'S':
			linhas = m.testeSassenfeld();
			if(linhas!=-1) 
				printf("Aviso: A matriz dada não passou no teste de Sassenfeld,\n"
					   "               E a culpa é da linha %d\n",linhas);
			sol = tnw::seidel(m,b,epsilon);
			inversa = tnw::inverterSeidel(m,epsilon);
			break;
		case 'J':
			linhas = m.testeLinhas();
			if(linhas!=-1) 
				printf("Aviso: A matriz dada não passou no teste das Linhas,\n"
					   "                E a culpa é da linha %d\n",linhas);
			sol = tnw::jacobi(m,b,epsilon);
			inversa = tnw::inverterJacobi(m,epsilon);
			break;
		default:
			printf("Opção invalida\n");
			return 1;
	}
	printf("\n");

	printf("Deseja ver os resultados aqui? (S) ou (N)\n");
	std::cin >> resposta;
	std::cin.ignore();
	
	if(resposta == 'S') {
		printf("A inversa da matriz é:\n%s\n",inversa.toString().c_str());
		printf("O resultado do sistema linear é:\n%s\n",sol.toString().c_str());
	}
	printf("\n");

	printf("Deseja salvar as matrizes em (C)SV ou (J)SON?\n"
		   "Digite qualquer outra coisa para não salvar.\n");
	std::cin >> resposta;
	std::cin.ignore();
	switch(resposta) {
		case 'C':
			printf("Entre agora o prefixo dos arquivos que iremos salvar\n");
			std::cin >> nomeArquivo;
			tnw::gerarCSV(m,nomeArquivo+"_original.csv");
			tnw::gerarCSV(b,nomeArquivo+"_coeficientes.csv");
			tnw::gerarCSV(inversa,nomeArquivo+"_inversa.csv");
			tnw::gerarCSV(sol,nomeArquivo+"_solução.csv");
			break;
		case 'J':
			printf("Entre agora o prefixo dos arquivos que iremos salvar\n");
			std::cin >> nomeArquivo;
			tnw::gerarJSON(m,nomeArquivo+"_original.json");
			tnw::gerarJSON(b,nomeArquivo+"_coeficientes.json");
			tnw::gerarJSON(inversa,nomeArquivo+"_inversa.json");
			tnw::gerarJSON(sol,nomeArquivo+"_solução.json");
			break;
	}
	printf("\n");

	return 0;
}

tnw::Vetor lerVetor(int n) {
	tnw::Vetor v(n);
	std::string str;
	for (int i = 0; i < n; ++i)
	{
		printf("[ ");
		std::cin >> std::noskipws >> str;
		v(i) = std::stod(str);
		std::cin.ignore();
		goUp(1);
		goRight(str.size()+2);
		printf(" ]\n");
	}
	return v;
}

tnw::MatrizQuadrada lerMatriz(int n) {
	tnw::MatrizQuadrada m(n);
	std::string str;
	for (int i = 0; i < n; ++i)
	{
		printf("[ ");
		for (int j = 0; j < n; ++j)
		{
			std::cin >> std::noskipws >> str;
			m(i,j) = std::stod(str);
			std::cin.ignore();

			if(j==0) {
				goUp(1);
				goRight(str.size()+3);
			}
			else {
				printf("\e[u");
				goRight(str.size()+1);
			}
			printf("\e[s");
		}
		printf("]\n");
	}
	return m;
}