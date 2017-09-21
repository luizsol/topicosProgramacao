#include "Leitor.h"
Leitor::Leitor(void)
{
}
Leitor::Leitor(string nome){
	arquivo.open(nome.c_str()); //
}
Leitor::~Leitor(void)
{
}
bool Leitor::conectar(string nome){	
	arquivo.open(nome.c_str());
	return arquivo.is_open();
}
void Leitor::desconectar(){
	if (arquivo.is_open()){
		arquivo.close();
		cout<<"::desconectar()"<<endl;
	}
}
string Leitor::lerConteudo(){
	string temp, linha;
	while (arquivo.good() ) /*percorre o arquivo enquanto este estiver aberto e não tiver achado o fim (EOF)*/
	{
		getline (arquivo,linha); 
		temp+=linha+'\n'; /*aqui é adicionado o '/n' na string retornada, pois o getline() não a inclui*/
	}
	return temp;
}


