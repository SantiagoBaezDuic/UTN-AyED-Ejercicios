#include <iostream>
using namespace std;

/*
Consigna:
Se ingresa por teclado dos valores numéricos enteros diferentes entre sí, informar
cuál es el mayor.
*/

int main()
{
    int a;
    int b;
    int mayor;
    cout << "Ingrese dos valores enteros distintos entre si: " << endl;
    cin >> a >> b;
    if (a > b)
    {
        mayor = a;
    }
    else
    {
        mayor = b;
    }

    cout << "El mayor de ambos valores es: " << mayor << endl;
    return 0;
}