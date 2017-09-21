#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class LeitorEscritor

{
public:
	LeitorEscritor(void);
	~LeitorEscritor(void);
	LeitorEscritor(string nomeArquivo);
	void escreverNovaLinha(string mensagem);
	void escreverSequencial(string mensagem);
	void mostrarNaTela();
	string retornarStringDoArquivo();
	void terminar();
private:
	fstream arquivo;
	string nomeArquivo;
};

