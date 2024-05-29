#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "ordenamientos.h"
#include "empleados.h"
#include "ventas.h"
#include "viajes.h"

/// ORDENAMIENTOS SELECCION/////////////////////////////////////////////////////////////////////////////////////////////////

/// ORDENAMIENTO EMPLEADOS/////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarPosMenorEmpleado (stEmpleado* A, int pos, int cantRegistrosE){

    int posMenor=pos, i;
    char menorEmpleado[30];

    strcpy(menorEmpleado, A[pos].nYa);

    for(i=pos+1; i<cantRegistrosE; i++){
        if(strcmpi(menorEmpleado, A[i].nYa) > 0){
            strcpy(menorEmpleado, A[i].nYa);
            posMenor=i;
        }
    }

    return posMenor;
}

void ordenamientoSeleccionEmpleado(stEmpleado* A, int cantRegistrosE){

    int posMenor;
    stEmpleado aux;
    int i=0;

     while(i<cantRegistrosE){
        posMenor=buscarPosMenorEmpleado(A, i, cantRegistrosE);
        aux=A[posMenor];
        A[posMenor]=A[i];
        A[i]=aux;
        i++;
     }
}

///ORDENAMIENTO CLIENTE//////////////////////////////////////////////////////////////////////////////////////////////////////

int cantRegistrosC=0;

int buscarPosMenorCliente (stCliente* A, int pos, int cantRegistrosC){

    int posMenor=pos, i;
    char menorCliente[30];

    strcpy(menorCliente, A[pos].nYa);

    for(i=pos+1; i<cantRegistrosC; i++){
        if(strcmpi(menorCliente, A[i].nYa) > 0){
            strcpy(menorCliente, A[i].nYa);
            posMenor=i;
        }
    }

    return posMenor;
}

void ordenamientoSeleccionCliente(stCliente* A, int cantRegistrosC){

    int posMenor;
    stCliente aux;
    int i=0;

     while(i<cantRegistrosC){
        posMenor=buscarPosMenorCliente(A, i, cantRegistrosC);
        aux=A[posMenor];
        A[posMenor]=A[i];
        A[i]=aux;
        i++;
     }
}

/// ORDENAMIENTOS INSERCION////////////////////////////////////////////////////////////////////////////////////////

/// ORDENAMIENTO VIAJES ///////////////////////////////////////////////////////////////////////////////////////////

int cantRegistrosV=0;

void insertar (stViaje* A, int u, stViaje aux){

    int i=u;

    while(i>=0 && A[i].id > aux.id){
        A[i+1]=A[i];
        i--;

    }

    A[i+1]=aux;

}

void ordenamientoInserccion (stViaje* A, int cantRegistrosV){

    int i=0;


    while(i < cantRegistrosV - 1){
        stViaje aux = A[i];
        insertar(A, i, A[i+1]);
        i++;
    }

}
