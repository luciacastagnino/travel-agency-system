#include "ventas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viajes.h"
#include "clientes.h"
#include "empleados.h"
#include "ordenamientos.h"

///VENTAS EN ORDEN/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

///Cargar ventas///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int cargarArreglosVentas(int dim, stCliente C[dim], stEmpleado E[dim], stViaje V[dim], int i){

char control;
char dni[10];
char nYa[30];
int id;
control = 's';

while((i < dim)){

printf("Ingrese el DNI del cliente que quiere agregar\n");
fflush(stdin);
gets(dni);

C[i]= encontrarClienteDni(dni);

printf("Ingrese el nombre del empleado que realizo la venta\n");
fflush(stdin);
gets(nYa);

E[i]= encontrarEmpleadoN(nYa);


printf("Ingrese la Id del viaje\n");
fflush(stdin);
scanf("%d", &id);

V[i]= encontrarViajeId(id);

i++;

}
return i;
}
*/
