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

# Goals
.DEFAULT_GOAL := lab2

# Object files
Funcionario.o: src/Funcionario.cpp src/Funcionario.h
	$(CC) $(CFLAGS) -c src/Funcionario.cpp

Empresa.o: src/Empresa.cpp src/Empresa.h
	$(CC) $(CFLAGS) -c src/Empresa.cpp

lab2.o: src/lab2.cpp
	$(CC) $(CFLAGS) -c src/lab2.cpp

# All
lab2: Funcionario.o Empresa.o lab2.o
	$(CC) $(CFLAGS) Funcionario.o Empresa.o lab2.o -o lab2 # $(LIBS)

clean:
	rm -f *.o lab2