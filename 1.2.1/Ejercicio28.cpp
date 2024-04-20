#include <iostream>
#include <vector>
using namespace std;

/*
Consigna:
Se ingresan n conjuntos de m valores numéricos cada uno. Se pide informar:

1. Para cada uno de los n conjuntos:
a. El valor promedio.
b. El máximo valor.
c. Porcentaje de valores positivos.

2. Para todo el lote de datos:
a. Valor promedio.
b. Porcentaje de valores negativos.
c. Valor mínimo.
*/

double calcularPromedio(std::vector<int> arr)
{
    double cuenta = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        cuenta += arr[i];
    }
    double resultado = cuenta / arr.size();
    return resultado;
}

int encontrarExtremo(std::vector<int> arr, string sentido)
{
    int resultado;
    if (sentido == "mayor")
    {
        int num = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > num)
            {
                num = arr[i];
            }
        }
        resultado = num;
    }
    else
    {
        int num = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < num)
            {
                num = arr[i];
            }
        }
        resultado = num;
    }

    return resultado;
}

double calcularPorcentaje(std::vector<int> arr, string signo)
{
    double resultado;
    if (signo == "positivos")
    {
        double cantidad = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > 0)
            {
                cantidad++;
            }
        }

        double porcentaje = (cantidad * 100) / arr.size();
        resultado = porcentaje;
    }
    else
    {
        int cantidad = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < 0)
            {
                cantidad++;
            }
        }

        double porcentaje = (cantidad * 100) / (double)arr.size();
        resultado = porcentaje;
    }

    return resultado;
}

int main()
{
    int n;
    int m;
    int num;

    cout << "Ingrese la cantidad de conjuntos: " << endl;
    cin >> n;
    cout << "Ingrese la longitud de los conjuntos: " << endl;
    cin >> m;

    int totalNumeros = n * m;

    std::vector<int> memory = {};

    cout << "Ingrese los " << n << " conjuntos de " << m << " números." << endl;

    while (memory.size() < totalNumeros)
    {
        cin >> num;
        memory.push_back(num);
    }

    for (int i = 0; i < n; i++)
    {
        std::vector<int> x = {};

        for (int z = 0; z < m; z++)
        {
            x.push_back(memory[z + (i * m)]);
        }

        cout << "Conjunto " << i + 1 << ":" << endl;
        cout << "El promedio del conjunto es de: " << calcularPromedio(x) << endl;
        cout << "El valor máximo del conjunto es de: " << encontrarExtremo(x, "mayor") << endl;
        cout << "El porcentaje de positivos del conjunto es de: " << calcularPorcentaje(x, "positivos") << endl;
        cout << "" << endl;
    }

    cout << "El promedio total es de: " << calcularPromedio(memory) << endl;
    cout << "El porcentaje de negativos total es de: " << calcularPorcentaje(memory, "") << endl;
    cout << "El valor mínimo total es de: " << encontrarExtremo(memory, "") << endl;

    return 0;
}

/*
TEST
3
3

1
-2
3

4
5
-6

7
-8
-9

RESULT
conjunto 1
promedio 0.666
maximo 3
porcentaje 66.666

conjunto 2
promedio 1
maximo 5
porcentaje 66.666

conjunto 3
promedio -3.333
maximo 7
porcentaje 33.333

total
promedio -0.5555
negativos 44.444
minimo -9

*/