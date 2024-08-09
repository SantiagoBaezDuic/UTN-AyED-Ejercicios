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

// int main()
// {
//    FILE *f = fopen("test.x", "w+b");

//    string s = "test0";
//    write<string>(f, s);
//    s = "test1";
//    write<string>(f, s);
//    s = "test2";
//    write<string>(f, s);
//    cout << "test1: " << ftell(f) / sizeof(string) << endl;
//    cout << "size: " << fileSize<string>(f) << endl;
//    cout << "test1: " << ftell(f) / sizeof(string) << endl;
//    fclose(f);

//    return 0;
// }

// int main()
// {
//    FILE *f2 = fopen("test.x", "r+b");
//    cout << "test1: " << ftell(f2) / sizeof(string) << endl;
//    cout << "size: " << fileSize<string>(f2) << endl;
//    cout << "test1: " << ftell(f2) / sizeof(string) << endl;
//    cout << read<string>(f2) << endl;
//    cout << read<string>(f2) << endl;
//    cout << read<string>(f2) << endl;

//    fclose(f2);
//    return 0;
// }

// int main()
// {
//    FILE *f = fopen("test.x", "w+b");

//    write<string>(f, "test1");
//    write<string>(f, "test2");
//    write<string>(f, "test3");
//    cout << filePos<string>(f) << endl;
//    seek<string>(f, 2);
//    cout << filePos<string>(f) << endl;

//    fclose(f);
//    return 0;
// }

// int main()
// {
//    FILE *f = fopen("test.txt", "w+b");
//    cout << f << endl;
//    write<char>(f, 'A');
//    write<char>(f, 'B');
//    write<char>(f, 'C');
//    write<char>(f, '3');
//    fclose(f);
//    return 0;
// }

// int main()
// {
//    FILE *f = fopen("test.txt", "r+b");
//    cout << fread(f, sizeof(char), 1, f) << endl;
//    cout << fread(f, sizeof(char), 1, f) << endl;
//    cout << fread(f, sizeof(char), 1, f) << endl;
//    cout << fread(f, sizeof(char), 1, f) << endl;
//    fclose(f);
//    return 0;
// }

// int main()
// {
//    Mtx<string> x = mtx<string>(3, 3, "X", stringToString);
//    mtxShow<string>(x, stringToString);
//    return 0;
// }

int cmpPalabras(string palabra1, string palabra2)
{
   palabra1 = toUpperCase(palabra1);
   palabra2 = toUpperCase(palabra2);
   int uno = charCount(palabra1, 'A');
   int dos = charCount(palabra2, 'A');
   return dos - uno;
}

int main()
{
   Coll<string> memoria = coll<string>();

   string palabra = "";

   cout << "Ingrese un conjunto de palabras, finalizado por la entrada de la palabra FIN" << endl;

   cin >> palabra;

   while (palabra != "FIN")
   {
      palabra = palabra + "-" + intToString(collSize<string>(memoria) + 1);
      collAdd<string>(memoria, palabra, stringToString);
      cin >> palabra;
   }

   collSort<string>(memoria, cmpPalabras, stringToString, stringToString);

   collReset<string>(memoria);
   FILE *f = fopen("PALABRAS.dat", "w+b");
   while (collHasNext<string>(memoria))
   {
      string s = collNext<string>(memoria, stringToString);
      write(f, s);
   }

   fclose(f);

   return 0;
}

#endif
