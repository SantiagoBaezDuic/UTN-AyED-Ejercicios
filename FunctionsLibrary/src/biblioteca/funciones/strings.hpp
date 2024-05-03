#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int count = 0;
   while (s[count] != '\0')
   {
      count++;
   }

   return count;
}

int charCount(string s, char c)
{
   int i = 0;
   int count = 0;
   while (s[i] != '\0')
   {
      if (s[i] == c)
      {
         count++;
      }
      i++;
   }

   return count;
}

string substring(string s, int d, int h)
{
   string subs = "";
   for (int i = d; i < h; i++)
   {
      subs = subs + s[i];
   }
   return subs;
}

string substring(string s, int d) // ok
{
   string subs = "";
   for (int i = d; i < length(s); i++)
   {
      subs = subs + s[i];
   }

   return subs;
}

int indexOf(string s, char c) // ok
{
   int pos = -1;
   for (int i = 0; i < length(s); i++)
   {
      if (s[i] == c)
      {
         pos = i;
         return pos;
      }
   }
   return pos;
}

int indexOf(string s, char c, int offSet) // ok
{
   int pos = -1;
   for (int i = offSet; i < length(s); i++)
   {
      if (s[i] == c)
      {
         pos = i;
         return pos;
      }
   }
   return pos;
}

int indexOf(string s, string toSearch) // ok
{
   int pos = -1;
   for (int i = 0; i < length(s); i++) // Recorro la palabra ingresada
   {
      bool coincidence = false;
      if (s[i] == toSearch[0]) // Busco una coincidencia del primer caracter a buscar
      {
         coincidence = true;                        // Existe coincidencia
         for (int x = 0; x < length(toSearch); x++) // Reviso los siguientes x caracteres según el largo de toSearch
         {
            int offset = i + x;
            if (s[offset] != toSearch[x]) // No corresponde con el string toSearch
            {
               coincidence = false;
            }
         }
         if (coincidence) // Si hay coincidencia, indico la posición inicial
         {
            pos = i;
            return pos;
         }
      }
   }
   return pos;
}

int indexOf(string s, string toSearch, int offset) // ok
{
   int pos = -1;
   for (int i = offset; i < length(s); i++) // Recorro el string s
   {
      bool coincidence = false;
      if (s[i] == toSearch[0]) // Busco una coincidencia del primer caracter a buscar
      {
         coincidence = true;                        // Existe coincidencia
         for (int x = 0; x < length(toSearch); x++) // Reviso los siguientes x caracteres según el largo de toSearch
         {
            int offset = i + x;
            if (s[offset] != toSearch[x]) // No corresponde con el string toSearch
            {
               coincidence = false;
            }
         }
         if (coincidence) // Si hay coincidencia, indico la posición inicial
         {
            pos = i;
            return pos;
         }
      }
   }
   return pos;
}

int lastIndexOf(string s, char c)
{
   int pos = -1;
   for (int i = 0; i < length(s); i++)
   {
      if (s[i] == c)
      {
         pos = i;
      }
   }
   return pos;
}

int indexOfN(string s, char c, int n)
{
   int pos = -1;
   if (n == 0)
   {
      return pos;
   }
   int ocurrences = 0;
   for (int i = 0; i < length(s); i++) // Recorro el string s
   {
      if (s[i] == c) // Encuentro coincidencias con el caracter c
      {
         pos = i;
         ocurrences++;
         if (ocurrences == n)
         {
            return pos;
         }
      }
      if (ocurrences < n)
      {
         pos = length(s);
      }
   }
   return pos;
}

int charToInt(char c)
{
   int num = -1;
   if (c >= 48 && c <= 57)
   {
      num = c - '0';
   }
   else
   {
      num = c - 'A' + 10;
   }
   return num;
}

char intToChar(int i)
{
   char c;
   if (i >= 0 && i <= 9)
   {
      c = (char)i;
   }
   else if (i + 55 >= 65 && i + 55 <= 90)
   {
      int value = i + 55;
      c = (char)value;
   }
   return c;
}

int getDigit(int n, int i)
{

   return 0;
}

int digitCount(int n)
{
   int x = n;
   int count = 0;
   while (x != 0)
   {
      x = x / 10;
      count++;
   }
   return count;
}

string intToString(int i)
{
   return "";
}

int stringToInt(string s, int b) // ok
{
   return 0;
}

int stringToInt(string s) // ok
{
   return 0;
}

string charToString(char c)
{
   return "";
}

char stringToChar(string s)
{
   return 'X';
}

string stringToString(string s)
{
   return "";
}

string doubleToString(double d)
{
   return "";
}

double stringToDouble(string s)
{
   return 1.1;
}

bool isEmpty(string s)
{
   return true;
}

bool startsWith(string s, string x)
{
   return true;
}

bool endsWith(string s, string x)
{
   return true;
}

bool contains(string s, char c)
{
   return true;
}

string replace(string s, char oldChar, char newChar)
{
   return "";
}

string insertAt(string s, int pos, char c)
{
   return "";
}

string removeAt(string s, int pos)
{
   return "";
}

string ltrim(string s)
{
   return "";
}

string rtrim(string s)
{
   return "";
}

string trim(string s)
{
   return "";
}

string replicate(char c, int n)
{
   return "";
}

string spaces(int n)
{
   return "";
}

string lpad(string s, int n, char c)
{
   return "";
}

string rpad(string s, int n, char c)
{
   return "";
}

string cpad(string s, int n, char c)
{
   return "";
}

bool isDigit(char c)
{
   return true;
}

bool isLetter(char c)
{
   return true;
}

bool isUpperCase(char c)
{
   return true;
}

bool isLowerCase(char c)
{
   return true;
}

char toUpperCase(char c)
{
   return 'X';
}

char toLowerCase(char c)
{
   return 'X';
}

string toUpperCase(string s)
{
   return "";
}

string toLowerCase(string s)
{
   return "";
}

int cmpString(string a, string b)
{
   return 0;
}

int cmpDouble(double a, double b)
{
   return 0;
}

#endif
