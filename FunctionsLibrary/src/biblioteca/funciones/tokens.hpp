#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s, char sep)
{
   int amount = 0;
   if (s != "")
   {
      amount = 1;
   }
   amount += charCount(s, sep);
   return amount;
}

void addToken(string &s, char sep, string t)
{
   if (tokenCount(s, sep) > 0)
   {
      s += sep + t;
   }
   else
   {
      s += t;
   }
}

string getTokenAt(string s, char sep, int i)
{
   string token;
   if (i == 0)
   {
      token = substring(s, 0, indexOf(s, sep));
   }
   else
   {
      int ini = indexOfN(s, sep, i) + 1;
      int end = indexOfN(s, sep, i + 1);
      token = substring(s, ini, end);
   }

   return token;
}

void removeTokenAt(string &s, char sep, int i)
{
   if (i == 0)
   {
      s = substring(s, indexOf(s, sep) + 1);
   }
   else
   {
      int ini = indexOfN(s, sep, i);
      int end = indexOfN(s, sep, i + 1);
      string subs1 = substring(s, 0, ini);
      string subs2 = substring(s, end, length(s));
      s = subs1 + subs2;
   }
}

void setTokenAt(string &s, char sep, string t, int i)
{
   if (i >= tokenCount(s, sep))
   {
      s += sep + t;
   }
   else
   {
      if (i == 0)
      {
         s = t + sep + substring(s, indexOf(s, sep) + 1);
      }
      else
      {
         int ini = indexOfN(s, sep, i);
         int end = indexOfN(s, sep, i + 1);
         string subs1 = substring(s, 0, ini + 1);
         string subs2 = substring(s, end, length(s));
         s = subs1 + t + subs2;
      }
   }
}

int findToken(string s, char sep, string t)
{
   int pos = -1;
   for (int i = 0; i < tokenCount(s, sep); i++)
   {
      if (getTokenAt(s, sep, i) == t)
      {
         pos = i;
      }
   }

   return pos;
}

#endif
