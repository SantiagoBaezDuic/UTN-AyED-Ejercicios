#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte1/MultidimColl.hpp"
using namespace std;

#ifndef _MAIN
#define _MAIN

/*Archivos: OBRAS.dat y TEATROS.dat*/

struct Obra
{
    int idObra;
    char titulo[100];
    int fEstreno; // aaaammdd
    int idTeatro;
};

struct RObra
{
    Obra obra;
    Map<RFuncion> funciones;
};

struct Teatro
{
    int idTeatro;
    char direccion[50];
    int capacidad;
    int sectores;
};

struct Funcion
{
    int idFuncion;
    int diaSem; // 1=>Lunes, 2=>Martes, ...
    int hora;   // hhmm
};

struct Sector
{
    int idSector;
    int capacidadTotal;
    int capacidadActual;
};

struct RFuncion
{
    Funcion funcion;
    Map<Sector> sectores;
    int cantRechazos;
};

struct Reserva
{
    int idCliente;
    int idObra;
    int idFuncion;
    int sector; // sector de la sala; ej: Pullman,Platea...
    int cant;
};

// Retorna una colección de funciones según cuál sea el idObra
List<Funcion> funcionesProgramadas(int idObra)
{
    List<Funcion> listaFunciones = list();
    return listaFunciones;
};

void subirObras()
{
    FILE *f = fopen("OBRAS.dat", "r+b");
    Obra ob = read<Obra>(f);
    while (!feof(f))
    {
        RObra rob = robra(ob);
        mapPut<RObra>(obras, ob.idObra, rob);
        ob = read<Obra>(f);
    }
    fclose(f);
};

void subirTeatros()
{
    FILE *f = fopen("TEATROS.dat", "r+b");
    Teatro te = read<Teatro>(f);
    while (!feof(f))
    {
        mapPut<Teatro>(teatros, te.idTeatro, te);
        te = read<Teatro>(f);
    }
    fclose(f);
};

List<Funcion> funcionesProgramadas(int idObra)
{
    List<Funcion> l = list<Funcion>();
    return l;
};

int comprararIdFunciones(int a, int b)
{
    return b - a;
}

int capacidadSector(int idTeatro, int sector)
{
    return 1;
};

void procesarReserva(Reserva r)
{
    RObra *obra = mapGet<RObra>(obras, r.idObra);                                                   // Busco la obra
    List<Funcion> funcs = funcionesProgramadas(r.idObra);                                           // Traigo las funciones de la obra
    Funcion f = listFind<Funcion>(funcs, r.idFuncion, comprararIdFunciones);                        // Busco la info de la función
    RFuncion rf = rfuncion(f);                                                                      // Wrappeo la función
    RFuncion *funcion = mapDiscover<RFuncion>(obra->funciones, r.idFuncion, f);                     // Descubro la función
    int capacidad = capacidadSector(r.idTeatro, r.sector);                                          // Calculo la capacidad del sector
    Sector *s = mapDiscover<Sector>(funcion->sectores, r.sector, {r.sector, capacidad, capacidad}); // Descubro el sector
    if (s->capacidadActual >= r.cant)                                                               // Si hay suficientes lugares
    {
        s->capacidadActual -= r.cant; // Hago la reserva
    }
    else // Si no hay lugares
    {
        funcion->cantRechazos++; // Aumento la cantidad de rechazados
    }
};

void mostrarResultados()
{
    int totalRechazos = 0;
    while (mapHasNext<RObra>(obras))
    {
        RObra rob = mapNextValue<RObra>(obras);
        cout << "Obra de teatro: " << rob.obra.titulo << endl;
        cout << "Id. Funcion " << "        " << "Día" << "        " << "Hora" << "        " << "Rechazos" << endl;
        while (mapHasNext<RFuncion>(rob->funciones))
        {
            RFuncion rfun = mapNextValue<RFuncion>(rob->funciones);
            cout << rfun.funcion.idFuncion << "        " << rfun.funcion.diaSem << "        " << rfun.funcion.hora << "        " << rfun.cantRechazos << endl;
            totalRechazos += rfun.cantRechazos;
        }
    }
    cout << "Total rechazos: " << totalRechazos << endl;
};

Reserva leerReserva()
{
    Reserva r = reserva();
    return r;
};

bool continuarOperando()
{
    return false;
};

int main()
{
    Map<RObra> obras = map<RObra>();
    Map<Teatro> teatros = map<Teatro>();
    subirObras();
    subirTeatros();

    while (continuarOperando())
    {
        Reserva r = leerReserva();
        procesarReserva(r);
    }

    mostrarResultados();

    return 0;
}

#endif
