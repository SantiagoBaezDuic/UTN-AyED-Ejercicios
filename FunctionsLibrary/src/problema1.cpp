#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/huffman/HuffmanSetup.hpp"
#include "principal.hpp"
using namespace std;

Coll<RCiudad> ciudadSubir()
{
    FILE *f = fopen("CIUDADES.dat", "r+b");
    Coll<RCiudad> c = coll<RCiudad>('&');
    Ciudad r = read<Ciudad>(f);
    while (!feof(f))
    {
        RCiudad x = rCiudad(r, 0);
        collAdd(c, x, rCiudadToString);
        r = read<Ciudad>(f);
    }
    return c;
}

Coll<RVuelo> vueloSubir()
{
    FILE *f = fopen("VUELOS.dat", "r+b");
    Coll<RVuelo> c = coll('&');
    Vuelo r = read<Vuelo>(f);
    while (!feof(f))
    {
        RVuelo x = rVuelo(r, 0, 0);
        collAdd(c, x, vueloToString);
        r = read<Vuelo>(f);
    }
    return {};
}

int cmpVueloId(RVuelo vuelo, int a)
{
    return a - vuelo.v.idVue;
}

void procesarPunto1(Reserva r, Coll<RVuelo> cVue, Coll<RCiudad> &cCiu)
{
    // Encuentro la posición del vuelo
    int pos = collFind<RVuelo, int>(cVue, r.idVue, cmpVueloId, rVueloFromString);
    // Traigo los datos del vuelo
    RVuelo vuelo = collGetAt<RVuelo>(cVue, pos, rVueloFromString);
    // Busco la posición de la ciudad de destino
    int posDest = collFind<RCiudad, int>(cCiu, vuelo.v.idDes, cmpCiudadDestino, ciudadFromString);
    // Traigo los datos de la ciudad
    RCiudad ciudadDest = collGetAt<RCiudad>(cCiu, posDest, rCiudadFromString);
    // Aumento el contador
    ciudadDest.cont++;
    collSetAt(cCiu, ciudadDest, posDest, rCiudadToString);
}

bool aprobarReserva(RVuelo vuelo, Reserva reserva)
{
    bool status;
    int restantes = vuelo.v.cap - vuelo.cpa;
    if (restantes >= reserva.cant)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

void procesarPunto2(Reserva r, Coll<RVuelo> &cVue)
{
    // Encuentro la posición del vuelo
    int pos = collFind<RVuelo, int>(cVue, r.idVue, cmpVueloId, rVueloFromString);
    // Traigo los datos del vuelo
    RVuelo vuelo = collGetAt<RVuelo>(cVue, pos, rVueloFromString);
    // Plazas restantes
    if (aprobarReserva(vuelo, r))
    {
        // Si puedo reservar
        vuelo.cpa += r.cant;
    }
    else
    {
        // Si no puedo reservar
        vuelo.cpr += r.cant;
    }
    collSetAt(cVue, vuelo, pos, rVueloToString);
}

int descubrirCliente(int id, Coll<RCliente> &cCli)
{
    // Se fija si existe el cliente y devuelve su posición
    int pos = collFind<RCliente, int>(cCli, id, cmpClienteId, rClienteFromString);
    // Si no existe lo crea
    if (pos < 0)
    {
        RCliente nuevoCliente = rCliente(id, 0);
        pos = collAdd<RCliente>(cCli, nuevoCliente, rClienteToString);
    }
    return pos;
}

// extraer logica de aprobacion de vuelo

void procesarPunto3(Reserva r, Coll<RVuelo> cVue, Coll<RCiudad> cCiu, Coll<RCliente> &cCli)
{

    // Descubro el cliente y lo traigo
    int posCli = descubrirCliente(r.idCli, cCli);
    RCliente cliente = collGetAt<RCliente>(cCli, posCli, rClienteFromString);
    // Encuentro la posición del vuelo
    int posVue = collFind<RVuelo, int>(cVue, r.idVue, cmpVueloId, rVueloFromString);
    // Traigo los datos del vuelo
    RVuelo vuelo = collGetAt<RVuelo>(cVue, pos, rVueloFromString);
    if (aprobarReserva(vuelo, r))
    {
        // Busco la posición de la ciudad de destino
        int posDest = collFind<RCiudad, int>(cCiu, vuelo.v.idDes, cmpCiudadDestino, ciudadFromString);
        // Busco la posición de la ciudad de origen
        int posOri = collFind<RCiudad, int>(cCiu, vuelo.v.idOri, cmpCiudadDestino, ciudadFromString);
        // Traigo los datos de la ciudad
        RCiudad ciudadDes = collGetAt<RCiudad>(cCiu, posDest, rCiudadFromString);
        RCiudad ciudadOri = collGetAt<RCiudad>(cCiu, posOri, rCiudadFromString);
        int millasASumar = ciudadDes.c.millas - ciudadOri.c.millas;
        cliente.acum += (millasASumar * millasASumar) / millasASumar;
        collSetAt(cCli, cliente, posCli, rClienteToString);
    }
}

void resultadosPunto1(Coll<RCiudad> cCiu)
{
    collReset(cCiu);
    while (collHasNext(cCiu))
    {
        RCiudad r = collNext(cCiu, rCiudadFromString);
        cout << r.cont << " familias eligieron a " << r.c.descr << " como destino." << endl;
    }
}
void resultadosPunto2(Coll<RVuelo> cVue)
{
    collReset(cVue);
    while (collHasNext(cVue))
    {
        RVuelo r = collNext(cVue, rVueloFromString);
        string status;
        if (r.v.cap == r.cpa)
        {
            status = "completo";
        }
        else
        {
            status = "incompleto";
        }

        cout << "El vuelo de id " << r.v.idVue << " tuvo " << r.cpr << " plazas rechazadas, y salió " << status << endl;
    }
}
void resultadosPunto3(Coll<RCliente> cCli)
{
    collReset(cCli);
    while (collHasNext(cCli))
    {
        RCliente r = collNext(cCli, rCiudadFromString);
        cout << "El cliente de id " << r.idCli << " acumula un total de " << r.acum << " millas." << endl;
    }
}

int main()
{
    Coll<RCiudad> cCiu = ciudadSubir();     // 7
    Coll<RVuelo> cVue = vueloSubir();       // 8
    Coll<RCliente> cCli = coll<RCliente>(); // 9

    FILE *f = fopen("RESERVAS.dat", "r+b");

    Reserva r = read<Reserva>(f);
    while (!feof(f))
    {
        procesarPunto1(r, cVue, cCiu);       // 1
        procesarPunto2(r, cVue);             // 2
        procesarPunto3(r, cVue, cCiu, cCli); // 3

        r = read<Reserva>(f);
    }

    resultadosPunto1(cCiu); // 4
    resultadosPunto2(cVue); // 5
    resultadosPunto3(cCli); // 6

    fclose(f);
    return 0;
}