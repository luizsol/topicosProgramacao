/**
    PCS2478 - Tópicos de Programação
    lab10.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-11-01
*/

#define LINE "------------------------------------------------------------"

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
  string filtro = "";
  string valorChave = "";
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

    cout << "[P] Mostrar Dados Pessoais" << endl;
    cout << "[F] Mostrar Funcionarios Contratados" << endl;
    cout << "[C] Contratar Funcionario" << endl;
    cout << "[D] Demitir Funcionario" << endl;
    cout << "[I] Inserir Pessoa" << endl;
    cout << "[O] Mostrar Funcionarios Ordenados por Salario" << endl;
    cout << "[S] Verificar Salario Liquido de Funcionarios" << endl;
    cout << "[E] Excluir Pessoa" << endl;
    cout << "[X] Sair" << endl;
    cout << LINE << endl << endl;

    getline(cin, option);

    cout << endl << LINE << endl << endl;

    string idPessoal, idFuncional, nome, profissao, endereco, funcao, cargo,
    	faixaSalarial;

    string pessoas;
    vector<string> vpessoas;

    switch (option.at(0)) {
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
    case 'F':
    case 'f':
      try{
        pessoas = aEmpresa->lerDadosFunc();
        vpessoas = aEmpresa->SplitPessoas(pessoas);

        for (unsigned long i = 0; i < vpessoas.size(); i++) {
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
        cout << "Digite o idPessoal a ser contratado:" << endl;
        getline(cin, idPessoal);

        cout << "Digite o idFuncional do contratado:" << endl;
        getline(cin, idFuncional);
        aEmpresa->contratarFuncCadastrado(idPessoal, idFuncional);
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'D':
    case 'd':
      try{
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
        cout << endl;

        aEmpresa->inserirPessoaCadastro(idPessoal, nome, profissao, endereco,
                                        funcao, cargo, faixaSalarial);

        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex) {
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'O':
    case 'o':
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