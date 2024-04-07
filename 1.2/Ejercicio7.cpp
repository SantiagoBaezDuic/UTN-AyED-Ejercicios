#include <iostream>
using namespace std;

/*
Consigna:
Se ingresan tres valores que representan las longitudes de los lados de un triángulo,
informar cuál es el tipo del triángulo ingresado (isósceles, equilátero o escaleno).
*/

int main()
{
    int a, b, c;
    cout << "Ingrese las longitudes de los lados del triángulo: " << endl;
    cin >> a >> b >> c;
    string tipo;
    if (a == b && a == c)
    {
        tipo = "equilátero";
    }
    else if (a == b || a == c || b == c)
    {
        tipo = "isóceles";
    }
    else
    {
        tipo = "escaleno";
    }

    cout << "El triángulo al cual corresponden estos lados es de tipo: " << tipo << endl;

    return 0;
}