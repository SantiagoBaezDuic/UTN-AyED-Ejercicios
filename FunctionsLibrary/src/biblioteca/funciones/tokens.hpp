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
   return "";
}

void removeTokenAt(string &s, char sep, int i)
{
}

void setTokenAt(string &s, char sep, string t, int i)
{
}

int findToken(string s, char sep, string t)
{
   return 0;
}

#endif
