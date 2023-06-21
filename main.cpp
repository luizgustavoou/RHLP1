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
    // atacadoDosCalcado->carregarEmpresa();
    // atacadoDosCalcado->carregarAsg();
    // atacadoDosCalcado->carregarVendedor();
    // atacadoDosCalcado->carregarGerente();
    // atacadoDosCalcado->carregaDono();
    // atacadoDosCalcado->imprimeAsgs();
    // atacadoDosCalcado->imprimeVendedores();
    // atacadoDosCalcado->imprimeGerentes();
    // atacadoDosCalcado->imprimeDono();
    // atacadoDosCalcado->buscaFuncionario("72.412-3");
    // atacadoDosCalcado->calculaSalarioFuncionario("72.412-3");
    // atacadoDosCalcado->calculaTodoOsSalarios();
    // atacadoDosCalcado->calcularRecisao("72.412-3", DataHoje);

    return 0;
}