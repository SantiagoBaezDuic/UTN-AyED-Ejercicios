#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte1/MultidimColl.hpp"
using namespace std;

#ifndef _MAIN
#define _MAIN

bool esAnagrama(string s, string token)
{
    bool result = false;
    string s2 = s;
    string token2 = token;
    for (int i = 0; i < length(s); i++)
    {
        for (int x = 0; x < length(token2); x++)
        {
            if (s[i] == token2[x])
            {
                token2 = removeAt(token2, x);
                s2 = removeAt(s2, length(s2) - 1);
            }
        }
    }

    if (token2 == "" && s2 == "")
    {
        result = true;
    }

    return result;
}

string encontrarAnagramas(string token, string entera)
{
    int found = 0;
    string result = "Los anagramas de " + token + " son: ";
    for (int i = 0; i < tokenCount(entera, '|'); i++)
    {
        string x = getTokenAt(entera, '|', i);
        if (x != token)
        {
            if (length(x) == length(token))
            {
                if (esAnagrama(token, x))
                {
                    if (found != 0)
                    {
                        result += ", " + x;
                    }
                    else
                    {
                        result += x;
                        found++;
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    /*Se ingresa por teclado un conjunto de palabras, finalizando con la llegada de la palabra FIN.
    Se pide informar: para cada una de las palabras del conjunto, cuáles de las otras palabras
    son sus anagramas.

    X = {ROMA, ZORRA, PEDRO, AMOR, ARROZ, MORA, CALESITA}

    ROMA: AMOR, MORA
    ZORRA: ARROZ
    PEDRO:
    AMOR: ROMA, MORA
    ARROZ: ZORRA
    MORA: ROMA, AMOR
    CALESITA:*/

    cout << "Ingrese un conjunto de palabras, finalizado por la entrada de la palabra FIN" << endl;

    string w;
    string s = "";
    while (w != "FIN")
    {
        addToken(s, '|', w);
        cin >> w;
    }

    for (int i = 0; i < tokenCount(s, '|'); i++)
    {
        string x = getTokenAt(s, '|', i);
        string resultado = encontrarAnagramas(x, s);
        cout << resultado << endl;
    }

    return 0;
}

#endif
