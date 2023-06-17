#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "asg.hpp"
#include "util.hpp"
#include "gerente.hpp"
#include "empresa.hpp"
using namespace std;

int main(int argc, char *argv[]){

    Data dataHoje;
    dataHoje.dia = stoi(argv[1]);
    dataHoje.mes = stoi(argv[2]);
    dataHoje.ano = stoi(argv[3]);

    Empresa *atacadoDosCalcado = new Empresa("Atacado dos Calcados",
"40.101.588/0001-98", 156289.56, dataHoje);

    atacadoDosCalcado->carregarFuncoes();

    cout << endl;
  
    return 0;
}