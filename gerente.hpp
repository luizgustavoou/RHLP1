#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "util.hpp"

/**
 * @brief Classe gerente
 * 
 */
class Gerente : public Pessoa, public Funcionario
{
    float _participacaoLucros;

public:
    Gerente();
    /**
     * @brief Construtor da classe gerente
     * 
     * @param nome 
     * @param cpf 
     * @param dataNascimento 
     * @param enderecoPessoal 
     * @param estadoCivil 
     * @param qtdFilhos 
     * @param salario 
     * @param matricula 
     * @param ingressoEmpresa 
     * @param participacaoLucros 
     * @param diasFalta 
     */
    Gerente(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, Data ingressoEmpresa, float participacaoLucros, int diasFalta);

    float getParticipacaoLucros();
    void setParticipacaoLucros(float participacaoLucros);

    /**
     * @brief Calcula o salario do gerente, retirando um valor referente as faltas
     * e adiona a participação nos lucros e o bônus para cada filho
     * 
     * @return float 
     */
    float calcularSalario();

    /**
     * @brief Calcula a recisão do gerente multiplicando os anos trabalhados pelo salario
     * 
     * @param desligamento 
     * @return float 
     */
    float calcularRecisao(Data desligamento);

    /**
     * @brief Imprime os atributos do gerente
     * 
     */
    void imprimirAtributosGerente();
};

#endif