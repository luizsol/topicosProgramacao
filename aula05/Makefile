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
.DEFAULT_GOAL := lab4

# Object files
Funcionario.o: $(SRC)/Funcionario.cpp $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Funcionario.cpp

Empresa.o: $(SRC)/Empresa.cpp $(SRC)/Empresa.h $(SRC)/CadastroPessoas.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Empresa.cpp

CadastroPessoas.o: $(SRC)/CadastroPessoas.cpp $(SRC)/CadastroPessoas.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/CadastroPessoas.cpp

TabelaSalarial.o: $(SRC)/TabelaSalarial.cpp $(SRC)/TabelaSalarial.h
	$(CC) $(CFLAGS) -c $(SRC)/TabelaSalarial.cpp

lab4.o: $(SRC)/lab4.cpp $(SRC)/Empresa.h
	$(CC) $(CFLAGS) -c $(SRC)/lab4.cpp

# All
lab4: Funcionario.o Empresa.o CadastroPessoas.o TabelaSalarial.o lab4.o
	$(CC) $(CFLAGS) Funcionario.o Empresa.o CadastroPessoas.o TabelaSalarial.o lab4.o -o lab4

# Tests
CadastroPessoasTest.o: $(TDIR)/CadastroPessoasTest.cpp
	$(CC) $(CFLAGS) -c $(TDIR)/CadastroPessoasTest.cpp

cadastroPessoasTest: CadastroPessoasTest.o CadastroPessoas.o
	$(CC) $(CFLAGS) CadastroPessoasTest.o CadastroPessoas.o -o cadastroPessoasTest

EmpresaTest.o: $(TDIR)/EmpresaTest.cpp
	$(CC) $(CFLAGS) -c $(TDIR)/EmpresaTest.cpp

empresaTest: EmpresaTest.o Empresa.o Funcionario.o CadastroPessoas.o
	$(CC) $(CFLAGS) EmpresaTest.o Empresa.o Funcionario.o CadastroPessoas.o -o empresaTest

TabelaSalarialTest.o: $(TDIR)/TabelaSalarialTest.cpp $(SRC)/TabelaSalarial.h
	$(CC) $(CFLAGS) -c $(TDIR)/TabelaSalarialTest.cpp

tabelaSalarialTest: TabelaSalarialTest.o TabelaSalarial.o
	$(CC) $(CFLAGS) TabelaSalarialTest.o TabelaSalarial.o -o tabelaSalarialTest

tests: cadastroPessoasTest empresaTest tabelaSalarialTest

clean:
	rm -f *.o lab4 cadastroPessoasTest empresaTest tabelaSalarialTest