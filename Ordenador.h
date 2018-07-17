#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"
using namespace std;

class Ordenador
{
private:
    void mez(int *arreglo,int ini,int fin);

    void  construirMonticulo(int * arreglo,int tam );
    void corregirCima(int i,int tam,int * arreglo);
    int cambia(int,int,int *);
    void ordenaRapido(int *,int ini,int fin);
    int particion(int *arreglo,int inicio,int fin);
    void CountingSort(int *A,int *B, int k,int n,int p);
    int maximo(int *arreglo,int n);
    int minimo(int *arreglo,int n);
    int particionRamdon(int *,int,int);
    int seleccionRamdon(int *arreglo,int inicio,int fin ,int i);

    //Defina aquí los métodos auxiliares de los algoritmos de ordenamiento solamente.
    //Puede definir cuantos métodos quiera.

public:

    Ordenador();
    ~Ordenador();

    //Si piensa no implementar algunos de los métodos de ordenamiento, no los borre,
    //simplemente déjelos con el cuerpo vacío para evitar errores de compilación, ya
    //que se va a ejecutar el mismo ‘main’ para todas las tareas.
    void seleccion(int * arreglo, int tamano);
    void insercion(int * arreglo, int tamano);
    void mergesort(int * arreglo, int tamano);
    void heapsort(int * arreglo, int tamano);
    void quicksort(int * arreglo, int tamano);
    void radixsort(int * arreglo, int tamano) ;
    int mediana(int * arreglo, int tamano) ;
};
#endif

