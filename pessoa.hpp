#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include "util.hpp"

/**
 * @brief Classe pessoa
 * 
 */
class Pessoa
{
    std::string nome;
    std::string cpf;
    Data dataNascimento;
    Endereco enderecoPessoal;
    std::string estadoCivil;
    int qtdFilhos;

public:
    Pessoa();
    /**
     * @brief Construtor da classe pessoa
     * 
     * @param nome 
     * @param cpf 
     * @param dataNascimento 
     * @param enderecoPessoal 
     * @param estadoCivil 
     * @param qtdFilhos 
     */
    Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos);

    std::string getNome();
    std::string getCpf();
    Data getDataNascimento();
    Endereco getEnderecoPessoal();
    std::string getEstadoCivil();
    int getQtdFilhos();

    void setNome(std::string nome);
    void setCpf(std::string cpf);
    void setDataNascimento(Data dataNascimento);
    void setEnderecoPessoal(Endereco enderecoPessoal);
    void setEstadoCivil(std::string estadoCivil);
    void setQtdFilhos(int qtdFilhos);

    /**
     * @brief Imprime todos os atributos da classe pessoa
     * 
     */
    void imprimirAtributosPessoa();
};

#endif