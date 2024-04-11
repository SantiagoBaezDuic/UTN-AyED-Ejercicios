#include <iostream>
#include <vector>
using namespace std;

/*
Consigna:
Se ingresan varios valores numéricos enteros, finalizando la carga de datos al ingresar
un 0 (cero). Se pide informar:
1. Cantidad positivos.
2. Cantidad de negativos.
3. Porcentaje de pares.
4. Promedio de los positivos.
5. Porcentaje de negativos.
*/

std::vector<int> getPositives(std::vector<int> memory)
{
    std::vector<int> positives = {};

    for (int i = 0; i < memory.size(); i++)
    {
        if (memory[i] > 0)
        {
            positives.push_back(memory[i]);
        }
    }

    return positives;
}

std::vector<int> getNegatives(std::vector<int> memory)
{
    std::vector<int> negatives = {};

    for (int i = 0; i < memory.size(); i++)
    {
        if (memory[i] < 0)
        {
            negatives.push_back(memory[i]);
        }
    }

    return negatives;
}

std::vector<int> getEven(std::vector<int> memory)
{
    std::vector<int> positives = {};

    for (int i = 0; i < memory.size(); i++)
    {
        if (memory[i] % 2 == 0)
        {
            positives.push_back(memory[i]);
        }
    }

    return positives;
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
    cout << "Ingrese valores enteros, el programa finaliza al ingresar un valor negativo: " << endl;

    int num;

    std::vector<int> memory = {};
    cin >> num;

    while (num != 0)
    {
        memory.push_back(num);

        cin >> num;
    }

    std::vector<int> positiveNumbers = getPositives(memory);
    std::vector<int> negativeNumbers = getNegatives(memory);
    double positivesAmount = positiveNumbers.size();
    double negativesAmount = negativeNumbers.size();
    std::vector<int> eveNumbers = getEven(memory);
    double positivesAverage = promediar(positiveNumbers);

    cout << "Se ingresaron " << positivesAmount << " números positivos." << endl;
    cout << "Se ingresaron " << negativesAmount << " números negativos." << endl;
    cout << "El " << (negativesAmount * 100) / (double)memory.size() << "% de los números ingresados fueron negativos." << endl;
    cout << "El " << (eveNumbers.size() * 100) / (double)memory.size() << "% de los números ingresados fueron pares." << endl;
    cout << "El promedio de los números positivos es de: " << positivesAverage << "." << endl;

    return 0;
}

// TEST
//-2, -1, -5, -3
// 15, 5, 10
// 0
// RESULTADOS
// 3
// 4
// 57,14
// 28,57
// 10