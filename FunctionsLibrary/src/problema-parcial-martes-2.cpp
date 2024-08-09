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

/*Se dispone del archivo de registros PALABRAS.dat, donde cada registro contiene una palabra de hasta 15 caracteres. Se pide
mostrar las palabras del archivo ordenadas decrecientemente según la cantidad de vocales que contienen, indicando también en qué
posición aparecieron en el archivo. No se debe discriminar entre mayúsculas y minúsculas. Por ejemplo: AMANECER tiene 4 vocales.
2 'A' y 2 'E'. Las palabras del archivo no tienen tilde.*/

string leerPalabra(FILE *f)
{
    char buff[15];
    fread(buff, 1, 15, f);
    return buff;
}

int contarVocales(string s)
{
    s = toUpperCase(s);
    int counter = 0;
    counter += charCount(s, 'A');
    counter += charCount(s, 'E');
    counter += charCount(s, 'I');
    counter += charCount(s, 'O');
    counter += charCount(s, 'U');
    return counter;
}

int cmpPalabras(string palabra1, string palabra2)
{
    int vocales1 = contarVocales(palabra1);
    int vocales2 = contarVocales(palabra2);
    return vocales2 - vocales1;
}

int main()
{
    // Leo las palabras del archivo y las guardo en la colección
    FILE *f = fopen("PALABRAS.dat", "r+b");
    Coll<string> memoria = coll<string>();
    while (!feof(f))
    {
        int pos = ftell(f);
        string s = intToString(pos) + "-" + leerPalabra(f);
        collAdd<string>(memoria, s, stringToString);
    }
    fclose(f);

    // Ordeno la colección
    collSort<string>(memoria, cmpPalabras, stringToString, stringToString);

    // Muestro todas las palabras por consola
    collReset<string>(memoria);
    while (collHasNext(memoria))
    {
        string s = collNext<string>(memoria, stringToString);
        cout << s << endl;
    }

    return 0;
}
#endif