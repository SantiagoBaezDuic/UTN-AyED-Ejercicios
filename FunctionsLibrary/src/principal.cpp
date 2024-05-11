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
   string s1 = "Carlos";
   string s2 = "Alma";

   if (cmpString(s1, s2) < 0)
   {
      cout << s1 << " es menor que: " << s2 << endl;
   }
   else if (cmpString(s1, s2) > 0)
   {
      cout << s2 << " es menor que: " << s1 << endl;
   }
   else if (cmpString(s1, s2) == 0)
   {
      cout << "son iguales" << endl;
   }

   return 0;
}

#endif
