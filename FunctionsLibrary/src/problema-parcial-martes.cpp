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

/*Se ingresa por teclado un conjunto de palabras separadas entre sí por [ENTER]. El ingreso de datos finalizará con la palabra "FIN"
(que no forma parte del conjunto). Se pide grabarlas en un archivo de registros (PALABRAS.dat) donde cada registro debe contener una
de las palabras ingresadas y el número de orden en que se ingresó. Los registros deben estar ordenados ascendentemente según la
cantidad de letras 'A' (sin discriminar entre mayúsculas y minúsculas) de las palabras que contienen.*/

int cmpPalabras(string palabra1, string palabra2)
{
    palabra1 = toUpperCase(palabra1);
    palabra2 = toUpperCase(palabra2);
    int uno = charCount(palabra1, 'A');
    int dos = charCount(palabra2, 'A');
    return uno - dos;
}

int main()
{
    Coll<string> memoria = coll<string>();

    string palabra = "";

    cout << "Ingrese un conjunto de palabras, finalizado por la entrada de la palabra FIN" << endl;

    cin >> palabra;

    while (palabra != "FIN")
    {
        palabra = intToString(collSize<string>(memoria) + 1) + "-" + palabra;
        collAdd<string>(memoria, palabra, stringToString);
        cin >> palabra;
    }

    collSort<string>(memoria, cmpPalabras, stringToString, stringToString);

    collReset<string>(memoria);
    FILE *f = fopen("PALABRAS.dat", "w+b");
    while (collHasNext<string>(memoria))
    {
        string s = collNext<string>(memoria, stringToString);
        cout << s << endl;
        write<string>(f, s);
    }

    fclose(f);

    return 0;
}
#endif