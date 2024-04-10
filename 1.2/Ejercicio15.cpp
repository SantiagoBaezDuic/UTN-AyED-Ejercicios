#include <iostream>
using namespace std;

/*
Consigna:
Dado un valor numérico entero positivo n, informar los primeros n números primos.
Por ejemplo: si n==6 entonces la salida debe ser: 1, 2, 3, 5, 7, 11.
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
    int cantidadPrimos = 0;
    int numAProbar = 1;
    cout << "Ingrese un número entero positivo: " << endl;
    cin >> num;

    std::string stringPrimos = "";

    while (cantidadPrimos < num)
    {
        if (esPrimo(numAProbar))
        {
            if (cantidadPrimos == 0)
            {
                stringPrimos = stringPrimos + std::to_string(numAProbar);
            }
            else
            {
                std::string stringNum = ", " + std::to_string(numAProbar);
                stringPrimos = stringPrimos + stringNum;
            }

            cantidadPrimos = cantidadPrimos + 1;
            numAProbar = numAProbar + 1;
        }
        else
        {
            numAProbar = numAProbar + 1;
        }
    }

    cout << "Los primeros " << num << " números primos son: " << stringPrimos << endl;

    return 0;
}