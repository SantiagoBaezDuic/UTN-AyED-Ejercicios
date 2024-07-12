#ifndef _TMTX_T_
#define _TMTX_T_

#include <iostream>
#include "Coll.hpp"

using namespace std;

template <typename T>
struct Mtx
{
   Coll<Coll<T>> mtx;
};

template <typename T>
Mtx<T> mtx(int f, int c, T valorDefault, string tToString(T))
{
   Mtx<T> m;
   // Agrego colecciones de T la cantidad necesaria de veces (corresponde con las filas)
   for (int i = 0; i < f; i++)
   {
      Coll<T> x;
      // Agrego elementos de T la cantidad necesaria de veces (corresponde con las columnas)
      for (int i = 0; i < c; i++)
      {
         collAdd<T>(x, valorDefault, tToString);
      }

      // Añado el elemento a la matriz
      collAdd<Coll<T>>(m.mtx, x, collToString);
   }

   return m;
}

template <typename T>
T mtxGetAt(Mtx<T> m, int f, int c, T tFromString(string))
{
   // Traigo la fila
   Coll<T> row = collGetAt<Coll<T>>(m, f, tFromString);
   // Leo el elemento de la columna correspondiente
   T t = collGetAt<T>(row, c, tFromString);
   return t;
}

template <typename T>
void mtxSetAt(Mtx<T> &m, T t, int f, int c, string tToString(T))
{
   // Traigo la fila
   Coll<T> row = collGetAt<Coll<T>>(m, f, collFromString);
   // Seteo el elemento nuevo
   collSetAt<T>(row, t, c, tToString);
   // Actualizo la fila
   collSetAt<Coll<T>>(m, row, f, tToString);
}

template <typename T>
void mtxShow(Mtx<T> m, T tFromString(string))
{
   collReset(m.mtx);
   while (collHasNext(m.mtx))
   {
      Coll<T> f = collNext<Coll<T>>(m.mtx, collFromString);
      collReset(f);
      while (collHasNext(f))
      {
         T e = collNext<T>(f, tFromString);
         cout << e;
      }
      cout << endl;
   }
}

// ------------------------

template <typename T>
struct Cube
{
};

template <typename T>
Cube<T> cube(int f, int c, int p, T valorDefault, string tToString(T))
{
   return {};
}

template <typename T>
T cubeGetAt(Cube<T> cu, int f, int c, int p, T tFromString(string))
{
   T t;
   return t;
}

template <typename T>
void cubeSetAt(Cube<T> &cu, T t, int f, int c, int p, string tToString(T))
{
}

#endif
