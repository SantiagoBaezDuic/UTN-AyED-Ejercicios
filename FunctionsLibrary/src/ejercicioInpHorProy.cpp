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

// Archivo: PROYECTOS.dat
struct Proyecto
{
    int idProyecto;
    char descripcion[100];
    int fechaInicio;
    int horasAsignadas;
    int horasImputadas;
};

// Archivo HORAS.dat
struct Hora
{
    int idEmpleado;
    int idProyecto;
    int fecha; // *ordenado
    int horas;
    char tareas[200];
};

// Archivo: EMPLEADOS.dat
struct Empleado
{
    int idEmpleado;
    char nombre[50];
};

struct IEmpleado
{
    Empleado emp;
    int horasCount;
    Stack<Tarea> tareas;
};

struct Tarea
{
    int idEmpleado;
    int fecha;
    int horas;
    char tareas[200];
};

struct IProyecto
{
    Proyecto proy;
    Map<int, IEmpleado> empleados;
};

void asignarHoras(Map<int, IProyecto> proyectos, Hora elem)
{
    // Busco el proyecto en cuestión
    IProyecto *pos = mapGet<int, IProyecto>(proyectos, elem.idProyecto);
    // Busco el nombre del empleado
    string nombreEmpleado = empleados[arrayFind<Empleado>(empleados, elem.idEmpleado, cmpIdEmpleado)].nombre;
    // Creo el objeto del empleado a agregar si fuera necesario
    IEmpleado empleadoNuevo = {{elem.idEmpleado, nombreEmpleado}, 0, stack<Tarea>()};
    // Descubro el empleado, y si no está, utilizo el objeto anterior
    IEmpleado *emp = mapDiscover<int, IEmpleado>(pos->empleados, elem.idEmpleado, empleadoNuevo);
    // Creo la tarea a agregar
    Tarea tareaNueva = {elem.idEmpleado, elem.fecha, elem.horas, elem.tareas};
    // Agrego la tarea a la pila
    stackPush<Tarea>(emp->tareas, tareaNueva);
    // Sumo las horas al contador del empleado en este proyecto
    emp->horasCount += elem.horas;
    // Sumo las horas de este elemento al contador total de horas imputadas del proyecto
    pos->proy.horasImputadas += elem.horas;
}

void mostrarResultados(Map<int, IProyecto> proyectos)
{
    mapReset<int, IProyecto>(proyectos);
    while (mapHasNext<int, IProyecto>(proyectos))
    {
        // Tomo el proyecto y devuelvo los datos pertinentes
        IProyecto proy = mapNextValue<int, IProyecto>(proyectos);
        cout << "Proyecto: " << proy.proy.descripcion << endl;
        cout << "Horas asignadas: " << proy.proy.horasAsignadas << endl;
        cout << "Horas imputadas: " << proy.proy.horasImputadas << endl;

        mapReset<int, IEmpleado>(proy.empleados);
        while (mapHasNext<int, IEmpleado>(proy.empleados))
        {
            // Recorro los empleados del proyecto, y por cada uno devuelvo los datos pertinentes
            IEmpleado sigEmp = mapNextValue<int, IEmpleado>(proy.empleados);
            cout << "Empleado: " << sigEmp.emp.nombre << ". Horas trabajadas: " << sigEmp.horasCount << endl;
            cout << "Fecha " << " Tarea Desarrollada " << " Horas" << endl;
            // Recorro las tareas de cada empleado y devuelvo los datos
            while (!stackIsEmpty<Tarea>(sigEmp.tareas))
            {
                Tarea tar = stackPop<Tarea>(sigEmp.tareas);
                cout << tar.fecha << tar.tareas << tar.horas << endl;
            }
        }
    }
}

int main()
{
    // Subir archivos de consulta EMPLEADOS.dat y PROYECTOS.dat a memoria
    Array<Empleado> empleados = array<Empleado>();
    // Recorro el archivo de Proyectos y por cada uno creo un elemento IProyecto en el map
    Map<int, IProyecto> proyectos = map<int, IProyecto>();
    FILE *f = fopen("HORAS.dat", "r+b");
    Hora siguiente = read<Hora>(f);
    while (!feof(f))
    {
        asignarHoras(proyectos, siguiente);

        siguiente = read<Hora>(f);
    }

    fclose(f);

    mostrarResultados(proyectos);

    return 0;
}

#endif
