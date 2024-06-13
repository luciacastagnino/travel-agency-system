#include "ventas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viajes.h"
#include "clientes.h"
#include "empleados.h"
#include "ordenamientos.h"
#include "pila.h"
#include <time.h>
#include "validaciones.h"


///VENTAS EN ORDEN/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarOrdenAlfabTActivo()
{
            stTickets *arrDinT;
            int validosT=0;
            validosT = ArchivoToArregloTicketActivo(&arrDinT, validosT);
            //printf("LISTA DE CLIENTES ORDENADOS:\n");
            ordenamientoSeleccionTicket(arrDinT, validosT);
            MostrarArregloTicket(arrDinT, validosT);
            if(validosT == 0){
            printf("No se encontraron Tickets activos\n");
        }
}

void mostrarOrdenIDActivosT()
{

    stTickets* arrDinT;
    int validosT=0;
    validosT = ArchivoToArregloTicketActivo(&arrDinT, validosT);
    ordenamientoInserccionTicket(arrDinT, validosT);
    MostrarArregloTicket(arrDinT, validosT);
    if(validosT == 0){
            printf("No se encontraron tickets activos\n");
        }
}

void mostrarOrdenAlfabBajaT()
{
            stTickets *arrDinT;
            int validosT = 0;
            validosT = ArchivoToArregloBajaTicket(&arrDinT, validosT);
            //printf("LISTA DE CLIENTES ORDENADOS:\n");
            ordenamientoSeleccionTicket(arrDinT, validosT);
            MostrarArregloTicket(arrDinT, validosT);
            if(validosT == 0){
            printf("No se encontraron ticket dados de baja\n");
        }

}

void mostrarOrdenIDBajaT()
{

    stTickets* arrDinT;
    int validosT=0;
    validosT=ArchivoToArregloBajaTicket(&arrDinT, validosT);
    ordenamientoInserccionTicket(arrDinT, validosT);
    MostrarArregloTicket(arrDinT, validosT);
    if(validosT == 0){
        printf("No se encontraron tickets dados de baja.\n");
    }
}

/// muestra archivo completo ///

void mostrarOrdenAlfabT()
{
    stTickets *arrDinT;
    int validosT=0;
    validosT= ArchivoToArregloTicket(&arrDinT, validosT);
    //printf("LISTA DE CLIENTES ORDENADOS:\n");
    ordenamientoSeleccionTicket(arrDinT, validosT);
    MostrarArregloTicket(arrDinT, validosT);
    if(validosT == 0){
        printf("No se encontraron tickets.\n");
    }
}

void mostrarOrdenIDT()
{

    stTickets* arrDinT;
    int validosT=0;
    validosT=ArchivoToArregloTicket(&arrDinT, validosT);
    ordenamientoInserccionTicket(arrDinT, validosT);
    MostrarArregloTicket(arrDinT, validosT);
    if(validosT == 0){
            printf("No se encontraron tickets.\n");
        }
}

///calcular registros/////////////////////////////

int calcularRegistrosT()
{
    int cant=0;

    FILE *buf;
    buf = fopen(archVentas, "rb");

    if(buf){
        fseek(buf, 0, 2);

        cant = ftell(buf)/ sizeof(stTickets);

    fclose(buf);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

int calcularRegistrosActivosT()
{

    int cant = 0;
    stTickets A;

    FILE *buf;
    buf = fopen(archVentas, "rb");

    if(buf){
        while(fread(&A, sizeof(stTickets), 1, buf))
        {
            if(A.estado == 1){
                cant++;
            }
        }

    fclose(buf);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

int calcularRegistrosInactivosT()
{

    int cant = 0;
    stTickets A;

    FILE *buf;
    buf = fopen(archVentas, "rb");

    if(buf){
        while(fread(&A, sizeof(stTickets), 1, buf))
        {
            if(A.estado == 0){
                cant++;
            }
        }

    fclose(buf);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

///pasar de archivo a arreglo////////////////////

int ArchivoToArregloTicket(stTickets** arrD, int validosT){

    FILE* buf;
    stTickets A;

    int cantRegistrosT = calcularRegistrosT();

    *arrD = (stTickets*)malloc(sizeof(stTickets)*cantRegistrosT);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validosT;
    }

    buf = fopen(archVentas, "rb");

    if (buf){
        while(fread(&A, sizeof(stTickets), 1, buf) > 0 && validosT < cantRegistrosT){
            (*arrD)[validosT] = A;
            validosT++;
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validosT;
}

int ArchivoToArregloTicketActivo(stTickets** arrD, int validosT)
{

    FILE* buf;
    stTickets A;

    int cantRegistrosT = calcularRegistrosActivosT();

    *arrD = (stTickets*)malloc(sizeof(stTickets)*cantRegistrosT);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validosT;
    }

    buf = fopen(archVentas, "rb");

    if (buf){
        while(fread(&A, sizeof(stTickets), 1, buf) > 0 && validosT < cantRegistrosT){
            if(A.estado == 1)
                {
                   (*arrD)[validosT] = A;
                   validosT++;

                }
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validosT;
}

int ArchivoToArregloBajaTicket(stTickets** arrD, int validosT)
{

    FILE* buf;
    stTickets A;

    int cantRegistrosT = calcularRegistrosInactivosT();

    *arrD = (stTickets*)malloc(sizeof(stTickets)*cantRegistrosT);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validosT;
    }

    buf = fopen(archVentas, "rb");

    if (buf){
        while(fread(&A, sizeof(stTickets), 1, buf) > 0 && validosT < cantRegistrosT){
            if(A.estado == 0)
                {
                    (*arrD)[validosT] = A;
                     validosT++;
                }
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validosT;
}

///ordenar arreglo/////////////////////////////////

void ordenarArrDinamicoTickets (stTickets** arrDinT, int validosT){

    ordenamientoSeleccionTicket(*arrDinT, validosT);

}
///mostrar arreglo/////////////////////////////////////////////////

void MostrarArregloTicket(stTickets A[], int validosT){

int i;

for(i=0; i<validosT; i++){
    MostrarTicket(A[i]);
    }
}

int generarIdRandom (){

    FILE* buf;
    buf=fopen(archVentas, "rb");
    stTickets A;
    int idRandom, flag=0;
    srand(time(NULL));


    if(buf){
        do{
        int min=10000, max=99999;
        idRandom = rand()%(max-min+1)+min;
        rewind(buf);
         while(fread(&A, sizeof(stTickets), 1, buf)>0 && flag==0){
            if(A.id!=idRandom){
                flag=1;
            }
        }}while(flag!=1);
        fclose(buf);
    }

    return idRandom;
}

/// Cargar un Ticket

stTickets CargarTicket()
{
    stTickets A;
    char dni[10];
    int flag=0, flag1=0, flagC=0, flagE=0;

    system("cls");

    printf("CARGANDO LA VENTA....\n\n");

    printf("Ingrese el cargo por servicio : ");
    scanf("%i", &A.monto);

    printf("\n");

    printf("Ingrese la fecha de la venta:\n");
    while(flag!=1){
        printf("Dia:");
        scanf("%d", &A.dia.dia);
        flag=validarDiaFecha(A.dia.dia);
        if(flag!=1){
            printf("Dia invalido. Vuelva a ingresar una fecha valida.\n");
        }
    }

    while(flag1!=1){
        printf("Mes:");
        scanf("%d", &A.dia.mes);
        flag1=validarMesFecha(A.dia.mes);
        if(flag1!=1){
            printf("Mes invalido. Vuelva a ingresar un mes valido.\n");
        }
    }

    printf("Anio:");
    scanf("%i", &A.dia.anio);

    printf("\n");

    while(flagC==0){
        printf("Ingrese el DNI del cliente: ");
        fflush(stdin);
        gets(dni);
        flagC=validarExistenciaCliente(dni);
        if(flagC==0){
            printf("DNI invalido, vuelva a cargarlo.\n");
        }else{
        strcpy(A.idCliente, dni);
        }
    }

    printf("\n");

    while(flagE==0){
        printf("Ingrese el DNI del empleado: ");
        fflush(stdin);
        gets(dni);
        flagE=validarExistenciaEmpleado(dni);
        if(flagE==0){
            printf("DNI invalido, vuelva a cargarlo.\n");
        }else{
        strcpy(A.idEmpleado, dni);
        }
    }

    printf("\n");

    printf("Ingrese el viaje por ID\n\n");
    int id;
    mostrarArchivoViaje();
    printf("ID: ");
    scanf("%d", &id);
    A.viaje=buscarViajePorID(id);

    printf("\n");

    printf("Ingrese el metodo de pago: ");
    fflush(stdin);
    gets(A.metodo);

    A.estado=1;

    int idR=generarIdRandom();
    A.id=idR;

    return A;
}

void cargarArchivoVentas()
{
    stTickets A;
    char control = 's';

    FILE* buf;
    buf = fopen(archVentas, "ab");

    if(buf){

        while(control == 's')
        {
            A = CargarTicket();

            fwrite(&A, sizeof(stTickets), 1, buf);
            system("pause");
            system("cls");
            printf("Ticket cargado exitosamente.\n");
            MostrarTicket(A);

            system("pause");
            system("cls");

            printf("¿Quiere seguir cargando Tickets?\n");
            fflush(stdin);
            scanf("%c", &control);
        }

        fclose(buf);


    }else{
        printf("El archivo no pudo abrirse\n");
    }
}

///MOSTRAR TICKET///

void MostrarTicket(stTickets A)
{
    int Cargos;
    printf("\n");
    printf("-----------------------------------------\n");
    printf("               CODETRAVEL             \n");
    printf("EXPEDIDO EN: LOCAL PRINCIPAL\n");
    printf("DIREC: Av. Dorrego 281\n");
    printf("TEL: 4810000\n");
    printf("EMAIL: codetravel@gmail.com\n");
    printf("\n");

    printf("                         Ticket: # %i\n", A.id);
    printf("****************************************\n");
    printf("\n");
    printf("DNI DEL EMPLEADO: %s.\n", A.idEmpleado);
    printf("DNI DEL CLIENTE: %s.\n", A.idCliente);
    printf("\n");
    printf("FECHA: %d/%d/%d\n", A.dia.dia, A.dia.mes, A.dia.anio);
    printf("****************************************\n");
    printf("DETALLE VIAJE:\n");
    printf("****************************************\n");
    mostrarViaje(A.viaje);
    printf("-----------------------------------------\n");
    printf("-----------------------------------------\n");

    printf("            SUBTOTAL: $%i.\n", A.viaje.precio);
    printf("            VALOR AGREGADO:$%i.\n", A.monto);
    Cargos=A.monto+A.viaje.precio;
    printf("            TOTAL:$%i.\n", Cargos);

    printf("\n            %s $%i.\n", A.metodo, Cargos);
    printf("-----------------------------------------\n");
    printf("\n");

}

///Mostrar Archivo Ventas

void mostrarArchivoVentas()
{
    stTickets A;

    FILE* buff;
    buff = fopen(archVentas, "rb");

    if(buff)
    {
        while(fread(&A, sizeof(stTickets), 1, buff)>0)
        {
            MostrarTicket(A);
        }
        fclose(buff);
    }
    else
    {
        printf("El archivo no pudo abrirse\n");
    }
}

///MODIFICAR VENTA//////////////////////////////////////////////////////////////////////////////////////////////////////
void modificarVenta(int id)
{

    stTickets aux;
    int flag = 0;
    int pos=0;

    FILE* buf;
    buf = fopen(archVentas, "r+b");

    if(buf){
        while((fread(&aux, sizeof(stTickets), 1, buf)>0)&& flag==0){
            if(aux.id == id){
                flag = 1;
            }else{
                pos++;
            }
        }
        fseek(buf, sizeof(stTickets) * pos, SEEK_SET);
        fread(&aux, sizeof(stTickets), 1, buf);

        aux = modificarDatosTicket(aux);

        fseek(buf, sizeof(stTickets)* (-1), SEEK_CUR);
        fwrite(&aux, sizeof(stTickets), 1, buf);
        fclose(buf);
    }
}

stTickets modificarDatosTicket(stTickets aux)
{

    int op=0;
        do{
        printf("\nQue desea modificar?\n\n");
        printf("1. Valor agregado.\n");
        printf("2. Fecha.\n");
        printf("3. DNI del cliente.\n");
        printf("4. DNI del empleado.\n");
        printf("5. Viaje.\n");
        printf("6. Metodo de pago.\n");
        printf("7. ID.\n");
        printf("8. Salir.\n");
        scanf("%i", &op);
        switch(op){
    case 1:
        aux = ModificarMontoTicket(aux);
        break;
    case 2:
        aux=ModificarFechaTicket(aux);
        break;
    case 3:
        aux=ModificarIdDelClienteEnTicket(aux);
        break;
    case 4:
        aux=ModificarIdDelEmpleadoEnTicket(aux);
        break;
    case 5:
        aux=modificarViajeT(aux);
        break;
    case 6:
        aux=ModificarMetodoDePago(aux);
        break;
    case 7:
        aux=ModificarIdTicket(aux);
    case 8:
        system("cls");
        break;
    default:
        printf("No existe la opcion.\n");
        break;
        }}while(op!=8);

        printf("Asi quedo modificado el ticket: \n");
        MostrarTicket(aux);
        system("pause");
        system("cls");

        return aux;
}

stTickets ModificarMetodoDePago(stTickets A)
{
    printf("Ingrese el nuevo metodo de pago: ");
    fflush(stdin);
    gets(A.metodo);

    return A;
}

stTickets ModificarMontoTicket(stTickets A)
{
    printf("Ingrese el nuevo monto del ticket: ");
    scanf("%d", &A.monto);

    return A;
}

stTickets ModificarFechaTicket (stTickets A){

    printf("Ingrese la fecha para modificar la anterior:\n");
    printf("Dia:");
    scanf("%d", &A.dia.dia);
    printf("Mes:");
    scanf("%d", &A.dia.mes);
    printf("Anio:");
    scanf("%d", &A.dia.anio);

    return A;

}

stTickets ModificarIdDelClienteEnTicket(stTickets A)
{
    printf("Ingresar el nuevo DNI del cliente: ");
    fflush(stdin);
    gets(A.idCliente);

    return A;
}

stTickets ModificarIdTicket(stTickets A)
{
    int idRandom;
    idRandom=generarIdRandom();
    A.id=idRandom;

    return A;
}

stTickets ModificarIdDelEmpleadoEnTicket(stTickets A)
{
    printf("Ingrese el nuevo DNI del empleado: ");
    fflush(stdin);
    gets(A.idEmpleado);

    return A;
}

stTickets modificarViajeT(stTickets A)
{
    int id;

    printf("Ingrese el ID del viaje que desea encontrar.\n");
    fflush(stdin);
    scanf("%d", &id);

    A.viaje = buscarViajePorID(id);

    return A;
}

///Dar Baja Venta//////////////////////////////////////////////////////////////////////////////////////////////////////////

void darBajaVenta(int idTicket)
{
    stTickets aux;
    int flag = 0;
    int pos=0;

    FILE* buf;
    buf = fopen(archVentas, "r+b");

    if(buf){
        while((fread(&aux, sizeof(stTickets), 1, buf)>0)&& flag==0){
            if(aux.id == idTicket){
                flag = 1;
            }else{
                pos++;
            }
        }
        fseek(buf, sizeof(stTickets) * pos, SEEK_SET);
        fread(&aux, sizeof(stTickets), 1, buf);

        aux = darBajaT(aux);

        fseek(buf, sizeof(stTickets)* (-1), SEEK_CUR);
        fwrite(&aux, sizeof(stTickets), 1, buf);
        fclose(buf);
    }
}

stTickets darBajaT(stTickets aux)
{

    char control = 's';

        printf("Desea dar de baja esta venta?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux.estado = 0;
        }

        printf("El ticket esta siendo dado de baja...\n");

        return aux;
}

///BUSCAR VENTA///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void encontrarVentaId(int id)
{
stTickets A;
int flag = 0;

FILE *buff;
buff = fopen(archVentas, "rb");

if(buff){
       while(fread(&A, sizeof(stTickets), 1, buff)>0 && flag == 0)
        {
            if(A.id == id)
            {
                    flag = 1;
                    MostrarTicket(A);
            }
        }
    fclose(buff);
    if (flag == 0) {
            printf("La ID ingresada no fue encontrada\n");
        }
    }else{
    printf("El archivo no se pudo abrir\n");
    }
}

///Encontrar Venta por idCliente///////////

void encontrarVentaDNIC(char dniC[])
{
stTickets A;
int flag = 0;

FILE *buf;
buf = fopen(archVentas, "rb");

if(buf){
       while(fread(&A, sizeof(stTickets), 1, buf)>0)
        {
            if(strcmpi(A.idCliente, dniC) == 0)
                {
                    flag = 1;
                    MostrarTicket(A);
                }
        }

    fclose(buf);
    if (flag == 0) {
            printf("El DNI ingresado no fue encontrado\n");
    }
}
else{
    printf("El archivo no se pudo abrir\n");
}
}

///FILTRAR VENTAS/////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Filtrar Venta por Empleado

void filtrarVentaEmpleado(char dniE[])
{
stTickets A;
int encontrado = 0;

FILE *buff;
buff = fopen(archVentas, "rb");

if(buff){
       while(fread(&A, sizeof(stTickets), 1, buff)>0)
        {
           if(strcmpi(A.idEmpleado, dniE) == 0)
                {
                    MostrarTicket(A);
                    encontrado=1;
                }
        }
        fclose(buff);
        if (!encontrado){
            printf("El DNI ingresado no fue encontrado\n");
        }
}
    else{
        printf("El archivo no se pudo abrir\n");
    }
}

///Filtrar Ventas por metodo de pago

void filtrarVentaMetodo(char met[])
{
stTickets A;
int encontrado=0;
FILE *buff;
buff = fopen(archVentas, "rb");

if(buff){
       while(fread(&A, sizeof(stTickets), 1, buff)>0)
        {
            if(strcmpi(A.metodo, met) == 0)
                {
                    MostrarTicket(A);
                    encontrado=1;
                }
        }
        fclose(buff);
        if (!encontrado){
            printf("El metodo ingresado no fue encontrado\n");
        }
}else{
        printf("El archivo no se pudo abrir\n");
    }
}

///Filtrar venta por Viaje

void filtrarVentaViaje(int ID)
{
stTickets A;
int encontrado=0;
FILE *buff;
buff = fopen(archVentas, "rb");

if(buff){
       while(fread(&A, sizeof(stTickets), 1, buff)>0)
        {
           if(A.viaje.id == ID)
                {
                    MostrarTicket(A);
                    encontrado=1;
                }
        }
        fclose(buff);
        if (!encontrado){
            printf("El ID ingresado no fue encontrado\n");
        }
    }
    else{
        printf("El archivo no se pudo abrir\n");
    }
}

int cargarArregloEstatico(int A[], int dim, int validos)
{
stTickets aux;

FILE *buff;
buff = fopen(archVentas, "rb");

if(buff){
       while(fread(&aux, sizeof(stTickets), 1, buff)>0 && validos<dim)
        {
           if(aux.estado == 1)
                {
                   A[validos]= aux.monto + aux.viaje.precio;
                   validos++;
                }
        }
        fclose(buff);
    }
    else{
        printf("El archivo no se pudo abrir\n");
    }
    return validos;
}

float sumarVentas(int A[], int validos)
{
int i;
float suma = 0;

for(i=0; i<validos; i++){
    suma = suma + A[i];
}
return suma;
}

void mostrarCalculo()
{
    int dim = calcularRegistrosActivosT();

    int A[dim];

    int validos;

    validos = cargarArregloEstatico(A, dim, 0);

    float suma= sumarVentas(A, validos);

    printf("\nLa recaudacion total de las ventas es: $%.2f\n\n", suma);
}

void mostrarGanancias()
{
    int dim = calcularRegistrosActivosT();
    float total;

    int A[dim];

    int validos;

    validos = cargarArregloEstatico(A, dim, 0);

    float suma= sumarVentas(A, validos);

    Pila p;
    inicpila(&p);
    ArchivoToPilaEmpleados(&p);
    float rta= sumarSueldos(p);

    total= suma-rta;

    printf("\nLas ganancias obtenidas son: $%.2f\n\n", total);
}

///Filtrar Cliente por Viaje

void filtrarClienteViaje(int id)
{

stTickets A;

FILE *buf;
buf = fopen(archVentas, "rb");
int flag =0;

if(buf){
          while(fread(&A, sizeof(stTickets), 1, buf)> 0)
          {
            if(A.viaje.id == id)
                {
                    flag = 1;
                    encontrarClienteDni(A.idCliente);
                }
          }

    fclose(buf);
    if (flag == 0){
            printf("El ID ingresado no fue encontrado\n");
        }
}
else{
    printf("El archivo no se pudo abrir\n");
}
}
