#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace std::filesystem;

int main()
{
    std::string codeTemplate = R"(#include <iostream>
using namespace std;

/*
Consigna:

*/

int main() {

    return 0;
})";

    string folder;
    string exerciseNumber;

    cout << "Ingrese el nombre de la carpeta (o un nombre nuevo para crear una carpeta): " << endl;
    cin >> folder;
    path folderPath = folder;

    if (!exists(folderPath))
    {
        create_directory(folderPath);
        cout << "Se ha creado la carpeta: " << folderPath << endl;
    }

    cout << "Ingrese el número de ejercicio: " << endl;
    cin >> exerciseNumber;

    std::string numberString = exerciseNumber + ".cpp";
    std::string exerciseString = "Ejercicio" + numberString;
    path exercisePath = folderPath / exerciseString;

    if (!exists(exercisePath))
    {
        ofstream file(exercisePath);
        if (file.is_open())
        {
            file << codeTemplate;
            file.close();
            cout << "Archivo de ejercicio creado: " << exerciseString << endl;
        }
        else
        {
            cerr << "Error al crear el archivo: " << exerciseString << endl;
        }
    }
    else
    {
        cout << "El archivo: " << exerciseString << " ya existe." << endl;
    }

    return 0;
}