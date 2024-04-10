#include <iostream>
using namespace std;

/*
Consigna:
Dado un valor numérico entero positivo, informar su factorial.
NOTA: El factorial de un número n (se indica n!) se calcula así: n * n-1 * n-2 * ... * 3 *
2 * 1. El factorial de 0 es 1. Por ejemplo: 5! es: 120, 4! es: 24 y 0! es: 1.
*/

int main()
{
    int num;
    cout << "Ingrese un valor entero positivo: " << endl;
    cin >> num;

    int resultado = 1;
    for (int i = 1; i <= num; i++)
    {
        resultado = resultado * i;
    }

    cout << "El factorial de " << num << " es: " << resultado << endl;

    return 0;
}