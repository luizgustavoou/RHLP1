#ifndef ASG_HPP
#define ASG_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "util.hpp"

/**
 * @brief Representa um asg.
 *
 */
class Asg : public Pessoa, public Funcionario
{
    float _adicionalInsalubridade = 0.05;

public:
    Asg();
    /**
     * @brief Construct a new Asg object
     *
     * @param nome Nome do asg.
     * @param cpf Cpf do asg.
     * @param dataNascimento Data de nascimento do asg.
     * @param enderecoPessoal Endereço pessoal do asg.
     * @param estadoCivil Estado civil do asg.
     * @param qtdFilhos Quantidade de filhos do asg.
     * @param salario Salário do asg.
     * @param matricula Matrícula do asg.
     * @param ingressoEmpresa Data de ingresso do asg na empresa.
     * @param adicionalInsalubridade Valor adicional em porcentagem do salário do asg.
     * @param diasFalta Quantidade de dias que o asg faltou no mes.
     */
    Asg(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, Data ingressoEmpresa, float adicionalInsalubridade, int diasFalta);

    float getAdicionalInsalubridade();
    void setAdicionalInsalubridade(float adicionalInsalubridade);

    float calcularSalario();
    float calcularRecisao(Data desligamento);

    void imprimirAtributosAsg();
};

#endif