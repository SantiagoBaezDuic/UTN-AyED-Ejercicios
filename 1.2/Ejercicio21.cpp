#include <iostream>
#include <vector>
using namespace std;

/*
Consigna:
Dados 50 valores numéricos enteros, que se ingresan de a uno por vez, se pide
informar el promedio de los mayores que 100, y la suma de los menores que -10.
*/

std::vector<int> getGreaterThanHundred(std::vector<int> memory)
{
    std::vector<int> memoryHolder = {};

    for (int i = 0; i < memory.size(); i++)
    {
        if (memory[i] > 100)
        {
            memoryHolder.push_back(memory[i]);
        }
    }

    return memoryHolder;
}

std::vector<int> getLesserThanMinusTen(std::vector<int> memory)
{
    std::vector<int> memoryHolder = {};

    for (int i = 0; i < memory.size(); i++)
    {
        if (memory[i] < -10)
        {
            memoryHolder.push_back(memory[i]);
        }
    }

    return memoryHolder;
}

double promediar(std::vector<int> conjunto)
{
    double counter = 0;
    for (int i = 0; i < conjunto.size(); i++)
    {
        counter = counter + conjunto[i];
    }

    double promedio = counter / conjunto.size();
    return promedio;
}

int main()
{
    cout << "Ingrese 50 valores enteros: " << endl;

    int num;

    std::vector<int> memory = {};
    cin >> num;

    while (memory.size() < 49)
    {
        memory.push_back(num);

        cout << "Se han ingresado " << memory.size() << " números." << endl;

        cin >> num;
    }

    std::vector<int> lesserNumbers = getLesserThanMinusTen(memory);
    std::vector<int> greaterNumbers = getGreaterThanHundred(memory);
    double greaterAverage = promediar(greaterNumbers);

    int lesserAddition = 0;

    for (int i = 0; i < lesserNumbers.size(); i++)
    {
        lesserAddition = lesserAddition + lesserNumbers[i];
    }

    cout << "El promedio de los números ingresados mayores que 100 es de: " << greaterAverage << "." << endl;
    cout << "La sumatoria de los números ingresados menores que -10 es de: " << lesserAddition << "." << endl;

    return 0;
}

// TEST
//-11, -11, -11
// 250, 250, 300
// 5, 5, 5, 5, 5...
// RESULTS
// 266,66
//-33