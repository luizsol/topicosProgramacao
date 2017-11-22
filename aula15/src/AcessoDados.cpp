/**
    PCS2478 - Tópicos de Programação
    AcessoDados.cpp

	@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
	@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
	@version 14.0 2017-11-22
*/

#include "AcessoDados.h"

using namespace std;

//Construtores e destrutores
AcessoDados::AcessoDados(){}

AcessoDados::~AcessoDados(){}

/**
    Lê todos os dados contidos em um determinado arquivo.

    @param arq (Arquivos): a enum que determina o arquivo a ser lido.
    @return true se a string for válida, false caso contrário
*/
string AcessoDados::lerTudo(Arquivos arq){
  AcessoDados::conectar(arq, LEITURA);

  string linha = "";
  string out = "";

  while(!this->arquivo.eof() && getline(this->arquivo, linha)){
    out.append(linha);
    out.append("\n");
  }

  AcessoDados::desconectar();

  return out;
}

/**
    Realiza uma busca por uma chave em uma determidada coluna de um arquivo de
    registros.

    Caso o valor da chave seja uma string vazia a pesquisa retornará todo o
    conteúdo do arquivo de registros.

    @param arq (Arquivos): o enum que descreve o arquivo a ser aberto.
    @param valChave (string): o valor a ser buscado na coluna do arquivo de
      registros.
    @param chave (Campos): o enum que representa a coluna a ser avaliada na
      busca.
    @return a concatenação de todas as linhas que se enquadram no critério da
      busca.
*/
string AcessoDados::ler(Arquivos arq, string valChave, Campos chave){
  if(valChave == ""){
    return AcessoDados::lerTudo(arq);
  }

  AcessoDados::conectar(arq, LEITURA);

  string resultado;
  string linha = "";
  string out = "";
  vector<string> vetorlinha;

  while(!this->arquivo.eof() && getline(this->arquivo, linha)){
    vetorlinha = AcessoDados::splitDado(linha.append("\n"));
    if(vetorlinha[chave] == valChave){
      out.append(linha);
    }
  }

  AcessoDados::desconectar();

  return out;
}

/**
    Retorna um vector de strings contendo os diferentes campos de uma linha.

    @param dado (string): o dado a ser processado
    @return o vetor de strings contendo os diferentes campos de uma linha.
    @throw caso o argumento seja inválido (invalid_argument)
*/
vector<string> AcessoDados::splitDado(string dado){
  vector<string> result;
  unsigned int start = 0;
  unsigned int i = 1;

  while(i < dado.length()){
    if(dado.at(i) == '|'){
      if(start == i){
        throw std::invalid_argument("AcessoDados::splitDado: String invalida.");
      }
      result.push_back(dado.substr(start, i - start));
      start = i + 1;
    }
    i++;
  }

  return result;
}

/**
    Retorna um vector de strings diferentes linhas de um arquivo.

    @param dado (string): o dado a ser processado
    @return um vector de strings diferentes linhas de um arquivo.
    @throw caso o argumento seja inválido (invalid_argument)
*/
vector<string> AcessoDados::splitLinha(string dado){
  vector<string> result;
  unsigned int start = 0;
  unsigned int i = 1;

  while(i < dado.length()){
    if(dado.at(i) == '\n'){
      if(start == i){
        throw std::invalid_argument("AcessoDados::splitLinha: String invalida.");
      }
      result.push_back(dado.substr(start, i - start));
      start = i + 1;
    }
    i++;
  }

  return result;
}

/**
    Insere uma nova linha em um arquivo.

    @param arq (Arquivos): o enum que descreve o arquivo a ser aberto.
    @param registro (string): a linha a ser adicionada ao arquivo.
    @return true se a operação for bem sucedida.
*/
bool AcessoDados::inserir(Arquivos arq, string registro){
  AcessoDados::conectar(arq, INSERCAO);
  arquivo << registro << endl;
  AcessoDados::desconectar();
  return true;
}

/**
    Realiza uma busca por uma chave em uma determidada coluna de um arquivo de
    registros e atualiza as linhas resultantes da busca.

    Caso o valor da chave seja uma string vazia a pesquisa retornará todo o
    conteúdo do arquivo de registros.

    @param arq (Arquivos): o enum que descreve o arquivo a ser aberto.
    @param valChave (string): o valor a ser buscado na coluna do arquivo de
      registros.
    @param chave (Campos): o enum que representa a coluna a ser avaliada na
      busca.
    @param novoValor (string): o valor que substituirá o valor a ser subscrito.
    @param campo (Campos): o enum que representa a coluna onde o novo dado será
      inserido (não precisa ser necessariamente o mesmo que foi utilizado na
      busca).
    @return true se pelo menos uma linha for atualizada.
*/
bool AcessoDados::atualizar(Arquivos arq, string valChave, Campos chave,
                            string novoValor, Campos campo){
  string dados = AcessoDados::ler(arq, valChave, chave);
  if(dados == ""){
    return false;
  }
  vector<string> linhas;
  linhas = AcessoDados::splitLinha(dados);

  unsigned int i = 0;
  string novoArquivo = "new.dat";
  arquivoAux.open(novoArquivo, ios::app);

  while(i < linhas.size()){
    AcessoDados::conectar(arq, LEITURA);
    string linha = "";
    while(!this->arquivo.eof() && getline(this->arquivo, linha)){
      if(linha != linhas[i]){
        arquivoAux << linha << endl;
      }
      else {
        vector <string> vecLinha = splitDado(linhas[i]);
        int indice;
        switch(campo){
        case C_IDPESSOA:
          indice = 0;
          break;
        case C_IDFUNC:
          indice = 1;
          break;
        case C_EFUNC:
          indice = 2;
          break;
        case C_NOME:
          indice = 3;
          break;
        case C_PROFISSAO:
          indice = 4;
          break;
        case C_ENDERECO:
          indice = 5;
          break;
        case C_FUNCAO:
          indice = 6;
          break;
        case C_CARGO:
          indice = 7;
          break;
        case C_FAIXASALARIAL:
          indice = 8;
          break;
        case C_GRATIFICACAO:
          indice = 9;
          break;
        }

        vecLinha[indice] = novoValor;
        for(int j = 0; j < int(vecLinha.size()); j++){
          arquivoAux << vecLinha[j] << "|";
        }
        arquivoAux << endl;
      }
    }
    i++;
  }

  string nomeArq;
  switch(arq){
  case CAD_PESSOAS:
    nomeArq = nomesArqs[CAD_PESSOAS];
    break;
  case TAB_SALARIAL:
    nomeArq = nomesArqs[TAB_SALARIAL];
    break;
  case IMP_RENDA:
    nomeArq = nomesArqs[IMP_RENDA];
    break;
  case CONTR_SINDICAL:
    nomeArq = nomesArqs[CONTR_SINDICAL];
  case TAB_VALOR:
	  nomeArq = this->nomesArqs[TAB_VALOR];
	  break;
  case HORAS_AUTON:
	  nomeArq = this->nomesArqs[HORAS_AUTON];
	  break;
  default:
	  throw std::invalid_argument("AcessoDados::conectar: tentativa de "
		  "conexao a um arquivo inexistente");
    break;
  }
  AcessoDados::desconectar();
  arquivoAux.clear();
  arquivoAux.close();
  remove(nomeArq.c_str());
  rename(novoArquivo.c_str(), nomeArq.c_str());
  AcessoDados::desconectar();
  return true;
}

/**
    Realiza uma busca por uma chave em uma determidada coluna de um arquivo de
    registros e exclui as linhas resultantes da busca.

    Caso o valor da chave seja uma string vazia a pesquisa retornará todo o
    conteúdo do arquivo de registros.

    @param arq (Arquivos): o enum que descreve o arquivo a ser aberto.
    @param valChave (string): o valor a ser buscado na coluna do arquivo de
      registros.
    @param chave (Campos): o enum que representa a coluna a ser avaliada na
      busca.
    @return true se pelo menos uma linha for excluida.
*/
bool AcessoDados::excluir(Arquivos arq, string valChave, Campos chave){
  string dados = AcessoDados::ler(arq, valChave, chave);
  if(dados == ""){
    return false;
  }
  vector<string> linhas;
  linhas = AcessoDados::splitLinha(dados);

  unsigned int i = 0;
  string novoArquivo = "new.dat";
  arquivoAux.open(novoArquivo, ios::app);

  while(i < linhas.size()){
    AcessoDados::conectar(arq, LEITURA);
    string linha = "";
    while(!this->arquivo.eof() && getline(this->arquivo, linha)){
      if(linha != linhas[i]){
        arquivoAux << linha << endl;
      }
    }
    i++;
  }

  string nomeArq;
  switch(arq){
  case CAD_PESSOAS:
    nomeArq = nomesArqs[CAD_PESSOAS];
    break;
  case TAB_SALARIAL:
    nomeArq = nomesArqs[TAB_SALARIAL];
    break;
  case IMP_RENDA:
    nomeArq = nomesArqs[IMP_RENDA];
    break;
  case CONTR_SINDICAL:
    nomeArq = nomesArqs[CONTR_SINDICAL];
  case TAB_VALOR:
	  nomeArq = this->nomesArqs[TAB_VALOR];
	  break;
  case HORAS_AUTON:
	  nomeArq = this->nomesArqs[HORAS_AUTON];
	  break;
  default:
	  throw std::invalid_argument("AcessoDados::conectar: tentativa de "
		  "conexao a um arquivo inexistente");
    break;
  }
  AcessoDados::desconectar();
  arquivoAux.clear();
  arquivoAux.close();
  remove(nomeArq.c_str());
  rename(novoArquivo.c_str(), nomeArq.c_str());
  AcessoDados::desconectar();
  return true;
}

/**
    Realiza a conexão com o arquivo.

    @param arquivo (Arquivos): o enum que descreve o arquivo a ser aberto.
    @param modo (ModoAcesso): o enum que descreve o modo de acesso do arquivo
      a ser aberto.
    @return true se a conexão for realizada com sucesso.
    @throw caso o arquivo não exista
    @throw caso o modo de leitura não exista
    @throw caso não seja possível abrir o arquivo
*/
bool AcessoDados::conectar(Arquivos arq, ModoAcesso modo){
  string nomeArq;

  switch(arq){
  case CAD_PESSOAS:
    nomeArq = this->nomesArqs[CAD_PESSOAS];
    break;
  case TAB_SALARIAL:
    nomeArq = this->nomesArqs[TAB_SALARIAL];
    break;
  case IMP_RENDA:
    nomeArq = this->nomesArqs[IMP_RENDA];
    break;
  case CONTR_SINDICAL:
    nomeArq = this->nomesArqs[CONTR_SINDICAL];
    break;
  case TAB_VALOR:
	  nomeArq = this->nomesArqs[TAB_VALOR];
	  break;
  case HORAS_AUTON:
	  nomeArq = this->nomesArqs[HORAS_AUTON];
	  break;
  default:
    throw std::invalid_argument("AcessoDados::conectar: tentativa de "
                                "conexao a um arquivo inexistente");
  }

  switch(modo){
  case LEITURA:
    this->arquivo.open(nomeArq.c_str(), ios::in);
    break;
  case ESCRITA:
    this->arquivo.open(nomeArq.c_str(), ios::out);
    break;
  case INSERCAO:
    this->arquivo.open(nomeArq.c_str(), ios::app);
    break;
  default:
    throw std::invalid_argument("AcessoDados::conectar: tentativa de "
                                "conexao a um arquivo em modo de de acesso "
                                "inexistente.");
  }

  if(this->arquivo.bad()){
    throw std::invalid_argument("AcessoDados::conectar: tentativa de "
                                "conexao ao arquivo malsucedida.");
  }

  this->arquivo.clear();

  return true;
}

/**
    Realiza a desconexão do arquivo.
*/
void AcessoDados::desconectar(){
  this->arquivo.clear();
  this->arquivo.close();
}
