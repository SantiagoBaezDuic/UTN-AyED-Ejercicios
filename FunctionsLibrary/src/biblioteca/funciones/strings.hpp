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
      c = '0' + i;
   }
   else if (i + 55 >= 65 && i + 55 <= 90)
   {
      c = 'A' + (i - 10);
   }
   else
   {
      c = '\0';
   }
   return c;
}

int getDigit(int n, int i)
{
   int x = 1;
   for (int z = 0; z < i; z++)
   {
      x = x * 10;
   }
   int digit = (n % (10 * x)) / x;
   return digit;
}

int digitCount(int n)
{
   int x = n;
   int count = 0;
   if (n == 0)
   {
      count = 1;
   }
   while (x != 0)
   {
      x = x / 10;
      count++;
   }
   return count;
}

string intToString(int i)
{
   string s = "";
   for (int n = digitCount(i) - 1; n >= 0; n--)
   {
      int d = getDigit(i, n);
      char c = intToChar(d);
      s = s + c;
   }
   return s;
}

int stringToInt(string s, int b) // ok
{
   int i = 0;
   int multiplier = 1;
   for (int z = length(s) - 1; z >= 0; z--)
   {
      i = i + (charToInt(s[z]) * multiplier);
      multiplier = multiplier * b;
   }
   return i;
}

int stringToInt(string s) // ok
{
   int i = 0;
   int multiplier = 1;
   for (int z = length(s) - 1; z >= 0; z--)
   {
      i = i + (charToInt(s[z]) * multiplier);
      multiplier = multiplier * 10;
   }
   return i;
}

string charToString(char c)
{
   string s;
   s += c;
   return s;
}

char stringToChar(string s)
{
   char c = (char)s[0];
   return c;
}

string stringToString(string s)
{
   string ss;
   ss = s;
   return ss;
}

string doubleToString(double d)
{
   double a = d;
   int entera = (int)a;
   double decimal = a - entera;
   string decimalString = "";
   string enteraString = intToString(entera);
   int cota = 0;
   int cotaMax = 3;
   while (decimal > 0.0000001 && cota < cotaMax)
   {
      int num = decimal * 10;
      decimal = decimal * 10 - num;
      decimalString = decimalString + intToChar(num);
      cota++;
   }
   string wholeString = enteraString + "." + decimalString;
   return wholeString;
}

double stringToDouble(string s)
{
   double d = 0;
   bool isDecimal = false;
   int posCount = 1;
   for (int i = 0; i < length(s); i++)
   {
      if (s[i] == '.')
      {
         isDecimal = true;
      }
      if (!isDecimal && s[i] != '.')
      {
         d = d * 10 + charToInt(s[i]);
      }
      else if (isDecimal && s[i] != '.')
      {
         d = d + s[i] / (10 * posCount);
         posCount++;
      }
   }

   return d;
}

bool isEmpty(string s)
{
   bool value = false;
   if (s == "")
   {
      value = true;
   }

   return value;
}

bool startsWith(string s, string x)
{
   bool value = true;
   if (length(x) == 0)
   {
      if (length(s) != 0)
      {
         value = false;
      }
   }

   for (int i = 0; i < length(x); i++)
   {
      if (s[i] != x[i])
      {
         value = false;
      }
   }

   return value;
}

bool endsWith(string s, string x)
{
   bool value = true;
   if (length(x) == 0)
   {
      if (length(s) != 0)
      {
         value = false;
         return value;
      }
   }
   int dif = length(s) - length(x);
   for (int i = length(s); i > dif; i--)
   {
      if (s[i] != x[i - dif])
      {
         value = false;
      }
   }

   return value;
}

bool contains(string s, char c)
{
   bool value = false;
   for (int i = 0; i < length(s); i++)
   {
      if (s[i] == c)
      {
         value = true;
      }
   }

   return value;
}

string replace(string s, char oldChar, char newChar)
{
   string newString = s;
   for (int i = 0; i < length(s); i++)
   {
      if (newString[i] == oldChar)
      {
         newString[i] = newChar;
      }
   }

   return newString;
}

string insertAt(string s, int pos, char c)
{
   string subs1 = substring(s, 0, pos);
   string subs2 = substring(s, pos);
   string newString = subs1 + c + subs2;
   return newString;
}

string removeAt(string s, int pos)
{
   string subs1 = substring(s, 0, pos);
   string subs2 = substring(s, pos + 1);
   string newString = subs1 + subs2;
   return newString;
}

string ltrim(string s)
{
   string newString;
   bool notEmpty = false;
   int count = 0;
   while (!notEmpty)
   {
      if (s[count] != ' ')
      {
         notEmpty = true;
      }
      else
      {
         count++;
      }
   }
   newString = substring(s, count);

   return newString;
}

string rtrim(string s)
{
   string newString;
   bool notEmpty = false;
   int count = length(s);
   while (!notEmpty)
   {
      if (s[count - 1] != ' ')
      {
         notEmpty = true;
      }
      else
      {
         count--;
      }
   }
   newString = substring(s, 0, count);

   return newString;
}

string trim(string s)
{
   string newString = rtrim(ltrim(s));
   return newString;
}

string replicate(char c, int n)
{
   string newString;
   for (int i = 0; i < n; i++)
   {
      newString += c;
   }

   return newString;
}

string spaces(int n)
{
   string newString;
   for (int i = 0; i < n; i++)
   {
      newString += ' ';
   }

   return newString;
}

string lpad(string s, int n, char c)
{
   string newString = replicate(c, n - length(s)) + s;
   return newString;
}

string rpad(string s, int n, char c)
{
   string newString = s + replicate(c, n - length(s));
   return newString;
}

string cpad(string s, int n, char c)
{
   int amount = (n - length(s)) / 2;
   string newString = replicate(c, amount) + s + replicate(c, amount);
   return newString;
}

bool isDigit(char c)
{
   bool value = false;
   if (c >= 48 && c <= 57)
   {
      value = true;
   }
   return value;
}

bool isLetter(char c)
{
   bool value = false;
   if (c >= 65 && c <= 90)
   {
      value = true;
   }
   else if (c >= 97 && c <= 122)
   {
      value = true;
   }
   return value;
}

bool isUpperCase(char c)
{
   bool value = false;
   if (c >= 65 && c <= 90)
   {
      value = true;
   }
   return value;
}

bool isLowerCase(char c)
{
   bool value = false;
   if (c >= 97 && c <= 122)
   {
      value = true;
   }
   return value;
}

char toUpperCase(char c)
{
   char upperChar = c - 32;
   return upperChar;
}

char toLowerCase(char c)
{
   char lowerChar = c + 32;
   return lowerChar;
}

string toUpperCase(string s)
{
   string newString;
   for (int i = 0; i < length(s); i++)
   {
      newString += toUpperCase(s[i]);
   }

   return newString;
}

string toLowerCase(string s)
{
   string newString;
   for (int i = 0; i < length(s); i++)
   {
      newString += toLowerCase(s[i]);
   }

   return newString;
}

int cmpString(string a, string b)
{
   int result = 0;
   for (int i = 0; i < length(a); i++)
   {
      if (result == 0 && charToInt(a[i]) < charToInt(b[i]))
      {
         result = -1;
      }
      else if (result == 0 && charToInt(a[i]) > charToInt(b[i]))
      {
         result = 1;
      }
   }
   if (result == 0 && length(a) < length(b))
   {
      result = -1;
   }
   else if (result == 0 && length(a) > length(b))
   {
      result = 1;
   }

   return result;
}

int cmpDouble(double a, double b)
{
   int result = 0;
   if (a > b)
   {
      result = 1;
   }
   else if (b > a)
   {
      result = -1;
   }

   return result;
}

#endif
