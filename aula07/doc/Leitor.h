#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Esta classe fornece os serviços necessários para acessar um arquivo e ler dados a partir dele.
class Leitor
{
public:
	Leitor(void);
	~Leitor(void);
	Leitor(string nome);
	bool conectar(string nome); 
	//este método recebe o caminho para um arquivo ou apenas seu nome 
	//se o arquivo estiver na mesma pasta do executável
	//se a conexão der certo, retorna true, se não, false.

	void desconectar ();
	string lerConteudo();
private:
	string nomeArquivo;
	ifstream arquivo;
};

