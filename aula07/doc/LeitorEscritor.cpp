#include "LeitorEscritor.h"
LeitorEscritor::LeitorEscritor(void)
{
}
LeitorEscritor::~LeitorEscritor(void)
{
}
LeitorEscritor::LeitorEscritor (string nomeArquivo){
	this->nomeArquivo = nomeArquivo;
	arquivo.open(nomeArquivo.c_str(), ios::app);
	//arquivo.open("nomeArquivo", 'ios::flag');
	/*Temos as seguintes flags:
	app (append) -> coloca o cursor no fim do stream 
	in (input) -> coloca o cursor no começo do stream
	out (output) -> coloca o cursor no começo do stream e escreve
	trunc (truncate) -> descarta o conteúdo atual (reseta o arquivo)
	*/
}
void LeitorEscritor::escreverNovaLinha(string mensagem){	
	if(!arquivo.is_open())
		arquivo.open(this->nomeArquivo.c_str(), ios::app);
	arquivo << endl <<mensagem.c_str(); //pula linha e escrevo.
	
	arquivo.close();
}
void LeitorEscritor::escreverSequencial(string mensagem){
	if(!arquivo.is_open())
		arquivo.open(this->nomeArquivo.c_str(),ios::app);
	arquivo << mensagem.c_str(); 
	
	arquivo.close();
}
void LeitorEscritor::terminar(){
	if(arquivo.is_open()){		
		arquivo.close();
	}
}
void LeitorEscritor::mostrarNaTela(){
	string tudo ="";
	string temp = "";
	arquivo.open(this->nomeArquivo.c_str(),ios::in);
	while(arquivo.good()){
		getline(arquivo, temp);
		tudo+=temp+'\n';
	}
	cout<<tudo;
	arquivo.close();
	
}
