#ifndef ASG_HPP
#define ASG_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "util.hpp"

class Asg : public Pessoa, public Funcionario{
    float adicionalInsalubridade;

public:
    Asg();
    Asg(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float adicionalInsalubridade, float salario, std::string matricula, Data ingressoEmpresa);

    float getAdicionalInsalubridade();
    void setAdicionalInsalubridade(float adicionalInsalubridade);

    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif