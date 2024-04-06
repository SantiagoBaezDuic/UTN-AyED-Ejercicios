#include <iostream>
using namespace std;

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