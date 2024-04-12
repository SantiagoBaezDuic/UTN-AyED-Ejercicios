#include <iostream>
#include <vector>
using namespace std;

/*
Consigna:
Cada uno de los siguientes ítems debe considerarse como un ejercicio en sí mismo.
1. Dados 100 valores enteros negativos, informar cuál es el menor.
2. Dados 100 valores enteros menores que 10, informar cuál es el menor.
3. Dados 100 valores enteros, informar cuál es el menor.
*/

int uno()
{
    cout << "Ingrese 100 valores enteros negativos: " << endl;

    int num;

    std::vector<int> memory = {};
    cin >> num;

    int menorNum = 0;
    while (memory.size() < 99)
    {
        memory.push_back(num);
        if (memory.size() == 1)
        {
            menorNum = num;
        }
        else
        {
            if (num < menorNum)
            {
                menorNum = num;
            }
        }

        cout << "Se han ingresado " << memory.size() << " números." << endl;

        cin >> num;
    }

    cout << "El menor número ingresado fue: " << menorNum << endl;
    return 0;
}
int dos()
{
    cout << "Ingrese 100 valores enteros menores a 10: " << endl;

    int num;

    std::vector<int> memory = {};
    cin >> num;

    int menorNum = 0;
    while (memory.size() < 99)
    {
        memory.push_back(num);
        if (memory.size() == 1)
        {
            menorNum = num;
        }
        else
        {
            if (num < menorNum)
            {
                menorNum = num;
            }
        }

        cout << "Se han ingresado " << memory.size() << " números." << endl;

        cin >> num;
    }

    cout << "El mayor número ingresado fue: " << menorNum << endl;
    return 0;
}

int tres()
{
    cout << "Ingrese 100 valores enteros: " << endl;

    int num;

    std::vector<int> memory = {};
    cin >> num;

    int menorNum = 0;
    while (memory.size() < 99)
    {
        memory.push_back(num);
        if (memory.size() == 1)
        {
            menorNum = num;
        }
        else
        {
            if (num < menorNum)
            {
                menorNum = num;
            }
        }

        cout << "Se han ingresado " << memory.size() << " números." << endl;

        cin >> num;
    }

    cout << "El mayor número ingresado fue: " << menorNum << endl;
    return 0;
}

int main()
{
    // uno();
    // dos();
    tres();
}

// TEST1
// -25
// -3
// -8
// -87
// -1, -1, -1, -1...
// RESULT1
// -87

// TEST2
// 9
// 3
// 8
// 1
//-9
//-7
//-1
//-75
// -1, -1, -1, -1...
// RESULT2
// -75

// TEST3
// -25
// 3
// 8
// 50
// 37
// -87
//-76
//-90
//-22
//-17
// 9
// 5
// 99
// 1, 1, 1, 1...
// RESULT3
// -90