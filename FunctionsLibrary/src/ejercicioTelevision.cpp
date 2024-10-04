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

struct Hora
{
};

struct Bache
{
    int horaDesde;
    int minDesde;
    int duracion;
};

struct Planificacion
{
    int idPlanif;
    int idProg;
    int horaInicio;
    int minutoInicio;
};

struct Programa
{
    int idProg;
    char titulo[100];
    int duracion; // minutos
    int atp;      // 0=>no, 1=>si
};

struct Descartado
{
    int idPlanif;
    string causa;
};

bool haySuperposicion(Hora hi1, int dur, Hora hi2)
{
    return false;
};

bool invadeHorarioATP(Hora h, int dur)
{
    return false;
};

int obtenerDuración(int idProg)
{
    Programa *prog = mapGet<int, Programa>(programas, idProg);
    return prog->duracion;
}

int calcularDiferenciaHoraria(Hora h1, Hora h2, int dur1)
{
    return h2 - (h1 + dur1);
};

Hora calcularBache(Hora hi1, int durp, Hora hi2, int &durb)
{
    durb = {hi1.hora, hi1.minuto, calcularDiferenciaHoraria(h1, h2)};
    return durb;
};

void evaluarPlanificaciones(Array<Planificacion> lista)
{
    Planificacion p1 = arrayGet<Planificacion>(lista, arraySize<Planificacion>(lista) - 2);
    Planificacion p2 = arrayGet<Planificacion>(lista, arraySize<Planificacion>(lista) - 1);
    int dur1 = obtenerDuración(p1.idProg);
    int dur2 = obtenerDuración(p2.idProg);
    if (invadeHorarioATP(p1.horaInicio, dur1))
    {
        Descartado d = {p1.idPlanif, "Invade ATP"};
        arrayAdd<Descartado>(descartados, d);
        arrayRemove<Planificacion>(tentativa, arraySize<Planificacion>(lista) - 2);
    }
    else if (invadeHorarioATP(p2.horaInicio, dur2))
    {
        Descartado d = {p2.idPlanif, "Invade ATP"};
        arrayAdd<Descartado>(descartados, d);
        arrayRemove<Planificacion>(tentativa, arraySize<Planificacion>(lista) - 1);
    }
    else if (haySuperposicion(p1.horaInicio, dur1, p2.horaInicio))
    {
        Descartado d = {p2.idPlanif, "Superposición de horario"};
        arrayAdd<Descartado>(descartados, d);
        arrayRemove<Planificacion>(tentativa, arraySize<Planificacion>(lista) - 1);
    }
    else
    {
        bache b = bache();
        calcularBache(p1.horaInicio, dur1, p2.horaInicio, b);
        arrayAdd<Bache>(baches, b);
    }
}

int main()
{
    // Subir archivo de consulta PROGRAMAS.dat a memoria
    Map<int, Programa> programas = map<int, Programa>();
    Array<Bache> baches = array<Bache>();
    Array<Descartado> descartados = array<Planificacion>();
    Array<Planificacion> tentativa = array<Planificacion>();
    FILE *f = fopen("PLANIFICACION.dat", "r+b");
    Planificacion siguiente = read<Planificacion>(f);
    while (!feof(f))
    {
        arrayAdd<Planificacion>(tentativa, siguiente);
        if (arraySize<Planificacion>(tentativa) > 0)
        {
            evaluarPlanificaciones(tentativa);
        }
        siguiente = read<Planificacion>(f);
    }

    fclose(f);

    return 0;
}

#endif
