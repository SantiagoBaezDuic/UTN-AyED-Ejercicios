#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/arrays.hpp"
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

int main()
{
    int a[5];
    int len = 0;
    add<int>(a, len, 1);
    add<int>(a, len, 2);
    add<int>(a, len, 3);
    add<int>(a, len, 4);
    add<int>(a, len, 5);
    show<int>(a, len);
    return 0;
}
#endif