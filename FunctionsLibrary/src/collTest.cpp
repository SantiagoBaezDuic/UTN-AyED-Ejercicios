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

int main()
{
    Coll c = coll<string>('&');

    collAdd<string>(c, "Test0", stringToString);
    collAdd<string>(c, "Test1", stringToString);
    collAdd<string>(c, "Test2", stringToString);
    collAdd<string>(c, "Test3", stringToString);
    collAdd<string>(c, "Test4", stringToString);

    cout << c.tokens << endl;

    cout << "collSize: " << collSize<string>(c) << " //expected:5" << endl;

    collRemoveAt<string>(c, 2);

    cout << c.tokens << " //expected:no Test 2" << endl;

    collSetAt<string>(c, "TestSeteado", 1, stringToString);

    cout << c.tokens << " //expected:TestSeteado en pos 1" << endl;

    collAdd<string>(c, "NuevoTest", stringToString);

    cout << collGetAt(c, 2, stringToString) << " //expected: Test3" << endl;

    int notfound = collFind<string, string>(c, "not", cmpString, stringToString);
    int found = collFind<string, string>(c, "NuevoTest", cmpString, stringToString);

    cout << notfound << " //expected -1" << endl;
    cout << found << " //expected 4" << endl;

    Coll s = coll<string>('&');

    collAdd<string>(s, "Jhon", stringToString);
    collAdd<string>(s, "Paul", stringToString);
    collAdd<string>(s, "George", stringToString);
    collAdd<string>(s, "Ringo", stringToString);

    cout << s.tokens << " //expected: Jhon&Paul&George&Ringo" << endl;

    collSort(s, cmpString, stringToString, stringToString);

    cout << s.tokens << " //expected: George&Jhon&Paul&Ringo" << endl;

    for (int i = 0; i < collSize(s); i++)
    {
        cout << collNext(s, s.eoc, stringToString) << " ";
    }
    cout << endl;

    cout << "Expected: George Jhon Paul Ringo" << endl;

    cout << boolalpha << s.eoc << " //expected: true" << endl;
    collReset(s);
    cout << boolalpha << s.eoc << " //expected: false" << endl;

    return 0;
}

#endif
