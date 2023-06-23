#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <iostream>
#include "util.hpp"

class Funcionario
{
    float salario;
    std::string matricula;
    Data ingressoEmpresa;
    int diasFalta;

public:
    float getSalario();
    std::string getMatricula();
    Data getIngressoEmpresa();
    int getDiasFalta();


    void setSalario(float salario);
    void setMatricula(std::string matricula);
    void setIngressoEmpresa(Data ingressoEmpresa);
    void setDiasFalta(int diasFalta);

    virtual float calcularSalario() = 0;
    virtual float calcularRecisao(Data desligamento) = 0;
};

#endif