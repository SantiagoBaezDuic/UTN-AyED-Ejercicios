#include <iostream>
using namespace std;

/*
Consigna:
Se ingresa por teclado un valor numérico entero, informar:
1. La quinta parte de dicho valor.
2. El resto que surge al dividir el valor ingresado en cinco partes iguales.
3. La séptima parte de la quinta parte del valor ingresado.
*/

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