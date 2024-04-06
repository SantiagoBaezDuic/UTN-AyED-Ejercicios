#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Ingrese un valor entero: " << endl;
    cin >> a;

    cout << "La quinta parte del valor ingresado es: " << (double)a / 5 << endl;
    cout << "El resto de dividir el valor ingresado en 5 es: " << ((double)a / 5) - (a / 5) << endl;
    cout << "La septima parte de la quinta parte del valor ingresado es: " << ((double)a / 5) / 7 << endl;
    return 0;
}