#include "pila.h"
#include "viajes.h"
#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

static const char archEmpleado[] = {"archivoEmpleado.bin"};

typedef struct{
char nYa[30];
char dni[10];
stViajeFecha fechaN;
char contrasenia[30];
char tel[11];
int sueldo;
char puesto[20];
int estado;
}stEmpleado;


///PROTOTIPO EMPLEADOS(alta, baja, mostrar, modificacion)///////////////////////////////////////////////////////////////////////
stEmpleado cargarEmpleado ();
void mostrarOrdenAlfabE();
void mostrarOrdenAlfabBajaE();
void mostrarOrdenAlfabEActivo();
void mostrarOrdenDniE();
void mostrarOrdenDniBajaE();
void mostrarOrdenDniActivosE();
void mostrarEmpleado(stEmpleado A);

///modificar empleado//////////////////////////////////////////////////////////////////////////////////////////////////////////
stEmpleado modificarNyAE(stEmpleado A);
stEmpleado modificarDniE(stEmpleado A);
stEmpleado modificarTelE(stEmpleado A);
stEmpleado modificarSueldoE(stEmpleado A);
stEmpleado modificarPuestoE(stEmpleado A);
stEmpleado modificarDatosEmpleado(stEmpleado aux);
void modificarEmpleado (char nYa[]);

///PROTOTIPO ARCHIVOS//////////////////////////////////////////////////////////////////////////////////////////////////////////
void cargarArchivoEmpleado();
void encontrarEmpleadoDni(char D[]);
void encontrarEmpleadoN(char N[]);
void mostrarArchivoEmpleado();

/// ORDENAMIENTO EMPLEADOS////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarArregloEmpleadosRecursiva(stEmpleado A[], int validos, int i);
int calcularRegistrosE();
int calcularRegistrosActivosE();
int calcularRegistrosInactivosE();
int ArchivoToArregloEmpleados(stEmpleado** arrD, int validos);
int ArchivoToArregloEmpleadosActivo (stEmpleado** arrD, int validos);
int ArchivoToArregloEmpleadosInactivos(stEmpleado** arrD, int validos);
void ordenarArrDinamicoEmpleados (stEmpleado** arrD, int validos);

/// dar baja empleado/////////////////////////////////////////////////////////////////////////////////////////////////////////
void darBajaEmpleado(char nYa[]);
stEmpleado darBajaE(stEmpleado aux);

///Filtrar Empleados//////////////////////////////////////////////////////////////////////////////////////////////////////////
void filtrarEmpleadoEstado(int E);
void filtrarEmpleadoPuesto(char P[]);

///Calcular sueldos////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoToPilaEmpleadosFilt(Pila* aux, char dep[]);
void ArchivoToPilaEmpleados(Pila* aux);
float sumarSueldos(Pila aux);

///Cuenta empleado///////////////////////////////////////
stEmpleado cargarContraseniaEmpleado(stEmpleado A);
stEmpleado busquedaEmpleadoInicioSesion (char dni[], char contrasenia[]);
stEmpleado iniciarSesionEmpleado();
void registrarEmpleado();
#endif // EMPLEADOS_H_INCLUDED
