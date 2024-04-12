#include <iostream>
#include <vector>
using namespace std;

/*
Consigna:
Cada uno de los siguientes ítems debe considerarse como un ejercicio en sí mismo.
1. Dados 100 valores enteros positivos, informar cuál es el mayor.
2. Dados 100 valores enteros, todos mayores que -10, informar cuál es el mayor.
3. Dados 100 valores enteros, informar cuál es el mayor.
*/

int uno()
{
    cout << "Ingrese 100 valores enteros positivos: " << endl;

    int num;

    std::vector<int> memory = {};
    cin >> num;

    int mayorNum = 0;
    while (memory.size() < 99)
    {
        memory.push_back(num);
        if (num > mayorNum)
        {
            mayorNum = num;
        }

        cout << "Se han ingresado " << memory.size() << " números." << endl;

        cin >> num;
    }

    cout << "El mayor número ingresado fue: " << mayorNum << endl;
    return 0;
}
int dos()
{
    cout << "Ingrese 100 valores enteros mayores a -10: " << endl;

    int num;

    std::vector<int> memory = {};
    cin >> num;

    int mayorNum = 0;
    while (memory.size() < 99)
    {
        memory.push_back(num);
        if (num > mayorNum)
        {
            mayorNum = num;
        }

        cout << "Se han ingresado " << memory.size() << " números." << endl;

        cin >> num;
    }

    cout << "El mayor número ingresado fue: " << mayorNum << endl;
    return 0;
}

int tres()
{
    cout << "Ingrese 100 valores enteros: " << endl;

    int num;

    std::vector<int> memory = {};
    cin >> num;

    int mayorNum = 0;
    while (memory.size() < 99)
    {
        memory.push_back(num);
        if (num > mayorNum)
        {
            mayorNum = num;
        }

        cout << "Se han ingresado " << memory.size() << " números." << endl;

        cin >> num;
    }

    cout << "El mayor número ingresado fue: " << mayorNum << endl;
    return 0;
}

int main()
{
    // uno();
    dos();
    // tres();
}

// TEST1
// 25
// 3
// 8
// 87
// 1, 1, 1, 1...
// RESULT1
// 87

// TEST2
// 25
// 3
// 8
// 87
//-9
//-7
//-1
// 1, 1, 1, 1...
// RESULT2
// 87

// TEST3
// 25
// 3
// 8
// 87
//-76
//-90
//-22
//-17
// 1, 1, 1, 1...
// RESULT3
// 87