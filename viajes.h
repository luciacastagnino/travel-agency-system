#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED

typedef struct{
int id;
char destino[30];
int duracion;
char transporte[20];
int precio;
int estado;
}stViaje;

///PROTOTIPOS VIAJE(alta, baja, mostrar, modificacion)
stViaje cargarViaje();
void mostrarViaje(stViaje A);

//modificar viaje
stViaje modificarIdV(stViaje A);
stViaje modificarDestinoV(stViaje A);
stViaje modificarDuracionV(stViaje A);
stViaje modificarTransporteV(stViaje A);
stViaje modificarPrecioV(stViaje A);
stViaje modificarEstadoV(stViaje A);
void modificarViaje (int id);

// dar baja viaje

stViaje darDeBajaViaje (int id);

//Filtrar Viajes
void filtrarViajeTransporte(char transporte[10]);
void filtrarViajeDestino(char D[10]);
void filtrarViajeEstado(int E);

///PROTOTIPO ARCHIVO
void cargarArchivoViaje();
stViaje encontrarViajeId(int id);
#endif // VIAJES_H_INCLUDED


