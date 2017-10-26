/**
    PCS2478 - Tópicos de Programação
    CadastroPessoas.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-10-11
*/

#include "CadastroPessoas.h"
#include <iostream>

using namespace std;

// Construtores da classe CadastroPessoas
CadastroPessoas::CadastroPessoas(){}

CadastroPessoas::CadastroPessoas(string dados){
}

// Destrutor da classe CadastroPessoas
CadastroPessoas::~CadastroPessoas(){
  delete &(this->dadosPessoais);
}

// Setters e Getters
vector<string> CadastroPessoas::getDadosPessoais(){
  return this->dadosPessoais;
}

/**
    Valida uma string de dados de cadastro.

    @param dados (string): a string a ser validada
    @return true se a string for válida, false caso contrário
*/
bool CadastroPessoas::validarDados(string dados){
  if(dados.back() != '\n'){ // String termina em '/n'?
    return false;
  }

  vector<string> resultado;

  try { // String é parseável?
    resultado = CadastroPessoas::splitDado(dados);
  } catch (int e) {
    return false;
  }

  if(resultado.size() != 10){ // String tem 9 campos?
    return false;
  }

  try { // O estado funcional é um inteiro?
    std::stoi(resultado[2]);
  } catch (int e) {
    return false;
  }

  return true;
}

/**
    Adiciona uma string de dados ao array de dados pessoais.

    @param dados (string): a string a ser adicionada
    @param sobrescrever (bool): true se a adição deve sobrescrever os dados de
                                um usuário com o mesmo idPessoa
    @return true se a string foi adicionada, false caso contrário
    @throw caso haja a tentativa de sobrescrever um usuário e o argumento
           'sobrescrever' seja false (domain_error)
*/
bool CadastroPessoas::adicionarDadosPessoa(string dados,
                                          bool sobrescrever){
  if(CadastroPessoas::validarDados(dados)){

    string idPessoa = CadastroPessoas::splitDado(dados)[0];
    int indice = CadastroPessoas::getIndicePessoa(idPessoa);

    if(indice == -1){ // Pessoa ainda não cadastrada
      this->dadosPessoais.push_back(dados);
      return true;
    } else if(sobrescrever) { // Pessoa já cadastrada, vamos sobrescrever
      this->dadosPessoais[indice] = dados;
      return true;
    }
  }
  throw std::domain_error("CadastroPessoas::adicionarDadosPessoa: "
                          "Tentativa de subscricao de pessoa ja cadastrada");
}

/**
    Adiciona uma string contendo várias strings de dados ao array de dados
    pessoais.

    @param dados (string): a string dos dados a serem adicionados
    @param sobrescrever (bool): true se a adição deve sobrescrever os dados de
                                um usuário com o mesmo idPessoa
    @return true se todos os dados foram adicionados, false caso contrário
    @throw caso sejam passados dados inválidos (invalid_argument)
    @throw caso outro cadastro já possua esse ID Pessoa (domain_error)
*/
bool CadastroPessoas::adicionarDadosPessoas(bool sobrescrever){
	string dados;
	dados = acessoDados.lerTudo(CAD_PESSOAS);
vector<string> linhas;
  string linha;
  istringstream f(dados);

  // Transformando a string de linhas em vetores
  while (std::getline(f, linha)) {
    linha.push_back('\n');
    linhas.push_back(linha);
  }

  // Validando as linhas
  for(unsigned int i = 0; i < linhas.size(); i++){
    // A linha é válida?
    if(! CadastroPessoas::validarDados(linhas[i])){
      throw std::invalid_argument("CadastroPessoas::adicionarDadosPessoas:"
                                  " dados invalidos");
    }
    string idPessoa = CadastroPessoas::splitDado(linhas[i])[0];

    // Caso não possa sobrescrever, já existe algum usuário com esse idPessoa?
    if(!sobrescrever && CadastroPessoas::getIndicePessoa(idPessoa) != -1) {
      throw std::domain_error("CadastroPessoas::adicionarDadosPessoas:"
                              " outro cadastro ja possui esse ID Pessoa");
    }
  }

  for(unsigned int i = 0; i < linhas.size(); i++){ // Adicionando as linhas
    CadastroPessoas::adicionarDadosPessoa(linhas[i]);
  }
  return true;
}

/**
    Retorna uma string obtida pela concatenação de todos os dados no vetor de
    dados pessoais.

    @return a string resultante da concatenação de todos os dados contidos no
            vetor de dados pessoais
*/
string CadastroPessoas::lerDadosTodasPessoas(){
  string resultado;
  resultado = acessoDados.ler(CAD_PESSOAS, "", C_IDPESSOA);
  return resultado;
}

/**
    Retorna uma string com os dados de uma pessoa.

    @param idPessoa (string): o id da pessoa a ser buscada
    @return a string contendo os dados da pessoa
    @throw caso os idPessoa não exista (domain_error)
*/
string CadastroPessoas::lerDadosPessoa(string idPessoa){
  int indice = CadastroPessoas::getIndicePessoa(idPessoa);
  if(indice == -1){
    throw std::domain_error("CadastroPessoas::lerDadosPessoa:"
                            " ID Pessoa inexistente.");
  } else {
    return this->dadosPessoais[indice];
  }
}

/**
    Atualiza os dados de uma pessoa.

    @param dados (string): os novos dados a serem atualizados
    @return true se a operação foi bem sucedida, false caso contrario
    @throw caso sejam passados dados inválidos (invalid_argument)
    @throw caso os idPessoa não exista (domain_error)
*/
bool CadastroPessoas::atualizarDadosPessoa(string dados){
  if(!CadastroPessoas::validarDados(dados)){
    throw std::invalid_argument("CadastroPessoas::atualizarDadosPessoa:"
                                " dados invalidos");
  }

  vector<string> resultado = CadastroPessoas::splitDado(dados);
  int indice = CadastroPessoas::getIndicePessoa(resultado[0]);

  if(indice == -1){
    throw std::domain_error("CadastroPessoas::atualizarDadosPessoa:"
                            " ID Pessoa inexistente.");
  }

  return CadastroPessoas::adicionarDadosPessoa(dados, true);
}

/**
    Retorna um vector de strings contendo os diferentes campos de uma linha de
    dados de pessoa.

    @param dado (string): o dado a ser processado
    @return o vetor de strings contendo os diferentes campos de uma linha de
            dados de pessoa
    @throw caso o argumento seja inválido (invalid_argument)
*/
vector<string> CadastroPessoas::splitDado(string dado){
  vector<string> result;
  unsigned int start = 0;
  unsigned int i = 1;

  while(i < dado.length()-1){
    if(dado.at(i) == '|'){
      if(start == i){
        throw std::invalid_argument("String invalida.");
      }
      result.push_back(dado.substr(start, i-start));
      start = i + 1;
    }
    i++;
  }

  return result;
}

/**
    Determina o índice do vector dadosPessoais em que está uma linha contendo
    os dados de uma determinada pessoa.

    @param idPessoa (string): o id da pessoa a ser localizada
    @return o índice da string contida no dadosPessoais caso ela exista, -1
            caso contrário
*/
int CadastroPessoas::getIndicePessoa(string idPessoa){
  for(unsigned int i = 0; i < this->dadosPessoais.size(); i++){
    if(CadastroPessoas::splitDado(this->dadosPessoais[i])[0] == idPessoa){
      return i;
    }
  }
  return -1;
}

/**
    Gera uma linha formatada contendo os dados relativos a uma pessoa.

    @param idPessoa (string): o id da pessoa
    @param idFuncional (string): o idFuncional da pessoa
    @param estadoFuncional (string): o estado funcional da pessoa
    @param nome (string): o nome da pessoa
    @param profissao (string): a profissão da pessoa
    @param endereco (string): o endereco da pessoa
    @param funcao (string): a funcao da pessoa
    @param cargo (string): o cargo da pessoa
    @param faixaSalarial (string): a faixa salarial da pessoa
    @param gratificacao (string): a gratificação salarial da pessoa
    @return a string formatada contendo os dados da pessoa
*/
string CadastroPessoas::gerarLinha(string idPessoa, string idFuncional,
                                   string estadoFuncional, string nome,
                                   string profissao, string endereco,
                                   string funcao, string cargo,
                                   string faixaSalarial, string gratificacao){
  return idPessoa + "|" + idFuncional + "|" + estadoFuncional + "|" + nome +
         "|" + profissao + "|" + endereco + "|" + funcao + "|" + cargo + "|" +
         faixaSalarial + "|" + gratificacao + "|\n";
}

string CadastroPessoas::lerDadosPessoas(string valorChave, Campos chave)
{
	return acessoDados.ler(CAD_PESSOAS, valorChave, chave);
}

string CadastroPessoas::dadosCP()
{
	return 	acessoDados.lerTudo(CAD_PESSOAS);
}

bool CadastroPessoas::atualizarDadosPessoas(string valChave, Campos chave, string novoValor, Campos campo)
{

	return acessoDados.atualizar(CAD_PESSOAS, valChave,chave, novoValor,campo);
}

bool CadastroPessoas::inserir(string idPessoal, string idFuncional, string estadoFuncional, string nome, string profissao, string endereco, string funcao, string cargo, string faixaSalarial, string gratificacao)
{
	string pessoa = idPessoal + "|" + idFuncional + "|" + estadoFuncional + "|" + nome + "|" + profissao + "|" + endereco + "|" + funcao + "|" + cargo + "|" + faixaSalarial + "|" + gratificacao + "|";

	
	return this->acessoDados.inserir(CAD_PESSOAS,pessoa);
}

bool CadastroPessoas::excluirPessoa(string idPessoal)
{
	return this->acessoDados.excluir(CAD_PESSOAS, idPessoal, C_IDPESSOA);
}

