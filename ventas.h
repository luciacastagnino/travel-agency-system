#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "viajes.h"
#include "clientes.h"
#include "empleados.h"
#include "ordenamientos.h"

static const char archVentas[] = {"archivoVentas.bin"};

typedef struct{
int idVenta;
char nYaC[30];
char nYaE[30];
int idViaje;
}stVentas;

///PROTOTIPOS VENTAS//////////////////////////////////////////////////////////////////////////////////////////////////////////
///Cargar ventas/////////////////


#endif // VENTAS_H_INCLUDED
