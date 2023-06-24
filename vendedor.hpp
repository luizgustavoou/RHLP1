#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "util.hpp"

/**
 * @brief Classe vendedor
 * 
 */
class Vendedor : public Pessoa, public Funcionario
{
    char _tipoVendedor;

public:
    Vendedor();
    /**
     * @brief Construtor da classe vendedor
     * 
     * @param nome 
     * @param cpf 
     * @param dataNascimento 
     * @param enderecoPessoal 
     * @param estadoCivil 
     * @param qtdFilhos 
     * @param salario 
     * @param matricula 
     * @param ingressoEmpresa 
     * @param tipoVendedor 
     * @param diasFalta 
     */
    Vendedor(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, Data ingressoEmpresa, char tipoVendedor, int diasFalta);

    char getTipoVendedor();
    void setTipoVendedor(char tipoVendedor);

    /**
     * @brief Calcula o salario do vendedor com sua gratificação e o desconto dos dias que faltou e somando o adicional por filho
     * Primeiro é realizado o desconto dos dias em que faltou e aadicionando a gratificação logo em seguida
     * Por ultimmo é adicionado um adicional por cada filho do vendedor
     * 
     * @return float 
     */
    float calcularSalario();

    /**
     * @brief Função para calcular a recisão a´pos desligamento do funcionario
     * A recisão é proporcional aos anos em que o vendedor trabalhou na empresa
     * A recisão é igual ao número de salarios multiplicados pelo número de anos trabalhados
     * 
     * @param desligamento 
     * @return float 
     */
    float calcularRecisao(Data desligamento);

    /**
     * @brief Retorna o valor da gratificação de acordo com o tipo do vendedor
     * 
     * @return float 
     */
    float getGratificacao();

    /**
     * @brief Imprime os atributos do vendedor
     * 
     */
    void imprimirAtributosVendedor();
};

#endif