#include <iostream>
#include "asg.hpp"
using namespace std;

//Construtores ASG
Asg::Asg(){
}
Asg::Asg(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float adicionalInsalubridade, float salario, string matricula, Data ingressoEmpresa){
    this->setNome(nome);
    this->setCpf(cpf);
    this->setDataNascimento(dataNascimento);
    this->setEnderecoPessoal(enderecoPessoal);
    this->setEstadoCivil(estadoCivil);
    this->setQtdFilhos(qtdFilhos);
    this->setAdicionalInsalubridade(adicionalInsalubridade);
    this->setSalario(salario);
    this->setMatricula(matricula);
    this->setIngressoEmpresa(ingressoEmpresa);
}


//Gets e sets
float Asg::getAdicionalInsalubridade(){
    return this->adicionalInsalubridade;
}
void Asg::setAdicionalInsalubridade(float adicionalInsalubridade){
    this->adicionalInsalubridade = adicionalInsalubridade;
}


//Outras funções
float Asg::calcularSalario(int diasFaltas){
    float salario = this->getSalario();//Salario funcionario
    salario -= (salario/30)*diasFaltas;//Retira dias de faltas

    float adicionalInsalubridade = this->getAdicionalInsalubridade();//Pega o valor da insalubridade
    float qtdFilhos = 100*this->getQtdFilhos(); //Pega a quantidade de filhos e calcula o bônus

    salario = salario * (1 + adicionalInsalubridade) + qtdFilhos; //Soma ao salario o adicional de insalubridade e o bônus de quantidade de filhos
    return salario;
}

float Asg::calcularRecisao(Data desligamento){
    Data ingresso = this->getIngressoEmpresa();
    float salario = this->getSalario();

    float anoIngresso = ingresso.ano + ((float)ingresso.mes / 12) + ((float)ingresso.dia / 365);//Pega o ano de entrada

    float anoDesligamento = desligamento.ano + ((float)desligamento.mes / 12) + ((float)desligamento.dia / 365);//Pega o ano de saida

    float anoTrabalhado = anoDesligamento - anoIngresso;//Quantidade de anos trabalhados

    float recisao = anoTrabalhado * salario;
    return recisao;
}