#include "Escritor.h"

Escritor::Escritor(void)
{
}
Escritor::Escritor(string nomeArquivo){
	this->nomeArquivo= nomeArquivo;
}
Escritor::~Escritor(void)
{
}

void Escritor::escrever(string mensagem, string modo){
	
	if (!arquivo.is_open()) {
		if (modo.compare("app") == 0) {
			arquivo.open(this->nomeArquivo.c_str(), ios::app); 
			//adiciona a mensagem no fim do arquivo.
		}
		else if (modo.compare("out") == 0) {
			arquivo.open(this->nomeArquivo.c_str(), ios::out);
			//apaga o arquivo e escreve no começo do arquivo. 
		}
		else if (modo.compare("trunc") == 0) {
			arquivo.open(this->nomeArquivo.c_str(), ios::trunc); 
			//apaga o arquivo e escreve no começo do arquivo.
		}
		else if (modo.compare("in") == 0) {
			arquivo.open(this->nomeArquivo.c_str(), ios::in);
			//escreve a partir do começo do arquivo, sobre-escrevendo-o.
		}
	}
	
	arquivo << mensagem.c_str();
	arquivo.close();
}

void Escritor::terminar(){
	if( arquivo.is_open()){
		arquivo.close();
		cout<<"::terminar()"<<endl;
	}
}