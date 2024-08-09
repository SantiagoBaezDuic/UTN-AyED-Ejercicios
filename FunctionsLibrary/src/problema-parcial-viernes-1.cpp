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
#include "./principal.hpp"
using namespace std;

#ifndef _MAIN
#define _MAIN

/*Se dispone del archivo de registros PALABRAS.dat, donde cada registro contiene una palabra de hasta 15 caracteres. Las palabras
podrían repetirse. Se pide mostrar las palabras del archivo (sin repetición) ordenadas ascendentemente según la cantidad de consonantes
que contienen. Por ejemplo AMANECIENDO tiene 5 consonantes.*/

string leerPalabra(FILE *f)
{
    char buff[15];
    fread(buff, 1, 15, f);
    return buff;
}

void filtrarRepetidas(Coll<string> &original)
{
    Coll<string> sinRepetidas = coll<string>();
    for (int i = 0; i < collSize<string>(original); i++) // Leo todas las palabras de memoria
    {
        string s = collGetAt<string>(original, i, stringToString);
        if (sinRepetidas.tokens == "") // Si la colección filtrada está vacía, meto la primera palabra
        {
            collAdd<string>(sinRepetidas, s, stringToString);
        }
        else if (collFind<string>(sinRepetidas, s, cmpString, stringToString) == -1) // Si la palabra no está en la colección filtrada, la agrego
        {
            collAdd<string>(sinRepetidas, s, stringToString);
        }
    }

    original.tokens = sinRepetidas.tokens;
}

int contarConsonantes(string s)
{
    // Cuento todas las letras y le resto las vocales
    int counter = length(s);
    counter -= charCount(s, 'A');
    counter -= charCount(s, 'E');
    counter -= charCount(s, 'I');
    counter -= charCount(s, 'O');
    counter -= charCount(s, 'U');

    return counter;
}

int cmpPalabras(string palabra1, string palabra2)
{
    int uno = contarConsonantes(palabra1);
    int dos = contarConsonantes(palabra2);
    return dos - uno;
}

int main()
{
    // Subo las palabras del archivo a memoria
    FILE *f = fopen("PALABRAS.dat", "r+b");
    Coll<string> memoria = coll<string>();
    while (!feof(f))
    {
        string s = leerPalabra(f);
        collAdd<string>(memoria, s, stringToString);
    }
    fclose(f);

    // Ordeno la colección según consonantes
    collSort<string>(memoria, cmpPalabras, stringToString, stringToString);
    // Filtro las repetidas
    filtrarRepetidas(memoria);

    // Muestro las palabras por consola
    collReset<string>(memoria);
    while (collHasNext<string>(memoria))
    {
        string s = collNext<string>(memoria, stringToString);
        cout << s << endl;
    }
    return 0;
}
#endif