#include <iostream>
#include "vendedor.hpp"
using namespace std;


//Construtores de vendedor
Vendedor::Vendedor(){
}
Vendedor::Vendedor(char tipoVendedor, string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa){
    this->setTipoVendedor(tipoVendedor);
    this->setNome(nome);
    this->setCpf(cpf);
    this->setDataNascimento(dataNascimento);
    this->setEnderecoPessoal(enderecoPessoal);
    this->setEstadoCivil(estadoCivil);
    this->setQtdFilhos(qtdFilhos);
    this->setSalario(salario);
    this->setMatricula(matricula);
    this->setIngressoEmpresa(ingressoEmpresa);
}


//Gets e Sets
char Vendedor::getTipoVendedor(){
  return this->tipoVendedor;
}
void Vendedor::setTipoVendedor(char tipoVendedor){
  this->tipoVendedor = tipoVendedor;
}


//Outras funções
float Vendedor::calcularSalario(int diasFaltas){
  float salario = this->getSalario();
  salario -= (salario/30) * diasFaltas; //retira o salario dos dias em que faltou
  if(getTipoVendedor() == 'A'){
    salario += salario*0.15;
  }
  else if(getTipoVendedor() == 'B'){
    salario += salario*0.10;
  }
  else if(getTipoVendedor() == 'C'){
    salario += salario*0.05;
  }
  salario += 100*getQtdFilhos();
  
  return salario;
}

float Vendedor::calcularRecisao(Data desligamento){
  Data ingresso = this->getIngressoEmpresa();
  float salario = this->getSalario();

  float anoIngresso = ingresso.ano + ((float)ingresso.mes / 12) + ((float)ingresso.dia / 365);//Pega o ano de entrada

  float anoDesligamento = desligamento.ano + ((float)desligamento.mes / 12) + ((float)desligamento.dia / 365);//Pega o ano de saida

  float anoTrabalhado = anoDesligamento - anoIngresso;//Quantidade de anos trabalhados

  float recisao = anoTrabalhado * salario;

  return recisao;
}