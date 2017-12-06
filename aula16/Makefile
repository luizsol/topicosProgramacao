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
.DEFAULT_GOAL := p3

# Object files
AcessoDados.o: $(SRC)/AcessoDados.cpp $(SRC)/AcessoDados.h
	$(CC) $(CFLAGS) -c $(SRC)/AcessoDados.cpp

Autonomo.o: $(SRC)/Autonomo.cpp $(SRC)/Autonomo.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Autonomo.cpp

CadastroPessoas.o: $(SRC)/CadastroPessoas.cpp $(SRC)/CadastroPessoas.h $(SRC)/AcessoDados.h
	$(CC) $(CFLAGS) -c $(SRC)/CadastroPessoas.cpp

ContribuicaoSindical.o: $(SRC)/ContribuicaoSindical.cpp $(SRC)/ContribuicaoSindical.h $(SRC)/AcessoDados.h
	$(CC) $(CFLAGS) -c $(SRC)/ContribuicaoSindical.cpp

Empresa.o: $(SRC)/Empresa.cpp $(SRC)/Empresa.h $(SRC)/Funcionario.h $(SRC)/CadastroPessoas.h $(SRC)/ContribuicaoSindical.h $(SRC)/ImpostoRenda.h $(SRC)/TabelaSalarial.h
	$(CC) $(CFLAGS) -c $(SRC)/Empresa.cpp

Funcionario.o: $(SRC)/Funcionario.cpp $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Funcionario.cpp

HorasTrabalhadas.o: $(SRC)/HorasTrabalhadas.cpp $(SRC)/HorasTrabalhadas.h
	$(CC) $(CFLAGS) -c $(SRC)/HorasTrabalhadas.cpp

ImpostoRenda.o: $(SRC)/ImpostoRenda.cpp $(SRC)/ImpostoRenda.h $(SRC)/AcessoDados.h
	$(CC) $(CFLAGS) -c $(SRC)/ImpostoRenda.cpp

Mensalista.o: $(SRC)/Mensalista.cpp $(SRC)/Mensalista.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Mensalista.cpp

TabelaSalarial.o: $(SRC)/TabelaSalarial.cpp $(SRC)/TabelaSalarial.h
	$(CC) $(CFLAGS) -c $(SRC)/TabelaSalarial.cpp

p3.o: $(SRC)/p3.cpp $(SRC)/Funcionario.h $(SRC)/Mensalista.h $(SRC)/Autonomo.h
	$(CC) $(CFLAGS) -c $(SRC)/p3.cpp

# All
p3: AcessoDados.o Autonomo.o CadastroPessoas.o ContribuicaoSindical.o Empresa.o Funcionario.o HorasTrabalhadas.o ImpostoRenda.o Mensalista.o TabelaSalarial.o p3.o
	$(CC) $(CFLAGS) AcessoDados.o Autonomo.o CadastroPessoas.o ContribuicaoSindical.o Empresa.o Funcionario.o HorasTrabalhadas.o ImpostoRenda.o Mensalista.o TabelaSalarial.o p3.o -o p3

clean:
	rm -f *.o p3
