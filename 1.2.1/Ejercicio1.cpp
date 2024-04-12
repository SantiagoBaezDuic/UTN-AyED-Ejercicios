#include <iostream>
using namespace std;

/*
Consigna:
Se ingresan por teclado dos valores numéricos enteros, a y b, se pide calcular e in-
formar por consola el resultado de las siguientes operaciones:

1. La suma: a+b.
2. La diferencia: a-b.
3. El producto: a*b.
4. El cociente: a/b, aceptando que b es distinto de 0 (cero).
*/

int main()
{
    int a;
    int b;
    cout << "Ingrese dos valores enteros: " << endl;
    cin >> a >> b;
    int suma = a + b;
    int resta = a - b;
    double division = (double)a / b;
    int producto = a * b;
    cout << "La suma de ambos valores es: " << suma << endl;
    cout << "La resta de ambos valores es: " << resta << endl;
    cout << "La división de ambos valores es: " << division << endl;
    cout << "El producto de ambos valores es: " << producto << endl;
    return 0;
}