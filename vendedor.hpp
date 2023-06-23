#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "util.hpp"

class Vendedor : public Pessoa, public Funcionario
{
    char _tipoVendedor;

public:
    Vendedor();
    Vendedor(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, Data ingressoEmpresa, char tipoVendedor, int diasFalta);

    char getTipoVendedor();
    void setTipoVendedor(char tipoVendedor);

    float calcularSalario();
    float calcularRecisao(Data desligamento);

    float getGratificacao();

    void imprimirAtributosVendedor();
};

#endif