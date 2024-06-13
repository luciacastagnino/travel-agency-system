#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#include "viajes.h"
#include "ordenamientos.h"
#include "validaciones.h"

///VIAJES EN ORDEN///////////////////////////////////////////////////////////////////////////////////////////////////////////
///calcular registros//////////////

int calcularRegistrosV(){

    int cant=0;

    FILE *buf;
    buf = fopen(archViaje, "rb");

    if(buf){
        fseek(buf, 0, 2);

        cant = ftell(buf)/ sizeof(stViaje);

    fclose(buf);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

int calcularRegistrosActivosV()
{

    int cant = 0;
    stViaje A;

    FILE *buff;
    buff = fopen(archViaje, "rb");

    if(buff){
        while(fread(&A, sizeof(stViaje), 1, buff))
        {
            if(A.estado == 1){
                cant++;
            }
        }

    fclose(buff);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

int calcularRegistrosInactivosV()
{
    int cant = 0;
    stViaje A;

    FILE *buff;
    buff = fopen(archViaje, "rb");

    if(buff){
        while(fread(&A, sizeof(stViaje), 1, buff))
        {
            if(A.estado == 0)
            {
                cant++;
            }
        }

    fclose(buff);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

///pasar de archivo a arreglo/////////////////
int ArchivoToArregloViaje (stViaje** arrD, int validos)
{

    FILE* bufViaje;
    stViaje A;

    int cantRegistrosV = calcularRegistrosV();

    *arrD = (stViaje*)malloc(sizeof(stViaje)*cantRegistrosV);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    bufViaje = fopen(archViaje, "rb");

    if (bufViaje){
        while(fread(&A, sizeof(stViaje), 1, bufViaje) > 0 && validos < cantRegistrosV){
            (*arrD)[validos] = A;
            validos++;
        }
        fclose(bufViaje);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validos;
}

int ArchivoToArregloViajeActivo(stViaje** arrD, int validos)
{

    FILE* bufViaje;
    stViaje A;

    int cantRegistrosV = calcularRegistrosActivosV();

    *arrD = (stViaje*)malloc(sizeof(stViaje)*cantRegistrosV);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    bufViaje = fopen(archViaje, "rb");

    if (bufViaje){
        while(fread(&A, sizeof(stViaje), 1, bufViaje) > 0 && validos < cantRegistrosV){
            if(A.estado == 1)
                {
                    (*arrD)[validos] = A;
                     validos++;
                }
        }
        fclose(bufViaje);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validos;
}

int ArchivoToArregloViajeInactivo(stViaje** arrD, int validos)
{

    FILE* bufViaje;
    stViaje A;

    int cantRegistrosV = calcularRegistrosInactivosV();

    *arrD = (stViaje*)malloc(sizeof(stViaje)*cantRegistrosV);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    bufViaje = fopen(archViaje, "rb");

    if (bufViaje){
        while(fread(&A, sizeof(stViaje), 1, bufViaje) > 0 && validos < cantRegistrosV){
            if(A.estado == 0)
                {
                    (*arrD)[validos] = A;
                     validos++;
                }
        }
        fclose(bufViaje);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validos;
}

///ordenar arreglo///
void ordenarArrDinamicoViaje (stViaje** arrD, int validos){

    ordenamientoInserccion(*arrD, validos);
    MostrarArregloViaje(*arrD, validos);

}

///mostrar arreglo///
void MostrarArregloViaje(stViaje A[], int validos){

    int i;

    for(i=0; i<validos; i++){
        mostrarViaje(A[i]);

    }
}
///mostrar completo
void mostrarOrdenIDV(){

        stViaje *arrDinV;
        int validosV=0;
        validosV=ArchivoToArregloViaje(&arrDinV, validosV);
        //printf("LISTA DE VIAJES ORDENADOS: \n");
        ordenamientoInserccion(arrDinV, validosV);
        MostrarArregloViaje(arrDinV, validosV);

        if(validosV == 0){
            printf("No se encontraron viajes\n");
        }
}

void mostrarOrdenDestinoV(){

    stViaje *arrDinV;
    int validosV=0;
    validosV=ArchivoToArregloViaje(&arrDinV, validosV);
    ordenamientoSeleccionViaje(arrDinV, validosV);
    MostrarArregloViaje(arrDinV, validosV);

    if(validosV == 0){
            printf("No se encontraron viajes\n");
        }

}

///mostrar activos
void mostrarOrdenIDActivosV()
{

        stViaje *arrDinV;
        int validosV=0;
        validosV=ArchivoToArregloViajeActivo(&arrDinV, validosV);
        //printf("LISTA DE VIAJES ORDENADOS: \n");
        ordenamientoInserccion(arrDinV, validosV);
        MostrarArregloViaje(arrDinV, validosV);

        if(validosV == 0){
            printf("No hay viajes activos\n");
        }
}

void mostrarOrdenDestinoActivosV(){

    stViaje *arrDinV;
    int validosV=0;
    validosV = ArchivoToArregloViajeActivo(&arrDinV, validosV);
    ordenamientoSeleccionViaje(arrDinV, validosV);
    MostrarArregloViaje(arrDinV, validosV);

    if(validosV == 0){
            printf("No hay viajes activos\n");
        }

}

///mostrar baja
void mostrarOrdenIDBajaV()
{

        stViaje *arrDinV;
        int validosV=0;
        validosV=ArchivoToArregloViajeInactivo(&arrDinV, validosV);
        //printf("LISTA DE VIAJES ORDENADOS: \n");
        ordenamientoInserccion(arrDinV, validosV);
        MostrarArregloViaje(arrDinV, validosV);

        if(validosV == 0){
            printf("No hay viajes dados de baja\n");
        }
}

void mostrarOrdenDestinoBajaV(){

    stViaje *arrDinV;
    int validosV=0;
    validosV=ArchivoToArregloViajeInactivo(&arrDinV, validosV);
    ordenamientoSeleccionViaje(arrDinV, validosV);
    MostrarArregloViaje(arrDinV, validosV);

    if(validosV == 0){
            printf("No hay viajes dados de baja\n");
        }
}

///Cargar Viaje/////////////////////////////////////////////////////////////////////////////////////////////////////////////

stViaje cargarViaje()
{
    stViaje A;
    int flag=0, flag1=0, flagr=0, flagr1=0;

    system ("cls");
    printf("CARGANDO VIAJE...\n\n");

    do {
        printf("Ingrese el ID del viaje\n");
        fflush(stdin);
        scanf("%d", &A.id);

        if (verificarIDViaje(A.id)) {
            printf("El ID del viaje ya existe. Ingrese un ID diferente:\n");
        }
    }while (verificarIDViaje(A.id));

    printf("\n");

    printf("Ingrese el destino\n");
    fflush(stdin);
    gets(A.destino);

    printf("\n");

    printf("Ingrese la fecha de partida:\n");
    while(flag!=1){
        printf("Dia:");
        scanf("%d", &A.fechaP.dia);
        flag= validarDiaFecha(A.fechaP.dia);
        if(flag!=1){
            printf("Dia invalido. Vuelva a ingresar una fecha valida.\n");
        }
    }

    while(flag1!=1){
        printf("Mes:");
        scanf("%d", &A.fechaP.mes);
        flag1= validarMesFecha(A.fechaP.mes);
        if(flag1!=1){
            printf("Mes invalido. Vuelva a ingresar un mes valido.\n");
        }
    }

    printf("Anio:");
    scanf("%i", &A.fechaP.anio);

    printf("\n");

    printf("Ingrese la fecha de regreso:\n");
        while(flagr!=1){
        printf("Dia:");
        scanf("%d", &A.fechaR.dia);
        flagr=validarDiaFecha(A.fechaR.dia);
        if(flagr!=1){
            printf("Dia invalido. Vuelva a ingresar una fecha valida.\n");
        }
    }

    while(flagr1!=1){
        printf("Mes:");
        scanf("%d", &A.fechaR.mes);
        flagr1=validarMesFecha(A.fechaR.mes);
        if(flagr1!=1){
            printf("Mes invalido. Vuelva a ingresar un mes valido.\n");
        }
    }

    printf("Anio:");
    scanf("%i", &A.fechaR.anio);

    printf("\n");

    printf("Ingrese la duracion del viaje (dias):\n");
    scanf("%d", &A.duracion);

    printf("\n");

    printf("Ingrese el transporte\n");
    fflush(stdin);
    gets(A.transporte);

    printf("\n");

    printf("Ingrese el precio del viaje:\n");
    fflush(stdin);
    scanf("%d", &A.precio);

    A.estado = 1;

    return A;
}

void cargarArchivoViaje()
{
    stViaje A;
    char control = 's';

    FILE* bufViaje;
    bufViaje = fopen(archViaje, "ab");

    if(bufViaje)
    {
        while(control == 's')
        {
            A = cargarViaje();

            fwrite(&A, sizeof(stViaje), 1, bufViaje);

            printf("¿Quiere seguir cargando viajes?\n");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(bufViaje);
    }
    else
    {
        printf("El archivo no pudo abrirse\n");
    }
}

///Mostrar Viaje/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarViaje(stViaje A)
{
    printf("\n");
    printf("ID: %d\n", A.id);
    printf("Destino: %s\n", A.destino);
    printf("Fecha de partida: %d/%d/%d\n", A.fechaP.dia, A.fechaP.mes, A.fechaP.anio);
    printf("Fecha de regreso: %d/%d/%d\n", A.fechaR.dia, A.fechaR.mes, A.fechaR.anio);
    printf("Duracion: %d dias\n", A.duracion);
    printf("Transporte: %s\n", A.transporte);
    printf("Precio: $%d\n", A.precio);
    printf("\n");
}

///Mostrar Archivo Viaje

void mostrarArchivoViaje()
{
    stViaje A;

    FILE* buff;
    buff = fopen(archViaje, "rb");

    if(buff)
    {
        while(fread(&A, sizeof(stViaje), 1, buff))
        {

            mostrarViaje(A);
            printf("\n");
        }
        fclose(buff);
    }
    else
    {
        printf("El archivo no pudo abrirse\n");
    }
}


/// Modificar Viaje

void modificarViaje (int id){

    stViaje aux;
    int flag = 0;
    int pos=0;

    FILE* buf;
    buf = fopen(archViaje, "r+b");

    if(buf){
        while((fread(&aux, sizeof(stViaje), 1, buf)>0)&& flag==0){
            if(aux.id == id){
                flag = 1;
            }else{
                pos++;
            }
        }
        fseek(buf, sizeof(stViaje) * pos, SEEK_SET);
        fread(&aux, sizeof(stViaje), 1, buf);

        aux = modificarDatosViaje(aux);

        fseek(buf, sizeof(stViaje)* (-1), SEEK_CUR);
        fwrite(&aux, sizeof(stViaje), 1, buf);
        fclose(buf);
    }
}

stViaje modificarDatosViaje(stViaje aux)
{

        int op=0;

        mostrarViaje(aux);

        do{

        printf("\nQue desea modificar?\n\n");
        printf("1. ID.\n");
        printf("2. Destino.\n");
        printf("3. Fecha de partida.\n");
        printf("4. Fecha de regreso.\n");
        printf("5. Duracion.\n");
        printf("6. Transporte.\n");
        printf("7. Precio.\n");
        printf("8. Salir.\n");
        scanf("%i", &op);
        system("pause");
        system("cls");
        switch(op){
    case 1:
        do {

            do {
                aux = modificarIdV(aux);
                if (verificarIDViaje(aux.id)) {
                    printf("El ID del viaje ya existe. Ingrese un ID diferente:\n");
                }
            } while (verificarIDViaje(aux.id));

        }while (verificarIDViaje(aux.id));
        break;
    case 2:
        aux = modificarDestinoV(aux);
        break;
    case 3:
        aux=modificarFechaPartidaV(aux);
        break;
    case 4:
        aux=modificarFechaRegresoV(aux);
        break;
    case 5:
        aux = modificarDuracionV(aux);
        break;
    case 6:
        aux = modificarTransporteV(aux);
        break;
    case 7:
        aux = modificarPrecioV(aux);
    case 8:
        system("cls");
        break;
    default:
        printf("No existe la opcion.\n");
        break;
        }}while(op!=8);

        printf("Asi quedo modificado el viaje: \n");
        mostrarViaje(aux);
        system("pause");
        system("cls");

        return aux;
}

stViaje modificarIdV(stViaje A)
{
    printf("Ingrese la id para modificar la anterior: \n");
	fflush(stdin);
	scanf("%d", &A.id);

	return A;
}

stViaje modificarDestinoV(stViaje A)
{
    printf("Ingrese el destino para modificar el anterior: \n");
	fflush(stdin);
	gets(A.destino);

	return A;
}

stViaje modificarFechaPartidaV (stViaje A){

    printf("Ingrese la fecha de partida para modificar la anterior:\n");
    printf("Dia:");
    scanf("%d", &A.fechaP.dia);
    printf("Mes:");
    scanf("%d", &A.fechaP.mes);
    printf("Anio:");
    scanf("%d", &A.fechaP.anio);

    return A;

}

stViaje modificarFechaRegresoV (stViaje A){

    printf("Ingrese la fecha de regreso para modificar la anterior:\n");
    printf("Dia:");
    scanf("%d", &A.fechaR.dia);
    printf("Mes:");
    scanf("%d", &A.fechaR.mes);
    printf("Anio:");
    scanf("%d", &A.fechaR.anio);

    return A;

}

stViaje modificarDuracionV(stViaje A)
{
    printf("Ingrese la duracion para modificar la anterior: \n");
	fflush(stdin);
	scanf("%d", &A.duracion);

	return A;
}

stViaje modificarTransporteV(stViaje A)
{
    printf("Ingrese el transporte para modificar el anterior: \n");
	fflush(stdin);
	gets(A.transporte);

	return A;
}

stViaje modificarPrecioV(stViaje A)
{
    printf("Ingrese el precio para modificar el anterior: \n");
	fflush(stdin);
	scanf("%d", &A.precio);

	return A;
}

///Dar Baja Viaje/////////////////////////////////////////////////////////////////////////////////////////////////////////////


void darDeBajaViaje (int id)
{
    stViaje aux;
    int flag = 0;
    int pos=0;

    FILE* buf;
    buf = fopen(archViaje, "r+b");

    if(buf){
        while((fread(&aux, sizeof(stViaje), 1, buf)>0)&& flag==0){
            if(aux.id == id){
                flag = 1;
            }else{
                pos++;
            }
        }

        fseek(buf, sizeof(stViaje) * pos, SEEK_SET);
        fread(&aux, sizeof(stViaje), 1, buf);

        aux = darBajaVJ(aux);

        fseek(buf, sizeof(stViaje)* (-1), SEEK_CUR);
        fwrite(&aux, sizeof(stViaje), 1, buf);

        fclose(buf);
    }

}

stViaje darBajaVJ(stViaje aux)
{

       char control = 's';

        printf("¿Desea dar de baja este viaje?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux.estado = 0;
        }

        printf("El viaje esta siendo dado de baja...\n");

        return aux;
}


///BUSCAR VIAJE///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//void encontrarViajeId(int id)
//{
//stViaje A;
//int flag = 0;
//
//FILE *bufViaje;
//bufViaje = fopen(archViaje, "rb");
//
//if(bufViaje){
//       while((fread(&A, sizeof(stViaje), 1, bufViaje)>0) && (flag == 0))
//        {
//            if(A.id == id)
//                {
//                    flag = 1;
//                    mostrarViaje(A);
//                }
//        }
//
//    fclose(bufViaje);
//}
//else{
//    printf("El archivo no se pudo abrir\n");
//}
////return A;
//}

///FILTRAR VIAJES///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Filtrar Viaje por Transporte

void filtrarViajeTransporte(char T[10]){
    stViaje A;
    int encontrado = 0;
    FILE *buff = fopen(archViaje, "rb");

    if (buff) {
        while (fread(&A, sizeof(stViaje), 1, buff)>0) {
            if (strcmpi(A.transporte, T) == 0) {
                mostrarViaje(A);
                encontrado = 1;
            }
        }
        fclose(buff);
        if (!encontrado) {
            printf("No se encontraron viajes que utilizaran el transporte %s\n", T);
        }
    } else {
        printf("El archivo de viajes no se pudo abrir\n");
    }
}

///Filtrar Viaje por Destino

void filtrarViajeDestino(char D[10]){
    stViaje A;
    int encontrado = 0;
    FILE *buff = fopen(archViaje, "rb");

    if (buff) {
        while (fread(&A, sizeof(stViaje), 1, buff)>0) {
            if (strcmpi(A.destino, D) == 0) {
                mostrarViaje(A);
                encontrado = 1;
            }
        }
        fclose(buff);
        if (!encontrado) {
            printf("No se encontraron viajes que viajen al destino %s\n", D);
        }
    } else {
        printf("El archivo de viajes no se pudo abrir\n");
    }
}

///Filtrar viaje por Estado

void filtrarViajeEstado(int E)
{
stViaje A;
int encontrado=0;
FILE *buff;
buff = fopen(archViaje, "rb");

if(buff){
       while(fread(&A, sizeof(stViaje), 1, buff)>0)
        {
            if(A.estado == E)
                {
                    mostrarViaje(A);
                    encontrado=1;
                }
        }
        fclose(buff);
     if (!encontrado){
            printf("El estado ingresado no fue encontrado\n");
        }
}
    else{
        printf("El archivo no se pudo abrir\n");
    }
}

///Buscar el ID para cargarlo en el cliente

stViaje buscarViajePorID(int id)
{
    stViaje A;
    int flag = 0;
    FILE *bufViaje = fopen(archViaje, "rb");

    if (bufViaje) {
            while ((fread(&A, sizeof(stViaje), 1, bufViaje)>0) && (flag == 0))
             {
                if (A.id == id)
                {
                    flag = 1;
                    break;
                }
            }

    fclose(bufViaje);
    }
    else{
            printf("El archivo no pudo abrirse\n");
        }

    if (flag == 0) {
            printf("ID de viaje no encontrado. Por favor, ingrese un ID valido:\n");
            scanf("%d", &id);
            return buscarViajePorID(id);
        }

    return A;
}

///Verificar que el ID ingresado no existe

int verificarIDViaje(int id){
    stViaje A;
    int encontrado = 0;

    FILE *bufViaje = fopen(archViaje, "rb");
    if (bufViaje) {
        while (fread(&A, sizeof(stViaje), 1, bufViaje)>0 && !encontrado) {
            if (A.id == id) {
                encontrado = 1;
            }
        }
        fclose(bufViaje);
    }

    return encontrado;
}

///Verificar que el ID ingresado en modificar exista

int verificarIDNoExiste(int id) {
    stViaje A;
    int encontrado = 0;

    FILE *bufViaje = fopen(archViaje, "rb");
    if (bufViaje) {
        while (fread(&A, sizeof(stViaje), 1, bufViaje)>0 && !encontrado) {
            if (A.id == id) {
                encontrado = 1;
            }
        }
        fclose(bufViaje);
    } else {
        printf("No se pudo abrir el archivo\n");
    }

    return !encontrado;
}
