#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "clientes.h"
#include "empleados.h"
#include "viajes.h"
#include "ventas.h"
#include "ordenamientos.h"
#include "calendario.h"


///MENU EMPLEADOS////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menuEmpleados()
{
    int opcion;

    printf("Ingrese una opcion.\n");
    printf("0. Ver la lista de empleados.\n");
    printf("1. Cargar un empleados.\n");
    printf("2. Modificar datos del empleado.\n");
    printf("3. Buscar un empleado\n");
    printf("4. Filtrar empleados\n");
    printf("5. Dar de baja empleado.\n");\
    printf("6. Mostrar empleados dados de baja.\n");

    fflush(stdin);
    scanf("%d", &opcion);
    system("pause");
    system("cls");
    switch(opcion)
    {
    case 0:
        {
            printf("LISTA DE EMPLEADOS\n\n");
            mostrarOrdenE();
            break;
        }

    case 1:
        {
            cargarArchivoEmpleado();
            system("pause");
            system("cls");
            printf("LISTA DE EMPLEADOS\n\n");
            mostrarOrdenEActivo();

            break;
        }
    case 2:
        {
            char nYa[30];
            printf("LISTA DE EMPLEADOS \n\n");
            mostrarOrdenEActivo();

            printf("Ingrese el nombre del empleado a modificar:\n");
            fflush(stdin);
            gets(nYa);

            system("pause");
            system("cls");

            modificarEmpleado(nYa);
            break;
        }
    case 3:
        {
            int opcion;
            printf("Si desea buscar al empleado por nombre y apellido Ingrese 1.\n\n");
            printf("Si desea buscar al empleado por DNI Ingrese 2.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            system("pause");
            system("cls");

            if(opcion==1)
                {
                    char N[30];
                    printf("Ingrese el nombre y apellido del empleado que desea buscar: \n");
                    fflush(stdin);
                    gets(N);
                    encontrarEmpleadoN(N);
                }else{
                    char DNI[10];
                    printf("Ingrese el DNI del empleado que desea buscar: \n");
                    fflush(stdin);
                    gets(DNI);

                    encontrarEmpleadoDni(DNI);
                }
            break;
        }
    case 4:
        {
            int opcion;
            printf("Si desea filtrar el/los empleado/s por el puesto Ingrese 1.\n\n");
            printf("Si desea filtrar el/los empleado/s por el estado Ingrese 2.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);
            system("pause");
            system("cls");
            if(opcion==1){
               char P[20];
               printf("Ingrese el puesto que desea filtrar: \n");
               fflush(stdin);
               gets(P);
               filtrarEmpleadoPuesto(P);
            }else{
                int E;
                printf("Ingrese el estado que desea filtrar (0. Inactivo | 1. Activo): \n");
                fflush(stdin);
                scanf("%d", &E);
                filtrarEmpleadoEstado(E);
            }
            break;
        }
    case 5:
        {

             char nYa[30];

            printf("LISTA DE EMPLEADOS \n\n");
            mostrarOrdenEActivo();

            printf("Ingrese el nombre del empleado a dar de baja:\n");
            fflush(stdin);
            gets(nYa);

            system("pause");
            system("cls");

            darBajaEmpleado(nYa);
           break;
        }
    case 6:
        {
            printf("LISTA DE EMPLEADOS DADOS DE BAJA\n\n");
            mostrarOrdenBajaE();
            break;
        }
    default:
        printf("La opcion no existe.\n");
    }
}

///MENU VIAJES////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuViajes()
{
     int opcion;

    printf("Ingrese una opcion:\n");
    printf("0. Mostrar lista de viajes\n");
    printf("1. Ingresar viaje.\n");
    printf("2. Modificar viaje.\n");
    printf("3. Buscar viaje.\n");
    printf("4. Filtrar viaje.\n");
    printf("5. Dar de baja viaje\n");
    fflush(stdin);
    scanf("%d", &opcion);

    system("pause");
    system("cls");
    switch(opcion)
    {
    case 0:
        {
            printf("LISTA DE VIAJES\n\n");
            //mostrarArchivoViaje();
            mostrarOrdenV();
            break;
        }
    case 1:
        {
            cargarArchivoViaje();
            system("pause");
            system("cls");
            printf("LISTA DE VIAJES\n\n");
            mostrarArchivoViaje();
            mostrarOrdenActivosV();

            break;
        }
    case 2:
        {
            int id;
            printf("LISTA DE VIAJES \n\n");
            //mostrarArchivoViaje();
            mostrarOrdenActivosV();

            printf("Ingrese la ID del viaje a modificar:\n");
            fflush(stdin);
            scanf("%d", &id);

            system("pause");
            system("cls");

            modificarViaje(id);
            break;
        }
    case 3:
        {
            int id;

            printf("Ingrese la ID del viaje que desea buscar: \n");
            fflush(stdin);
            scanf("%d", &id);

            system("pause");
            system("cls");

            encontrarViajeId(id);
            break;
        }
    case 4:
        {
            int opcion;

            printf("Si desea filtrar el/los viaje/s por el destino Ingrese 1.\n\n");
            printf("Si desea filtrar el/los viaje/s por el transporte Ingrese 2.\n\n");
            printf("Si desea filtrar el/los viaje/s por el estado Ingrese 3.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            system("pause");
            system("cls");
            if(opcion==1){
               char P[30];
               printf("Ingrese el destino que desea filtrar: \n");
               fflush(stdin);
               gets(P);
               filtrarViajeDestino(P);
            }
            else if(opcion == 2){
                char T[20];
                printf("Ingrese el transporte que desea filtrar: (Avion | Tren | Micro): \n");
                fflush(stdin);
                gets(T);
                filtrarViajeTransporte(T);
            }
            else if(opcion == 3){
                int E;
                printf("Ingrese el estado que desea filtrar (0. Inactivo | 1. Activo): \n");
                fflush(stdin);
                scanf("%d", &E);
                filtrarViajeEstado(E);
            }
            break;
        }
    case 5:
        {
            int id;

            printf("Ingrese la ID del viaje que desea dar de baja: \n");
            fflush(stdin);
            scanf("%d", &id);

            system("pause");
            system("cls");

            //darBajaVJ(id);
            break;
        }
    case 6:
        {
            printf("LISTA DE VIAJES DADOS DE BAJA\n\n");
            //mostrarOrdenBajaV();
            break;
        }
    case 7:
        {
            int calendario[6][7]; ///Invoco la matriz de calendario///

            char controlCalendario='s';
            while(controlCalendario=='s')  ///While para que el usuario pueda ver mas de un mes si lo desea///
             {
                int calendarioOpciones; ///Sirve para indica que mes desea ver el usuario///
                printf("Ingrese el numero de mes que desea ver: ");
                scanf("%i", &calendarioOpciones);

                CargarCalendario(calendario, calendarioOpciones); ///Invocacion de la funcion cargar el mes (dentro de la funcion se realiza un printf con el mes que se carga///
                MostrarCalendario(calendario);  ///Invocacion de la funcion mostrar mes///

                printf("Desea ver otro mes? s/n"); ///Se le pregunta al usiario si desea continuar viendo otros meses///
                fflush(stdin);
                scanf("%c",&controlCalendario);
             }
        }

    }
}

///MENU VENTAS////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menuVentas()
{
     int opcion;

    printf("Ingrese una opcion:\n");
    printf("0. Mostrar lista de ventas\n");
    printf("1. Ingresar venta.\n");
    printf("2. Modificar venta.\n");
    printf("3. Buscar venta.\n");
    printf("4. Filtrar ventas.\n");
    printf("5. Dar de baja ventas");
    printf("6. Calcular cantidad de ventas que realizo un empleado.\n");
    printf("7. Calcular ganancias.\n");
    fflush(stdin);
    scanf("%d", &opcion);

    system("pause");
    system("cls");
    switch(opcion){}
}

///MENU CLIENTES////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuClientes()
{
    int opcion;

    printf("0. Ver la lista de clientes.\n");
    printf("1. Cargar clientes.\n");
    printf("2. Modificar datos del cliente.\n");
    printf("3. Buscar un cliente.\n");
    printf("4. Filtrar un cliente.\n");
    printf("5. Dar de baja clientes\n");
    printf("6. Mostrar clientes dados de baja\n");
    fflush(stdin);
    scanf("%d", &opcion);
    system("pause");
    system("cls");

    switch(opcion){
        case 0:
        {
            printf("LISTA DE CLIENTES \n\n");
            mostrarOrdenCActivo();
            break;
        }

        case 1:
        {
            cargarArchivoCliente();
            system("pause");
            system("cls");
            mostrarOrdenCActivo();

            ///Cargar clientes tal vez tendria que ser en ventas

            break;
        }
        case 2:
        {
            char nYa[30];
            printf("LISTA DE CLIENTES \n\n");
            mostrarOrdenCActivo();

            printf("Ingrese el nombre del cliente a modificar:\n");
            fflush(stdin);
            gets(nYa);

            system("pause");
            system("cls");

            modificarCliente(nYa);
            break;
        }
        case 3:
        {
            int opcion;
            printf("Si desea buscar al empleado por nombre y apellido Ingrese 1.\n\n");
            printf("Si desea buscar al empleado por DNI Ingrese 2.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);
            if(opcion==1)
                {
                    char N[30];
                    printf("Ingrese el nombre y apellido del cliente que desea buscar: ");
                    fflush(stdin);
                    gets(N);
                    encontrarClienteN(N);
                }else{
                    char DNI[10];
                    printf("Ingrese el DNI del cliente que desea buscar: ");
                    fflush(stdin);
                    gets(DNI);
                    encontrarClienteDni(DNI);
                }
                 break;
        }
        case 4:
        {
            int opcion;
            printf("Si desea filtrar el/los cliente/s por el genero Ingrese 1.\n\n");
            printf("Si desea filtrar el/los empleado/s por el estado Ingrese 2.\n\n");
            printf("Si desea filtrar el/los empleado/s por el viaje Ingrese 3.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            if(opcion==1){
               char G;
               printf("Ingrese el genero que desea filtrar (M o F): ");
               fflush(stdin);
               scanf("%c", &G);
               filtrarClienteGenero(G);
            }else if(opcion == 2){
                int E;
                printf("Ingrese el estado que desea filtrar (0. Inactivo | 1. Activo): ");
                fflush(stdin);
                scanf("%d", &E);
                filtrarClienteEstado(E);
            }else{
                int ID;
                printf("Ingrese el ID que desea filtrar: ");
                fflush(stdin);
                scanf("%d", &ID);
                filtrarClienteViaje(ID);
            }
            break;
        }
        case 5:
        {
            char nYa[30];

            printf("LISTA DE CLIENTES \n\n");
            mostrarOrdenCActivo();

            printf("Ingrese el nombre del cliente a dar de baja:\n");
            fflush(stdin);
            gets(nYa);

            system("pause");
            system("cls");

            darBajaCliente(nYa);
           break;
        }
        case 6:
            {
                printf("LISTA DE CLIENTES DADOS DE BAJA\n\n");
                mostrarOrdenBajaC();
                break;

            }
        default:
            printf("La opcion no existe.\n");
    }
}

