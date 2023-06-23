#include <iostream>
using namespace std;

#include "util.hpp"
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"
#include "empresa.hpp"

int main(int argc, char *argv[])
{

    Data DataHoje;
    DataHoje.dia = stoi(argv[1]);
    DataHoje.mes = stoi(argv[2]);
    DataHoje.ano = stoi(argv[3]);

    Empresa *atacadoDosCalcado = new Empresa("xxxxxxxx", "yyyyyyyy", 111111, DataHoje);

    atacadoDosCalcado->carregaFuncoes();

    return 0;
}