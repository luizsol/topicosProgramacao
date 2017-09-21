#include "Leitor.h"
#include "Escritor.h"
#include "LeitorEscritor.h"
#include <iostream>

using namespace std;

 void exemploLeitura(){
	string mensagem = "";
	string conteudo = "";
	Leitor* leitor = new Leitor();
	cout << "Exemplo de Leitura" << endl;
	if(leitor->conectar("ler.txt")){
		mensagem = "Sucesso, arquivo aberto";
	}else { mensagem = "Erro na abertura do arquivo";}
	cout<<mensagem<<endl;

	cout<<"Escrevendo na tela o conteudo do arquivo"<<endl;
	conteudo = leitor->lerConteudo();
	cout<<conteudo<<endl;
	leitor->desconectar();
}
 
void exemploEscrita(){
	string mensagem = "";
	cout << "Exemplo de Escrita" << endl;
	cout<<"Escrita em escrever.txt"<<endl;
	Escritor* escritor = new Escritor("escrever.txt");	
	escritor->escrever("escrever em modo ios::in", "in"); //passa como parametro o modo de escrita
	escritor->terminar();
}
void exemploLeituraEscrita (){
	cout << "Exemplo de Leitura e Escrita" << endl;
	LeitorEscritor* el = new LeitorEscritor("lerEscrever.txt");
	el->mostrarNaTela();
	el->escreverSequencial("Mensagem Sequencial");
	el->escreverNovaLinha("Mensagem com nova linha");
	el->mostrarNaTela();
	el->terminar();

}
int main(void){
	exemploLeitura();
	//exemploEscrita();
	//exemploLeituraEscrita();
	return 0;
}
