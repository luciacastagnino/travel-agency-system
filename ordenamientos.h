#ifndef ORDENAMIENTOS_H_INCLUDED
#define ORDENAMIENTOS_H_INCLUDED
#include "empleados.h"
#include "clientes.h"
#include "ventas.h"
#include "viajes.h"

///ORDENAMIENTO POR SELECCION/////////////////////////////////////////////////////////////////////////////////////////////////////
///ORDENAMIENTO EMPLEADOS////////////////////////////////////////////////////////////////////////////////////////
int contarCantidadRegistrosE();
int buscarPosMenorEmpleado (stEmpleado* A, int pos, int cantRegistrosE);
void ordenamientoSeleccionEmpleado(stEmpleado* A, int cantRegistrosE);

///ORDENAMIENTO CLIENTES/////////////////////////////////////////////////////////////////////////////////////////
int buscarPosMenorCliente (stCliente* A, int pos, int cantRegistrosC);
void ordenamientoSeleccionCliente(stCliente* A, int cantRegistrosC);

///ORDENAMIENTO POR INSERCION/////////////////////////////////////////////////////////////////////////////////////////////////////

void insertar (stViaje* A, int u, stViaje aux);
void ordenamientoInserccion (stViaje* A, int cantRegistrosV);

#endif // ORDENAMIENTOS_H_INCLUDED
