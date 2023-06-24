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

/**
 * @brief Classe empresa
 * 
 */
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
    /**
     * @brief Metodo construtor de empresa
     * 
     * @param nomeEmpresa 
     * @param cnpj 
     * @param faturamentoMensal 
     * @param hoje 
     */
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

    /**
     * @brief Ler um arquivo .txt com as funções que devem ser executadas e as executa em ordem
     * 
     */
    void carregaFuncoes(); // Faltando

    /**
     * @brief Lê um arquivo .txt com os atributos da empresa e a costroi
     * 
     */
    void carregarEmpresa();

    /**
     * @brief Lê um arquivo .txt com varias ASGs e as adiciona no vetor de asgs da classe
     * 
     */
    void carregarAsg();

    /**
     * @brief Lê um arquivo .txt com varios vendedores e as adiciona no vetor de vendedores da classe
     * 
     */
    void carregarVendedor();

    /**
     * @brief Lê um arquivo .txt com varios gerentes e as adiciona no vetor de gerentes da classe
     * 
     */
    void carregarGerente();

    /**
     * @brief Lê o arquivo .txt com o dono da empresa que é do tipo Pessoa e adiciona ele no atributo da classe
     * 
     */
    void carregaDono();

    /**
     * @brief Imprime todas as ASGs que estão no vetor asgs
     * 
     */
    void imprimeAsgs();

    /**
     * @brief Imprime todos os vendedores que estão no vetor vendedores
     * 
     */
    void imprimeVendedores();

    /**
     * @brief Imprime todos os gerentes que estão no vetor gerentes
     * 
     */
    void imprimeGerentes();

    /**
     * @brief Imprime os atributos do Dono
     * 
     */
    void imprimeDono();

    /**
     * @brief Recebe a matricula do funcionario e busca nos vetores de asgs, vendedores e gerentes
     * se o funcionario for achado os seus atributos são impressos
     * 
     * @param matricula 
     */
    void buscaFuncionario(std::string matricula);

    /**
     * @brief Recebe a matricula do funcionario e faz uma busca nos vetores de asgs, vendedores
     * e gerentes, se encontrar o salario do funcionario é calculado com os descontos e bônus
     * 
     * @param matricula 
     */
    void calculaSalarioFuncionario(std::string matricula);

    /**
     * @brief Faz o relatorio financeiro encravendo em um arquivo .txt com nome de relatorio
     * que contem todos os salarios e nomes de todos os funcionarios, separados por tipo e o
     * total da soma, alem de mostrar os ganhos da empresa, se ela está em lucro ou prejuizo 
     * e seu lucro se houver
     * 
     */
    void calculaTodoOsSalarios();

    /**
     * @brief REcebe a matricula e a data de desligamento do funcionario, com a matricula 
     * verifica se ele existe e se ele é asg, vendedor ou gerente; e com a data de desligamento
     * e a de ingresso do funcionario é calculado o tempo em anos que ele trabalhou e multiplica
     * pelo salario dele para saber o valor da recisão
     * 
     * @param matricula 
     * @param desligamento 
     */
    void calcularRecisao(std::string matricula, Data desligamento);

    /**
     * @brief Com a matricula do funcionarrio é verificado se aquele funcionario existe no sistema
     * e de qual tipo ele é, e se ele existe, é realizado a remoção do funcionario do vetor e a
     * atualização do arquivo do respectivo tipo do funcionario
     * 
     * @param matricula 
     * @param desligamento 
     */
    void demitirFuncionario(std::string matricula, Data desligamento);

    /**
     * @brief Escreve o relatorio da demissão do funcionario
     * 
     * @tparam T 
     * @param funcionario 
     * @param arquivo 
     * @param desligamento 
     * @param cargo 
     */
    template <typename T>
    void escreverArquivoRelatorioDemissional(T funcionario, std::fstream &arquivo, Data desligamento, std::string cargo);

    /**
     * @brief Realiza a busca do funcionario que se quer demitir
     * 
     * @tparam T 
     * @param funcionarios 
     * @param matricula 
     * @param arquivo 
     * @param desligamento 
     * @param cargo 
     * @return true 
     * @return false 
     */
    template <typename T>
    bool buscaFuncionarioDemite(std::vector<T> &funcionarios, std::string matricula, std::fstream &arquivo, Data desligamento, std::string cargo);

    // template <typename T>
    // void atualizarArquivo(std::string nomeArquivo, std::vector<T> &funcionarios, std::string cargo);

    /**
     * @brief Reescreve o arquivo das asgs após realizar uma demissão ou uma contratação
     * 
     */
    void atualizarArquivoAsg();

    /**
     * @brief Reescreve o arquivo dos vendedores após realizar uma demissão ou uma contratação
     * 
     */
    void atualizarArquivoVendedor();

    /**
     * @brief Reescreve o arquivo dos gerentes após realizar uma demissão ou uma contratação
     * 
     */
    void atualizarArquivoGerente();

    /**
     * @brief Lê um arquivo .txt com os funcionarios que se deve contratar, checa de que tipo
     * eles são e adiciona em seu respectivo vetor, após serem adicionados os arquivos do tipo
     * do funcionario contratado são reescritos com o novo funcionario
     * 
     */
    void contratarFuncionario();
};

#endif