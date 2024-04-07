#include <iostream>
using namespace std;

/*
Consigna:
Se ingresan tres valores numéricos enteros, diferentes entre sí, informar cuál es el
menor, cuál está en el medio y cuál es el mayor.
*/

int main()
{
    int a, b, c;
    cout << "Ingrese tres valores enteros diferentes entre si: " << endl;
    cin >> a >> b >> c;
    int masGrande, mediano, masChico;

    if (a > b && a > c)
    {
        masGrande = a;
        if (b > c)
        {
            mediano = b;
            masChico = c;
        }
        else
        {
            mediano = c;
            masChico = b;
        }
    }
    else if (b > a && b > c)
    {
        masGrande = b;
        if (a > c)
        {
            mediano = a;
            masChico = c;
        }
        else
        {
            mediano = c;
            masChico = a;
        }
    }
    else
    {
        masGrande = c;
        if (a > b)
        {
            mediano = a;
            masChico = b;
        }
        else
        {
            mediano = b;
            masChico = a;
        }
    }

    cout << "El mayor número es: " << masGrande << ", el del medio es: " << mediano << ", y el menor es: " << masChico << endl;

    return 0;
}