#include <iostream>
#include <vector>
using namespace std;

/*
Consigna:
Se dispone de un conjunto de valores enteros positivos cuyo ingreso finaliza con la
llegada de un número negativo.
El conjunto está dividido en subconjuntos, separados entre sí mediante valores
0 (cero). Se pide informar:
1. Por cada subconjunto:
a. Promedio de sus valores.
b. Valor mínimo.
2. Para el conjunto completo:
a. Cantidad de subconjuntos.
b. Sumatoria de sus valores.
c. Número del subconjunto en el que se ingresó el mayor valor (será
único), indicando también cuál fue ese valor y en qué posición
relativa se encontró.
*/

int main()
{
    int num;

    cout << "Ingrese conjuntos de valores enteros positivos separados mediante el número 0: (finaliza al ingresar un número negativo)" << endl;

    std::vector<std::vector<int>> completeMemory = {};

    std::vector<int> partialMemory = {};

    while (num >= 0)
    {
        cin >> num;

        if (num == 0)
        {
            completeMemory.push_back(partialMemory);
        }
        else
        {
            partialMemory.push_back(num);
        }
    }

    if (partialMemory.size() != 0)
    {
        completeMemory.push_back(partialMemory);
    }

    cout << "Cantidad de conjuntos: " << completeMemory.size() << endl;

    return 0;
}