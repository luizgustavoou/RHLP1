#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include "util.hpp"

class Pessoa{
    std::string nome;
    std::string cpf;
    Data dataNascimento;
    Endereco enderecoPessoal;
    std::string estadoCivil;
    int qtdFilhos;

public:
    Pessoa();
    Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos);

    std::string getNome();
    void setNome(std::string nome);

    std::string getCpf();
    void setCpf(std::string cpf);

    Data getDataNascimento();
    void setDataNascimento(Data dataNascimento);

    Endereco getEnderecoPessoal();
    void setEnderecoPessoal(Endereco enderecoPessoal);

    std::string getEstadoCivil();
    void setEstadoCivil(std::string estadoCivil);

    int getQtdFilhos();
    void setQtdFilhos(int qtdFilhos);
};

#endif