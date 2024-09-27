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

struct Mov
{
    int idCli;
    char mov; // 'E' o 'S'
    int hora; // hhmm
};

struct cData
{
    Queue<int> horas = queue<int>();
    int cajaId;
    int cantidadClientes;
    int tiempoTotalEsperado;
    int ultimaHoraSalida;
    int tiempoOciosoTotal;
    int filaMax;
};

cData cdata(int id)
{
    return {queue<int>(), id, 0, 0, -1, 0, 0};
}

struct Simulacion
{
    Map<int, int> mapa = map<int, int>();
    Array<cData> arr = array<cData>();
};

int cmpQueues(cData caja1, cData caja2)
{
    return queueSize<int>(caja2.horas) - queueSize<int>(caja1.horas);
}

int asignarCaja(Array<cData> cajas)
{
    int pos = NULL;
    int cant = NULL;
    for (int i = 0; i < cajas.len; i++)
    {
        if (pos == NULL)
        {
            pos = i;
            cant = queueSize(cajas.arr[i].horas);
        }
        else
        {
            if (queueSize(cajas.arr[i].horas) < cant)
            {
                pos = i;
                cant = queueSize(cajas.arr[i].horas);
            }
        }
    }
    return pos;
}

int main()
{
    int[5] tests = {3, 4, 7, 8, 10};
    int len = 5;

    Array<Simulacion> casos = array<Simulacion>();

    // Creo los casos necesarios
    for (int i = 0; i < len; i++)
    {
        arrayAdd<Simulacion>(simulacion());
    }

    // Abro el archivo de movimientos
    FILE *f = fopen("MOVIMIENTOS", "r+b");

    for (int i = 0; i < casos.len; i++)
    {
        Simulacion next = casos[i];
        for (int x = 0; x < tests[x]; i++)
        {
            arrayAdd<cData>(next.arr, cdata(x));
        }
    }

    // Leo el siguiente movimiento
    Mov siguiente = read<Mov>(f);
    while (!feof(f))
    {
        mapReset<int, Simulacion>(casos);
        while (mapHasNext<int, Simulacion>(casos))
        {
            Simulacion current = mapNextValue<Simulacion>(casos);
            if (siguiente.mov == 'E')
            {
                int arrayElegido = asignarCaja(current.arr);
                // Agrego el cliente a la cola
                enqueue<int>(current.arr[arrayElegido]);
                // Agrego al map el id del cliente junto con el id de la caja a la que se agregó
                mapDiscover<int, int>(current.mapa, siguiente.idCli, arrayElegido);
            }
            else
            {
                int cajaId = mapGet<int, int>(current.mapa, siguiente.idCli);
            }
        }

        // Leo el siguiente movimiento
        siguiente = read<Mov>(f);
    }
    fclose(f);

    return 0;
}

#endif
