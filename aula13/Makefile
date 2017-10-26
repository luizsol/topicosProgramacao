# Makefile

# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11

# Enable warnings
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpedantic

# Library includes
# LIBS = -lpthread -lwiringPi

# Directories
TDIR = test
SRC = src

# Goals
.DEFAULT_GOAL := p2

# Object files
Funcionario.o: $(SRC)/Funcionario.cpp $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Funcionario.cpp

AcessoDados.o: $(SRC)/AcessoDados.cpp $(SRC)/AcessoDados.h $(SRC)/globais.h
	$(CC) $(CFLAGS) -c $(SRC)/AcessoDados.cpp

CadastroPessoas.o: $(SRC)/CadastroPessoas.cpp $(SRC)/CadastroPessoas.h $(SRC)/AcessoDados.h
	$(CC) $(CFLAGS) -c $(SRC)/CadastroPessoas.cpp

ContribuicaoSindical.o: $(SRC)/ContribuicaoSindical.cpp $(SRC)/ContribuicaoSindical.h $(SRC)/AcessoDados.h
	$(CC) $(CFLAGS) -c $(SRC)/ContribuicaoSindical.cpp

ImpostoRenda.o: $(SRC)/ImpostoRenda.cpp $(SRC)/ImpostoRenda.h $(SRC)/AcessoDados.h
	$(CC) $(CFLAGS) -c $(SRC)/ImpostoRenda.cpp

TabelaSalarial.o: $(SRC)/TabelaSalarial.cpp $(SRC)/TabelaSalarial.h $(SRC)/AcessoDados.h
	$(CC) $(CFLAGS) -c $(SRC)/TabelaSalarial.cpp

Empresa.o: $(SRC)/Empresa.cpp $(SRC)/Empresa.h $(SRC)/Funcionario.h $(SRC)/CadastroPessoas.h $(SRC)/ContribuicaoSindical.h $(SRC)/ImpostoRenda.h $(SRC)/TabelaSalarial.h
	$(CC) $(CFLAGS) -c $(SRC)/Empresa.cpp

p2.o: $(SRC)/p2.cpp $(SRC)/ImpostoRenda.h $(SRC)/Empresa.h
	$(CC) $(CFLAGS) -c $(SRC)/p2.cpp

# All
p2: Funcionario.o AcessoDados.o CadastroPessoas.o ContribuicaoSindical.o ImpostoRenda.o TabelaSalarial.o Empresa.o p2.o
	$(CC) $(CFLAGS) Funcionario.o AcessoDados.o CadastroPessoas.o ContribuicaoSindical.o ImpostoRenda.o TabelaSalarial.o Empresa.o p2.o -o p2

clean:
	rm -f *.o p2
