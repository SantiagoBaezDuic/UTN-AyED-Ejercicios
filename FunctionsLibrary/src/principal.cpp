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
   Coll<string> c = coll<string>();
   collAdd<string>(c, "John", stringToString);
   collAdd<string>(c, "Paul", stringToString);
   collAdd<string>(c, "George", stringToString);
   collAdd<string>(c, "Ringo", stringToString);

   collSort<string>(c, cmpString, stringToString, stringToString);

   collShow<string>(c, stringToString, stringToString);

   return 0;
}

#endif
