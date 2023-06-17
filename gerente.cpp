#include <iostream>
#include "gerente.hpp"
#include "util.hpp"
using namespace std;


//Construtor gerente
Gerente::Gerente(){
}
Gerente::Gerente(float participacaoLucros, std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, Data ingressoEmpresa){
  this->setParticipacaoLucros(participacaoLucros);
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
float Gerente::getParticipacaoLucros(){
  return this->participacaoLucros;
};
void Gerente::setParticipacaoLucros(float participacaoLucros){
  this->participacaoLucros = participacaoLucros;
};


//Outras funções
float Gerente::calcularSalario(int diasFaltas){
  float salario = this->getSalario(); //Pega o salario
  salario -= (salario/30)*diasFaltas;//retira o valor das faltas
  salario += getParticipacaoLucros();//soma a participação dos lucros
  salario += 100*getQtdFilhos();//soma o valor dos filhos

  return salario;//retorna o salario
};

float Gerente::calcularRecisao(Data desligamento){
  Data ingresso = this->getIngressoEmpresa();
  float salario = this->getSalario();

  float anoIngresso = ingresso.ano + ((float)ingresso.mes / 12) + ((float)ingresso.dia / 365);//Pega o ano de entrada

  float anoDesligamento = desligamento.ano + ((float)desligamento.mes / 12) + ((float)desligamento.dia / 365);//Pega o ano de saida

  float anoTrabalhado = anoDesligamento - anoIngresso;//Quantidade de anos trabalhados

  float recisao = anoTrabalhado * salario;

  return recisao;
};