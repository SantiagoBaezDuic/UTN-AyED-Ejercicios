#include <iostream>
#include <chrono>
#include <ctime>
#include <stdlib.h>
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

/*
A la hora de resolver este problema nos encontramos con distintos casos:
-El día, mes y año ingresados son iguales al actual. -> la diferencia de días es 0.
-El mes y año ingresados son iguales al actual. ->  hay que calcular la diferencia entre el día de inicio y el día final.
-El año ingresado es igual al actual. -> hay que calcular el resto de días del mes de inicio, los días que pasaron del mes final, y los meses intermedios.
-La fecha ingresada corresponde a un año distinto al actual. -> hay que calcular lo mismo que en el caso anterior y los años intermedios.
*/

int añoActual = 2024;
int mesActual = 04;
int diaActual = 07;

int getCurrentDate() // Devuelve la fecha actual en las variables añoActual, mesActual y diaActual.
{
    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    std::tm *now_tm = std::localtime(&t_c);

    añoActual = now_tm->tm_year + 1900;
    mesActual = now_tm->tm_mon + 1;
    diaActual = now_tm->tm_mday;

    cout << "El año actual es " << añoActual << " el mes actual es " << mesActual << " y el día actual es " << diaActual << "." << endl;
    return 0;
}

int esBisiesto(int anio) // Evalúa si un año es bisiesto o no.
{
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int diasSegunMes(int mes, int anio) // Devuelve la cantidad de días segun mes teniendo en cuenta si el año es bisiesto o no.
{
    switch (mes)
    {
    case 1:
        return 31;
        break;
    case 2:
        if (esBisiesto(anio))
        {
            return 29;
        }
        else
        {
            return 28;
        }
        break;
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;
    default:
        return 0;
        break;
    }
}

int calcularMesIncompleto(int mes, int dia, int anio, string sentido) // Calcula según un string los días que pasaron o los días que restan del mes.
{
    int resultado = 0;
    if (sentido == "resto")
    {
        resultado = resultado + diasSegunMes(mes, anio) - dia;
    }
    else
    {
        resultado = resultado + dia;
    }
    return resultado;
}

int calcularAnioIncompleto(int mes, int anio, string sentido) // Calcula según un string los meses que pasaron o los meses que restan del año
{
    int resultado = 0;
    if (sentido == "resto")
    {
        for (int i = mes + 1; i < 13; i++)
        {
            resultado = resultado + diasSegunMes(i, anio);
        }
    }
    else
    {
        for (int i = 1; i < mes; i++)
        {
            resultado = resultado + diasSegunMes(i, anio);
        }
    }
    return resultado;
}

int calcularAniosCompletos(int anio) // Calcula los años entre la fecha ingresada y el año actual
{
    int resultado = 0;

    if (anio > añoActual)
    {
        for (int i = añoActual + 1; i < anio; i++)
        {
            if (esBisiesto(i))
            {
                resultado = resultado + 366;
            }
            else
            {
                resultado = resultado + 365;
            }
        }
    }
    else
    {
        for (int i = anio + 1; i < añoActual; i++)
        {
            if (esBisiesto(i))
            {
                resultado = resultado + 366;
            }
            else
            {
                resultado = resultado + 365;
            }
        }
    }
    return resultado;
}

int calcularDiferencia(int anio, int mes, int dia)
{
    int resultado = 0;

    if (anio == añoActual && mes == mesActual && dia == diaActual)
    {
        return resultado;
    }
    else if (mes == mesActual && anio == añoActual)
    {
        // Calcular diferencia entre dia de inicio y final
        resultado = abs(dia - diaActual);
    }
    else if (anio == añoActual)
    {
        if (mes > mesActual)
        {
            // Calcular el resto del mes de inicio
            resultado = resultado + calcularMesIncompleto(mesActual, diaActual, añoActual, "resto");

            // Calcular los meses intermedios
            for (int i = mesActual + 1; i < mes; i++)
            {
                resultado = resultado + diasSegunMes(i, anio);
            }

            // Calcular los dias pasados del mes final
            resultado = resultado + calcularMesIncompleto(mes, dia, anio, "");
        }
        else
        {
            // Calcular el resto del mes de inicio
            resultado = resultado + calcularMesIncompleto(mes, dia, anio, "resto");

            // Calcular los meses intermedios
            for (int i = mes + 1; i < mesActual; i++)
            {
                resultado = resultado + diasSegunMes(i, anio);
            }

            // Calcular los dias pasados del mes final
            resultado = resultado + calcularMesIncompleto(mesActual, diaActual, añoActual, "");
        }
    }
    else
    {
        if (anio < añoActual)
        {
            // Calcular el resto del mes de inicio
            resultado = resultado + calcularMesIncompleto(mes, dia, anio, "resto"); // bien

            // Calcular el resto de los meses del año de inicio
            resultado = resultado + calcularAnioIncompleto(mes, anio, "resto"); // bien

            // Calcular años intermedios
            resultado = resultado + calcularAniosCompletos(anio);

            // Calcular los meses pasados del año final
            resultado = resultado + calcularAnioIncompleto(mesActual, añoActual, ""); // bien

            // Calcular los dias pasados del mes final
            resultado = resultado + calcularMesIncompleto(mesActual, diaActual, añoActual, ""); // bien
        }
        else
        {
            // Calcular el resto del mes de inicio
            resultado = resultado + calcularMesIncompleto(mesActual, diaActual, añoActual, "resto");

            // Calcular el resto de los meses del año de inicio
            resultado = resultado + calcularAnioIncompleto(mesActual, añoActual, "resto");

            // Calcular años intermedios
            resultado = resultado + calcularAniosCompletos(anio);

            // Calcular los meses pasados del año final
            resultado = resultado + calcularAnioIncompleto(mes, anio, "");

            // Calcular los dias pasados del mes final
            resultado = resultado + calcularMesIncompleto(mes, dia, anio, "");
        }
    }

    return resultado;
}

int main()
{
    getCurrentDate();

    int fecha1;
    cout << "Ingrese la primera fecha (formato aaaammdd): " << endl;
    cin >> fecha1;

    int fecha2;
    cout << "Ingrese la segunda fecha (formato aaaammdd)(distinta a la primera): " << endl;
    cin >> fecha2;

    int año1, mes1, dia1;
    int año2, mes2, dia2;

    año1 = fecha1 / 10000;
    mes1 = (fecha1 % 10000) / 100;
    dia1 = fecha1 % 100;

    int tiempo1 = calcularDiferencia(año1, mes1, dia1);

    cout << "Desde la primera fecha pasaron " << tiempo1 << " días" << endl;

    año2 = fecha2 / 10000;
    mes2 = (fecha2 % 10000) / 100;
    dia2 = fecha2 % 100;

    int tiempo2 = calcularDiferencia(año2, mes2, dia2);

    cout << "Desde la segunda fecha pasaron " << tiempo2 << " días" << endl;

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