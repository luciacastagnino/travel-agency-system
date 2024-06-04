#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "viajes.h"
#include "clientes.h"
#include "empleados.h"
#include "ordenamientos.h"

static const char archVentas[] = {"archivoVentas.bin"};

typedef struct
{
  int monto;              /// Valor por cargo de servicios que se agrega al precio de viaje
  char fecha[10];         /// Fecha en la que se imprime el ticket
  char metodo[15];        /// Metodo de pago
  char idCliente[10];     /// Id del cliente
  char idEmpleado[10];    /// Id del empleado
  int id;                 /// Id del ticket
  int estado;             /// 1/0
  stViaje viaje;          /// Estructura *AUXILIAR* de viaje

}stTickets;

//typedef struct{
//int idVenta;
//char nYaC[30];
//char nYaE[30];
//int idViaje;
//}stVentas;
//



///PROTOTIPOS VENTAS//////////////////////////////////////////////////////////////////////////////////////////////////////////
stTickets CargarTicket();
void MostrarTicket(stTickets A);
void cargarArchivoVentas();
void mostrarArchivoVentas();

///Cargar ventas/////////////////


#endif // VENTAS_H_INCLUDED
