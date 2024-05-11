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

int main()
{
   string s = "John|Paul|George|Ringo";
   char sep = '|';
   string t = "Paul";
   int p = findToken(s, sep, t);
   cout << p << endl; // Salida: 1
   string x = "John";
   p = findToken(s, sep, x);
   cout << p << endl; // Salida: 0
   string o = "George";
   p = findToken(s, sep, o);
   cout << p << endl; // Salida: 2
   string r = "Ringo";
   p = findToken(s, sep, r);
   cout << p << endl; // Salida: 3
   string q = "Pablo";
   p = findToken(s, sep, q);
   cout << p << endl; // Salida: -1

   return 0;
}

#endif
