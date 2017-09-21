#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Escritor
{
public:
	Escritor(void);
	Escritor (string nomeArquivo);
	~Escritor(void);
	void escrever(string mensagem, string modo);

	void terminar();
private:
	
	ofstream arquivo;
	string nomeArquivo;
};

