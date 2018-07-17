#include "Ordenador.h"
#include <iostream>
#include <math.h>
#define length(x) (sizeof(x)/sizeof(x[0]))
Ordenador::Ordenador()
{
    //ctor
}

Ordenador::~Ordenador()
{
    //dtor
}

int Ordenador::maximo(int *arreglo,int n)
{

    int  mayor = arreglo[0];
    for (int i = 1; i < n; i++)
        if (arreglo[i] > mayor)
            mayor = arreglo[i];
    return mayor;

}
int Ordenador::minimo(int *arreglo,int n)
{

    int  menor = arreglo[0];
    for (int i = 1; i < n; i++)
        if (arreglo[i] < menor)
            menor = arreglo[i];
    return menor;

}
/*
Este metodo ordena de la forma que busca el menor de todo el arreglo y lo intercambia con i
asi se va aplicando para cada i por esto se utilizan dos fors anidados y no retorna nada y recibe
el arreglo y el tamaño de este
*/
void Ordenador::seleccion(int *arreglo, int n)
{
    int posmin;
    int temp;
    for(int i=0; i<n; i++)
    {
        posmin=i;//asume que el minimo es el primero
        for(int j=i+1; j<n; j++)
        {
            if(arreglo[posmin]>arreglo[j])
            {
                posmin=j;//actualiza la posicion del actual minimo

            }

        }
        temp=arreglo[posmin];
        arreglo[posmin]=arreglo[i];//una vez que termina de encontral el minimo lo intercambia con el i-esimo elemento
        arreglo[i]=temp;

    }

}
/*
este metodo corre a la derecha los valores del arreglo dependiendo de la posicion que ocupe el Key
recibe el vector y tamano  y no retorna nada
*/
void Ordenador::insercion(int *arreglo, int n)
{
    int key;
    int i;
    for(int j=1; j<n; j++)
    {
        key= arreglo[j];
        i=j-1;
        while(i>=0 && arreglo[i]>key)//mientras la llave sea menor a los elementos de la izquierda corre los elementos ciertas posiciones e inserta la Key
        {
            arreglo[i+1]=arreglo[i];
            arreglo[i]=key;
            i=i-1;

        }

    }



}
/*
Este metodo utiliza la tecnica divide y venceras, divide el arreglo en dos recursivamente hasta que quede arreglos triviales de
tamaño 1 y luego se devuelve ordenando los vectores hasta llegar a un vector de tamaño n ordenado
recibe el arreglo a ordenar y el tamaño
*/
void Ordenador::mergesort(int *arreglo,int n)
{
    int inicio=0;
    mez(arreglo,inicio,n);

}

void Ordenador::mez(int *arreglo,int inicio,int fin)
{
    if((fin-inicio)==0 || (fin-inicio)==1 )
    {
        return;
    }
    int temp=(inicio+fin)/2;
    mez(arreglo,inicio,temp);//llama recursicamente a la parte izquierda del arreglo
    mez(arreglo,temp,fin);//llama a la parte derecha recursivamente
    int p1=inicio;
    int p2=temp;
    int p3=0;
    int vect[fin-inicio];
    while(p1<temp || p2<fin)
    {
        if(p1<temp && p2<fin)
        {

            if(arreglo[p1]<arreglo[p2])//compara los arreglos y los ordena en un nuevo vector
            {
                vect[p3++]=arreglo[p1++];
            }
            else
            {
                vect[p3++]=arreglo[p2++];
            }

        }

        else
        {
            if(p1<temp)
            {
                vect[p3++]=arreglo[p1++];

            }
            else
            {
                vect[p3++]=arreglo[p2++];

            }
        }
    }
    for(int i=0; i<fin-inicio; i++)
    {
        arreglo[inicio+i]=vect[i];//pasa el arreglo ordenado temporal al arreglo pasado como parametro
    }

}
/*
este metodo se basa en una estructura llamada monticulo
*/
void Ordenador::heapsort(int *arre, int tam)
{
    construirMonticulo(arre,tam);//crea la estructura monticulo
    for(int i=tam; i>=1; i--)
    {
        cambia(0,i,arre);//cambia el valor mayor del arreglo y lo cambia con el mayor actual del monticulo
        tam=tam-1;//decrementa el tamaño del monticulo
        corregirCima(0,tam,arre);//corrige el monticulo si se incumple la propiedad fundamental de monticulo
    }

}
void Ordenador::construirMonticulo(int *arreglo,int tamano)
{
    for(int i=floor(tamano/2); i>=0; i--)
    {
        corregirCima(i,tamano,arreglo);

    }
}

/*
cambia dos elementos de un vector
*/
int Ordenador::cambia(int n1,int n2,int *arreglo)
{
    int temp=arreglo[n1];
    arreglo[n1]=arreglo[n2];
    arreglo[n2]=temp;

}
//este metodo corrige la cima de cada sub arbol en caso de que se incumpla la propiedad fundamental de un monticulo
void Ordenador::corregirCima(int j,int tamMoticulo,int *arreglo)
{
    int largo;
    int hijoizq=j*2;//forma de acceder al hijo izquierdo
    int hijoder=j*2+1;//forma de acceder al hijo derecho
    if(hijoizq<=tamMoticulo && arreglo[hijoizq]>arreglo[j])//si el hijo izquierdo es el mayor actualiza el mayor
    {
        largo=hijoizq;
    }
    else
    {
        largo=j;

    }
    if (hijoder<=tamMoticulo && arreglo[hijoder]>arreglo[largo])//si el derecho es el mayor actualiza el m
    {
        largo=hijoder;

    }
    if(largo!=j)//si el mayor no es el padre no cambie ni llame a corregir cima
    {
        cambia(j,largo,arreglo);
        corregirCima(largo,tamMoticulo,arreglo);
    }

}
/*
este metodo es  muy similar al de mezcla en el sentido que se llama recursivamente a dos partes del arreglo a
excepcion que mezcla necesita memoria extra
no retorna nada y recibe el tamaño, el arreglo y el inicio de este
*/
void Ordenador::ordenaRapido(int *arreglo,int inicio,int fin)
{
    int q;
    if(inicio<fin)
    {
        q=particion(arreglo,inicio,fin);
        ordenaRapido(arreglo,inicio,q-1);// llama a particion del lado izquierdo
        ordenaRapido(arreglo,q+1,fin);//llama a particion del lado izquierdo
    }


}
int Ordenador::particion(int *arreglo,int inicio,int fin)
{
    int pivote=arreglo[fin];//toma como pivote al ultimo
    int i=(inicio-1);

    for(int j=inicio; j<=fin-1; j++)
    {
        if(arreglo[j]<=pivote)//pregunta si los elemetos en la posicion j estan del lado incorrecto y los cambia
        {
            i=i+1;
            cambia(i,j,arreglo);
        }


    }

    cambia(i+1,fin,arreglo);


    return i+1;
}


void Ordenador::quicksort(int *arreglo, int tamano)
{
    int inicio=0;
    ordenaRapido(arreglo, inicio,tamano);
}
/*
metodo que ordena sin hacer comparaciones directas sino que se utilizan shifters y la base optima para ordenar en forma lineal
*/
void Ordenador::radixsort(int *arreglo, int n)
{
    int r=floor(log2(n));// la base indicada o optima para cierto tamaño del arreglo
    int b=sizeof(arreglo[0]);
    int  B[n];
    int contadores[1<<r];//crea un vector de contadores de acuerdo a los corrimientos que hace
    int pre[1<<r];
    int grups=ceil(b/2*r);
    int  mask  =  ( 1 << r ) - 1 ;
    for  ( int  c = 0, shift = 0 ;  c <grups;  c++)
    {

        for ( int  j = 0 ;  j < length(contadores)  ;  j++)
        {
            contadores[ j ] = 0 ;//pone en ceros el vector de contadores
        }
        for  ( int  i = 0 ;  i < n;  i ++)
        {
            contadores [( arreglo [ i ] >> shift ) &mask ]++;//con respecto a la mascara y el shift crea el histograma
        }

        pre [ 0 ] = 0 ;
        for  ( int  i = 1 ;  i < length(contadores) ;  i ++)
        {
            pre [ i ] = pre [ i - 1 ] + contadores[ i - 1 ];//actualiza el histograma acumulativo
        }

        for ( int  i = 0 ;  i < n ;  i++)
        {
            B [ pre [( arreglo [ i ] >> shift ) & mask]++] = arreglo [ i ];//ordena en un arreglo temporal B de acuerdo a cierta a la agrupacion de bits que tomo es decir el r optimo
        }
        for  ( int  i = 0 ;  i < n;  i ++)
        {
            arreglo[i]=B[i];

        }
        shift += r;
    }
    int contador=0;
    for  ( int  i = 0 ;  i < n;  i ++)//cuenta la cantidad de negativos del arreglo
    {
        if(arreglo[i]<0)
        {
            contador++;
        }
    }

    int v[contador]= {0};
    int k=0;
    int p=n;
    for  ( int  i= contador+1 ;  i <=(i+p);  i++)
    {
        v[k]=arreglo[p-1];
        k++;
        p--;
    }


    int v2[n-contador];
    for(int i=0; i<n-contador; i++)
    {
        v2[i]=arreglo[i];

    }

    int ind=contador-1;
    for(int i=0; i<=contador; i++)
    {

        arreglo[i]=v[ind];
        ind--;

    }
    int l=0;
    for(int i=contador; i<n; i++)
    {
        arreglo[i]=v2[l];
        l++;

    }

}



int Ordenador::seleccionRamdon(int *arreglo,int inicio,int fin,int i)
{
    int v=particion(arreglo,inicio,fin);
    if(i==v) // pregunta si el valor que  busca es el mismo que devuelve partition y si es cierto retorna el valor en esa posicion
    {

        return arreglo[v];

    }
    else
    {
        if(i<v)
        {
            seleccionRamdon(arreglo,inicio,v-1,i);//busca ala izquierda

        }
        else
        {
            seleccionRamdon(arreglo,v+1,fin,i);//busca a la derecha
        }
    }
}
/*
recibe el arreglo y el tamano y busca el valor de la mediana y la retorna en un int
*/
int Ordenador::mediana(int * arreglo, int tamano)
{
    int inicio=0;

    int v= seleccionRamdon(arreglo,inicio,tamano,ceil(tamano/2));// llama a un metodo que me devuelve la mediana del arreglo
    return v;
}




