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
.DEFAULT_GOAL := lab6

# Object files
AcessoDados.o: $(SRC)/AcessoDados.cpp $(SRC)/AcessoDados.h $(SRC)/globais.h
	$(CC) $(CFLAGS) -c $(SRC)/AcessoDados.cpp

Funcionario.o: $(SRC)/Funcionario.cpp $(SRC)/Funcionario.h $(SRC)/globais.h
	$(CC) $(CFLAGS) -c $(SRC)/Funcionario.cpp

CadastroPessoas.o: $(SRC)/CadastroPessoas.cpp $(SRC)/CadastroPessoas.h $(SRC)/AcessoDados.h $(SRC)/globais.h
	$(CC) $(CFLAGS) -c $(SRC)/CadastroPessoas.cpp

ContribuicaoSindical.o: $(SRC)/ContribuicaoSindical.cpp $(SRC)/ContribuicaoSindical.h $(SRC)/AcessoDados.h $(SRC)/globais.h
	$(CC) $(CFLAGS) -c $(SRC)/ContribuicaoSindical.cpp

ImpostoRenda.o: $(SRC)/ImpostoRenda.cpp $(SRC)/ImpostoRenda.h $(SRC)/AcessoDados.h $(SRC)/globais.h
	$(CC) $(CFLAGS) -c $(SRC)/ImpostoRenda.cpp

TabelaSalarial.o: $(SRC)/TabelaSalarial.cpp $(SRC)/TabelaSalarial.h $(SRC)/AcessoDados.h $(SRC)/globais.h
	$(CC) $(CFLAGS) -c $(SRC)/TabelaSalarial.cpp

Empresa.o: $(SRC)/Empresa.cpp $(SRC)/Empresa.h $(SRC)/Funcionario.h $(SRC)/CadastroPessoas.h $(SRC)/ContribuicaoSindical.h $(SRC)/ImpostoRenda.h $(SRC)/TabelaSalarial.h
	$(CC) $(CFLAGS) -c $(SRC)/Empresa.cpp

lab6.o: $(SRC)/lab6.cpp $(SRC)/Empresa.h $(SRC)/AcessoDados.h $(SRC)/globais.h
	$(CC) $(CFLAGS) -c $(SRC)/lab6.cpp

# All
lab6: AcessoDados.o Funcionario.o CadastroPessoas.o ContribuicaoSindical.o ImpostoRenda.o TabelaSalarial.o Empresa.o lab6.o
	$(CC) $(CFLAGS) AcessoDados.o Funcionario.o CadastroPessoas.o ContribuicaoSindical.o ImpostoRenda.o TabelaSalarial.o Empresa.o lab6.o -o lab6

clean:
	rm -f *.o lab6