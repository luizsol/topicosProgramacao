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
.DEFAULT_GOAL := lab3

# Object files
Funcionario.o: $(SRC)/Funcionario.cpp $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Funcionario.cpp

Empresa.o: $(SRC)/Empresa.cpp $(SRC)/Empresa.h $(SRC)/CadastroPessoas.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Empresa.cpp

CadastroPessoas.o: $(SRC)/CadastroPessoas.cpp $(SRC)/CadastroPessoas.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/CadastroPessoas.cpp

lab3.o: $(SRC)/lab3.cpp $(SRC)/Empresa.h
	$(CC) $(CFLAGS) -c $(SRC)/lab3.cpp

# All
lab3: Funcionario.o Empresa.o CadastroPessoas.o lab3.o
	$(CC) $(CFLAGS) Funcionario.o Empresa.o CadastroPessoas.o lab3.o -o lab3

# Tests
CadastroPessoasTest.o: $(TDIR)/CadastroPessoasTest.cpp
	$(CC) $(CFLAGS) -c $(TDIR)/CadastroPessoasTest.cpp

cadastroPessoasTest: CadastroPessoasTest.o CadastroPessoas.o
	$(CC) $(CFLAGS) CadastroPessoasTest.o CadastroPessoas.o -o cadastroPessoasTest

EmpresaTest.o: $(TDIR)/EmpresaTest.cpp
	$(CC) $(CFLAGS) -c $(TDIR)/EmpresaTest.cpp

empresaTest: EmpresaTest.o Empresa.o Funcionario.o CadastroPessoas.o
	$(CC) $(CFLAGS) EmpresaTest.o Empresa.o Funcionario.o CadastroPessoas.o -o empresaTest

tests: cadastroPessoasTest empresaTest

clean:
	rm -f *.o lab3 cadastroPessoasTest empresaTest