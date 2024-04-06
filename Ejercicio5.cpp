#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    int mayor;
    int menor;
    cout << "Ingrese dos valores enteros: " << endl;
    cin >> a >> b;
    if (a > b)
    {
        mayor = a;
        menor = b;
    }
    else if (b > a)
    {
        mayor = b;
        menor = a;
    }
    else if (a == b)
    {
        cout << "Los valores ingresados son iguales." << endl;
        return 0;
    }

    cout << "El mayor de ambos valores es: " << mayor << " y el menor es: " << menor << endl;
    return 0;
}