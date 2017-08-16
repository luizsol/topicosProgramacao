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
.DEFAULT_GOAL := main

# Object files
Funcionario.o: src/Funcionario.cpp src/Funcionario.h
	$(CC) $(CFLAGS) -c src/Funcionario.cpp

lab1-4.o: src/lab1-4.cpp
	$(CC) $(CFLAGS) -c src/lab1-4.cpp

# All
lab1-4: Funcionario.o lab1-4.o
	$(CC) $(CFLAGS) Funcionario.o lab1-4.o -o lab1-4 # $(LIBS)

# all main: main.o lumiar.o pwm.o queue.o web.o ldr.o
# 	$(CC) $(CFLAGS) queue.o web.o pwm.o main.o lumiar.o ldr.o -o web $(LIBS)

clean:
	rm -f *.o lab1-4