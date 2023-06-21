#include <iostream>
#include "pessoa.hpp"
#include "util.hpp"

using namespace std;

Pessoa::Pessoa()
{
    // cout << "Pessoa criada!" << endl;
}

Pessoa::Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos)
{
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
    this->enderecoPessoal = enderecoPessoal;
    this->estadoCivil = estadoCivil;
    this->qtdFilhos = qtdFilhos;
}

string Pessoa::getNome()
{
    return this->nome;
}
string Pessoa::getCpf()
{
    return this->cpf;
}
Data Pessoa::getDataNascimento()
{
    return this->dataNascimento;
}

Endereco Pessoa::getEnderecoPessoal()
{
    return this->enderecoPessoal;
}

string Pessoa::getEstadoCivil()
{
    return this->estadoCivil;
}

int Pessoa::getQtdFilhos()
{
    return this->qtdFilhos;
}

void Pessoa::setNome(string nome)
{
    this->nome = nome;
}

void Pessoa::setCpf(string cpf)
{
    this->cpf = cpf;
}

void Pessoa::setDataNascimento(Data dataNascimento)
{
    this->dataNascimento = dataNascimento;
}

void Pessoa::setEnderecoPessoal(Endereco enderecoPessoal)
{
    this->enderecoPessoal = enderecoPessoal;
}

void Pessoa::setEstadoCivil(string estadoCivil)
{
    this->estadoCivil = estadoCivil;
}

void Pessoa::setQtdFilhos(int qtdFilhos)
{
    this->qtdFilhos = qtdFilhos;
}

//

void Pessoa::imprimirAtributosPessoa()
{
    cout << this->getNome() << endl;
    cout << this->getCpf() << endl;
    cout << this->getQtdFilhos() << endl;
    cout << this->getEstadoCivil() << endl;
    cout << this->getEnderecoPessoal().cidade << endl;
    cout << this->getEnderecoPessoal().cep << endl;
    cout << this->getEnderecoPessoal().bairro << endl;
    cout << this->getEnderecoPessoal().rua << endl;
    cout << this->getEnderecoPessoal().numero << endl;
    cout << this->getDataNascimento().ano << endl;
    cout << this->getDataNascimento().mes << endl;
    cout << this->getDataNascimento().dia << endl;
}