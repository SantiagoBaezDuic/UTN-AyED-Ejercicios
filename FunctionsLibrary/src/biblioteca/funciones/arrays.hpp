#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[], int &len, T e)
{
   arr[len++] = e;
   return len - 1;
}

template <typename T>
void insert(T arr[], int &len, T e, int p)
{
   if (len == 0)
   {
      add<T>(arr, len, e);
   }
   else
   {
      for (int i = len; i > p; i--)
      {
         arr[i] = arr[i - 1];
      }
      arr[p] = e;
      len++;
   }
}

template <typename T>
T remove(T arr[], int &len, int p)
{
   T ret = arr[p];
   for (int i = p; i < len; i++)
   {
      arr[i] = arr[i + 1];
   }
   len--;

   return ret;
}

template <typename T, typename K>
int find(T arr[], int len, K k, int cmpTK(T, K))
{
   int pos = -1;
   for (int i = 0; i < len && pos == -1; i++)
   {
      if (cmpTK(arr[i], k) == 0)
      {
         pos = i;
      }
   }

   return pos;
}

template <typename T>
int orderedInsert(T arr[], int &len, T e, int cmpTT(T, T))
{
   int pos = -1;
   bool inserted = false;
   for (int i = 0; i < len && !inserted; i++)
   {
      if (cmpTT(arr[i], e) < 0)
      {
         cout << "Saltando en pos: " << i << endl;
         insert<T>(arr, len, e, i);
         inserted = true;
         pos = i;
      }
   }

   if (!inserted)
   {
      insert<T>(arr, len, e, len);
      pos = len;
   }

   return pos;
}

template <typename T>
void show(T arr[], int len)
{
   for (int i = 0; i < len; i++)
   {
      cout << arr[i] << endl;
   }
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T, T))
{
   T arrB[len];
   int lenB;
   for (int i = 0; i < len; i++)
   {
      cout << orderedInsert<T>(arrB, lenB, arr[i], cmpTT) << endl;
   }

   for (int i = 0; i < len; i++)
   {
      arr[i] = arrB[i];
   }
}

// template <typename T>
// void show(T arr[], int len)
// {
//    for (int i = 0; i < len; i++)
//    {
//       cout << arr[i] << endl;
//    }
// }

#endif
