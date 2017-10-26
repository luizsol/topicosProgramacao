/**
PCS2478 - Tópicos de Programação
Empresa.cpp

@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
@version 1.0 2017-10-11
*/

#include "Empresa.h"
#include <iostream>

using namespace std;

// Construtores da classe Empresa
Empresa::Empresa() : Empresa("Sem Nome", 10) {}

Empresa::Empresa(string nome) : Empresa(nome, 10) {}

Empresa::Empresa(int maxFuncionarios) : Empresa("Sem Nome", maxFuncionarios) {}


Empresa::Empresa(string nome, int maxFuncionarios){
 /* string l01, l02, l03, l04, l05, l06, lTotal;
  l01 = "0001|0021|1|Cristiana Souza|Tecnica Administrativa|Rua AA, 154|Secretaria|Pleno|05|0|\n";
  l02 = "0002|0042|1|Heroldo Teles|Tecnico Eletronico|Rua BB, 32|Suporte|Junior|03|1|\n";
  l03 = "0003|0000|2|Carlos Peixoto|Engenheiro Eletrico|Alameda ZZ, 187|Engenheiro|Senior|07|0|\n";
  l04 = "0004|0063|1|Teresa Alves|Engenheiro de Producao|Rua CCC, 501|Engenheiro|Senior|06|1|\n";
  l05 = "0005|0000|2|Eliana Silva|Administrador de Empresa|Rua DD, 735|Administrador|Diretor|09|0|\n";
  l06 = "0006|0000|2|Ricardo Souza Carvalho|Contador|Praca E, 128|Contador|Pleno|04|0|\n";
  lTotal = l01 + l02 + l03 + l04 + l05 + l06;
  */


  Empresa::initFuncArray(maxFuncionarios);
  //this->cadastroPessoas.adicionarDadosPessoas();
  Empresa::setNome(nome);
  Empresa::iniciarFuncionarios();
  
}


// Destrutor da classe empresa
Empresa::~Empresa(){
  Empresa::demitirTodosFuncionarios();
  delete &(this->funcionarios);
  delete &(this->cadastroPessoas);
  delete &(this->tabelaSalarial);
}

// Setters e Getters
string Empresa::getNome(){
  return this->nome;
}

void Empresa::setNome(string nome){
  this->nome = nome;
}


/**
    Solicita os dados de todas as pessoas cadastradas e contrata aquelas que
    tiverem o estado funcional "empregado" (1)

    @return true se todos os funcionários foram devidamente contratados
*/
bool Empresa::iniciarFuncionarios(){
	string dados;
	dados = this->cadastroPessoas.lerDadosTodasPessoas();
  vector<string> pessoas = Empresa::SplitPessoas(dados);

  for(unsigned long i = 0; i < pessoas.size(); i++){
    vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);
    if(pessoa[2].compare("1") == 0){
      Empresa::contratarFuncionario(pessoa[0], pessoa[1], pessoa[3], pessoa[4],
                                    pessoa[5], pessoa[6], pessoa[7], pessoa[8],
                                    pessoa[9]);
    }
  }
  return true;
}

/**
    Cria e cadastra um funcionário na empresa.

    @param idFuncional (string): o ID Funcional do funcionário
    @param nome (string): o nome do funcionário
    @param endereco (string): o endereço do funcionário
    @param profissao (string): a profissão do funcionário
    @param funcao (string): a função do funcionário
    @param cargo (string): o cargo do funcionário
    @param faixaSalario (string): a faixa salarial do funcionário
    @param gratificação (string): o gratificação salarial do funcionário
    @return true se o funcionário foi criado e cadastrado, false caso contrário
    @throw caso se tente contratar mais funcionários que o limite máximo
           (domain_error)
    @throw caso se tente contratar um funcionário com um ID Funcional já
           existente (domain_error)
*/
bool Empresa::contratarFuncionario(string idPessoa, string idFuncional,
                                   string nome, string profissao,
                                   string endereco, string funcao, string cargo,
                                   string faixaSalario, string gratificacao){

  if(this->maxFuncionarios == this->funcionarios.size()){
    throw std::domain_error("Empresa::contratarFuncionario: "
                            "Limite de funcionarios atingido");
  }

  if(Empresa::idJaCadastrado(idFuncional)){
    throw std::domain_error("Empresa::contratarFuncionario: "
                            "ID Funcional ja cadastrado");
  }

  string linha = this->cadastroPessoas.gerarLinha(idPessoa, idFuncional, "1",
                                                  nome, profissao, endereco,
                                                  funcao, cargo, faixaSalario,
                                                  gratificacao);

  this->funcionarios.push_back(Funcionario(idPessoa, idFuncional, nome,
                                           profissao, endereco, funcao, cargo,
                                           faixaSalario));
  return true;
}

/**
    Cadastra um funcionário na empresa de maneira interativa (via CLI)
    utilizando os dados do cadastroPessoa.

    @return true se o funcionário foi cadastrado, false caso
            contrário
    @throw caso não haja funcionario elegivel para contratacao (domain_error)
    @throw caso o ID Pessoa seja inexistente (domain_error)
    @throw caso a pessoa não esteja com o status de aguardando vaga
           (domain_error)
*/
bool Empresa::contratarFuncionario(){
  // Verificando se existem pessoas para serem contratadas
  vector<string> pessoas = Empresa::getAndSplitPessoas();
  bool ninguemPorCadastrar = true;
  for(unsigned long i = 0; i < pessoas.size() && ninguemPorCadastrar; i++){
    vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);
    if(std::to_string(2).compare(pessoa[2]) == 0){
      ninguemPorCadastrar = false;
    }
  }

  if(ninguemPorCadastrar){
    throw std::domain_error("Empresa::contratarFuncionario: "
                            "Nenhum funcionario elegivel para contratacao.");
  }


  cout << endl << "Pessoas elegiveis para contratacao: " << endl;
  cout << "-----------------------------------------------------------" << endl;
  Empresa::obterDadosPessoas(2);
  cout << "Digite o ID da pessoa que deseja contratar: " << endl;
  string idPessoa;
  getline(cin, idPessoa);

  int indice = this->cadastroPessoas.getIndicePessoa(idPessoa);
  if(indice < 0){
    throw std::domain_error("Empresa::contratarFuncionario: "
                            "ID pessoa inexistente.");
  }

  vector<string> pessoa = this->cadastroPessoas.splitDado(
                            this->cadastroPessoas.lerDadosPessoa(idPessoa)
                          );
  if(pessoa[2].compare("2") != 0){
    throw std::domain_error("Empresa::contratarFuncionario: "
                            "a pessoa com esse ID pessoa nao esta aguardando"
                            " vaga");
  }

  cout << "Digite o novo ID funcional da pessoa a ser contratada (ID antigo = "
    << pessoa[1] << "): " ;
  getline(cin, pessoa[1]);

  return Empresa::contratarFuncionario(pessoa[0], pessoa[1], pessoa[3],
                                       pessoa[4], pessoa[5], pessoa[6],
                                       pessoa[7], pessoa[8], pessoa[9]);
}

/**
    Demite e apaga um funcionário da empresa.

    @param idFuncional (string): o ID Funcional do funcionário a ser demitido
    @return true se o funcionário foi demitido e apagado, false caso contrário
    @throw caso o ID Funcional seja inexistente (domain_error)
*/
bool Empresa::demitirFuncionario(string idFuncional){
	string pessoa;
	string idPessoal;
	pessoa = this->cadastroPessoas.lerDadosPessoas(idFuncional, C_IDFUNC);
	idPessoal = this->cadastroPessoas.splitDado(pessoa)[0];


  return this->cadastroPessoas.atualizarDadosPessoas(idPessoal, C_IDPESSOA,"0",C_EFUNC);
}

/**
    Demite e apaga um funcionário da empresa via CLI

    @return true se o funcionário foi demitido e apagado, false caso contrário
*/
bool Empresa::demitirFuncionario(){
  Empresa::obterDadosFuncionarios();
  cout << "Forneca o ID Funcional do funcionario que deseja demitir:" << endl;
  string idFuncional;
  getline(cin, idFuncional);
  return Empresa::demitirFuncionario(idFuncional);

}

// Demite e apaga todos funcionário da empresa.
void Empresa::demitirTodosFuncionarios(){
  while(this->funcionarios.size() > 0){
    Empresa::demitirFuncionario(this->funcionarios[0].getIdFuncional());
  }
}

/**
    Imprime os dados de todas as pessoas contidas em cadastroPessoa de forma
    formatada
*/
void Empresa::obterDadosPessoas(int filtro){
  vector<string> pessoas = Empresa::getAndSplitPessoas();

  for(unsigned long i = 0; i < pessoas.size(); i++){
    vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);

    // Verificando se o usuário deseja filtrar os resultados
    if(filtro != -1 && std::to_string(filtro).compare(pessoa[2]) != 0){
      // O usuário deseja filtrar e essa pessoa não se encaixa no filtro.
      continue;
    }
    cout << i+1 << "a pessoa:" << endl;
    cout << "ID Pessoa: \t\t" << pessoa[0] << endl;
    cout << "Id Funcional: \t\t" << pessoa[1] << endl;
    cout << "Estado Funcional:\t" << pessoa[2] << endl;
    cout << "Nome:\t\t\t" << pessoa[3] << endl;
    cout << "Endereco:\t\t" << pessoa[4] << endl;
    cout << "Profissao:\t\t" << pessoa[5] << endl;
    cout << "Funcao:\t\t\t" << pessoa[6] << endl;
    cout << "Cargo:\t\t\t" << pessoa[7] << endl;
    cout << "Faixa Salarial:\t\t" << pessoa[8] << endl;
    cout << "Gratificacao Salarial:\t" << pessoa[9] << endl << endl;
  }
}

// Imprime os dados de todos os funcionários da empresa de forma formatada
void Empresa::obterDadosFuncionarios(){
  cout << "Dados de todas os funcionarios:" << endl;
  cout << "------------------------------------------------------------" << endl
    << endl;
  for(unsigned long i = 0; i < this->funcionarios.size(); i++){
    cout << i+1 << "o Funcionario: " << endl << endl;
    Empresa::obterDadosFuncionario(i);
    cout << endl;
  }
  if(this->funcionarios.size() == 0){
    cout << "Nenhum funcionario cadastrado." << endl;
  }
}

/**
    Inicializa o array de funcionários.

    @param maxFuncionarios (int): a capacidade máxima de funcionários da empresa
    @return true se a inicialização foi bem sucedida, false caso contrário
*/
bool Empresa::initFuncArray(int maxFuncionarios){
  this->maxFuncionarios = maxFuncionarios;

  return true;
}

/**
    Verifica se existe um funcionário cadastrado com um determinado ID Funcional

    @param idFuncional (string): o idFuncional a ser verificado
    @return true se já existe um funcionário com o idFuncional, false caso
            contrário
*/
bool Empresa::idJaCadastrado(string idFuncional){
  if(Empresa::buscaIdFuncional(idFuncional) == -1){
    return false;
  }
  return true;
}

/**
    Determina o índice no array de funcionários de determinado funcionário

    @param idFuncional (string): o idFuncional a ser localizado
    @return o índice do array de funcionário onde o funcionário está armazenado
            ou -1 caso ele não tenha sido encontrado
*/
int Empresa::buscaIdFuncional(string idFuncional){
  for(unsigned long i = 0; i < this->funcionarios.size(); i++){
    if(this->funcionarios[i].getIdFuncional().compare(idFuncional) == 0){
      return i;
    }
  }
  return -1;
}

/**
    Imprime os dados de um determinado funcionário de forma formatada

    @param index (string): o índice no array de funcionários do funcionário a
                           ser impresso
*/
void Empresa::obterDadosFuncionario(int index){
  cout << "Id Pessoa: \t" << this->funcionarios[index].getIdPessoa()
    << endl;
  cout << "Id Funcional: \t" << this->funcionarios[index].getIdFuncional()
    << endl;
  cout << "Nome:\t\t" << this->funcionarios[index].getNome() << endl;
  cout << "Endereco:\t" << this->funcionarios[index].getEndereco() << endl;
  cout << "Profissao:\t" << this->funcionarios[index].getProfissao() << endl;
  cout << "Funcao:\t\t" << this->funcionarios[index].getFuncao() << endl;
  cout << "Cargo:\t\t" << this->funcionarios[index].getCargo() << endl;
  cout << "Salario:\t" << Empresa::calcularSalario(this->funcionarios[index].
                                                   getIdFuncional())
    << endl << endl;
}

/**
    Retorna uma string com formato monetário correspondente ao salário de um
    determinado funcionário

    @param idFuncional (string): o id funcional do funcionário
    @return a string formatada correspondente ao salário do funcionário
    @throw caso não exista o id funcional (domain_error)
*/
string Empresa::calcularSalario(string idFuncional){
  int i = Empresa::buscaIdFuncional(idFuncional);
  if(i == -1){
    throw std::domain_error("Empresa::calcularSalario: "
                            "ID Funcional inexistente");
  }

  string faixaSalario = this->funcionarios[i].getFaixaSalario();
  float salario = this->tabelaSalarial.lerSalario(faixaSalario);
  if(Empresa::getGratificacaoFuncionario(this->funcionarios[i].getIdFuncional()).compare("1") == 0){
    salario *= 1.01;
  }

  stringstream stream;
  stream << "R$ " << fixed << setprecision(2) << salario;
  return stream.str();
}

/**
    Apresenta as informações sobre a remuneração de um determinado funcionário

    @throw caso não exista o id funcional inserido pelo usuário (domain_error)
*/
void Empresa::calcularSalarioLiquido(){
  string idFuncional;
  cout << "Insira o ID Funcional do funcionário: ";
  getline(cin, idFuncional);

  int index = Empresa::buscaIdFuncional(idFuncional);
  if(index == -1){
    throw std::domain_error("Empresa::calcularSalario: "
                            "ID Funcional inexistente");
  }
  string salarioBruto = Empresa::calcularSalario(idFuncional);

  float sb = stof(salarioBruto.substr(3, salarioBruto.length()-3));

  ContribuicaoSindical contribSindical;
  float cs = this->contribuicaoSindical.calcularCS(sb, this->funcionarios[index].getFuncao());

  // Ajustando a resolução
  stringstream streamCS;
  streamCS << "R$ " << fixed << setprecision(2) << cs;

  float ir = this->impostoRenda.calcularIR(sb);

  float sl = sb - cs - ir;

  // Ajustando a resolução
  stringstream streamSL;
  streamSL << "R$ " << fixed << setprecision(2) << sl;
  stringstream streamIR;
  streamIR << "R$ " << fixed << setprecision(2) << ir;

  cout << endl << endl << "Id Funcional: \t\t"
    << this->funcionarios[index].getIdFuncional() << endl;
  cout << "Nome:\t\t\t" << this->funcionarios[index].getNome() << endl;
  cout << "Salario Bruto:\t\t" << salarioBruto << endl;
  cout << "Desconto Sindical:\t" << streamCS.str() << endl;
  cout << "Imposto de Renda:\t" << streamIR.str() << endl;
  cout << "Salario Liquido:\t" << streamSL.str() << endl << endl;
}

/**
    Obtem e processa os dados dos funcionários de uma forma menos eficiente
    para ficar de acordo com as especificações.

    @return um vector de strings contendo os dados das pessoas
*/
vector<string> Empresa::getAndSplitPessoas(){
  vector<string> linhas;
  string linha;
  istringstream f(this->cadastroPessoas.lerDadosTodasPessoas());

  // Transformando a string de linhas em vetores
  while (std::getline(f, linha)) {
    linha.push_back('\n');
    linhas.push_back(linha);
  }

  return linhas;
}

vector<string> Empresa::SplitPessoas(string in) {
	vector<string> linhas;
	string linha;
	istringstream f(in);

	// Transformando a string de linhas em vetores
	while (std::getline(f, linha)) {
		linha.push_back('\n');
		linhas.push_back(linha);
	}

	return linhas;
}

vector<string> Empresa::SplitPessoa(string in)
{
	vector<string> pessoa;
	pessoa = this->cadastroPessoas.splitDado(in);
	return pessoa;
}

void Empresa::displayPessoa(string in)
{
	vector<string> pessoa;
	pessoa = this->SplitPessoa(in);

	cout << "ID Pessoa: \t\t" << pessoa[0] << endl;
	cout << "Id Funcional: \t\t" << pessoa[1] << endl;
	cout << "Estado Funcional:\t" << pessoa[2] << endl;
	cout << "Nome:\t\t\t" << pessoa[3] << endl;
	cout << "Endereco:\t\t" << pessoa[4] << endl;
	cout << "Profissao:\t\t" << pessoa[5] << endl;
	cout << "Funcao:\t\t\t" << pessoa[6] << endl;
	cout << "Cargo:\t\t\t" << pessoa[7] << endl;
	cout << "Faixa Salarial:\t\t" << pessoa[8] << endl;
	cout << "Gratificacao Salarial:\t" << pessoa[9] << endl << endl;
}

bool Empresa::excluirPessoa(string idPessoal)
{
	return this->cadastroPessoas.excluirPessoa(idPessoal);
}

/**
    Obtém a gratificação de um determinado funcionário.

    @return a string relativa à gratificação do funcionário
*/
string Empresa::getGratificacaoFuncionario(string idFuncional){
	string pessoa;
	vector <string> vpessoa;
	pessoa = this->cadastroPessoas.lerDadosPessoas(idFuncional, C_IDFUNC);
	vpessoa = SplitPessoa(pessoa);
	return vpessoa[9];
}

bool Empresa::contratarFuncCadastrado(string idPessoal, string idFuncional)
{
	string pessoa;
	pessoa = this->cadastroPessoas.lerDadosPessoas(idPessoal, C_IDPESSOA);

	string check;
	check = this->cadastroPessoas.lerDadosPessoas(idFuncional, C_IDFUNC);

	if (check == "erro") {
		cout << "Id Funcional ja existente.";
		return false;
	}

	this->cadastroPessoas.atualizarDadosPessoas(idPessoal, C_IDPESSOA, idFuncional, C_IDFUNC);
	this->cadastroPessoas.atualizarDadosPessoas(idPessoal, C_IDPESSOA, "1", C_EFUNC);

	vector<string> vfunc;
	vfunc = this->cadastroPessoas.splitDado(pessoa);
	this->funcionarios.push_back(Funcionario(idPessoal, idFuncional, vfunc[3],
		vfunc[4], vfunc[5], vfunc[6], vfunc[7], vfunc[8]));


	return false;
}

bool Empresa::inserirPessoaCadastro(string idPessoal, string nome, string profissao, string endereco, string funcao, string cargo, string faixaSalarial)
{
	string idFuncional = "0000";
	string estadoFuncional = "2";
	string gratificacao = "0";
	return this->cadastroPessoas.inserir(idPessoal, idFuncional, estadoFuncional, nome, profissao, endereco, funcao, cargo, faixaSalarial, gratificacao);
}

string Empresa::lerDadosTodasPessoas()
{
	return this->cadastroPessoas.lerDadosTodasPessoas();
}

string Empresa::lerDadosFunc()
{
	return this->cadastroPessoas.lerDadosPessoas("1", C_EFUNC);
}

string Empresa::obterDadosArquivo(int idArquivo)
{
	switch (idArquivo) {
	case 0:
		return this->cadastroPessoas.dadosCP();
		break;
	case 1:
		return this->tabelaSalarial.dadosTS();
		break;
	case 2:
		return this->contribuicaoSindical.dadosCS();
		break;
	case 3:
		return this->impostoRenda.dadosIR();
		break;
	}
	
}

void Empresa::obterDadosPessoasEspecificas(string valorChave, Campos chave)
{
	string resultado = this->cadastroPessoas.lerDadosPessoas(valorChave, chave);
	vector<string> pessoas = this->SplitPessoas(resultado);

	for (unsigned long i = 0; i < pessoas.size(); i++) {

		vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);

		cout << i + 1 << "a pessoa:" << endl;
		cout << "ID Pessoa: \t\t" << pessoa[0] << endl;
		cout << "Id Funcional: \t\t" << pessoa[1] << endl;
		cout << "Estado Funcional:\t" << pessoa[2] << endl;
		cout << "Nome:\t\t\t" << pessoa[3] << endl;
		cout << "Endereco:\t\t" << pessoa[4] << endl;
		cout << "Profissao:\t\t" << pessoa[5] << endl;
		cout << "Funcao:\t\t\t" << pessoa[6] << endl;
		cout << "Cargo:\t\t\t" << pessoa[7] << endl;
		cout << "Faixa Salarial:\t\t" << pessoa[8] << endl;
		cout << "Gratificacao Salarial:\t" << pessoa[9] << endl << endl;
	}
}

void Empresa::obterDadosOrdenadosFunc() {
	cout << "Dados de todos os funcionarios ordenados pelo salario:" << endl;
	cout << "------------------------------------------------------------" << endl
		<< endl;
	string dados;
	dados = this->cadastroPessoas.lerDadosTodasPessoas();
	vector<string> pessoas = Empresa::SplitPessoas(dados);
	int n = 1;
	for (int j = 9; j > 0; j--) {
		for (unsigned long i = 0; i < pessoas.size()-1; i++) {
			vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);
			if (pessoa[2] == "1") {
				if (stoi(pessoa[8]) == j) {
					cout << n << "o Funcionario: " << endl << endl;
					cout << "Id Pessoa: \t" << pessoa[0] << endl;
					cout << "Id Funcional: \t" << pessoa[1] << endl;
					cout << "Nome:\t\t" << pessoa[3] << endl;
					cout << "Endereco:\t" << pessoa[5] << endl;
					cout << "Profissao:\t" << pessoa[4] << endl;
					cout << "Funcao:\t\t" << pessoa[6] << endl;
					cout << "Cargo:\t\t" << pessoa[7] << endl;
					cout << "Salario:\t" << Empresa::calcularSalario(pessoa[1])
						<< endl << endl;
					cout << endl;
					n++;
				}
			}
		}
	}
	if (this->funcionarios.size() == 0) {
		cout << "Nenhum funcionario cadastrado." << endl;
	}
}

