#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <iostream>
#include "util.hpp"

class Funcionario{
    float salario;
    std::string matricula;
    Data ingressoEmpresa;

public:
    float getSalario();
    void setSalario(float salario);

    std::string getMatricula();
    void setMatricula(std::string matricula);

    Data getIngressoEmpresa();
    void setIngressoEmpresa(Data ingressoEmpresa);

    virtual float calcularSalario(int diasFaltas) = 0;
    virtual float calcularRecisao(Data desligamento) = 0;
};

#endif