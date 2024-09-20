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
    int caja;
    char mov; // 'E' => Entra, 'S' => Sale
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

// Tiempo promedio de espera por caja
void mostrarPunto1()
{
    mapReset<int, cData>(mapa);
    while (mapHasNext<int, cData>(mapa))
    {
        cData elem = mapNextValue<int, cData>(mapa);
        double promedio = elem.tiempoTotalEsperado / elem.cantidadClientes;
        cout << "El promedio de la caja " << elem.cajaId << " es " << promedio << endl;
    }
};

// Sumatoria del tiempo ocioso por caja.
void mostrarPunto2()
{
    mapReset<int, cData>(mapa);
    while (mapHasNext<int, cData>(mapa))
    {
        cData elem = mapNextValue<int, cData>(mapa);
        cout << "El tiempo ocioso de la caja " << elem.cajaId << " es " << elem.tiempoOciosoTotal << endl;
    }
};

// Longitud máxima a la llegó la cola de cada caja.
void mostrarPunto3()
{
    mapReset<int, cData>(mapa);
    while (mapHasNext<int, cData>(mapa))
    {
        cData elem = mapNextValue<int, cData>(mapa);
        cout << "La longitud de cola máxima de la caja " << elem.cajaId << " fue " << elem.filaMax << endl;
    }
};

// Tiempo promedio de espera por caja
void procesarPunto1(Mov siguiente)
{
    if (siguiente.mov == 'E')
    {
        // Añado al hora a la cola
        queueEnqueue<int>(pos->horas, siguiente.hora);
        // Aumento la cantidad de clientes
        pos->cantidadClientes++;
    }
    else
    {
        // Si el movimiento es una salida elimino el elemento más antiguo
        int entrada = queueDequeue<int>(pos->horas);
        int diferencia = siguiente.hora - entrada;
        // Sumo la cantidad de tiempo que espero dicho elemento
        pos->tiempoTotalEsperado += diferencia;
    }
}

// Sumatoria del tiempo ocioso por caja.
void procesarPunto2(Mov siguiente)
{
    if (siguiente.mov == 'E')
    {
        // Si la caja estuvo en tiempo ocioso
        if (pos->ultimaHoraSalida >= 0)
        {
            // Sumo el tiempo desde la última salida hasta esta entrada
            pos->tiempoOciosoTotal += siguiente.hora - pos->ultimaHoraSalida;
        }
    }
    else
    {
        // Me fijo si la cola queda vacía
        if (queueSize<int>(pos->horas) == 0)
        {
            // Guardo el tiempo de la última salida;
            pos->ultimaHoraSalida = salida;
        }
    }
}

void procesarPunto3(Mov siguiente)
{
    if (siguiente.mov == 'E')
    {
        // Si el tamaño nuevo de la cola supera al valor guardado, lo sobreescribo
        if (queueSize<int>(pos) > pos->filaMax)
        {
            pos->filaMax = queueSize<int>(pos);
        }
    }
}

cData cdata(int id)
{
    return {queue<int>(), id, 0, 0, -1, 0, 0};
}

int main()
{
    Map<int, cData> mapa = map<int, cData>();
    FILE *f = fopen("MOVIMIENTOS", "r+b");

    // Leo el siguiente movimiento
    Mov siguiente = read<Mov>(f);
    while (!feof(f))
    {
        cData datos = cdata(siguiente.caja);
        // Consigo la posición del valor (cData) de la caja correspondiente al movimiento actual (estuviera o no antes en el map)
        Queue<int> *pos = mapDiscover<int, cData>(mapa, siguiente.caja, datos);
        procesarPunto1(siguiente);
        procesarPunto2(siguiente);
        procesarPunto3(siguiente);
        // Leo el siguiente movimiento
        Mov siguiente = read<Mov>(f);
    }
    fclose(f);

    mostrarPunto1();
    mostrarPunto2();
    mostrarPunto3();

    return 0;
}

#endif
