#include <iostream>
#include <vector>
using namespace std;

/*
Consigna:
Se ingresan por teclado varios valores enteros positivos, de a uno por vez. Se
solicita informar:
1. Cuántos valores v fueron ingresados, tal que v<=12.
2. Cuántos valores v fueron ingresados, tal que12<v<=24.
3. Cuántos valores v fueron ingresados, tal que 24<v<=36.
4. Cuántos valores v fueron ingresados, tal que v==0 (cero).
La carga de datos finaliza cuando se ingresa un valor negativo.
*/

int main()
{
    cout << "Ingrese valores enteros positivos, el programa finaliza al ingresar un valor negativo: " << endl;

    int num;

    std::vector<int> memory = {};
    cin >> num;

    while (num >= 0)
    {
        memory.push_back(num);

        cin >> num;
    }

    std::string primeraConsigna = "";
    std::string segundaConsigna = "";
    std::string terceraConsigna = "";
    int cuartaConsigna = 0;

    for (int i = 0; i < memory.size(); i++)
    {
        if (memory[i] == 0)
        {
            cuartaConsigna = cuartaConsigna + 1;
        }
        else if (memory[i] <= 12)
        {
            if (primeraConsigna == "")
            {
                primeraConsigna = primeraConsigna + std::to_string(memory[i]);
            }
            else
            {
                primeraConsigna = primeraConsigna + ", " + std::to_string(memory[i]);
            }
        }
        else if (memory[i] > 12 && memory[i] <= 24)
        {
            if (segundaConsigna == "")
            {
                segundaConsigna = segundaConsigna + std::to_string(memory[i]);
            }
            else
            {
                segundaConsigna = segundaConsigna + ", " + std::to_string(memory[i]);
            }
        }
        else if (memory[i] > 24 && memory[i] <= 36)
        {
            if (terceraConsigna == "")
            {
                terceraConsigna = terceraConsigna + std::to_string(memory[i]);
            }
            else
            {
                terceraConsigna = terceraConsigna + ", " + std::to_string(memory[i]);
            }
        }
    }

    cout << "Los números ingresados menores o iguales a 12 fueron: " << primeraConsigna << endl;
    cout << "Los números ingresados mayores a 12 y menores o iguales a 24 fueron: " << segundaConsigna << endl;
    cout << "Los números ingresados mayores a 24 y menores o iguales a 36 fueron: " << terceraConsigna << endl;
    cout << "Los números ingresados iguales a 0 fueron: " << std::to_string(cuartaConsigna) << endl;

    return 0;
}

// TEST
//  7, 11
//  16, 20
//  25, 35
//  0, 0, 0
// -1