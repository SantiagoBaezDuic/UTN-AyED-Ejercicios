#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template <typename T>
void write(FILE *f, T t)
{
   fseek(f, 0, SEEK_CUR);
   fwrite(&t, sizeof(T), 1, f);
}

template <typename T>
T read(FILE *f)
{
   fseek(f, 0, SEEK_CUR);
   T t;
   fread(&t, sizeof(T), 1, f);
   return t;
}

template <typename T>
void seek(FILE *f, int n)
{
   fseek(f, n * sizeof(T), SEEK_SET);
}

template <typename T>
int fileSize(FILE *f)
{
   int l, c;
   c = ftell(f);
   fseek(f, 0, SEEK_END);
   l = ftell(f);
   fseek(f, c, SEEK_SET);

   return l / sizeof(T);
}

template <typename T>
int filePos(FILE *f)
{
   int i = ftell(f) / sizeof(T);
   return i;
}

#endif
