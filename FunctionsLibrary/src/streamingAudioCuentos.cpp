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

Coll<CuentoEstad> temp = coll<CuentoEstad>();
collAdd<CuentoEstad>(temp, cuentoEstad("0-25", 0), cuentoEstadToString);
collAdd<CuentoEstad>(temp, cuentoEstad("25-50", 0), cuentoEstadToString);
collAdd<CuentoEstad>(temp, cuentoEstad("50-75", 0), cuentoEstadToString);
collAdd<CuentoEstad>(temp, cuentoEstad("75-100", 0), cuentoEstadToString);
collAdd<CuentoEstad>(temp, cuentoEstad("100", 0), cuentoEstadToString);

Coll<RCuentos> cuentosSubir()
{
    FILE *f = fopen("CUENTOS.dat", "r+b");
    Coll<RCuentos> rc = coll<RCuentos>('&');
    Cuento c = read<Cuento>(f);
    while (!feof(f))
    {
        RCuento x = rCuento(c, temp);
        collAdd(rc, x, rCuentoToString);
        c = read<Cuento>(f);
    }
    return rc;
}

Coll<RCuentos> relatoresSubir()
{
    FILE *f = fopen("RELATORES.dat", "r+b");
    Coll<RRelator> rc = coll<RRelator>('&');
    Relator r = read<Relator>(f);
    while (!feof(f))
    {
        RRelator x = rRelator(rc, 0);
        collAdd(rc, x, rRelatorToString);
        r = read<Relator>(f);
    }
    return rc;
}

struct CuentoEstad
{
    string porcentaje;
    int c;
};

struct RCuento
{
    Cuento cuento;
    Coll<CuentoEstad> estad;
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

int cmpCuentoId(RCuento cue, int id)
{
    return id - cue.cuento.idCuento;
};

int cmpEstadString(CuentoEstad est, string s)
{
    return s - est.porcentaje;
};

void actualizarContadorPorcentaje(string s, RCuento &cuento)
{
    // Busco la posición del estad que cuenta procentajes correspondientes
    int pos = collFind<CuentoEstad, string>(cuento.estad, s, cmpEstadString, cuentoEstadFromString);
    // Traigo los datos del estad
    CuentoEstad estad = collGetAt<CuentoEstad>(cuento.estad, pos, cuentoEstadFromString);
    // Aumento el contador en 1
    estad.c++;
    // Actualizo
    collSetAt<CuentoEstad>(cuento.estad, estad, pos, cuentoEstadToString);
}

void procesarPunto1(Reproduccion r, Coll<RCuento> &cCue)
{
    // Busco la posición del Wrapper del cuento en memoria
    int pos = collFind<RCuento, int>(cCue, r.idCuento, cmpCuentoId, rCuentoFromString);
    // Traigo los datos del cuento
    RCuento cuento = collGetAt<RCuento>(cCue, pos, rCuentoFromString);
    // Calculo el porcentaje de reproduccion
    double porcentaje = (r.minutos * 100) / cuento.cuento.duracion;
    // Actualizo el contador del porcentaje que corresponde
    if (porcentaje <= 25)
    {
        actualizarContadorPorcentaje("0-25", cuento);
    }
    else if (porcentaje > 25 && porcentaje <= 50)
    {
        actualizarContadorPorcentaje("25-50", cuento);
    }
    else if (porcentaje > 50 && porcentaje <= 75)
    {
        actualizarContadorPorcentaje("50-75", cuento);
    }
    else if (porcentaje > 75 && < 100)
    {
        actualizarContadorPorcentaje("75-100", cuento);
    }
    else
    {
        actualizarContadorPorcentaje("100", cuento);
    }
    // Actualizo la colección
    collSetAt(cCue, cuento, pos, rCuentoToString);
};

int cmpRelatorId(RRelator rel, int id)
{
    return id - rel.relator.idRelator;
};

void procesarPunto2(Coll<RCuento> cCue, Coll<RRelator> &cRel)
{
    collReset<RCuento>(cCue);
    while (collHasNext<RCuento>(cCue))
    {
        // Leo el cuento
        RCuento x = collNext<RCuento>(cCue, rCuentoFromString);
        // Busco la posición del relator en memoria
        int posRelator = collFind<RRelator>(cRel, x.cuento.idRelator, cmpRelatorId, rRelatorFromString);
        // Traigo la info del relator
        RRelator relator = collGetAt<RRelator>(cRel, posRRelator, rRelatorFromString);
        // Posición 75-100
        int estad1Pos = collFind<CuentoEstad, string>(x, "75-100", cmpEstadString, cuentoEstadFromString);
        // Traigo la data
        CuentoEstad cantidadCasiCompletados = collGetAt<CuentoEstad>(x.estad, estad1Pos, cuentoEstadFromString);
        // Se los sumo al relator
        relator.c += cantidadCasiCompletados.c;
        // Posición 100
        int estad2Pos = collFind<CuentoEstad, string>(x, "100", cmpEstadString, cuentoEstadFromString);
        // Traigo la data
        CuentoEstad cantidadCompletados = collGetAt<CuentoEstad>(x.estad, estad2Pos, cuentoEstadFromString);
        // Se los sumo al relator
        relator.c += cantidadCompletados.c;
        // Actualizo la data
        collSetAt<RRelator>(cRel, relator, posRelator, rRelatorToString);
    }
};

void resultadosPunto1(Coll<RCuento> cCue)
{
    collReset<RCuento>(cCue);
    while (collHasNext<RCuento>(cCue))
    {
        // Leo el proximo cuento
        RCuento cuento = collNext<RCuento>(cCue, rCuentoFromString);
        // Leo el titulo
        cout << "El cuento " << cuento.cuento.titulo << " tiene:" << endl;
        collReset<CuentoEstad>(cuento.estad);
        while (collHasNext<CuentoEstad>(cuento.estad))
        {
            // Leo la proxima estadistica
            CuentoEstad estad = collNext<CuentoEstad>(cuento.estad, cuentoEstadFromString);
            // Leo el porcentaje y la cantidad
            cout << "Entre " << estad.porcentaje << "%, " << estad.c << " lecturas." << endl;
        }
    }
}

void cmpRelatores(RRelator r1, RRelator r2)
{
    return r2.c - r1.c;
}

void resultadosPunto2(Coll<RRelator> &cRel)
{
    bool fin = false;
    // Ordeno la colección
    collSort<RRelator>(cRel, cmpRelatores, rRelatorFromString, rRelatorToString);
    int n = min(collSize<RRelator>(cRel), 10);
    for (int i = 0; i < n && !fin; i++)
    {
        RRelator x = collGetAt<RRelator>(cRel, i, rRelatorFromString);
        if (x.c > 0)
        {
            cout << "x" << endl;
        }
        else
        {
            fin = true;
        }
    }

    /*
        // Colección para almacenar el top
        Coll<RRelator> top;
        // Recorre mientras haya elementos y no haya completado el top
        while (collHasNext<RRelator>(cRel) && collSize<RRelator>(top) < 10)
        {
            RRelator r = collNext(cRel, rRelatorFromString);
            // Si tiene cuentos en el top, lo añado al top
            if (r.c > 0)
            {
                collAdd<RRelator>(top, r, rRelatorToString);
            }
        }
        // Si no hay nadie en el top
        if (collSize<RRelator>(top) == 0)
        {
            cout << "Ningún relator está en el top." << endl;
        }
        else
        {
            // Saco por consola los integrantes del top sea cual sea el largo (siempre es menor o igual a 10)
            for (int i = 0; i < collSize<RRelator>(top); i++)
            {
                RRelator x = collGetAt<RRelator>(top, i, rRelatorFromString);
                cout << "Top " << i << ". " << x.relator.nombre << "." << endl;
            }
        }
    */
}

int main()
{
    Coll<RCuento> cCue = cuentosSubir();
    Coll<RRelator> cRel = relatoresSubir();

    FILE *f = fopen("REPRODUCCIONES.dat", "r+b");

    Reproduccion r = fread<Reproduccion>(f);
    while (!feof(f))
    {
        procesarPunto1(r, cCue);
        procesarPunto2(cCue, cRel);
        r = fread<Reproduccion>(f);
    }

    resultadosPunto1(cCue);
    resultadosPunto2(cRel);

    return 0;
};