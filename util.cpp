#include <iostream>
#include "util.hpp"
using namespace std;

float calcularAnoData(Data data)
{
    float anoData = data.ano + (float)data.mes / 12 + (float)data.dia / 365;

    return anoData;
}