#include <iostream>
using namespace std;

/*
Consigna:
Dado un valor entero positivo, informar si es un número primo.
NOTA: Un número es primo si sólo es divisible por sí mismo y por 1.
*/

/*
Utilizo el teorema que dice que un número es primo si no es divisible por ningun numero entre 2 y la raíz cuadrada del número
*/

bool esPrimo(int num)
{
    if (num <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int num;
    cout << "Ingrese un valor entero positivo: " << endl;
    cin >> num;

    if (esPrimo(num))
    {
        cout << "El número " << num << " es primo." << endl;
    }
    else
    {
        cout << "El número " << num << " no es primo." << endl;
    }

    return 0;
}