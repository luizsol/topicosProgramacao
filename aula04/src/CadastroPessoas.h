/**
    PCS2478 - Tópicos de Programação
    CadastroPessoas.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado
    @version 1.0 2017-08-23
*/


#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "Funcionario.h"

using namespace std;

class CadastroPessoas{
  vector<string> dadosPessoais;

public:
  CadastroPessoas();
  CadastroPessoas(string cargaInicial);
  ~CadastroPessoas();

  bool validarDados(string dados);
  bool adicionarDadosPessoa(string dados, bool sobrescrever=true);
  bool adicionarDadosPessoas(string dados, bool sobrescrever=true);
  string lerDadosTodasPessoas();
  string lerDadosPessoa(string idPessoa);
  bool atualizarDadosPessoa(string dados);
  vector<string> splitDado(string dado);
  int getIndicePessoa(string idPessoa);
  string gerarLinha(string idPessoa, string idFuncional, string estadoFuncional,
                    string nome, string profissao, string endereco,
                    string funcao, string cargo, string faixaSalarial);

private:

};