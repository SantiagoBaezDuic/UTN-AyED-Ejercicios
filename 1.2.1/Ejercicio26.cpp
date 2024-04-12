#include <iostream>
using namespace std;

/*
Consigna:
Sea un conjunto de valores numéricos que finaliza al ingresar un 0 (cero), informar
cuál es el mínimo valor considerando sólo aquellos que pertenecen al intervalo [-16, 27].
*/

int main()
{
    int num;
    cout << "Ingrese valores númericos, finaliza al ingresar un 0: " << endl;
    cin >> num;

    int min = 2000;
    while (num != 0)
    {
        if (num >= -16 && num <= 27)
        {
            if (min = 2000)
            {
                min = num;
            }
            else if (num < min)
            {
                min = num;
            }
        }

        cin >> num;
    }

    cout << "El menor valor ingresado que se encuentra dentro del intervalo [-16, 27] es: " << min << "." << endl;

    return 0;
}

// TEST
/*
3
14
56
-40
-17
26
-15
0
*/
// RESULTS
//-15