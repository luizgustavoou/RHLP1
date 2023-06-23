#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <iostream>
#include <vector>
#include "util.hpp"
#include "pessoa.hpp"
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"
#include <vector>

class Empresa
{
    float _faturamentoMensal;
    std::string _nomeEmpresa;
    std::string _cnpj;
    Pessoa _dono;
    std::vector<Asg> _asgs;
    std::vector<Vendedor> _vendedores;
    std::vector<Gerente> _gerentes;
    Data _hoje;

public:
    Empresa();
    Empresa(std::string nomeEmpresa, std::string cnpj, float faturamentoMensal, Data hoje);

    float getFaturamentoMensal();
    std::string getNomeEmpresa();
    std::string getCnpj();
    Pessoa getDono();
    Data getHoje();
    std::vector<Asg> &getAsgs();
    std::vector<Vendedor> &getVendedores();
    std::vector<Gerente> &getGerentes();

    void setFaturamentoMensal(float faturamentoMensal);
    void setNomeEmpresa(std::string nomeEmpresa);
    void setCnpj(std::string cnpj);
    void setHoje(Data hoje);

    void carregaFuncoes(); // Faltando
    void carregarEmpresa();
    void carregarAsg();
    void carregarVendedor();
    void carregarGerente();
    void carregaDono();
    void imprimeAsgs();
    void imprimeVendedores();
    void imprimeGerentes();
    void imprimeDono();
    void buscaFuncionario(std::string matricula);
    void calculaSalarioFuncionario(std::string matricula);
    void calculaTodoOsSalarios();
    void calcularRecisao(std::string matricula, Data desligamento);
    void demitirFuncionario(std::string matricula, Data desligamento);

    template <typename T>
    void escreverArquivoRelatorioDemissional(T funcionario, std::fstream &arquivo, Data desligamento, std::string cargo);

    template <typename T>
    bool buscaFuncionarioDemite(std::vector<T> &funcionarios, std::string matricula, std::fstream &arquivo, Data desligamento, std::string cargo);

    template <typename T>
    void atualizarArquivo(std::string nomeArquivo, std::vector<T> &funcionarios, std::string cargo);
};

#endif