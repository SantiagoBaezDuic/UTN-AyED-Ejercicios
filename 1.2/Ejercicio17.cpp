#include <iostream>
#include <vector>
using namespace std;

/*
Consigna:
Dado un valor numérico entero positivo n, informar los primeros n múltiplos de 5
que no sean múltiplos de 3.
Por ejemplo: si n fuera 6, la salida deberá ser: 5, 10, 20, 25, 35, 40.
*/

int main()
{
    int num;
    cout << "Ingrese un valor entero positivo: " << endl;
    cin >> num;
    cout << "El valor ingresado es: " << num << endl;

    std::string stringMultiplos = "";
    std::vector<int> arrayMultiplos = {};
    int cantidadEncontrada = 0;
    int numAProbar = 5;

    while (cantidadEncontrada < num)
    {
        if (numAProbar % 3 != 0)
        {
            arrayMultiplos.push_back(numAProbar);
            cantidadEncontrada = cantidadEncontrada + 1;
            numAProbar = numAProbar + 5;
            cout << "Nuevo número: " << numAProbar << endl;
        }
        else
        {
            numAProbar = numAProbar + 5;
        }
    }

    for (int i = 0; i <= num - 1; i++)
    {
        if (stringMultiplos == "")
        {
            stringMultiplos = stringMultiplos + std::to_string(arrayMultiplos[i]);
        }
        else
        {
            std::string numString = ", " + std::to_string(arrayMultiplos[i]);
            stringMultiplos = stringMultiplos + numString;
        }
    }

    cout << "Los primeros " << num << " números multiplos de 5 no múltiplos de 3 son: " << stringMultiplos << endl;

    return 0;
}