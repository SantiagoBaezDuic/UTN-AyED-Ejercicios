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
   for (int i = len; i > p; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[p] = e;
   len++;
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
   if (len == 0)
   {
      add(arr, len, e);
      return 0;
   }
   int pos = -1;
   for (int i = 0; i < len; i++)
   {
      if (cmpTT(arr[i], e) < 0)
      {
         insert(arr, len, e, i);
      }
   }

   return pos;
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T, T))
{
}

template <typename T>
void show(T arr[], int len)
{
   for (int i = 0; i < len; i++)
   {
      cout << arr[i] << endl;
   }
}

#endif
