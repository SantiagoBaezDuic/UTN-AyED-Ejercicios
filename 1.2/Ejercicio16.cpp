#include <iostream>
#include <vector>
using namespace std;

/*
Consigna:
Dado un valor numérico entero positivo n, informar el n-ésimo término de la suce-
sión de Fibonacci. Por ejemplo: si n es 6, la salida del programa debe ser 8.

NOTA: Los primeros dos términos de la serie de Fibonacci son 1 y 1. Luego, cada
término se calcula como la suma de los dos términos anteriores. Así, los primeros
términos de la serie de Fibonacci son: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, etcétera.
*/

int generarFibonacci(int n)
{
    std::vector<int> fibonacci = {1, 1};

    if (n > 2)
    {
        while (fibonacci.size() < n)
        {
            fibonacci.push_back(fibonacci[fibonacci.size() - 1] + fibonacci[fibonacci.size() - 2]);
        }
    }
    return fibonacci[n - 1];
}

int main()
{
    int num;
    cout << "Ingrese un número entero positivo: " << endl;
    cin >> num;
    cout << "El número en la posición " << num << " de la serie de Fibonacci es el " << generarFibonacci(num) << "." << endl;

    return 0;
}