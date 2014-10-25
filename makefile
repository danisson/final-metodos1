# usando g++ como compilador
CC = g++

# compiler flags:
#  -g        adiciona informações de debug no executável
#  -Wall     ativa a maioria dos erros de compilação
#  -std=c+11 usa o standard mais recente
CFLAGS  = -g -Wall -std=c++11

default: clean all

teste: clean bin/aplicacoes.o bin/metodosNumericos.o funcoesReais
	$(CC) $(CFLAGS) -o bin/teste bin/aplicacoes.o bin/funcoesReais.o bin/funcaoReal.o bin/polinomios.o bin/exponencial.o bin/identidade.o bin/operadores.o bin/metodosNumericos.o bin/auxiliar.o
	bin/teste

bin/teste.o: src/teste.cpp src/funções/funcoes.h src/métodos/metodosNumericos.h
	$(CC) $(CFLAGS) -c src/teste.cpp -o bin/teste.o

bin/aplicacoes.o: src/aplicações/aplicacoes.cpp src/aplicações/aplicacoes.h src/funções/funcoes.h src/métodos/metodosNumericos.h src/auxiliar/auxiliar.h
	$(CC) $(CFLAGS) -c src/aplicações/aplicacoes.cpp -o bin/aplicacoes.o

#OBS: o auxiliar.o não está sendo encontrado e não faço ideia do porquê, por isso o make file não está funcionando
bin/auxiliar.o: src/auxiliar/auxiliar.cpp src/auxiliar/auxiliar.h
	$(CC) $(CFLAGS) -c src/auxiliar/auxiliar.cpp -o bin/auxiliar.o

funcoesReais:
	$(CC) $(CFLAGS) -c src/funções/implementadas/exponencial.cpp -o bin/exponencial.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/funcaoReal.cpp -o bin/funcaoReal.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/funcoesReais.cpp -o bin/funcoesReais.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/identidade.cpp -o bin/identidade.o
	$(CC) $(CFLAGS) -c src/funções/implementadas/polinomios.cpp -o bin/polinomios.o
	$(CC) $(CFLAGS) -c src/funções/operadores.cpp -o bin/operadores.o

bin/metodosNumericos.o: src/métodos/metodosNumericos.cpp src/métodos/metodosNumericos.h src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/métodos/metodosNumericos.cpp -o bin/metodosNumericos.o

clean:
	-rm -f bin/*