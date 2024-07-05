#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct CuentoEstad
{
    string porcentaje;
    int c;
};

struct RCuento
{
    Cuento cuento;
    CuentoEstad estad;
};

struct Reproduccion
{
    int idUsuario;
    int idCuento;
    int fecha;
    int minutos;
};

struct Cuento
{
    int idCuento;
    int idRelator;
    int idAutor;
    char titulo[50];
    int duracion;
};

struct Relator
{
    int idRelator;
    char nombre[50];
};

struct RRelator
{
    Relator relator;
    int c;
};

string cuentoEstadToString(CuentoEstad x)
{
    char sep = 1;
    string sPorcentaje = x.porcentaje;
    string sC = to_string(x.c);
    return sPorcentaje + sep + sC;
}

CuentoEstad cuentoEstadFromString(string s)
{
    char sep = 1;
    CuentoEstad x;
    string t0 = getTokenAt(s, sep, 0);
    x.porcentaje = t0;
    string t1 = getTokenAt(s, sep, 1);
    x.c = stoi(t1);
    return x;
}

string rCuentoToString(RCuento x)
{
    char sep = 2;
    string sCuento = cuentoToString(x.cuento);
    string sEstad = cuentoEstadToString(x.estad);
    return sCuento + sep + sEstad;
}

RCuento rCuentoFromString(string s)
{
    char sep = 2;
    RCuento x;
    string t0 = getTokenAt(s, sep, 0);
    x.cuento = cuentoFromString(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.estad = cuentoEstadFromString(t1);
    return x;
}

string reproduccionToString(Reproduccion x)
{
    char sep = 3;
    string sIdUsuario = to_string(x.idUsuario);
    string sIdCuento = to_string(x.idCuento);
    string sFecha = to_string(x.fecha);
    string sMinutos = to_string(x.minutos);
    return sIdUsuario + sep + sIdCuento + sep + sFecha + sep + sMinutos;
}

Reproduccion reproduccionFromString(string s)
{
    char sep = 3;
    Reproduccion x;
    string t0 = getTokenAt(s, sep, 0);
    x.idUsuario = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.idCuento = stoi(t1);
    string t2 = getTokenAt(s, sep, 2);
    x.fecha = stoi(t2);
    string t3 = getTokenAt(s, sep, 3);
    x.minutos = stoi(t3);
    return x;
}

string cuentoToString(Cuento x)
{
    char sep = 4;
    string sIdCuento = to_string(x.idCuento);
    string sIdRelator = to_string(x.idRelator);
    string sIdAutor = to_string(x.idAutor);
    string sTitulo = x.titulo;
    string sDuracion = to_string(x.duracion);
    return sIdCuento + sep + sIdRelator + sep + sIdAutor + sep + sTitulo + sep + sDuracion;
}

Cuento cuentoFromString(string s)
{
    char sep = 4;
    Cuento x;
    string t0 = getTokenAt(s, sep, 0);
    x.idCuento = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.idRelator = stoi(t1);
    string t2 = getTokenAt(s, sep, 2);
    x.idAutor = stoi(t2);
    string t3 = getTokenAt(s, sep, 3);
    strcpy(x.titulo, t3.c_str());
    string t4 = getTokenAt(s, sep, 4);
    x.duracion = stoi(t4);
    return x;
}

string relatorToString(Relator x)
{
    char sep = 5;
    string sIdRelator = to_string(x.idRelator);
    string sNombre = x.nombre;
    return sIdRelator + sep + sNombre;
}

Relator relatorFromString(string s)
{
    char sep = 5;
    Relator x;
    string t0 = getTokenAt(s, sep, 0);
    x.idRelator = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    strcpy(x.nombre, t1.c_str());
    return x;
}

string rRelatorToString(RRelator x)
{
    char sep = 6;
    string sRelator = relatorToString(x.relator);
    string sC = to_string(x.c);
    return sRelator + sep + sC;
}

RRelator rRelatorFromString(string s)
{
    char sep = 6;
    RRelator x;
    string t0 = getTokenAt(s, sep, 0);
    x.relator = relatorFromString(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.c = stoi(t1);
    return x;
}

#endif
