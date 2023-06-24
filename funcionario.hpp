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

    /**
     * @brief Metodo virtual de calcular salario para ser implementado nas classes filhas
     * 
     * @return float 
     */
    virtual float calcularSalario() = 0;

    /**
     * @brief Metodo virtual que recebe como parametro a data de desligamento do funcionario
     * para ser implementada nas classes filhas
     * 
     * @param desligamento 
     * @return float 
     */
    virtual float calcularRecisao(Data desligamento) = 0;
};

#endif