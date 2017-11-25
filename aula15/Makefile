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
.DEFAULT_GOAL := lab12

# Object files
AcessoDados.o: $(SRC)/AcessoDados.cpp $(SRC)/AcessoDados.h
	$(CC) $(CFLAGS) -c $(SRC)/AcessoDados.cpp

Autonomo.o: $(SRC)/Autonomo.cpp $(SRC)/Autonomo.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Autonomo.cpp

Funcionario.o: $(SRC)/Funcionario.cpp $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Funcionario.cpp

HorasTrabalhadas.o: $(SRC)/HorasTrabalhadas.cpp $(SRC)/HorasTrabalhadas.h
	$(CC) $(CFLAGS) -c $(SRC)/HorasTrabalhadas.cpp

Mensalista.o: $(SRC)/Mensalista.cpp $(SRC)/Mensalista.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Mensalista.cpp

TabelaSalarial.o: $(SRC)/TabelaSalarial.cpp $(SRC)/TabelaSalarial.h
	$(CC) $(CFLAGS) -c $(SRC)/TabelaSalarial.cpp

lab12.o: $(SRC)/lab12.cpp $(SRC)/Funcionario.h $(SRC)/Mensalista.h $(SRC)/Autonomo.h
	$(CC) $(CFLAGS) -c $(SRC)/lab12.cpp

# All
lab12: Funcionario.o Mensalista.o Autonomo.o lab12.o
	$(CC) $(CFLAGS) Funcionario.o Mensalista.o Autonomo.o lab12.o -o lab12

clean:
	rm -f *.o lab12
