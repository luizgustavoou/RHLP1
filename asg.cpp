#include <iostream>
#include "asg.hpp"
#include "util.hpp"

using namespace std;

Asg::Asg()
{
    // cout << "Asg criado!" << endl;
}

Asg::Asg(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa, float adicionalInsalubridade, int diasFalta)
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
    this->setAdicionalInsalubridade(adicionalInsalubridade);
    this->setDiasFalta(diasFalta);
}

float Asg::getAdicionalInsalubridade()
{
    return this->_adicionalInsalubridade;
}
void Asg::setAdicionalInsalubridade(float adicionalInsalubridade)
{
    this->_adicionalInsalubridade = adicionalInsalubridade;
}

float Asg::calcularSalario()
{
    // TODO: Criar uma const da qtde de dias do mês: 30
    float salario = this->getSalario();
    float salarioPorFalta = salario / 30;
    float descontaFalta = salarioPorFalta * this->getDiasFalta();
    float adicionalInsalubridade = this->getAdicionalInsalubridade();
    float qtdFilhos = this->getQtdFilhos();

    salario -= descontaFalta;
    salario = salario * (1 + adicionalInsalubridade);
    salario += qtdFilhos * 100;

    return salario;
}

float Asg::calcularRecisao(Data desligamento)
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
void Asg::imprimirAtributosAsg()
{

    this->imprimirAtributosPessoa();

    cout << this->getMatricula() << endl;
    cout << this->getSalario() << endl;
    cout << this->getAdicionalInsalubridade() << endl;

    cout << this->getIngressoEmpresa().ano << endl;
    cout << this->getIngressoEmpresa().mes << endl;
    cout << this->getIngressoEmpresa().dia << endl;
}