#include <iostream>
#include "funcionario.hpp"
#include "util.hpp"
using namespace std;


//Gets e Sets
float Funcionario::getSalario(){
    return this->salario;
}
void Funcionario::setSalario(float salario){
    this->salario = salario;
}

string Funcionario::getMatricula(){
    return this->matricula;
}
void Funcionario::setMatricula(string Matricula){
    this->matricula = Matricula;
}

Data Funcionario::getIngressoEmpresa(){
    return this->ingressoEmpresa;
}
void Funcionario::setIngressoEmpresa(Data ingressoEmpresa){
    this->ingressoEmpresa = ingressoEmpresa;
}