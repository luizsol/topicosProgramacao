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
.DEFAULT_GOAL := lab5

# Object files
ImpostoRenda.o: $(SRC)/ImpostoRenda.cpp $(SRC)/ImpostoRenda.h
	$(CC) $(CFLAGS) -c $(SRC)/ImpostoRenda.cpp

lab5.o: $(SRC)/lab5.cpp $(SRC)/ImpostoRenda.h
	$(CC) $(CFLAGS) -c $(SRC)/lab5.cpp

# All
lab5: ImpostoRenda.o lab5.o
	$(CC) $(CFLAGS) ImpostoRenda.o lab5.o -o la5

clean:
	rm -f *.o lab5