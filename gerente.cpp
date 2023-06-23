#include <iostream>
#include "gerente.hpp"
#include "util.hpp"

using namespace std;

Gerente::Gerente()
{
    // cout << "Gerente criado!" << endl;
}

Gerente::Gerente(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa, float participacaoLucros, int diasFalta)
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
    this->setParticipacaoLucros(participacaoLucros);
    this->setDiasFalta(diasFalta);

}

float Gerente::getParticipacaoLucros()
{
    return this->_participacaoLucros;
}
void Gerente::setParticipacaoLucros(float participacaoLucros)
{
    this->_participacaoLucros = participacaoLucros;
}

float Gerente::calcularSalario()
{
    // TODO: Criar uma const da qtde de dias do mês: 30
    float salario = this->getSalario();
    float salarioPorFalta = salario / 30;
    float descontaFalta = salarioPorFalta * this->getDiasFalta();
    float participacaoLucros = this->getParticipacaoLucros();
    float qtdFilhos = this->getQtdFilhos();

    salario -= descontaFalta;
    salario = salario + participacaoLucros;
    salario += qtdFilhos * 100;

    return salario;
}

float Gerente::calcularRecisao(Data desligamento)
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
void Gerente::imprimirAtributosGerente()
{
    this->imprimirAtributosPessoa();

    cout << this->getMatricula() << endl;
    cout << this->getSalario() << endl;
    cout << this->getParticipacaoLucros() << endl;

    cout << this->getIngressoEmpresa().ano << endl;
    cout << this->getIngressoEmpresa().mes << endl;
    cout << this->getIngressoEmpresa().dia << endl;
}