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
// #include "Empresa.h"

using namespace std;

class CadastroPessoas{
  vector<string> dadosPessoais;

public:
  CadastroPessoas();
  CadastroPessoas(string cargaInicial);
  ~CadastroPessoas();

  bool validarDados(string dados);
  bool adicionaDadosPessoa(string dados);
  string lerDadosTodasPessoas();
  string lerDadosPessoa(string idFuncional);
  string atualizarDadosPessoa(string dados);

private:

};