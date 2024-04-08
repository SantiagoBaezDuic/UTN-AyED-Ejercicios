#include <iostream>
using namespace std;

/*
Consigna:
Se ingresan dos valores numéricos enteros que corresponden a un mes y un año (1
para enero, 2 para febrero, etcétera), se pide informar cuántos días tiene el mes;
teniendo en cuenta que el año podría ser bisiesto.
*/

int esBisiesto(int anio)
{
    if (anio % 4 == 0 || anio % 400 == 0)
    {
        if (anio % 100 != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    int resultado;
    int mes, anio;

    cout << "Ingrese dos valores enteros corresponientes a un mes y un año: " << endl;
    cin >> mes >> anio;

    switch (mes)
    {
    case 1:
        resultado = 31;
        break;
    case 2:
        if (esBisiesto(anio))
        {
            resultado = 29;
        }
        else
        {
            resultado = 28;
        }
        break;
    case 3:
        resultado = 31;
        break;
    case 4:
        resultado = 30;
        break;
    case 5:
        resultado = 31;
        break;
    case 6:
        resultado = 30;
        break;
    case 7:
        resultado = 31;
        break;
    case 8:
        resultado = 31;
        break;
    case 9:
        resultado = 30;
        break;
    case 10:
        resultado = 31;
        break;
    case 11:
        resultado = 30;
        break;
    case 12:
        resultado = 31;
        break;
    default:
        break;
    }

    cout << "El mes " << mes << " del año " << anio << " tiene " << resultado << " días." << endl;

    return 0;
}