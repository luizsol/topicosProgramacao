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
.DEFAULT_GOAL := p1

# Object files
Funcionario.o: $(SRC)/Funcionario.cpp $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Funcionario.cpp

CadastroPessoas.o: $(SRC)/CadastroPessoas.cpp $(SRC)/CadastroPessoas.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/CadastroPessoas.cpp

TabelaSalarial.o: $(SRC)/TabelaSalarial.cpp $(SRC)/TabelaSalarial.h
	$(CC) $(CFLAGS) -c $(SRC)/TabelaSalarial.cpp

ContribuicaoSindical.o: $(SRC)/ContribuicaoSindical.cpp $(SRC)/ContribuicaoSindical.h
	$(CC) $(CFLAGS) -c $(SRC)/ContribuicaoSindical.cpp

Empresa.o: $(SRC)/Empresa.cpp $(SRC)/Empresa.h $(SRC)/CadastroPessoas.h $(SRC)/Funcionario.h $(SRC)/TabelaSalarial.h $(SRC)/ContribuicaoSindical.h
	$(CC) $(CFLAGS) -c $(SRC)/Empresa.cpp

p1.o: $(SRC)/p1.cpp $(SRC)/Empresa.h
	$(CC) $(CFLAGS) -c $(SRC)/p1.cpp

# All
p1: Funcionario.o Empresa.o CadastroPessoas.o TabelaSalarial.o ContribuicaoSindical.o p1.o
	$(CC) $(CFLAGS) Funcionario.o Empresa.o CadastroPessoas.o TabelaSalarial.o ContribuicaoSindical.o p1.o -o p1

# Test
TestContribuicaoSindical.o: $(TDIR)/TestContribuicaoSindical.cpp $(SRC)/ContribuicaoSindical.h
	$(CC) $(CFLAGS) -c $(TDIR)/TestContribuicaoSindical.cpp

tests TestContribuicaoSindical: TestContribuicaoSindical.o ContribuicaoSindical.o
	$(CC) $(CFLAGS) TestContribuicaoSindical.o ContribuicaoSindical.o -o testContribuicaoSindical

clean:
	rm -f *.o p1