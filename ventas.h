#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "viajes.h"
#include "clientes.h"
#include "empleados.h"
#include "ordenamientos.h"

static const char archVentas[] = {"archivoVentas.bin"};

typedef struct{
int monto;
char fecha[10];
char metodo[20];
char idCliente[10];
char idEmpleado[10];
int id;
int estado;
stViaje viaje;
}stTickets;

///PROTOTIPOS VENTAS//////////////////////////////////////////////////////////////////////////////////////////////////////////

stTickets CargarTicket();
void MostrarTicket(stTickets A);
void cargarArchivoVentas();
void mostrarArchivoVentas();

///Dar de baja ventas///////////////////////////////////////////////////////////////////////////////////////////////////////

void darBajaVenta(int idTicket);
stTickets darBajaT(stTickets aux);

///MODIFICAR VENTAS///////////////////////////////////////////////////////////////////////////////////////////////////////

stTickets modificarViajeT(stTickets A);
stTickets ModificarIdDelEmpleadoEnTicket(stTickets A);
stTickets ModificarIdTicket(stTickets A);
stTickets ModificarIdDelClienteEnTicket(stTickets A);
stTickets ModificarFechaTicket(stTickets A);
stTickets ModificarMontoTicket(stTickets A);
stTickets ModificarMetodoDePago(stTickets A);
stTickets modificarDatosTicket(stTickets aux);
void modificarVenta(int id);

///BUSCAR VENTA///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void encontrarVentaId(int id);
void encontrarVentaDNIC(char dniC[]);

///FILTRAR VENTAS/////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Filtrar Venta por Empleado

void filtrarVentaEmpleado(char dniE[]);

///Filtrar Ventas por metodo de pago

void filtrarVentaMetodo(char met[]);

///Filtrar venta por Viaje

void filtrarVentaViaje(int ID);

///Cargar ventas///////////////

///ARREGLO/////////////////////////////////////////////////////

void MostrarArregloTicket(stTickets A[], int validos);
void ordenarArrDinamicoTicket(stTickets** arrD, int validos);
int ArchivoToArregloBajaTicket(stTickets** arrD, int validos);
int ArchivoToArregloTicketActivo(stTickets** arrD, int validos);
int ArchivoToArregloTicket(stTickets** arrD, int validos);
int calcularRegistrosInactivosT();
int calcularRegistrosActivosT();
int calcularRegistrosT();
void mostrarOrdenIDT();
void mostrarOrdenAlfabT();
void mostrarOrdenIDBajaT();
void mostrarOrdenAlfabBajaT();
void mostrarOrdenIDActivosT();
void mostrarOrdenAlfabTActivo();

#endif // VENTAS_H_INCLUDED
