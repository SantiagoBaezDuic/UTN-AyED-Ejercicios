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
   int n = tokenCount(s, sep);
   cout << n << endl; // Salida: 4
   s = "John";
   sep = '|';
   n = tokenCount(s, sep);
   cout << n << endl; // Salida: 1
   s = "";
   sep = '|';
   n = tokenCount(s, sep);
   cout << n << endl; // Salida: 0

   return 0;
}

#endif
