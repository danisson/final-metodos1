# usando g++ como compilador
CC = g++

# compiler flags:
#  -g        adiciona informações de debug no executável
#  -Wall     ativa a maioria dos erros de compilação
#  -std=c+11 usa o standard mais recente
CFLAGS  = -g -Wall -std=c++11

default: clean all

teste: clean bin/teste.o bin/funcoesReais.o bin/funcaoReal.o bin/polinomios.o bin/exponencial.o bin/identidade.o bin/metodosNumericos.o
	$(CC) $(CFLAGS) -o bin/teste bin/teste.o bin/funcoesReais.o bin/funcaoReal.o bin/polinomios.o bin/exponencial.o bin/identidade.o bin/metodosNumericos.o
	bin/teste

bin/teste.o: src/teste.cpp src/funções/funcoesReais.h src/métodos/metodosNumericos.h
	$(CC) $(CFLAGS) -c src/teste.cpp -o bin/teste.o

bin/funcoesReais.o: src/funções/funcoesReais.cpp src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/funções/funcoesReais.cpp -o bin/funcoesReais.o

bin/funcaoReal.o: src/funções/funcaoReal.cpp src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/funções/funcaoReal.cpp -o bin/funcaoReal.o

bin/polinomios.o: src/funções/polinomios.cpp src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/funções/polinomios.cpp -o bin/polinomios.o

bin/exponencial.o: src/funções/exponencial.cpp src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/funções/exponencial.cpp -o bin/exponencial.o

bin/identidade.o: src/funções/identidade.cpp src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/funções/identidade.cpp -o bin/identidade.o

bin/metodosNumericos.o: src/métodos/metodosNumericos.cpp src/métodos/metodosNumericos.h src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/métodos/metodosNumericos.cpp -o bin/metodosNumericos.o

clean:
	-rm -f bin/*