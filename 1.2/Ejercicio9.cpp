#include <iostream>
using namespace std;

/*
Consigna:
Dada una terna de números naturales que representan el día, mes y año de una fecha,
se pide unificarlos en un único valor numérico entero de ocho dígitos (aaaammdd),
tal que los primeros cuatro dígitos representen el año, los dos siguientes el mes, y los
dos últimos el día.
*/

int main()
{
    string day, month, year;
    cout << "Ingrese tres numeros representativos de un día, un mes y un año en ese orden" << endl;
    cin >> day >> month >> year;

    std::string wholeNumber = year + month + day;

    cout << "La fecha ingresada corresponde al número: " << wholeNumber << endl;

    return 0;
}