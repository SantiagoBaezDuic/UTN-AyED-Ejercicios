#include <iostream>
using namespace std;

/*
Consigna:
Dado un valor numérico entero positivo n, se pide mostrar el factorial de los primeros
n números naturales.
Por ejemplo: si n=7, entonces la salida debe ser: 1, 2, 6, 24, 120, 720, 5040.
*/

int calcularFactorial(int num)
{
    int resultado = 1;
    for (int i = 1; i <= num; i++)
    {
        resultado = resultado * i;
    }
    return resultado;
}

int main()
{
    int num;
    cout << "Ingrese un valor entero positivo: " << endl;
    cin >> num;

    std::string resultString = "";

    for (int i = 1; i <= num; i++)
    {
        int factorial = calcularFactorial(i);
        std::string numString = std::to_string(factorial);
        if (resultString == "")
        {
            resultString = resultString + numString;
        }
        else
        {
            resultString = resultString + ", " + numString;
        }
    }

    cout << "Los factoriales de los primeros " << num << " números enteros positivos son (en orden): " << resultString << "." << endl;

    return 0;
}