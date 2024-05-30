#ifndef ORDENAMIENTOS_H_INCLUDED
#define ORDENAMIENTOS_H_INCLUDED
#include "empleados.h"
#include "clientes.h"
#include "ventas.h"
#include "viajes.h"

///ORDENAMIENTO POR SELECCION/////////////////////////////////////////////////////////////////////////////////////////////////////

// empleados

int contarCantidadRegistrosE();
int buscarPosMenorEmpleado (stEmpleado* A, int pos, int cantRegistrosE);
void ordenamientoSeleccionEmpleado(stEmpleado* A, int cantRegistrosE);

// clientes

int buscarPosMenorCliente (stCliente* A, int pos, int cantRegistrosC);
void ordenamientoSeleccionCliente(stCliente* A, int cantRegistrosC);

// viajes

int buscarPosMenorViaje (stViaje* A, int pos, int cantRegistrosV);
void ordenamientoSeleccionViaje(stViaje* A, int cantRegistrosV);

///ORDENAMIENTO POR INSERCION/////////////////////////////////////////////////////////////////////////////////////////////////////

// empleados

void insertarEmpleado (stEmpleado* A, int u, stEmpleado aux);
void ordenamientoInserccionEmpleado (stEmpleado* A, int cantRegistrosE);

// clientes

void insertarCliente (stCliente* A, int u, stCliente aux);
void ordenamientoInserccionCliente (stCliente* A, int cantRegistrosC);

// viajes

void insertar (stViaje* A, int u, stViaje aux);
void ordenamientoInserccion (stViaje* A, int cantRegistrosV);

#endif // ORDENAMIENTOS_H_INCLUDED
