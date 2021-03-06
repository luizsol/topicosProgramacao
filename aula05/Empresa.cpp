/**
PCS2478 - Tópicos de Programação
Empresa.cpp

@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
@version 3.0 2017-08-30
*/

#include "Empresa.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Construtores da classe Empresa
Empresa::Empresa() : Empresa("Sem Nome", 10) {}

Empresa::Empresa(string nome) : Empresa(nome, 10) {}

Empresa::Empresa(int maxFuncionarios) : Empresa("Sem Nome", maxFuncionarios) {}

Empresa::Empresa(string nome, int maxFuncionarios) {
	string l01, l02, l03, l04, l05, lTotal;
	l01 = "0001|0021|1|Cristiana Souza|Tecnica Administrativa|Rua AA, 154|Secretaria|Pleno|05|0|\n";
	l02 = "0002|0042|1|Heroldo Teles|Tecnico Eletronico|Rua BB, 32|Suporte|Junior|03|1|\n";
	l03 = "0003|0000|2|Carlos Peixoto|Engenheiro Eletrico|Alameda ZZ, 187|Engenheiro|Senior|07|0|\n";
	l04 = "0004|0063|1|Teresa Alves|Engenheiro de Producao|Rua CCC, 501|Engenheiro|Senior|06|1|\n";
	l05 = "0005|0000|2|Eliana Silva|Administrador de Empresa|Rua DD, 735|Administrador|Diretor|09|0|\n";
	lTotal = l01 + l02 + l03 + l04 + l05;

	Empresa::initFuncArray(maxFuncionarios);
	this->cadastroPessoas.adicionarDadosPessoas(lTotal);
	Empresa::setNome(nome);
	Empresa::iniciarFuncionarios();
}

// Destrutor da classe empresa
Empresa::~Empresa() {
	Empresa::demitirTodosFuncionarios();
}

// Setters e Getters
string Empresa::getNome() {
	return this->nome;
}

void Empresa::setNome(string nome) {
	this->nome = nome;
}

/**
Solicita os dados de todas as pessoas cadastradas e contrata aquelas que
tiverem o estado funcional "empregado" (1)

@return true se todos os funcionários foram devidamente contratados
*/
bool Empresa::iniciarFuncionarios() {
	vector<string> pessoas = this->cadastroPessoas.getDadosPessoais();

	for (unsigned long i = 0; i < pessoas.size(); i++) {
		vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);
		if (pessoa[2].compare("1") == 0) {
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
	string faixaSalario, string gratificacao) {

	if (this->maxFuncionarios == this->funcionarios.size()) {
		throw std::domain_error("Empresa::contratarFuncionario: "
			"Limite de funcionarios atingido");
	}

	if (Empresa::idJaCadastrado(idFuncional)) {
		throw std::domain_error("Empresa::contratarFuncionario: "
			"ID Funcional ja cadastrado");
	}

	string linha = this->cadastroPessoas.gerarLinha(idPessoa, idFuncional, "1",
		nome, profissao, endereco,
		funcao, cargo, faixaSalario,
		gratificacao);

	this->cadastroPessoas.atualizarDadosPessoa(linha);
	this->funcionarios.push_back(Funcionario(idPessoa, idFuncional, nome,
		profissao, endereco, funcao, cargo,
		faixaSalario, gratificacao));
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
bool Empresa::contratarFuncionario() {
	// Verificando se existem pessoas para serem contratadas
	vector<string> pessoas = this->cadastroPessoas.getDadosPessoais();
	bool ninguemPorCadastrar = true;
	for (unsigned long i = 0; i < pessoas.size() && ninguemPorCadastrar; i++) {
		vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);
		if (std::to_string(2).compare(pessoa[2]) == 0) {
			ninguemPorCadastrar = false;
		}
	}

	if (ninguemPorCadastrar) {
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
	if (indice < 0) {
		throw std::domain_error("Empresa::contratarFuncionario: "
			"ID pessoa inexistente.");
	}

	vector<string> pessoa = this->cadastroPessoas.splitDado(
		this->cadastroPessoas.lerDadosPessoa(idPessoa)
	);
	if (pessoa[2].compare("2") != 0) {
		throw std::domain_error("Empresa::contratarFuncionario: "
			"a pessoa com esse ID pessoa nao esta aguardando"
			" vaga");
	}

	cout << "Digite o novo ID funcional da pessoa a ser contratada (ID antigo = "
		<< pessoa[1] << "): ";
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
bool Empresa::demitirFuncionario(string idFuncional) {
	if (!Empresa::idJaCadastrado(idFuncional)) {
		throw std::domain_error("Empresa::demitirFuncionario: "
			"ID Funcional inexistente.");
	}

	int index = Empresa::buscaIdFuncional(idFuncional);

	string linha = this->cadastroPessoas.gerarLinha(this->funcionarios[index].
		getIdPessoa(),
		this->funcionarios[index].
		getIdFuncional(), "0",
		this->funcionarios[index].
		getNome(),
		this->funcionarios[index].
		getProfissao(),
		this->funcionarios[index].
		getEndereco(),
		this->funcionarios[index].
		getFuncao(),
		this->funcionarios[index].
		getCargo(),
		this->funcionarios[index].
		getFaixaSalario(),
		this->funcionarios[index].
		getGratificacao());

	this->cadastroPessoas.atualizarDadosPessoa(linha);
	this->funcionarios.erase(this->funcionarios.begin() + index);
	return true;
}

/**
Demite e apaga um funcionário da empresa via CLI

@return true se o funcionário foi demitido e apagado, false caso contrário
*/
bool Empresa::demitirFuncionario() {
	Empresa::obterDadosFuncionarios();
	cout << "Forneca o ID Funcional do funcionario que deseja demitir:" << endl;
	string idFuncional;
	getline(cin, idFuncional);
	return Empresa::demitirFuncionario(idFuncional);

}

// Demite e apaga todos funcionário da empresa.
void Empresa::demitirTodosFuncionarios() {
	while (this->funcionarios.size() > 0) {
		Empresa::demitirFuncionario(this->funcionarios[0].getIdFuncional());
	}
}

/**
Imprime os dados de todas as pessoas contidas em cadastroPessoa de forma
formatada
*/
void Empresa::obterDadosPessoas(int filtro) {
	vector<string> pessoas = this->cadastroPessoas.getDadosPessoais();

	for (unsigned long i = 0; i < pessoas.size(); i++) {
		vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);

		// Verificando se o usuário deseja filtrar os resultados
		if (filtro != -1 && std::to_string(filtro).compare(pessoa[2]) != 0) {
			// O usuário deseja filtrar e essa pessoa não se encaixa no filtro.
			continue;
		}
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
		cout << "Gratificacao:\t" << pessoa[9] << endl << endl;
	}
}

// Imprime os dados de todos os funcionários da empresa de forma formatada
void Empresa::obterDadosFuncionarios() {
	cout << "Dados de todas os funcionarios:" << endl;
	cout << "------------------------------------------------------------" << endl
		<< endl;
	for (unsigned long i = 0; i < this->funcionarios.size(); i++) {
		cout << i + 1 << "o Funcionario: " << endl << endl;
		Empresa::obterDadosFuncionario(i);
		cout << endl;
	}
	if (this->funcionarios.size() == 0) {
		cout << "Nenhum funcionario cadastrado." << endl;
	}
}

/**
Inicializa o array de funcionários.

@param maxFuncionarios (int): a capacidade máxima de funcionários da empresa
@return true se a inicialização foi bem sucedida, false caso contrário
*/
bool Empresa::initFuncArray(int maxFuncionarios) {
	this->maxFuncionarios = maxFuncionarios;

	return true;
}

/**
Verifica se existe um funcionário cadastrado com um determinado ID Funcional

@param idFuncional (string): o idFuncional a ser verificado
@return true se já existe um funcionário com o idFuncional, false caso
contrário
*/
bool Empresa::idJaCadastrado(string idFuncional) {
	if (Empresa::buscaIdFuncional(idFuncional) == -1) {
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
int Empresa::buscaIdFuncional(string idFuncional) {
	for (unsigned long i = 0; i < this->funcionarios.size(); i++) {
		if (this->funcionarios[i].getIdFuncional().compare(idFuncional) == 0) {
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
void Empresa::obterDadosFuncionario(int index) {
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
float Empresa::calcularSalario(string idFuncional) {
	int index = Empresa::buscaIdFuncional(idFuncional);
	if (index == -1) {
		return false;
	}
	else {
		vector<string> pessoas = this->cadastroPessoas.getDadosPessoais();
		vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[index]);
		float faixaSalarial = stoi(this->funcionarios[index].getFaixaSalario());
		float salario = this->tabelaSalarial.lerSalario(faixaSalarial);
		if (pessoas[9] == "0") {
			return salario;
		}
		else {
			return salario*1.01;
		}
	}
}
