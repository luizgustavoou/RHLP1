#include <iostream>
#include "funcionario.hpp"
#include "util.hpp"

using namespace std;

float Funcionario::getSalario()
{
    return this->salario;
}

string Funcionario::getMatricula()
{
    return this->matricula;
}

Data Funcionario::getIngressoEmpresa()
{
    return this->ingressoEmpresa;
}

void Funcionario::setMatricula(string Matricula)
{
    this->matricula = Matricula;
}

void Funcionario::setSalario(float salario)
{
    this->salario = salario;
}

void Funcionario::setIngressoEmpresa(Data ingressoEmpresa)
{
    this->ingressoEmpresa = ingressoEmpresa;
}
