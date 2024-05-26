#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <strings.h>
#include "clientes.h"
#include "viajes.h"
#include "ordenamientos.h"

const char archCliente[] = {"archivoCliente.bin"};

///CLIENTE ORDEN///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarOrdenC()
{
            stCliente *arrDinC;
            int validos=0;
            validos=ArchivoToArregloCliente(&arrDinC, validos);
            //printf("LISTA DE CLIENTES ORDENADOS:\n");
            ordenamientoSeleccionCliente(arrDinC, validos);
            MostrarArreglo(arrDinC, validos);
}

int calcularRegistrosC(){

    int cant=0;

    FILE *buf;
    buf = fopen(archCliente, "rb");

    if(buf){
        fseek(buf, 0, 2);

        cant = ftell(buf)/ sizeof(stCliente);

    fclose(buf);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

int ArchivoToArregloCliente(stCliente** arrD, int validos){

    FILE* buf;
    stCliente A;

    int cantRegistrosC = calcularRegistrosC();

    *arrD = (stCliente*)malloc(sizeof(stCliente)*cantRegistrosC);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    buf = fopen(archCliente, "rb");

    if (buf){
        while(fread(&A, sizeof(stCliente), 1, buf) > 0 && validos < cantRegistrosC){
            (*arrD)[validos] = A;
            validos++;
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validos;
}

void ordenarArrDinamicoClientes (stCliente** arrD, int validos){

    ordenamientoSeleccionCliente(&arrD, validos);

}

void MostrarArreglo(stCliente A[], int validos){

int i;

printf("El contenido del arreglo:\n");

for(i=0; i<validos; i++){
    mostrarCliente(A[i]);
    }
}
///Cargar cliente/////////////////////////////////////////////////////////////////////////////////////////////////////////////

stCliente cargarCliente()
{
    stCliente A;

    printf("Ingrese el nombre y apellido del cliente\n");
    fflush(stdin);
    gets(A.nYa);

    printf("Ingrese la fecha de nacimiento del cliente\n");
    fflush(stdin);
    gets(A.fechaNac);

    printf("Ingrese el genero\n");
    fflush(stdin);
    scanf("%c", &A.genero);

    printf("Ingrese el DNI del cliente\n");
    fflush(stdin);
    gets(A.dni);

    printf("Ingrese el numero de telefono del cliente\n");
    fflush(stdin);
    gets(A.tel);

    printf("Ingrese el domicilio del cliente\n");
    A.dom = cargarDomicilio();

    printf("Ingrese el viaje del cliente por ID\n\n");
    int id;
    mostrarArchivoViaje();
    printf("ID: ");
    scanf("%d", &id);
    A.v=buscarViajePorID(id);

    A.estado=1;

    return A;
}

void cargarArchivoCliente()
{
    stCliente A;
    char control = 's';

    FILE* buf;
    buf = fopen(archCliente, "ab");

    if(buf){

        while(control == 's')
        {
            A = cargarCliente();

            fwrite(&A, sizeof(stCliente), 1, buf);

            printf("¿Quiere seguir cargando clientes?\n");
            fflush(stdin);
            scanf("%c", &control);
        }

        fclose(buf);


    }else{
        printf("El archivo no pudo abrirse\n");
    }
}
///Mostrar Cliente///////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarCliente(stCliente A)
{
    printf("Nombre y Apellido: %s\n", A.nYa);
    printf("Fecha de nacimiento: %s\n", A.fechaNac);
    printf("Genero: %c\n", A.genero);
    printf("DNI: %s\n", A.dni);
    printf("Telefono: %s\n", A.tel);
    mostrarDomicilio(A.dom);
    mostrarViaje(A.v);
    printf("\n");
}

///Mostrar archivo Clientes/////////////////

void mostrarArchivoCliente()
{
    stCliente A;

    FILE* buff;
    buff = fopen(archCliente, "rb");

    if(buff)
    {
        while(fread(&A, sizeof(stCliente), 1, buff))
        {
            mostrarCliente(A);
        }
        fclose(buff);
    }
    else
    {
        printf("El archivo no pudo abrirse\n");
    }
}


///Modificar Cliente///////////////////////////////////////////////////////////////////////////////////////////////////////////
void modificarCliente (char nYa[30]){

    stCliente aux;
    int flag = 0;
    int pos=0;

    FILE* buf;
    buf = fopen(archCliente, "r+b");

    if(buf){
        while((fread(&aux, sizeof(stCliente), 1, buf)>0)&& flag==0){
            if(strcmpi(aux.nYa, nYa) == 0){
                flag = 1;
            }else{
                pos++;
            }
        }
        fseek(buf, sizeof(stCliente) * pos, SEEK_SET);
        fread(&aux, sizeof(stCliente), 1, buf);

        aux = modificarDatosCliente(aux);

        fseek(buf, sizeof(stCliente)* pos, SEEK_CUR);
        fwrite(&aux, sizeof(stCliente), 1, buf);
        fclose(buf);
    }
}

stCliente modificarDatosCliente(stCliente aux)
{

char control = 's';

        printf("1. Desea modificar el Nombre y apellido?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarNyAC(aux);
        }

        printf("2. Desea modificar la Fecha de nacimiento?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarFechaNacC(aux);
        }

        printf("3. Desea modificar el Genero?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarGeneroC(aux);
        }

        printf("4. Desea modificar el DNI?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarDniC(aux);
        }

        printf("5. Desea modificar el Telefono?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarTelC(aux);
        }

        printf("6. Desea mdificar el Domicilio?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarDomicilioC(aux);
        }

        printf("7. Desea modificar el Viaje?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarViajeC(aux);
        }

        printf("Asi quedo modificado el cliente: \n");
        mostrarCliente(aux);
        return aux;
}

stCliente modificarNyAC(stCliente A)
{
    printf("Ingrese el nuevo nombre y apellido:\n");
    fflush(stdin);
    gets(A.nYa);

    return A;
}

stCliente modificarFechaNacC(stCliente A)
{
    printf("Ingrese la nueva fecha de nacimiento:\n");
    fflush(stdin);
    gets(A.fechaNac);

    return A;
}

stCliente modificarGeneroC(stCliente A)
{
    printf("Ingrese el nuevo genero:\n");
    fflush(stdin);
    scanf("%c", &A.genero);

    return A;
}

stCliente modificarDniC(stCliente A)
{
    printf("Ingrese la nueva fecha de nacimiento:\n");
    fflush(stdin);
    gets(A.dni);

    return A;
}

stCliente modificarTelC(stCliente A)
{
    printf("Ingrese la nueva fecha de nacimiento:\n");
    fflush(stdin);
    gets(A.tel);

    return A;
}

stCliente modificarDomicilioC(stCliente A)
{
    A.dom = modificarDomicilio(A.dom);

    return A;
}

stCliente modificarViajeC(stCliente A)
{
    int id;

    printf("Ingrese el ID del viaje que desea encontrar.\n");
    fflush(stdin);
    scanf("%d", &id);

    A.v = encontrarViajeId(id);

    return A;
}

///Dar Baja Cliente//////////////////////////////////////////////////////////////////////////////////////////////////////////
stCliente darBajaCliente (char nYa[]){

    FILE* buf;
    buf = fopen(archCliente, "r+b");
    stCliente cliente;
    int flag=0;

    if(buf){
        while((fread(&cliente, sizeof(stCliente), 1, buf) > 0) && (flag == 0))
        {
            if(strcmp(cliente.nYa, nYa) == 0)
            {
                cliente.estado = 0;
                flag = 1;

                fseek(buf, sizeof(stCliente)*(-1), SEEK_CUR);
                fwrite(&cliente, sizeof(cliente), 1, buf);
            }
        }
        fclose(buf);
    }
   return cliente;
}

///DOMICILIO////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///Cargar Domicilio

stDomicilio cargarDomicilio()
{
    stDomicilio A;

	printf("Ingrese calle: \n");
	fflush(stdin);
	gets(A.calle);

	printf("Ingrese numero de calle: \n");
            fflush(stdin);
	scanf("%i", &A.num);

	printf("Ingrese localidad: \n");
	fflush(stdin);
	gets(A.localidad);

	return A;
	}

///Mostrar Domicilio

void mostrarDomicilio(stDomicilio A)
{
	printf("Calle: %s\n", A.calle);
	printf("Numero de calle: %i\n", A.num);
	printf("Localidad: %s\n", A.localidad);
}

///Modificar Domicilio

stDomicilio modificarDomicilio(stDomicilio A)
{
    char control = 'n';

    printf("Desea cambiar la calle?\n");
    fflush(stdin);
    scanf("%c", &control);

    if(control == 's'){
       	printf("Ingrese la calle para modificar la anterior: \n");
	    fflush(stdin);
	    gets(A.calle);
    }

    printf("Desea cambiar el numero de calle?\n");
    fflush(stdin);
    scanf("%c", &control);

    if(control == 's'){
        printf("Ingrese el numero de calle para modificar la anterior: \n");
	    fflush(stdin);
	    scanf("%i", &A.num);
    }

    printf("Desea cambiar la localidad?\n");
    fflush(stdin);
    scanf("%c", &control);

    if(control == 's'){
    printf("Ingrese la localidad para modificar la anterior: \n");
	fflush(stdin);
	gets(A.localidad);
    }

	return A;
}

///BUSCAR CLIENTE///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void encontrarClienteN(char N[30])
{
stCliente A;
int flag = 0;

FILE *buff;
buff = fopen(archCliente, "rb");

if(buff){
       while(fread(&A, sizeof(stCliente), 1, buff) && flag == 0)
        {
            if(strcmpi(A.nYa, N) ==0)
            {
                    flag = 1;
                    mostrarCliente(A);
            }
        }
    fclose(buff);
    if (flag == 0) {
            printf("El nombre ingresado no fue encontrado\n");
        }
    }else{
    printf("El archivo no se pudo abrir\n");
    }
}

///Encontrar Cliente por DNI///////////
void encontrarClienteDni(char D[10])
{
stCliente A;
int flag = 0;

FILE *buf;
buf = fopen(archCliente, "rb");

if(buf){
       while(fread(&A, sizeof(stCliente), 1, buf) && flag == 0)
        {
            if(strcmpi(A.dni, D) == 0)
                {
                    flag = 1;
                    mostrarCliente(A);
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

///FILTRAR CLIENTES/////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Filtrar Cliente por Genero
void filtrarClienteGenero(char G)
{
stCliente A;
int encontrado = 0;

FILE *buff;
buff = fopen(archCliente, "rb");

if(buff){
       while(fread(&A, sizeof(stCliente), 1, buff))
        {
           if(toupper(A.genero) == toupper(G))
                {
                    mostrarCliente(A);
                    encontrado=1;
                }
        }
        fclose(buff);
        if (!encontrado){
            printf("El genero ingresado no fue encontrado\n");
        }
}
    else{
        printf("El archivo no se pudo abrir\n");
    }
}

///Filtrar Clientes por Estado
void filtrarClienteEstado(int E)
{
stCliente A;
int encontrado=0;
FILE *buff;
buff = fopen(archCliente, "rb");

if(buff){
       while(fread(&A, sizeof(stCliente), 1, buff))
        {
            if(A.estado == E)
                {
                    mostrarCliente(A);
                    encontrado=1;
                }
        }
        fclose(buff);
        if (!encontrado){
            printf("El estado ingresado no fue encontrado\n");
        }
}else{
        printf("El archivo no se pudo abrir\n");
    }
}

///Filtrar Cliente por Viaje
void filtrarClienteViaje(int ID)
{
stCliente A;
int encontrado=0;
FILE *buff;
buff = fopen(archCliente, "rb");

if(buff){
       while(fread(&A, sizeof(stCliente), 1, buff))
        {
           if(A.v.id == ID)
                {
                    mostrarCliente(A);
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


