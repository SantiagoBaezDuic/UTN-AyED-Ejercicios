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

   string s = "Saracatunga";
   write<string>(f, s);
   s = "xd";
   write<string>(f, s);
   s = "xd2";
   write<string>(f, s);
   cout << "size: " << fileSize<string>(f) << endl;
   fclose(f);

   FILE *f2 = fopen("test.x", "r+b");
   while (!feof(f2))
   {
      string x = read<string>(f2);
      cout << x << endl;
   }

   fclose(f2);

   return 0;
}

#endif
