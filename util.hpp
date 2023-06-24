#ifndef UTIL_HPP
#define UTIL_HPP
#include <iostream>


const std::string caminhoArquivosLeitura = "./leituras/";
const std::string caminhoArquivosEscrita = "./escrita/";

/**
 * @brief Estrutura de data para guardar as datas utilizadas nos outros arquivos
 * 
 */
typedef struct _Data
{
    int ano;
    int mes;
    int dia;
} Data;

/**
 * @brief Estrutura de endereço para guardar os endereços utilizadas nos outros arquivos
 * 
 */
typedef struct _Endereco
{
    std::string cidade;
    std::string bairro;
    std::string rua;
    std::string cep;
    int numero;
} Endereco;

/**
 * @brief Função para calcular uma data em anos para calculos de recisões
 * 
 * @param data 
 * @return float 
 */
float calcularAnoData(Data data);

#endif