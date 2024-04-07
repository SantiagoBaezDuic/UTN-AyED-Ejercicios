#include <iostream>
using namespace std;

/*
Consigna:
Dado un número de ocho dígitos que representa una fecha con formato aaaammdd,
se pide mostrar por separado el día, el mes y el año de la fecha ingresada.
*/

int main()
{
    string num;
    cout << "Ingrese un número de 8 dígitos: " << endl;
    cin >> num;

    string year;
    string month;
    string day;

    year = num.substr(0, 4);
    month = num.substr(4, 2);
    day = num.substr(6, 2);

    cout << "El número ingresado corresponde al día " << day << " del mes " << month << " del año " << year << "." << endl;

    return 0;
}