# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -std=c++11

default: clean all

all: bin/teste.o bin/funcoesReais.o bin/funcaoReal.o bin/polinomios.o bin/exponencial.o
	$(CC) $(CFLAGS) -o bin/teste bin/teste.o bin/funcoesReais.o bin/funcaoReal.o bin/polinomios.o bin/exponencial.o

bin/teste.o: src/teste.cpp src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/teste.cpp -o bin/teste.o

bin/funcoesReais.o: src/funções/funcoesReais.cpp src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/funções/funcoesReais.cpp -o bin/funcoesReais.o

bin/funcaoReal.o: src/funções/funcaoReal.cpp src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/funções/funcaoReal.cpp -o bin/funcaoReal.o

bin/polinomios.o: src/funções/polinomios.cpp src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/funções/polinomios.cpp -o bin/polinomios.o

bin/exponencial.o: src/funções/exponencial.cpp src/funções/funcoesReais.h
	$(CC) $(CFLAGS) -c src/funções/exponencial.cpp -o bin/exponencial.o

clean:
	-rm -f bin/*