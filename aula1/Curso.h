#pragma once
#include <string>
using namespace std;
class Curso
{
private:
	string nome;
public:
	string getNome();
	void setNome(string nome);
	Curso(void);
	Curso(string);
	~Curso(void);
};

