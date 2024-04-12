#include <iostream>
#include <vector>
using namespace std;

/*
Consigna:
Dados tres valores numéricos enteros positivos: n, a y b, informar el n-ésimo múltiplo
de a que no es múltiplo de b.
Por ejemplo: si n=10, a=5, b=3 entonces el n-ésimo múltiplo de 5 que no es
múltiplo de 3 es: 70; y surge de la siguiente lista:
Múltiplos de 5 = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70 }
*/

int main()
{
    int n, a, b;
    cout << "Ingrese tres números enteros positivos: " << endl;
    cin >> n >> a >> b;

    std::vector<int> multiplosEncontrados = {};

    int aMultiplicar = 1;
    while (multiplosEncontrados.size() < n)
    {
        int multiplo = a * aMultiplicar;
        if (multiplo % b != 0)
        {
            multiplosEncontrados.push_back(multiplo);
            aMultiplicar = aMultiplicar + 1;
        }
        else
        {
            aMultiplicar = aMultiplicar + 1;
        }
    }

    cout << "El múltiplo número " << n << " de " << a << " que no es divisible por " << b << " es: " << multiplosEncontrados[multiplosEncontrados.size() - 1] << endl;

    return 0;
}