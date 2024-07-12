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
#include "principal.hpp"
using namespace std;

// subo archivos a memoria
Coll<Rempresa> subirEmpresas()
{
    return {};
}

int cmpEmpresaId()
{
}

// buscamos empresa e incrementar el contador de los accidentes
void procesarPunto1(Accidente a, Coll<Rempresa> &cEmp)
{
    int pos = collFind<Rempresa, int>(cEmp, a.idEmpresa, cmpEmpresaId, rempresaFromString);
}

// buscamos empresa, descubrimos el empleado e incrementamos los dias ausentes
void procesarPunto2(Accidente a, Coll<Rempresa> &cEmp)
{
}

int main()
{

    Coll<Rempresa> cEmp = subirEmpresas();
    FILE *f = fopen("ACCIDENTES.dat", "r+b");
    Accidente a = read<Accidente>(f);
    while (!feof(f))
    {

        procesarPunto1(a, cEmp);

        procesarPunto2(a, cEmp);

        a = read<Accidente>(f);
    }

    return 0;
}

#endif