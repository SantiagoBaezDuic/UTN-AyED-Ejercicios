#include <iostream>
using namespace std;

/*
Consigna:
Se ingresa un conjunto de pares (n, f), donde n es el nombre de una persona y f su
fecha de nacimiento, informar el nombre de la persona más joven y el de la más vieja.
*/

int main()
{
    int currentAge = 0;
    string currentName = "";

    cout << "Ingrese un par de valores (Nombre edad), finaliza al ingresar (a 1000): " << endl;
    cin >> currentName >> currentAge;

    string youngestName = "";
    int youngestAge = 0;
    string oldestName = "";
    int oldestAge = 0;

    while (currentName != "a" && currentAge != 1000)
    {
        if (youngestAge == 0)
        {
            youngestName = currentName;
            youngestAge = currentAge;
        }
        if (oldestAge == 0)
        {
            oldestAge = currentAge;
            oldestName = currentName;
        }
        else
        {
            if (currentAge < youngestAge)
            {
                youngestAge = currentAge;
                youngestName = currentName;
            }

            if (currentAge > oldestAge)
            {
                oldestAge = currentAge;
                oldestName = currentName;
            }
        }

        cin >> currentName >> currentAge;
    }

    cout << "La persona mas jóven es " << youngestName << " con " << youngestAge << " años." << endl;
    cout << "La persona mas anciana es " << oldestName << " con " << oldestAge << " años." << endl;

    return 0;
}

// TEST
/*
Jorge 24
Rodrigo 5
Ana 73
Manuel 18
Josefina 2
Gerardo 89
Roberto 37
a 1000
*/
// RESULTS
// Josefina 2
// Gerardo 89