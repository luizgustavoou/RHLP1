#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "util.hpp"
using namespace std;

class Vendedor : public Pessoa, public Funcionario{
  char tipoVendedor;

  public:
    Vendedor();
    Vendedor(char tipoVendedor, string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa);
  
    char getTipoVendedor();
    void setTipoVendedor(char tipoVendedor);
  
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif