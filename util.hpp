#ifndef UTIL_HPP
#define UTIL_HPP
#include <iostream>

typedef struct _Data {
    int ano;
    int mes;
    int dia;
}Data;

typedef struct _Endereco {
    std::string cidade;
    std::string bairro;
    std::string rua;
    std::string cep;
    int numero;
}Endereco;

#endif