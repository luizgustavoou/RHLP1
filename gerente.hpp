#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "util.hpp"

class Gerente : public Pessoa, public Funcionario
{
    float _participacaoLucros;

public:
    Gerente();
    Gerente(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, Data ingressoEmpresa, float participacaoLucros);

    float getParticipacaoLucros();
    void setParticipacaoLucros(float participacaoLucros);

    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);

    void imprimirAtributosGerente();
};

#endif