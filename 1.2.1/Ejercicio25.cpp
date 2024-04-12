#include <iostream>
using namespace std;

/*
Consigna:
Dado un conjunto de valores numéricos que finaliza con el ingreso de un 0 (cero),
informar cuál es el mayor de los negativos, y cuál el menor de los positivos.
*/

int main()
{
    int num;
    cout << "Ingrese valores númericos, finaliza al ingresar un 0: " << endl;
    cin >> num;

    int menorPositivo = 0;
    int mayorNegativo = 0;
    while (num != 0)
    {
        if (num < 0)
        {
            if (mayorNegativo == 0)
            {
                mayorNegativo = num;
            }
            else
            {
                if (num > mayorNegativo)
                {
                    mayorNegativo = num;
                }
            }
        }
        else
        {
            if (menorPositivo == 0)
            {
                menorPositivo = num;
            }
            else
            {
                if (num < menorPositivo)
                {
                    menorPositivo = num;
                }
            }
        }

        cin >> num;
    }

    cout << "El menor positivo ingresado es: " << menorPositivo << endl;
    cout << "El mayor negativo ingresado es: " << mayorNegativo << endl;

    return 0;
}

// TEST
/*
-3
-2
-5
-7
-25
-643
5
6
3
80
57
35
0
*/
// RESULTS
// 3
// -2