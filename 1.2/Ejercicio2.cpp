#include <iostream>
using namespace std;

/*
Consigna:
Se ingresan por teclado dos valores numéricos enteros: a y b, se pide calcular e
informar el cociente a/b, validando que b sea distinto de cero. En tal caso, mostrar
un mensaje de error en la consola.
*/

int main()
{
    int a;
    int b;
    cout << "Ingrese dos valores enteros: " << endl;
    cin >> a >> b;

    if (b == 0)
    {
        cout << "No es posible dividir por 0." << endl;
        return 0;
    }

    cout << "El cociente de los valores ingresados es: " << (double)a / b << endl;

    return 0;
}