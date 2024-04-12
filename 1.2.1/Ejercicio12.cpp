#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Consigna:
Dados dos valores numéricos enteros, informar su producto calculándolo
mediante sumas sucesivas.
1. Considerando que los valores ingresados serán números positivos o cero.
2. Considerando que los valores ingresados también podrían ser negativos.
*/

int main()
{
    int a, b;
    cout << "Ingrese dos valores enteros: " << endl;
    cin >> a >> b;

    int resultado = 0;
    if (a == 0 || b == 0)
    {
        resultado = 0;
    }
    else if (a < 0)
    {
        for (int i = 1; i <= abs(a); i++)
        {
            resultado = resultado - b;
        }
    }
    else
    {
        for (int i = 1; i <= a; i++)
        {
            resultado = resultado + b;
        }
    }

    cout << "El producto entre ambos números es: " << resultado << endl;

    return 0;
}