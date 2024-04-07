#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

/*
Consigna:
Entre dos fechas indicadas por el usuario, informar cuál es la más cercana a la actual.
Se debe establecer:
    1. Cuáles son los datos de entrada que el algoritmo necesitará para resolver el
    problema planteado.
    2. En qué formato el usuario deberá ingresar dichos datos de entrada.
Se debe considerar los años bisiestos, entendiendo que un año es bisiesto si es
divisible por 4, o por 400 pero no por 100.
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

int añoActual = 2024;
int mesActual = 04;
int diaActual = 07;

int contarCercania(int anio, int mes, int dia)
{
    int tiempo = 0;

    int añoInicio;
    int mesInicio;
    int diaInicio;
    int añoFinal;
    int mesFinal;
    int diaFinal;

    // Seteo el año de inicio y de final segun el año a evaluar sea anterior o posterior al actual
    if (anio < añoActual)
    {
        añoInicio = anio;
        mesInicio = mes;
        diaInicio = dia;
        añoFinal = añoActual;
        mesFinal = mesActual;
        diaFinal = diaActual;
    }
    else if (anio > añoActual)
    {
        añoInicio = añoActual;
        mesInicio = mesActual;
        diaInicio = diaActual;
        añoFinal = anio;
        mesFinal = mes;
        diaFinal = dia;
    }
    else if (anio == añoActual)
    {
        if (mes < mesActual)
        {
            mesInicio = mes;
            diaInicio = dia;
            mesFinal = mesActual;
            diaFinal = diaActual;
        }
        else if (mes > mesActual)
        {
            mesInicio = mesActual;
            diaInicio = diaActual;
            mesFinal = mes;
            diaFinal = dia;
        }
        else if (mes == mesActual)
        {
            if (dia < diaActual)
            {
                diaInicio = dia;
                diaFinal = diaActual;
            }
            else if (dia > diaActual)
            {
                diaInicio = diaActual;
                diaFinal = dia;
            }
            else if (dia == diaActual)
            {
                return tiempo;
            }
        }
    }

    if (dia == diaActual && mes == mesActual && anio == añoActual)
    {
        tiempo = diaFinal;
        return tiempo;
    }
    if (mes == mesActual && anio == añoActual)
    {
        tiempo = diaFinal - diaInicio;
        return tiempo;
    }
    else
    {
        if (anio == añoActual)
        {
            // Sumo los días desde el día de inicio
            switch (mesInicio)
            {
            case 1:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 2:
                if (esBisiesto(añoInicio))
                {
                    tiempo = tiempo + 29 - diaInicio;
                }
                else
                {
                    tiempo = tiempo + 28 - diaInicio;
                }
                break;
            case 3:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 4:
                tiempo = tiempo + 30 - diaInicio;
                break;
            case 5:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 6:
                tiempo = tiempo + 30 - diaInicio;
                break;
            case 7:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 8:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 9:
                tiempo = tiempo + 30 - diaInicio;
                break;
            case 10:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 11:
                tiempo = tiempo + 30 - diaInicio;
                break;
            case 12:
                tiempo = tiempo + 31 - diaInicio;
                break;
            default:
                break;
            }

            // Sumo los días de los meses restantes del año
            for (int i = mesInicio + 1; i < mesFinal; i++)
            {
                switch (i)
                {
                case 1:
                    tiempo = tiempo + 31;
                    break;
                case 2:
                    if (esBisiesto(añoInicio))
                    {
                        tiempo = tiempo + 29;
                    }
                    else
                    {
                        tiempo = tiempo + 28;
                    }
                    break;
                case 3:
                    tiempo = tiempo + 31;
                    break;
                case 4:
                    tiempo = tiempo + 30;
                    break;
                case 5:
                    tiempo = tiempo + 31;
                    break;
                case 6:
                    tiempo = tiempo + 30;
                    break;
                case 7:
                    tiempo = tiempo + 31;
                    break;
                case 8:
                    tiempo = tiempo + 31;
                    break;
                case 9:
                    tiempo = tiempo + 30;
                    break;
                case 10:
                    tiempo = tiempo + 31;
                    break;
                case 11:
                    tiempo = tiempo + 30;
                    break;
                case 12:
                    tiempo = tiempo + 31;
                    break;
                default:
                    break;
                }
            }

            tiempo = tiempo + diaFinal;
        }
        else
        {
            // Sumo los días desde el día de inicio
            switch (mesInicio)
            {
            case 1:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 2:
                if (esBisiesto(añoInicio))
                {
                    tiempo = tiempo + 29 - diaInicio;
                }
                else
                {
                    tiempo = tiempo + 28 - diaInicio;
                }
                break;
            case 3:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 4:
                tiempo = tiempo + 30 - diaInicio;
                break;
            case 5:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 6:
                tiempo = tiempo + 30 - diaInicio;
                break;
            case 7:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 8:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 9:
                tiempo = tiempo + 30 - diaInicio;
                break;
            case 10:
                tiempo = tiempo + 31 - diaInicio;
                break;
            case 11:
                tiempo = tiempo + 30 - diaInicio;
                break;
            case 12:
                tiempo = tiempo + 31 - diaInicio;
                break;
            default:
                break;
            }

            // Sumo los dias de los meses restantes del año
            for (int i = mesInicio + 1; i <= 12; i++)
            {
                switch (i)
                {
                case 1:
                    tiempo = tiempo + 31;
                    break;
                case 2:
                    if (esBisiesto(añoInicio))
                    {
                        tiempo = tiempo + 29;
                    }
                    else
                    {
                        tiempo = tiempo + 28;
                    }
                    break;
                case 3:
                    tiempo = tiempo + 31;
                    break;
                case 4:
                    tiempo = tiempo + 30;
                    break;
                case 5:
                    tiempo = tiempo + 31;
                    break;
                case 6:
                    tiempo = tiempo + 30;
                    break;
                case 7:
                    tiempo = tiempo + 31;
                    break;
                case 8:
                    tiempo = tiempo + 31;
                    break;
                case 9:
                    tiempo = tiempo + 30;
                    break;
                case 10:
                    tiempo = tiempo + 31;
                    break;
                case 11:
                    tiempo = tiempo + 30;
                    break;
                case 12:
                    tiempo = tiempo + 31;
                    break;
                default:
                    break;
                }
            }

            // Sumo los días de los años entre el de inicio y el final
            if (anio != añoActual)
            {
                for (int i = añoInicio + 1; i < añoFinal; i++)
                {
                    if (esBisiesto(i))
                    {
                        tiempo = tiempo + 366;
                    }
                    else
                    {
                        tiempo = tiempo + 365;
                    }
                }
            }

            // Sumo los días de los meses anteriores al mes final que están dentro del año final
            for (int i = 1; i < mesFinal; i++)
            {
                switch (i)
                {
                case 1:
                    tiempo = tiempo + 31;
                    break;
                case 2:
                    if (esBisiesto(añoFinal))
                    {
                        tiempo = tiempo + 29;
                    }
                    else
                    {
                        tiempo = tiempo + 28;
                    }
                    break;
                case 3:
                    tiempo = tiempo + 31;
                    break;
                case 4:
                    tiempo = tiempo + 30;
                    break;
                case 5:
                    tiempo = tiempo + 31;
                    break;
                case 6:
                    tiempo = tiempo + 30;
                    break;
                case 7:
                    tiempo = tiempo + 31;
                    break;
                case 8:
                    tiempo = tiempo + 31;
                    break;
                case 9:
                    tiempo = tiempo + 30;
                    break;
                case 10:
                    tiempo = tiempo + 31;
                    break;
                case 11:
                    tiempo = tiempo + 30;
                    break;
                case 12:
                    tiempo = tiempo + 31;
                    break;
                default:
                    break;
                }
            }

            tiempo = tiempo + diaFinal;
        }
    }

    return tiempo;
}

int main()
{
    int fecha1;
    int fecha2;
    cout << "Ingrese la primera fecha (formato aaaammdd): " << endl;
    cin >> fecha1;
    cout << "Ingrese la segunda fecha (formato aaaammdd)(distinta a la primera): " << endl;
    cin >> fecha2;
    int año1, mes1, dia1;
    int año2, mes2, dia2;

    año1 = fecha1 / 10000;
    mes1 = (fecha1 % 10000) / 100;
    dia1 = fecha1 % 100;

    int tiempo1 = contarCercania(año1, mes1, dia1);

    año2 = fecha2 / 10000;
    mes2 = (fecha2 % 10000) / 100;
    dia2 = fecha2 % 100;

    int tiempo2 = contarCercania(año2, mes2, dia2);

    if (tiempo1 > tiempo2)
    {
        cout << "La fecha más cercana es la del " << dia2 << "-" << mes2 << "-" << año2 << endl;
    }
    else
    {
        cout << "La fecha más cercana es la del " << dia1 << "-" << mes1 << "-" << año1 << endl;
    }

    return 0;
}