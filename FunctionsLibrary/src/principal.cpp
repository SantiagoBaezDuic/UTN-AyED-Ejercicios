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
   string s = "";
   char sep = '|';

   addToken(s, sep, "John");
   cout << s << endl; // Salida: John

   addToken(s, sep, "Paul");
   cout << s << endl; // Salida: John|Paul

   addToken(s, sep, "George");
   cout << s << endl; // Salida: John|Paul|George

   addToken(s, sep, "Ringo");
   cout << s << endl; // Salida: John|Paul|George|Ringo

   return 0;
}

#endif
