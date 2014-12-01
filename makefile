# usando g++ como compilador
CC = g++

# compiler flags:
#  -g        adiciona informações de debug no executável
#  -Wall     ativa a maioria dos erros de compilação
#  -std=c+11 usa o standard mais recente
CFLAGS  = -g -Wall -std=c++11 -L lib

default: clean main

main: bin/main.o bin/gerarCSV.o bin/main.o bin/metodosNumericos.o lib/libmatriz.a
	$(CC) $(CFLAGS) -o bin/trabalho2 bin/main.o bin/gerarCSV.o bin/metodosNumericos.o -lmatriz

testeMatriz: lib/libmatriz.a bin/metodosNumericos.o 
	$(CC) $(CFLAGS) src/testeMatriz.cpp bin/metodosNumericos.o -o bin/testeMatriz -lmatriz

lib/libfuncoes.a:
	$(CC) $(CFLAGS) -c src/funções/implementadas/exponencial.cpp -o bin/exponencial.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/funcaoReal.cpp -o bin/funcaoReal.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/funcoesReais.cpp -o bin/funcoesReais.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/identidade.cpp -o bin/identidade.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/polinomios.cpp -o bin/polinomios.o
	$(CC) $(CFLAGS) -c src/funções/operadores.cpp -o bin/operadores.o
	ar rvs lib/libfuncoes.a bin/exponencial.o bin/funcaoReal.o bin/funcoesReais.o bin/identidade.o bin/polinomios.o bin/operadores.o
	rm bin/exponencial.o bin/funcaoReal.o bin/funcoesReais.o bin/identidade.o bin/polinomios.o bin/operadores.o

lib/libmatriz.a: src/matrizes/matrizes.h src/matrizes/matriz.cpp src/matrizes/vetor.cpp src/matrizes/operadores.cpp
	$(CC) $(CFLAGS) -c src/matrizes/matriz.cpp -o bin/matriz.o
	$(CC) $(CFLAGS) -c src/matrizes/vetor.cpp -o bin/vetor.o
	$(CC) $(CFLAGS) -c src/matrizes/operadores.cpp -o bin/operadores.o
	$(CC) $(CFLAGS) -c src/auxiliar/tempo.cpp -o bin/tempo.o
	ar rvs lib/libmatriz.a bin/operadores.o bin/vetor.o bin/matriz.o bin/tempo.o
	rm bin/matriz.o bin/vetor.o bin/operadores.o bin/tempo.o

bin/metodosNumericos.o: src/métodos/metodosNumericos.cpp
	$(CC) $(CFLAGS) -c src/métodos/metodosNumericos.cpp -o bin/metodosNumericos.o
	
bin/gerarCSV.o: src/auxiliar/gerarCSV.cpp
	$(CC) $(CFLAGS) -c src/auxiliar/gerarCSV.cpp -o bin/gerarCSV.o

bin/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp -o bin/main.o

clean:
	-rm -f bin/*