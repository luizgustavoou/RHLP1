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
    /**
     * @brief Construir um novo objeto asg.
     * 
     */
    Asg();
    /**
     * @brief Construir um novo objeto asg.
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

    /**
     * @brief Calcular o salário do asg.
     * O salário é calculado subtraindo o salário dos dias de faltas durante o mes
     * adicionando a porcentagem de insalubridade e adicionado R$ 100 por filho
     * @return Retorna um salário
     */
    float calcularSalario();
    
    /**
     * @brief Calcular o salário da recisão que o asg receberá após o término do contrato.
     * O salário da recisão é calculado multiplicando o salário do asg pela quantidade de anos trabalhado
     * @param desligamento Data em que a recisão ocorreu 
     * @return Retorna o salário da recisão
     */
    float calcularRecisao(Data desligamento);

    /**
     * @brief Imprimir os atributos da classe asg.
     * 
     */
    void imprimirAtributosAsg();
};

#endif