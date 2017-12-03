/**
    PCS2478 - Tópicos de Programação
    lab12.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-11-29
*/

#define LINE "------------------------------------------------------------"

#include <sstream>
#include <iomanip>
#include <vector>

#include "Empresa.h"

using namespace std;

void sistema() {
  string nomeEmpresa;
  cout << "Forneca o nome da empresa:" << endl;
  getline(cin, nomeEmpresa);

  string tamanho;
  cout << "Forneca o numero maximo de funcionarios da empresa " << nomeEmpresa
    << ":" << endl;

  getline(cin, tamanho);

  Empresa * aEmpresa;

  try {
    aEmpresa = new Empresa(nomeEmpresa, atoi(tamanho.c_str()));
  } catch (logic_error& ex) {
    cout << "ERRO ao criar a empresa: " << ex.what() << endl;
    cout << "Saindo..." << endl;
    exit(1);
  }

  string option = "";


  while (true) {
    cout << endl << LINE << endl;
    cout << aEmpresa->getNome() << endl;
    cout << LINE << endl << endl;

    cout << "[A] Apresentar Conteudo dos Arquivos" << endl;
    cout << "[P] Mostrar Dados Pessoais" << endl;
    cout << "[F] Mostrar Funcionarios Contratados" << endl;
    cout << "[S] Mostrar Salario Liquido de Funcionarios" << endl;
    cout << "[M] Mostrar Folha de Pagamento" << endl;
    cout << "[C] Contratar Funcionario" << endl;
    cout << "[D] Demitir Funcionario" << endl;
    cout << "[I] Inserir Pessoa" << endl;
    cout << "[E] Excluir Pessoa" << endl;
    cout << "[X] Sair" << endl;

    cout << LINE << endl << endl;

    getline(cin, option);

    cout << endl << LINE << endl << endl;

    string idPessoal, idFuncional, nome, profissao, endereco, funcao, cargo,
      faixaSalarial, tipoFuncionario;

    string pessoas;
    vector<string> vpessoas;

    switch (option.at(0)) {
    case 'A':
    case 'a':
      try{
        cout << "cadpessoas.dat:" << endl << endl;
        cout << aEmpresa->obterDadosArquivo(0) << endl;
        cout << "tabsalarial.dat:" << endl << endl;
        cout << aEmpresa->obterDadosArquivo(1) << endl;
        cout << "tabcs.dat:" << endl << endl;
        cout << aEmpresa->obterDadosArquivo(2) << endl;
        cout << "tabir.dat:" << endl << endl;
        cout << aEmpresa->obterDadosArquivo(3) << endl;

        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'P':
    case 'p':
      try{
        pessoas = aEmpresa->lerDadosTodasPessoas();
        vpessoas = aEmpresa->SplitPessoas(pessoas);

        for (unsigned long i = 0; i < vpessoas.size()-1; i++){
          cout << i + 1 << "a pessoa:" << endl;
          aEmpresa->displayPessoa(vpessoas[i]);
        }
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'C':
    case 'c':
      try{
        cout << "Pessoas disponiveis para contratacao:" << endl << endl;

        pessoas = aEmpresa->lerDadosTodasPessoas();
        vpessoas = aEmpresa->SplitPessoas(pessoas);

        for (unsigned long i = 0; i < vpessoas.size()-1; i++){
          if(aEmpresa->SplitPessoa(vpessoas[i])[C_EFUNC] == "2"){
            cout << i + 1 << "a pessoa:" << endl;
            aEmpresa->displayPessoa(vpessoas[i]);
          }
        }

        cout << "Digite o idPessoal a ser contratado:" << endl;
        getline(cin, idPessoal);
        cout << "Digite o idFuncional do contratado:" << endl;
        getline(cin, idFuncional);
        cout << "Digite o tipo de funcionario (1 para mensalista,"
                " 2 para autonomo): " << endl;
        getline(cin, tipoFuncionario);
        aEmpresa->contratarFuncCadastrado(idPessoal, idFuncional,
                                          tipoFuncionario);
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'D':
    case 'd':
      try{
        cout << "Funcionarios cadastrados:" << endl;

        aEmpresa->obterDadosOrdenadosFunc();

        cout << "Digite o idFuncional a ser demitido:" << endl;
        getline(cin, idFuncional);
        aEmpresa->demitirFuncionario(idFuncional);
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'I':
    case 'i':
      try{
        cout << "Digite o idPessoal:";
        getline(cin, idPessoal);
        cout <<endl<< "Digite o nome:";
        getline(cin, nome);
        cout << endl << "Digite a profissao:";
        getline(cin, profissao);
        cout << endl << "Digite o endereco:";
        getline(cin, endereco);
        cout << endl << "Digite a funcao:";
        getline(cin, funcao);
        cout << endl << "Digite o cargo:";
        getline(cin, cargo);
        cout << endl << "Digite a faixa salarial:";
        getline(cin, faixaSalarial);
        cout << endl << "Digite o tipo de funcionario (1 para mensalista,"
                        " 2 para autonomo): ";
        getline(cin, tipoFuncionario);
        cout << endl;

        if(tipoFuncionario != "1" && tipoFuncionario != "2"){
          throw std::invalid_argument("Tipo de funcionario invalido");
        }

        aEmpresa->inserirPessoaCadastro(idPessoal, nome, profissao, endereco,
                                        funcao, cargo, faixaSalarial,
                                        tipoFuncionario);

        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'F':
    case 'f':
      try {
        aEmpresa->obterDadosOrdenadosFunc();
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'S':
    case 's':
      try{
        aEmpresa->calcularSalarioLiquido();
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'E':
    case 'e':
      try{
        cout << "Digite o ID Pessoal a ser excluido:" << endl;
        getline(cin, idPessoal);

        aEmpresa->excluirPessoa(idPessoal);
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'M':
    case 'm':
      try{
        aEmpresa->emitirFolhaPagamento();
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'X':
    case 'x':
      cout << "Saindo..." << endl;
      exit(0);
      break;
    default:
      cout << endl << "Opcao invalida" << endl;
    }
  }
}


int main() {
  sistema();

  return 0;
}
