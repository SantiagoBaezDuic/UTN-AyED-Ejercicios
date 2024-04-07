#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

/*
Consigna:
Entre dos fechas indicadas por el usuario, informar cuál es la más cercana a la actual.
Se debe establecer:
    1. Cuáles son los datos de entrada que el algoritmo necesitará para resolver el
    problema planteado.
    2. En qué formato el usuario deberá ingresar dichos datos de entrada.
Se debe considerar los años bisiestos, entendiendo que un año es bisiesto si es
divisible por 4, o por 400 pero no por 100.
*/

int main()
{
    string fecha1;
    string fecha2;
    cout << "Ingrese la primera fecha (formato aaaammdd): " << endl;
    cin >> fecha1;
    cout << "Ingrese la segunda fecha (formato aaaammdd): " << endl;
    cin >> fecha2;

    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

    cout << "Tiempo " << std::ctime(&t_c) << endl;
    return 0;
}