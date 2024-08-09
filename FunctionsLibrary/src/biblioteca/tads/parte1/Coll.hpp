#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../../funciones/strings.hpp"

using namespace std;

template <typename T>
struct Coll
{
   string tokens;
   char sep;
   int cI;
   bool eoc;
};

template <typename T>
Coll<T> coll(char sep)
{
   return {"", sep, 0, true};
}

template <typename T>
Coll<T> coll()
{
   return {"", '|', 0, true};
}

template <typename T>
int collSize(Coll<T> c)
{
   int i = tokenCount(c.tokens, c.sep);
   return i;
}

template <typename T>
void collRemoveAll(Coll<T> &c)
{
   c.tokens = "";
}

template <typename T>
void collRemoveAt(Coll<T> &c, int p)
{
   removeTokenAt(c.tokens, c.sep, p);
}

template <typename T>
int collAdd(Coll<T> &c, T t, string tToString(T))
{
   addToken(c.tokens, c.sep, tToString(t));
   int newTokenAmount = tokenCount(c.tokens, c.sep);
   c.eoc = false;
   return newTokenAmount;
}

template <typename T>
void collSetAt(Coll<T> &c, T t, int p, string tToString(T))
{
   setTokenAt(c.tokens, c.sep, tToString(t), p);
}

template <typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string))
{
   T t = tFromString(getTokenAt(c.tokens, c.sep, p));
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string))
{
   int p = -1;
   for (int i = 0; i < tokenCount(c.tokens, c.sep); i++)
   {
      string currentToken = getTokenAt(c.tokens, c.sep, i);
      if (cmpTK(currentToken, k) == 0)
      {
         p = i;
      }
   }
   return p;
}

template <typename T>
void collSort(Coll<T> &c, int cmpTT(T, T), T tFromString(string), string tToString(T))
{
   Coll<T> sortedC = coll<T>(c.sep);
   for (int i = 0; i < tokenCount(c.tokens, c.sep); i++) // Recorro la cadena tokenizada desordenada
   {
      string currentToken = getTokenAt(c.tokens, c.sep, i);
      if (isEmpty(sortedC.tokens)) // Si la cadena ordenada esta vacía, ingreso el primero token
      {
         addToken(sortedC.tokens, c.sep, currentToken);
      }
      else
      {
         bool hasBeenAdded = false;

         for (int x = 0; x < tokenCount(sortedC.tokens, sortedC.sep); x++) // Recorro la cadena ordenada y comparo con cada token
         {
            string currentTokenToCompare = getTokenAt(sortedC.tokens, sortedC.sep, x);
            if (cmpTT(tFromString(currentToken), tFromString(currentTokenToCompare)) <= 0 && !hasBeenAdded) // Si el token actual precede al de la cadena ordenada
            {
               Coll<T> nextTokens = coll<T>(c.sep);
               for (int y = 0; y < x; y++)
               {
                  addToken(nextTokens.tokens, sortedC.sep, getTokenAt(sortedC.tokens, sortedC.sep, y));
               }
               addToken(nextTokens.tokens, sortedC.sep, currentToken);
               for (int z = x; z < tokenCount(sortedC.tokens, sortedC.sep); z++)
               {
                  addToken(nextTokens.tokens, sortedC.sep, getTokenAt(sortedC.tokens, sortedC.sep, z));
               }
               sortedC.tokens = nextTokens.tokens;

               hasBeenAdded = true;
            }
         }
         if (!hasBeenAdded) // Si no se metió el token, es posterior a todos, por lo tanto lo agrego
         {
            addToken(sortedC.tokens, sortedC.sep, currentToken);
         }
      }
      cout << "DEBUG//" << sortedC.tokens << endl;
   }
   c.tokens = sortedC.tokens;
}

template <typename T>
bool collHasNext(Coll<T> c)
{
   bool status = false;
   if (c.cI < collSize(c))
   {
      status = true;
   }

   return status;
}

template <typename T>
T collNext(Coll<T> &c, T tFromString(string))
{
   T t;
   if (collHasNext(c))
   {
      t = tFromString(getTokenAt(c.tokens, c.sep, c.cI));
      c.cI++;
   }

   return t;
}

template <typename T>
T collNext(Coll<T> &c, bool &endOfColl, T tFromString(string))
{
   T t;
   if (!endOfColl)
   {
      t = tFromString(getTokenAt(c.tokens, c.sep, c.cI));
      c.cI++;
      if (c.cI >= collSize(c))
      {
         c.eoc = true;
      }
   }
   return t;
}

template <typename T>
void collReset(Coll<T> &c)
{
   c.cI = 0;
   if (c.cI >= collSize(c))
   {
      c.eoc = true;
   }
   else
   {
      c.eoc = false;
   }
}

template <typename T>
string collToString(Coll<T> x)
{
   char sep = 1;
   string sTokens = x.tokens;
   string sSep = string(1, x.sep);
   string sCI = to_string(x.cI);
   string sEoc = to_string(x.eoc);
   return sTokens + sep + sSep + sep + sCI + sep + sEoc;
}

template <typename T>
Coll<T> collFromString(string s)
{
   char sep = 1;
   Coll<T> x;
   string t0 = getTokenAt(s, sep, 0);
   x.tokens = t0;
   string t1 = getTokenAt(s, sep, 1);
   x.sep = (char)t1[0];
   string t2 = getTokenAt(s, sep, 2);
   x.cI = stoi(t2);
   string t3 = getTokenAt(s, sep, 3);
   return x;
}

#endif
