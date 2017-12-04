/**
    PCS2478 - Tópicos de Programação
    CadastroPessoas.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-12-04
*/

#include "CadastroPessoas.h"

using namespace std;

// Construtores da classe CadastroPessoas
CadastroPessoas::CadastroPessoas(){}

// Destrutor da classe CadastroPessoas
CadastroPessoas::~CadastroPessoas(){}

/**
    Retorna todos os dados contidos no arquivo cadpessoas.dat

    @return a string contendo todos os dados contidos no arquivo cadpessoas.dat
*/
string CadastroPessoas::lerDadosTodasPessoas(){
  return acessoDados.ler(CAD_PESSOAS, "", C_IDPESSOA);;
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
    Realiza uma busca por uma chave em uma determidada coluna do arquivo de
    cadastro de pessoas.

    Caso o valor da chave seja uma string vazia a pesquisa retornará todo o
    conteúdo do arquivo.

    @param valChave (string): o valor a ser buscado na coluna do arquivo de
      registros.
    @param chave (Campos): o enum que representa a coluna a ser avaliada.
    @return a concatenação de todas as linhas que se enquadram no critério da
      busca.
*/
string CadastroPessoas::lerDadosPessoas(string valorChave, Campos chave){
  return acessoDados.ler(CAD_PESSOAS, valorChave, chave);
}

/**
    Retorna todos os dados contidos no arquivo cadpessoas.dat

    @return a string contendo todos os dados contidos no arquivo cadpessoas.dat
*/
string CadastroPessoas::dadosCP(){
  return acessoDados.lerTudo(CAD_PESSOAS);
}

/**
    Realiza uma busca por uma chave em uma determidada coluna do arquivo de
    cadastro de pessoas e atualiza as linhas resultantes da busca.

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
bool CadastroPessoas::atualizarDadosPessoas(string valChave, Campos chave,
                                            string novoValor, Campos campo){
  return acessoDados.atualizar(CAD_PESSOAS, valChave, chave, novoValor, campo);
}

/**
    Insere uma nova linha no arquivo de cadastro de pessoas.

    @param idPessoal (string): o id da pessoa
    @param nome (string): o nome da pessoa
    @param profissao (string): a profissão da pessoa
    @param endereco (string): o endereco da pessoa
    @param funcao (string): a funcao da pessoa
    @param cargo (string): o cargo da pessoa
    @param faixaSalarial (string): a faixa salarial da pessoa
    @param tipoFuncionario(string): o tipo de funcionário ("1"=Mensalista e
      "2"=Autônomo)
    @return true se a operação for bem sucedida.
*/
bool CadastroPessoas::inserir(string idPessoal, string idFuncional,
  string estadoFuncional, string nome, string profissao, string endereco,
  string funcao, string cargo, string faixaSalarial, string gratificacao,
  string tipoFuncionario){

  return this->acessoDados.inserir(CAD_PESSOAS, CadastroPessoas::gerarLinha(
    idPessoal, idFuncional, estadoFuncional, nome, profissao, endereco, funcao,
    cargo, faixaSalarial, gratificacao, tipoFuncionario));
}

/**
    Realiza uma busca por uma pessoa contendo um determinado id pessoal e a
    exclui do registro.

    @param idPessoal (string): o id pessoa da pessoa a ser excuída.
    @return true se pelo menos uma linha for excluida.
*/
bool CadastroPessoas::excluirPessoa(string idPessoal){
  return this->acessoDados.excluir(CAD_PESSOAS, idPessoal, C_IDPESSOA);
}

/**
    Gera uma linha formatada contendo os dados relativos a uma pessoa.

    @param idPessoal (string): o id da pessoa
    @param idFuncional (string): o idFuncional da pessoa
    @param estadoFuncional (string): o estado funcional da pessoa
    @param nome (string): o nome da pessoa
    @param profissao (string): a profissão da pessoa
    @param endereco (string): o endereco da pessoa
    @param funcao (string): a funcao da pessoa
    @param cargo (string): o cargo da pessoa
    @param faixaSalarial (string): a faixa salarial da pessoa
    @param gratificacao (string): a gratificação salarial da pessoa
    @param tipoFuncionario(string): o tipo de funcionário ("1"=Mensalista e
      "2"=Autônomo)
    @return a string formatada contendo os dados da pessoa
*/
string CadastroPessoas::gerarLinha(string idPessoal, string idFuncional,
  string estadoFuncional, string nome, string profissao, string endereco,
  string funcao, string cargo, string faixaSalarial, string gratificacao,
  string tipoFuncionario){
  return idPessoal + "|" + idFuncional + "|" + estadoFuncional + "|" + nome +
         "|" + profissao + "|" + endereco + "|" + funcao + "|" + cargo + "|" +
         faixaSalarial + "|" + gratificacao + "|" + tipoFuncionario + "|";
}
