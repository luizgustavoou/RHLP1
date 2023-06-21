#include <iostream>
#include "vendedor.hpp"
#include "util.hpp"

using namespace std;

Vendedor::Vendedor()
{
    // cout << "Vendedor criado!" << endl;
}

Vendedor::Vendedor(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa, char tipoVendedor)
{
    this->setNome(nome);
    this->setCpf(cpf);
    this->setDataNascimento(dataNascimento);
    this->setEnderecoPessoal(enderecoPessoal);
    this->setEstadoCivil(estadoCivil);
    this->setQtdFilhos(qtdFilhos);
    this->setSalario(salario);
    this->setMatricula(matricula);
    this->setIngressoEmpresa(ingressoEmpresa);
    this->setTipoVendedor(tipoVendedor);
}

float Vendedor::getGratificacao()
{
    char tipoVendedor = this->getTipoVendedor();

    if (tipoVendedor == 'A')
    {
        return 0.25;
    }
    else if (tipoVendedor == 'B')
    {
        return 0.10;
    }
    else
    {
        return 0.05;
    }
}

char Vendedor::getTipoVendedor()
{
    return this->_tipoVendedor;
}
void Vendedor::setTipoVendedor(char tipoVendedor)
{
    this->_tipoVendedor = tipoVendedor;
}

float Vendedor::calcularSalario(int diasFaltas)
{
    // TODO: Criar uma const da qtde de dias do mês: 30
    float salario = this->getSalario();
    float salarioPorFalta = salario / 30;
    float descontaFalta = salarioPorFalta * diasFaltas;
    float qtdFilhos = this->getQtdFilhos();
    float gratificacao = this->getGratificacao();

    salario -= descontaFalta;
    salario = salario * (1 + gratificacao);
    salario += qtdFilhos * 100;

    return salario;
}

float Vendedor::calcularRecisao(Data desligamento)
{
    Data ingresso = this->getIngressoEmpresa();
    float salario = this->getSalario();
    float anoIngresso = calcularAnoData(ingresso);
    float anoDesligamento = calcularAnoData(desligamento);
    float anoTrabalhado = anoDesligamento - anoIngresso;

    float recisao = anoTrabalhado * salario;

    return recisao;
}

// FUNÇÕES FORA DA PROVA
void Vendedor::imprimirAtributosVendedor()
{
    this->imprimirAtributosPessoa();

    cout << this->getMatricula() << endl;
    cout << this->getSalario() << endl;
    cout << this->getTipoVendedor() << endl;

    cout << this->getIngressoEmpresa().ano << endl;
    cout << this->getIngressoEmpresa().mes << endl;
    cout << this->getIngressoEmpresa().dia << endl;
}