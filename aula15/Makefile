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
.DEFAULT_GOAL := lab11

# Object files
Funcionario.o: $(SRC)/Funcionario.cpp $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Funcionario.cpp

Mensalista.o: $(SRC)/Mensalista.cpp $(SRC)/Mensalista.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Mensalista.cpp

Autonomo.o: $(SRC)/Autonomo.cpp $(SRC)/Autonomo.h $(SRC)/Funcionario.h
	$(CC) $(CFLAGS) -c $(SRC)/Autonomo.cpp

lab11.o: $(SRC)/lab11.cpp $(SRC)/Funcionario.h $(SRC)/Mensalista.h $(SRC)/Autonomo.h
	$(CC) $(CFLAGS) -c $(SRC)/lab11.cpp

# All
lab11: Funcionario.o Mensalista.o Autonomo.o lab11.o
	$(CC) $(CFLAGS) Funcionario.o Mensalista.o Autonomo.o lab11.o -o lab11

clean:
	rm -f *.o lab11
