#include <iostream>
using namespace std;

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