/* Arquivo: lab2.cpp
 *
 *  Autores:
 *    Luiz Eduardo Sol      8586861
 *    Augusto Ruy Machado   7576829
 *
 * Versao: 1
 */

#include "Funcionario.h"
#include "Empresa.h"
#include <iostream>
#include <string>

using namespace std;


void sistema(){
  string nomeEmpresa;
  cout << "Forneca o nome da empresa:" << endl;
  getline(cin, nomeEmpresa);
  Empresa novaEmpresa(nomeEmpresa, 5);

  string option = "";

  while(option.compare("X") != 0){
    cout << novaEmpresa.getNome() << endl;
    cout << "-------------------------" << endl << endl;

    cout << "[C] Cadastrar Funcionario" << endl;
    cout << "[D] Demitir Funcionario" << endl;
    cout << "[M] Mostrar Funcionarios" << endl;
    cout << "[X] Sair" << endl;
    getline(cin, nomeEmpresa);

  }

}

int main(int argc, char * argv[]){

  /* A. Cria dinamicamente um objeto do tipo Empresa; seu nome deve ser
   * solicitado ao usuário. Após a criação, não existe nenhum funcionário
   * contratado na empresa.
   */
  string nomeEmpresa;
  cout << "Forneca o nome da empresa:" << endl;
  getline(cin, nomeEmpresa);
  Empresa novaEmpresa(nomeEmpresa, 5);


  /* B. Apresenta na tela os dados dos funcionários contratados.
   *
   */
  cout << "Apresentando os dados sobre os funcionarios da empresa:" << endl;
  novaEmpresa.obterDadosFuncionarios();


  /* C. Contrata 2 funcionários, com dados fornecidos pelo teclado e escolhidos
   * por vocês.
   */
  novaEmpresa.contratarFuncionarioIterativo();

  novaEmpresa.contratarFuncionarioIterativo();

  /* D. Apresenta na tela os dados dos funcionários contratados.
   */
  cout << "Apresentando os dados sobre os funcionarios da empresa:" << endl;
  novaEmpresa.obterDadosFuncionarios();

  /* E. Demite um funcionário, fornecendo um valor inexistente de idFuncional.
   */
  novaEmpresa.demitirFuncionarioIterativo();

  /* F. Demite o 1º funcionário contratado, fornecendo sua identificação
   * funcional pelo teclado.
   */
  novaEmpresa.demitirFuncionarioIterativo();

  /* G. Apresenta na tela os dados dos funcionários contratados.
   */
  cout << "Apresentando os dados sobre os funcionarios da empresa:" << endl;
  novaEmpresa.obterDadosFuncionarios();

  /* H. Contrata mais 3 funcionários, com dados fornecidos pelo teclado e
   * escolhidos por vocês.
   */
  novaEmpresa.contratarFuncionarioIterativo();

  novaEmpresa.contratarFuncionarioIterativo();

  novaEmpresa.contratarFuncionarioIterativo();

  /* I. Demite o último funcionário contratado, fornecendo sua identificação
   * funcional pelo teclado.
   */
  novaEmpresa.demitirFuncionarioIterativo();

  /* J. Apresenta na tela os dados dos funcionários contratados.
   */
  cout << "Apresentando os dados sobre os funcionarios da empresa:" << endl;
  novaEmpresa.obterDadosFuncionarios();

  /* K. Demite todos os funcionários da empresa.
   */
  novaEmpresa.demitirTodosFuncionarios();

  /* L. Apresenta na tela os dados dos funcionários contratados.
   */
  cout << "Apresentando os dados sobre os funcionarios da empresa:" << endl;
  novaEmpresa.obterDadosFuncionarios();

  /* M. Demite mais um funcionário.
   */
  novaEmpresa.demitirFuncionarioIterativo();

  /* N. Testar o caso em que a empresa não tem mais vagas para contratação.
   */
  novaEmpresa.contratarFuncionario("0123", "Carlos", "Rua dos bobos, #0",
                                   "Estivador", "Carregar Pedra", "Junior");
  novaEmpresa.contratarFuncionario("013", "Alberto", "Rua dos bobos, #0",
                                   "Estivador", "Carregar Pedra", "Junior");
  novaEmpresa.contratarFuncionario("0144423", "Adriano", "Rua dos bobos, #0",
                                   "Estivador", "Carregar Pedra", "Junior");
  novaEmpresa.contratarFuncionario("03", "Pedro", "Rua dos bobos, #0",
                                   "Estivador", "Carregar Pedra", "Junior");



  cout << "Bye" << endl;
  return 0;
}