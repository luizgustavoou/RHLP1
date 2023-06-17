#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <iostream>
#include <vector>
#include "vendedor.hpp"
#include "pessoa.hpp"
#include "asg.hpp"
#include "gerente.hpp"
#include "util.hpp"

class Empresa{
  float faturamentoMensal;
  std::string nomeEmpresa;
  std::string cnpj;
  Pessoa dono;
  vector<Asg> asgs;
  vector<Vendedor> vendedores;
  vector<Gerente> gerentes;
  Data hoje;

  public:
    Empresa();
    Empresa(std::string nomeEmpresa, std::string cnpj, float faturamentoMensal, Data hoje);
    
    float getFaturamentoMensal();
    void setFaturamentoMensal(float faturamentoMensal);
  
    std::string getNomeEmpresa();
    void setNomeEmpresa(std::string nomeEmpresa);
  
    std::string getCnpj();
    void setCnpj(std::string cnpj);
  
    Pessoa getDono();
    void setDono(Pessoa dono);
  
    vector<Asg> getAsgs();
    void setAsgs(vector<Asg> asgs);
  
    vector<Vendedor> getVendedores();
    void setVendedores(vector<Vendedor> vendedores);
  
    vector<Gerente> getGerentes();
    void setGerentes(vector<Gerente> gerentes);
  
    void carregarFuncoes();
    
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
};

#endif