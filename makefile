# usando g++ como compilador
CC = g++

# compiler flags:
#  -g        adiciona informações de debug no executável
#  -Wall     ativa a maioria dos erros de compilação
#  -std=c+11 usa o standard mais recente
CFLAGS  = -g -Wall -std=c++11

default: clean all

teste: clean bin/teste.o funcoesReais
	$(CC) $(CFLAGS) -o bin/teste bin/teste.o bin/funcoesReais.o bin/funcaoReal.o bin/polinomios.o bin/exponencial.o bin/identidade.o bin/operadores.o
	bin/teste | less

bin/teste.o: src/teste.cpp src/funções/funcoes.h
	$(CC) $(CFLAGS) -c src/teste.cpp -o bin/teste.o

funcoesReais:
	$(CC) $(CFLAGS) -c src/funções/implementadas/exponencial.cpp -o bin/exponencial.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/funcaoReal.cpp -o bin/funcaoReal.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/funcoesReais.cpp -o bin/funcoesReais.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/identidade.cpp -o bin/identidade.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/polinomios.cpp -o bin/polinomios.o
	$(CC) $(CFLAGS) -c src/funções/operadores.cpp -o bin/operadores.o

clean:
	-rm -f bin/*