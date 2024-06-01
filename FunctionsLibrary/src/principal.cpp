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
   FILE *f = fopen("test.x", "w+b");

   string s = "Esto es un test";
   write<string>(f, s);
   fclose(f);

   FILE *f2 = fopen("test.x", "r+b");
   string s2 = read<string>(f2);
   cout << s2 << endl;
   fclose(f2);

   return 0;
}

#endif
