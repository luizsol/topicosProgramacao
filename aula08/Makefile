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
Funcionario.o: $(SRC)/Funcionario.cpp $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Funcionario.cpp

CadastroPessoas.o: $(SRC)/CadastroPessoas.cpp $(SRC)/CadastroPessoas.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/CadastroPessoas.cpp

TabelaSalarial.o: $(SRC)/TabelaSalarial.cpp $(SRC)/TabelaSalarial.h
	$(CC) $(CFLAGS) -c $(SRC)/TabelaSalarial.cpp

Empresa.o: $(SRC)/Empresa.cpp $(SRC)/Empresa.h $(SRC)/CadastroPessoas.h $(SRC)/Funcionario.h $(SRC)/TabelaSalarial.h
	$(CC) $(CFLAGS) -c $(SRC)/Empresa.cpp

lab6.o: $(SRC)/lab6.cpp $(SRC)/Empresa.h
	$(CC) $(CFLAGS) -c $(SRC)/lab6.cpp

# All
lab6: Funcionario.o Empresa.o CadastroPessoas.o TabelaSalarial.o lab6.o
	$(CC) $(CFLAGS) Funcionario.o Empresa.o CadastroPessoas.o TabelaSalarial.o lab6.o -o lab6

clean:
	rm -f *.o lab6