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
#include "admin.h"
#include "menu.h"


/// MENU ADMIN //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuAdmin(char nYa[]){

    int op=0;

    do{
    printf("MENU PRINCIPAL:\n\n");
    printf("1. Perfil\n");
    printf("2. Gestion de usuarios\n");
    printf("3. Registro\n");
    printf("4. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 1:
    menuPerfilAdmin(nYa);
    break;
case 2:
    menuGestionAdmin();
    break;
case 3:
    menuRegistroAdmin();
    break;
case 4:
    printf("Cerrando sesion...\n");
    system("pause");
    system("cls");
    break;
    }
    }while(op!=4);

}

/// MENU DE GESTION DE USUARIOS //////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuGestionAdmin (){

    int op;
    do{
    printf("MENU DE GESTION DE USUARIOS\n\n");
    printf("1. Empleados\n");
    printf("2. Clientes\n");
    printf("3. Viajes\n");
    printf("4. Ventas\n");
    printf("5. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 1:
    menuGestionEmpleado();
    break;
case 2:
    menuGestionCliente();
    break;
case 3:
    menuGestionViajes();
    break;
case 4:
    menuGestionVentas();
    break;
case 5:
    printf("Volviendo a la pantalla de login/registro...\n");
    system("cls");
    break;
default:
    printf("Opcion incorrecta\n");
    break;
    }}while(op!=5);
}

void menuGestionEmpleado(){

    int op=0, opcion=0;

    do{
    printf("\nIngrese una opcion.\n\n");
    printf("0. Ver la lista de empleados.\n");
    printf("1. Ver lista de empleados activos.\n");
    printf("2. Ver lista de empleados inactivos.\n");
    printf("3. Cargar un empleados.\n");
    printf("4. Modificar datos del empleado.\n");
    printf("5. Buscar un empleado\n");
    printf("6. Filtrar empleados\n");
    printf("7. Dar de baja empleado.\n");
    printf("8. Calcular sueldos\n");
    printf("9. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 0:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por DNI.\n");
            scanf("%i", &opcion);

            system("pause");
            system("cls");

            if(opcion==1){
                printf("LISTA DE EMPLEADOS\n\n");
                mostrarOrdenAlfabE();
            }else if (opcion==2){
                printf("LISTA DE EMPLEADOS\n\n");
                mostrarOrdenDniE();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 1:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por DNI.\n");
            scanf("%i", &opcion);

            system("pause");
            system("cls");

            if(opcion==1){
                printf("LISTA DE EMPLEADOS ACTIVOS\n\n");
                mostrarOrdenAlfabEActivo();
            }else if (opcion==2){
                printf("LISTA DE EMPLEADOS ACTIVOS\n\n");
                mostrarOrdenDniActivosE();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 2:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por DNI.\n");
            scanf("%i", &opcion);

            system("pause");
            system("cls");

            if(opcion==1){
                printf("LISTA DE EMPLEADOS ACTIVOS\n\n");
                mostrarOrdenAlfabBajaE();
            }else if (opcion==2){
                printf("LISTA DE EMPLEADOS ACTIVOS\n\n");
                mostrarOrdenDniBajaE();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 3:
            registrarEmpleado();
            system("pause");
            system("cls");
            printf("LISTA DE EMPLEADOS\n\n");
            mostrarOrdenAlfabEActivo();
            system("pause");
            system("cls");
    break;
case 4:

            printf("LISTA DE EMPLEADOS \n\n");
            mostrarOrdenAlfabEActivo();

            char nYa[30];

            printf("Ingrese el nombre del empleado a modificar:\n");
            fflush(stdin);
            gets(nYa);

            system("pause");
            system("cls");

            modificarEmpleado(nYa);
            system("pause");
            system("cls");
    break;
case 5:
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

            system("pause");
            system("cls");
    break;
case 6:
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

            system("pause");
            system("cls");
    break;
case 7:
            printf("LISTA DE EMPLEADOS \n\n");
            mostrarOrdenAlfabEActivo();

            char nYaa[30];

            printf("Ingrese el nombre del empleado a dar de baja:\n");
            fflush(stdin);
            gets(nYaa);

            system("pause");
            system("cls");

            darBajaEmpleado(nYaa);
            system("pause");
            system("cls");
    break;
case 8:
            printf("Si desea calcular los sueldos por el puesto, ingrese 1.\n\n");
            printf("Si desea calcular el total de todos los sueldos, ingrese 2.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);
            system("pause");
            system("cls");
            if(opcion==1){
               char P[20];
               Pila A;
               inicpila(&A);

               printf("Ingrese el puesto que desea filtrar: \n");
               fflush(stdin);
               gets(P);

               ArchivoToPilaEmpleadosFilt(&A, P);
               float rta= sumarSueldos(A);

               printf("Total %s: %.2f\n", P, rta);
            }else{
               Pila A;
               inicpila(&A);

               ArchivoToPilaEmpleados(&A);
               float rta= sumarSueldos(A);

               printf("Total de sueldos: %.2f\n", rta);
            }
            system("pause");
            system("cls");
    break;
case 9:
    system("cls");
    break;
default:
    printf("No existe la opcion.\n");
    break;
    }
    }while(op!=8);

}

void menuGestionCliente(){

    int op=0, opcion=0;

    do{
    printf("\nIngrese una opcion.\n\n");
    printf("0. Ver la lista de clientes.\n");
    printf("1. Ver lista de clientes activos.\n");
    printf("2. Ver lista de clientes inactivos.\n");
    printf("3. Cargar un cliente.\n");
    printf("4. Modificar datos del cliente.\n");
    printf("5. Buscar un cliente\n");
    printf("6. Filtrar clientes\n");
    printf("7. Dar de baja cliente.\n");
    printf("8. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 0:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por DNI.\n");
            scanf("%i", &opcion);

            system("pause");
            system("cls");

            if(opcion==1){
                printf("LISTA DE CLIENTES\n\n");
                mostrarOrdenAlfabC();
            }else if (opcion==2){
                printf("LISTA DE CLIENTES\n\n");
                mostrarOrdenDNIC();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 1:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por DNI.\n");
            scanf("%i", &opcion);

            system("pause");
            system("cls");

            if(opcion==1){
                printf("LISTA DE CLIENTES ACTIVOS\n\n");
                mostrarOrdenAlfabCActivo();
            }else if (opcion==2){
                printf("LISTA DE CLIENTES ACTIVOS\n\n");
                mostrarOrdenDNIActivosC();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 2:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por DNI.\n");
            scanf("%i", &opcion);

            system("pause");
            system("cls");

            if(opcion==1){
                printf("LISTA DE CLIENTES INACTIVOS\n\n");
                mostrarOrdenAlfabBajaC();
            }else if (opcion==2){
                printf("LISTA DE CLIENTES INACTIVOS\n\n");
                mostrarOrdenDNIBajaC();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 3:
            registrarCliente();
            system("pause");
            system("cls");
            printf("LISTA DE CLIENTES\n\n");
            mostrarOrdenAlfabCActivo();
            system("pause");
            system("cls");
    break;
case 4:

            printf("LISTA DE CLIENTES \n\n");
            mostrarOrdenAlfabCActivo();

            char nYa[30];

            printf("Ingrese el nombre del cliente a modificar:\n");
            fflush(stdin);
            gets(nYa);

            system("pause");
            system("cls");

            modificarClienteEaux(nYa);
            system("pause");
            system("cls");
    break;
case 5:
            printf("Si desea buscar al cliente por nombre y apellido Ingrese 1.\n\n");
            printf("Si desea buscar al cliente por DNI Ingrese 2.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            system("pause");
            system("cls");

            if(opcion==1)
                {
                    char N[30];
                    printf("Ingrese el nombre y apellido del cliente que desea buscar: \n");
                    fflush(stdin);
                    gets(N);
                    encontrarClienteN(N);
                }else{
                    char DNI[10];
                    printf("Ingrese el DNI del cliente que desea buscar: \n");
                    fflush(stdin);
                    gets(DNI);

                    encontrarClienteDni(DNI);
                }
                system("pause");
                system("cls");
    break;
case 6:

            printf("Si desea filtrar el/los cliente/s por el genero, ingrese 1.\n\n");
            printf("Si desea filtrar el/los cliente/s por el estado, ingrese 2.\n\n");
            printf("Si desea filtrar el/los cliente/s por el viaje, ingrese 3.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            if(opcion==1){
               char G;
               printf("Ingrese el genero que desea filtrar (M o F) en mayuscula: ");
               fflush(stdin);
               scanf("%c", &G);

                while((G != 'M') && (G !='F')){
                   printf("\nSexo erroneo, ingrese nuevamente. \n");
                   fflush(stdin);
                   scanf("%c", &G);
                 }
               filtrarClienteGenero(G);
            }
            else if(opcion == 2){
                int E;
                printf("Ingrese el estado que desea filtrar (0. Inactivo | 1. Activo): ");
                fflush(stdin);
                scanf("%d", &E);
                filtrarClienteEstado(E);
            }
            else{
                int ID;
                printf("Ingrese el ID que desea filtrar: ");
                fflush(stdin);
                scanf("%d", &ID);
                filtrarClienteViaje(ID);
            }
            system("pause");
            system("cls");
    break;
case 7:
            printf("LISTA DE CLIENTES \n\n");
            mostrarOrdenAlfabCActivo();

            char nYaa[30];

            printf("Ingrese el nombre del cliente a dar de baja:\n");
            fflush(stdin);
            gets(nYaa);

            system("pause");
            system("cls");

            darBajaCliente(nYaa);
            system("pause");
            system("cls");
    break;
case 8:
    system("cls");
    break;
default:
    printf("No existe la opcion.\n");
    break;
    }
    }while(op!=8);

}

void menuGestionViajes(){

    int op=0, opcion=0;

    do{
    printf("\nIngrese una opcion.\n\n");
    printf("0. Ver la lista de viajes.\n");
    printf("1. Ver lista de viajes activos.\n");
    printf("2. Ver lista de viajes inactivos.\n");
    printf("3. Cargar un viaje.\n");
    printf("4. Modificar datos del viaje.\n");
    printf("5. Buscar un viaje\n");
    printf("6. Filtrar viajes\n");
    printf("7. Dar de baja viaje.\n");
    printf("8. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 0:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenDestinoV();
                printf("\nCalendario:\n");
                mostrarCalendarioCompleto();
            }else if (op==2){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenIDV();
                printf("\nCalendario:\n");
                mostrarCalendarioCompleto();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 1:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenDestinoActivosV();
                printf("\nCalendario:\n");
                mostrarCalendarioCompleto();
            }else if (op==2){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenIDActivosV();
                printf("\nCalendario:\n");
                mostrarCalendarioCompleto();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 2:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenDestinoBajaV();
            }else if (op==2){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenIDBajaV();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 3:
            cargarArchivoViaje();
            system("pause");
            system("cls");
            printf("LISTA DE VIAJES\n\n");
            mostrarOrdenIDActivosV();
            system("pause");
            system("cls");
    break;
case 4:
            printf("LISTA DE VIAJES \n\n");
            mostrarOrdenIDActivosV();
            int id;
            int idNoExiste;
        do {
            printf("Ingrese el ID del viaje\n");
            fflush(stdin);
            scanf("%d", &id);

            idNoExiste = verificarIDNoExiste(id);
            if (idNoExiste) {
                printf("El ID del viaje no existe. Ingrese un ID diferente:\n");
            }
        } while (idNoExiste);


            modificarViaje(id);
            system("pause");
            system("cls");
    break;
case 5:
            printf("Ingrese la ID del viaje que desea buscar: \n");
            fflush(stdin);
            scanf("%d", &id);

            stViaje A;

            system("pause");
            system("cls");

            A= buscarViajePorID(id);
            mostrarViaje(A);
            system("pause");
            system("cls");

    break;
case 6:
            printf("Si desea filtrar el/los viaje/s por el destino, ingrese 1.\n\n");
            printf("Si desea filtrar el/los viaje/s por el transporte, ingrese 2.\n\n");
            printf("Si desea filtrar el/los viaje/s por el estado, ingrese 3.\n\n");
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
            system("pause");
            system("cls");
    break;
case 7:
            mostrarOrdenDestinoActivosV();
            printf("Ingrese la ID del viaje que desea dar de baja: \n");
            fflush(stdin);
            scanf("%d", &id);

            system("pause");
            system("cls");

            darDeBajaViaje(id);
            system("pause");
            system("cls");
    break;
case 8:
    system("cls");
    break;
default:
    printf("No existe la opcion.\n");
    break;
    }
    }while(op!=8);

}

void menuGestionVentas(){

    int op=0, opcion=0, id=0;

    do{
    printf("\nIngrese una opcion.\n\n");
    printf("0. Ver la lista de ventas.\n");
    printf("1. Ver lista de ventas activos.\n");
    printf("2. Ver lista de ventas inactivos.\n");
    printf("3. Cargar una venta.\n");
    printf("4. Modificar datos de la venta.\n");
    printf("5. Buscar una venta\n");
    printf("6. Filtrar ventas\n");
    printf("7. Recaudacion total.\n");
    printf("8. Ganancias.\n");
    printf("9. Dar de baja venta.\n");
    printf("10. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 0:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenAlfabT();
            }else if (op==2){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenIDT();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 1:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenAlfabTActivo();
            }else if (op==2){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenIDActivosT();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 2:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenAlfabBajaT();
            }else if (op==2){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenIDBajaT();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 3:
            cargarArchivoVentas();
            system("pause");
            system("cls");
            printf("LISTA DE VENTAS\n\n");
            mostrarOrdenAlfabTActivo();
            system("pause");
            system("cls");
    break;
case 4:
            printf("LISTA DE VENTAS \n\n");
            mostrarOrdenIDActivosT();

            printf("Ingrese la ID de la venta a modificar:\n");
            fflush(stdin);
            scanf("%d", &id);

            system("pause");
            system("cls");

            modificarVenta(id);
            system("pause");
            system("cls");
    break;
case 5:
            printf("Si desea buscar la venta por el DNI del cliente, ingrese 1.\n\n");
            printf("Si desea buscar la venta por la ID del ticket, ingrese 2.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            system("pause");
            system("cls");
            if(opcion==1){
             char dni[10];

             printf("Ingrese el DNI del cliente: \n");
             fflush(stdin);
             gets(dni);

             system("pause");
             system("cls");

             encontrarVentaDNIC(dni);
            }
            else if (opcion==2){
              int id;

              printf("Ingrese la ID del ticket: \n");
              fflush(stdin);
              scanf("%d", &id);

              system("pause");
              system("cls");

              encontrarVentaId(id);
            }
            system("pause");
            system("cls");
    break;
case 6:
            printf("Si desea filtrar el/los ticket/s por el empleado que realizo la venta, ingrese 1.\n\n");
            printf("Si desea filtrar el/los ticket/s por el metodo de pago, ingrese 2.\n\n");
            printf("Si desea filtrar el/los ticket/s por el viaje, ingrese 3.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            system("pause");
            system("cls");
            if(opcion==1){
               char P[10];
               printf("Ingrese el DNI del empleado: \n");
               fflush(stdin);
               gets(P);
               filtrarVentaEmpleado(P);
            }
            else if(opcion == 2){
                char T[20];
                printf("Ingrese el metodo de pago a filtrar: \n");
                fflush(stdin);
                gets(T);
                filtrarVentaMetodo(T);
            }
            else if(opcion == 3){
                int E;
                printf("Ingrese la ID del viaje que desea filtrar: \n");
                fflush(stdin);
                scanf("%d", &E);
                filtrarVentaViaje(E);
            }
            system("pause");
            system("cls");
    break;
case 7:
            mostrarCalculo();
            system("pause");
            system("cls");
    break;
case 8:
            mostrarGanancias();
            system("pause");
            system("cls");
    break;
case 9:
            mostrarOrdenIDActivosT();
            printf("Ingrese la ID del ticket que desea dar de baja: \n");
            fflush(stdin);
            scanf("%d", &id);

            system("pause");
            system("cls");

            darBajaVenta(id);
            system("pause");
            system("cls");
    break;
case 10:
    system("cls");
    break;
default:
    printf("No existe la opcion.\n");
    break;
    }
    }while(op!=10);

}

/// MENU REGISTRO ADMIN ///////////////////////////////////////////////////////////////////////////

void menuRegistroAdmin(){

    int op;
    do{
    printf("MENU REGISTRO OTRO ADMINISTRADOR:\n\n");
    printf("1. Agregar administrador.\n");
    printf("2. Atras.\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 1:
    registrarAdmin();
    break;
case 2:
    system("cls");
    break;
    }}while(op!=2);
}

/// MENU MODIFICAR PERFIL ADMIN ////////////////////////////////////////////////////////////////////

void menuPerfilAdmin(char nYa[]){

    int op;
    do{
    printf("MENU PERFIL:\n\n");
    printf("1. Ver perfil.\n");
    printf("2. Modificar perfil.\n");
    printf("3. Atras.\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 1:
    mostrarPerfilAdmin(nYa);
    break;
case 2:
    modificarAdmin(nYa);
    break;
case 3:
    system("cls");
    break;
    }}while(op!=3);

}

/// MENU EMPLEADOS ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuEmpleados(char nYa[]){

    int op=0;

    do{
    printf("\nMENU PRINCIPAL:\n\n");
    printf("1. Perfil\n");
    printf("2. Clientes\n");
    printf("3. Viajes\n");
    printf("4. Ventas\n");
    printf("5. Salir\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 1:
    menuPerfilEmpleado(nYa);
    break;
case 2:
    menuClienteEmpleado();
    break;
case 3:
    menuViajesEmpleado();
    break;
case 4:
    menuVentasEmpleado();
    break;
case 5:
    printf("Cerrando sesion...\n");
    system("pause");
    system("cls");
    break;
    }
    }while(op!=5);
}

/// MENU PERFIL EMPLEADO ////////////////////////////

void menuPerfilEmpleado (char nYa[])
{

    int op=0;

    do{
    printf("PERFIL\n\n");
    printf("1. Ver perfil.\n");
    printf("2. Modificar perfil.\n");
    printf("3. Darse de baja.\n");
    printf("4. Atras.\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
    case 1:
        encontrarEmpleadoN(nYa);
        system("pause");
        system("cls");
        break;
    case 2:
        modificarEmpleado(nYa);
        system("pause");
        system("cls");
        break;
    case 3:
        darBajaEmpleado(nYa);
        system("pause");
        system("cls");
        break;
    case 4:
        printf("Volviendo a la pantalla de login/registro...\n");
        system("cls");
        break;
    default:
        printf("No existe la opcion.\n");
        break;
    }
    }while(op!=4);

}

/// MENU CLIENTE EMPLEADO ////////////////////////////

void menuClienteEmpleado (){

    int op=0, opcion=0;

    do{
    printf("\nIngrese una opcion.\n\n");
    printf("0. Ver la lista de clientes.\n");
    printf("1. Ver lista de clientes activos.\n");
    printf("2. Ver lista de clientes inactivos.\n");
    printf("3. Cargar un cliente.\n");
    printf("4. Modificar datos del cliente.\n");
    printf("5. Buscar un cliente\n");
    printf("6. Filtrar clientes\n");
    printf("7. Dar de baja cliente.\n");
    printf("8. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 0:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por DNI.\n");
            scanf("%i", &opcion);

            system("pause");
            system("cls");

            if(opcion==1){
                printf("LISTA DE CLIENTES\n\n");
                mostrarOrdenAlfabC();
            }else if (opcion==2){
                printf("LISTA DE CLIENTES\n\n");
                mostrarOrdenDNIC();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 1:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por DNI.\n");
            scanf("%i", &opcion);

            system("pause");
            system("cls");

            if(opcion==1){
                printf("LISTA DE CLIENTES ACTIVOS\n\n");
                mostrarOrdenAlfabCActivo();
            }else if (opcion==2){
                printf("LISTA DE CLIENTES ACTIVOS\n\n");
                mostrarOrdenDNIActivosC();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 2:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por DNI.\n");
            scanf("%i", &opcion);

            system("pause");
            system("cls");

            if(opcion==1){
                printf("LISTA DE CLIENTES INACTIVOS\n\n");
                mostrarOrdenAlfabBajaC();
            }else if (opcion==2){
                printf("LISTA DE CLIENTES INACTIVOS\n\n");
                mostrarOrdenDNIBajaC();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 3:
            registrarCliente();
            system("pause");
            system("cls");
            printf("LISTA DE CLIENTES\n\n");
            mostrarOrdenAlfabCActivo();
            system("pause");
            system("cls");
    break;
case 4:

            printf("LISTA DE CLIENTES \n\n");
            mostrarOrdenAlfabCActivo();

            char nYa[30];

            printf("Ingrese el nombre del cliente a modificar:\n");
            fflush(stdin);
            gets(nYa);

            system("pause");
            system("cls");

            modificarClienteEaux(nYa);
            system("pause");
            system("cls");
    break;
case 5:
            printf("Si desea buscar al cliente por nombre y apellido Ingrese 1.\n\n");
            printf("Si desea buscar al cliente por DNI Ingrese 2.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            system("pause");
            system("cls");

            if(opcion==1)
                {
                    char N[30];
                    printf("Ingrese el nombre y apellido del cliente que desea buscar: \n");
                    fflush(stdin);
                    gets(N);
                    encontrarClienteN(N);
                }else{
                    char DNI[10];
                    printf("Ingrese el DNI del cliente que desea buscar: \n");
                    fflush(stdin);
                    gets(DNI);

                    encontrarClienteDni(DNI);
                }

            system("pause");
            system("cls");
    break;
case 6:

            printf("Si desea filtrar el/los cliente/s por el genero, ingrese 1.\n\n");
            printf("Si desea filtrar el/los cliente/s por el estado, ingrese 2.\n\n");
            printf("Si desea filtrar el/los cliente/s por el viaje, ingrese 3.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            if(opcion==1){
               char G;
               printf("Ingrese el genero que desea filtrar (M o F) en mayuscula: ");
               fflush(stdin);
               scanf("%c", &G);

                while((G != 'M') && (G !='F')){
                   printf("\nSexo erroneo, ingrese nuevamente. \n");
                   fflush(stdin);
                   scanf("%c", &G);
                 }
               filtrarClienteGenero(G);
            }
            else if(opcion == 2){
                int E;
                printf("Ingrese el estado que desea filtrar (0. Inactivo | 1. Activo): ");
                fflush(stdin);
                scanf("%d", &E);
                filtrarClienteEstado(E);
            }
            else{
                int ID;
                printf("Ingrese el ID que desea filtrar: ");
                fflush(stdin);
                scanf("%d", &ID);
                filtrarClienteViaje(ID);
            }
            system("pause");
            system("cls");
    break;
case 7:
            printf("LISTA DE CLIENTES \n\n");
            mostrarOrdenAlfabCActivo();

            char nYaa[30];

            printf("Ingrese el nombre del cliente a dar de baja:\n");
            fflush(stdin);
            gets(nYaa);

            system("pause");
            system("cls");

            darBajaCliente(nYaa);
            system("pause");
            system("cls");
    break;
case 8:
    system("cls");
    break;
default:
    printf("No existe la opcion.\n");
    break;
    }
    }while(op!=8);

}

/// MENU VIAJES EMPLEADO ////////////////////////////

void menuViajesEmpleado (){

    int op=0, opcion=0;

    do{
    printf("\nIngrese una opcion.\n\n");
    printf("0. Ver la lista de viajes.\n");
    printf("1. Ver lista de viajes activos.\n");
    printf("2. Ver lista de viajes inactivos.\n");
    printf("3. Cargar un viaje.\n");
    printf("4. Modificar datos del viaje.\n");
    printf("5. Buscar un viaje\n");
    printf("6. Filtrar viajes\n");
    printf("7. Dar de baja viaje.\n");
    printf("8. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 0:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenDestinoV();
                printf("\nCalendario:\n");
                mostrarCalendarioCompleto();
            }else if (op==2){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenIDV();
                printf("\nCalendario:\n");
                mostrarCalendarioCompleto();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 1:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenDestinoActivosV();
                printf("\nCalendario:\n");
                mostrarCalendarioCompleto();
            }else if (op==2){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenIDActivosV();
                printf("\nCalendario:\n");
                mostrarCalendarioCompleto();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 2:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenDestinoBajaV();
            }else if (op==2){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenIDBajaV();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 3:
            cargarArchivoViaje();
            system("pause");
            system("cls");
            printf("LISTA DE VIAJES\n\n");
            mostrarOrdenIDActivosV();
            system("pause");
            system("cls");
    break;
case 4:
            printf("LISTA DE VIAJES \n\n");
            mostrarOrdenIDActivosV();
            int id;
            int idNoExiste;
        do {
            printf("Ingrese el ID del viaje\n");
            fflush(stdin);
            scanf("%d", &id);

            idNoExiste = verificarIDNoExiste(id);
            if (idNoExiste) {
                printf("El ID del viaje no existe. Ingrese un ID diferente:\n");
            }
        } while (idNoExiste);


            system("pause");
            system("cls");

            modificarViaje(id);
            system("pause");
            system("cls");
    break;
case 5:
            printf("Ingrese la ID del viaje que desea buscar: \n");
            fflush(stdin);
            scanf("%d", &id);

            stViaje A;

            system("pause");
            system("cls");

            A= buscarViajePorID(id);
            mostrarViaje(A);
            system("pause");
            system("cls");
    break;
case 6:
            printf("Si desea filtrar el/los viaje/s por el destino, ingrese 1.\n\n");
            printf("Si desea filtrar el/los viaje/s por el transporte, ingrese 2.\n\n");
            printf("Si desea filtrar el/los viaje/s por el estado, ingrese 3.\n\n");
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
            system("pause");
            system("cls");
    break;
case 7:
            mostrarOrdenDestinoActivosV();
            printf("Ingrese la ID del viaje que desea dar de baja: \n");
            fflush(stdin);
            scanf("%d", &id);

            system("pause");
            system("cls");

            darDeBajaViaje(id);
            system("pause");
            system("cls");
    break;
case 8:
    system("cls");
    break;
default:
    printf("No existe la opcion.\n");
    break;
    }
    }while(op!=8);

}

/// MENU VENTAS EMPLEADO ////////////////////////////

void menuVentasEmpleado (){

    int op=0, opcion=0, id=0;

    do{
    printf("\nIngrese una opcion.\n\n");
    printf("0. Ver la lista de ventas.\n");
    printf("1. Ver lista de ventas activos.\n");
    printf("2. Ver lista de ventas inactivos.\n");
    printf("3. Cargar una venta.\n");
    printf("4. Modificar datos de la venta.\n");
    printf("5. Buscar una venta\n");
    printf("6. Filtrar ventas\n");
    printf("7. Recaudacion total.\n");
    printf("8. Ganancias.\n");
    printf("9. Dar de baja viaje.\n");
    printf("10. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 0:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenAlfabT();
            }else if (op==2){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenIDT();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 1:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenAlfabTActivo();
            }else if (op==2){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenIDActivosT();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 2:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenAlfabBajaT();
            }else if (op==2){
                printf("LISTA DE VENTAS\n\n");
                mostrarOrdenIDBajaT();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 3:
            cargarArchivoVentas();
            system("pause");
            system("cls");
            printf("LISTA DE VENTAS\n\n");
            mostrarOrdenAlfabTActivo();
            system("pause");
            system("cls");
    break;
case 4:
            printf("LISTA DE VENTAS \n\n");
            mostrarOrdenIDActivosV();

            printf("Ingrese la ID de la venta a modificar:\n");
            fflush(stdin);
            scanf("%d", &id);

            system("pause");
            system("cls");

            modificarVenta(id);
            system("pause");
            system("cls");
    break;
case 5:
            printf("Si desea buscar la venta por el DNI del cliente, ingrese 1.\n\n");
            printf("Si desea buscar la venta por la ID del ticket, ingrese 2.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            system("pause");
            system("cls");
            if(opcion==1){
             char dni[10];

             printf("Ingrese el DNI del cliente: \n");
             fflush(stdin);
             gets(dni);

             system("pause");
             system("cls");

             encontrarVentaDNIC(dni);
            }
            else if (opcion==2){
              int id;

              printf("Ingrese la ID del ticket: \n");
              fflush(stdin);
              scanf("%d", &id);

              system("pause");
              system("cls");

              encontrarVentaId(id);
            }

            system("pause");
            system("cls");
    break;
case 6:
            printf("Si desea filtrar el/los ticket/s por el empleado que realizo la venta, ingrese 1.\n\n");
            printf("Si desea filtrar el/los ticket/s por el metodo de pago, ingrese 2.\n\n");
            printf("Si desea filtrar el/los ticket/s por el viaje, ingrese 3.\n\n");
            fflush(stdin);
            scanf("%d", &opcion);

            system("pause");
            system("cls");
            if(opcion==1){
               char P[10];
               printf("Ingrese el DNI del empleado: \n");
               fflush(stdin);
               gets(P);
               filtrarVentaEmpleado(P);
            }
            else if(opcion == 2){
                char T[20];
                printf("Ingrese el metodo de pago a filtrar: \n");
                fflush(stdin);
                gets(T);
                filtrarVentaMetodo(T);
            }
            else if(opcion == 3){
                int E;
                printf("Ingrese la ID del viaje que desea filtrar: \n");
                fflush(stdin);
                scanf("%d", &E);
                filtrarVentaViaje(E);
            }

            system("pause");
            system("cls");
    break;
case 7:
            mostrarCalculo();
            system("pause");
            system("cls");
    break;
case 8:
            mostrarGanancias();
            system("pause");
            system("cls");
    break;
case 9:
            mostrarOrdenIDActivosT();
            printf("Ingrese la ID del ticket que desea dar de baja: \n");
            fflush(stdin);
            scanf("%d", &id);

            system("pause");
            system("cls");

            darBajaVenta(id);
            system("pause");
            system("cls");
    break;
case 10:
    system("cls");
    break;
default:
    printf("No existe la opcion.\n");
    break;
    }
    }while(op!=10);

}

/// MENU CLIENTES /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuClientes(char nYa[]){

    int op=0;

    do{
    printf("\nMENU PRINCIPAL:\n\n");
    printf("1. Perfil\n");
    printf("2. Viajes\n");
    printf("3. Compras\n");
    printf("4. Salir\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 1:
    menuPerfilCliente(nYa);
    break;
case 2:
    menuViajesCliente();
    break;
case 3:
    menuComprasCliente();
    break;
case 4:
    printf("Cerrando sesion...\n");
    system("pause");
    system("cls");
    break;
default:
    printf("Opcion incorrecta\n");
    break;
    }
    }while(op!=4);
}

/// MENU PERFIL CLIENTE ///////////////////////////////////

void menuPerfilCliente (char nYa[]){

    int op=0;

    do{
    printf("PERFIL\n\n");
    printf("1. Ver perfil.\n");
    printf("2. Modificar perfil.\n");
    printf("3. Darse de baja.\n");
    printf("4. Atras.\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
    case 1:
        encontrarClienteN(nYa);
        system("pause");
        system("cls");
        break;
    case 2:
        modificarCliente(nYa);
        system("pause");
        system("cls");
        break;
    case 3:
        darBajaCliente(nYa);
        system("pause");
        system("cls");
        break;
    case 4:
        system("cls");
        break;
    default:
        printf("No existe la opcion.\n");
        break;
    }
    }while(op!=4);

}

/// MENU VIAJE CLIENTE ///////////////////////////////////

void menuViajesCliente ()
{
    int op=0, opcion=0, id=0;

    do{
    printf("\nIngrese una opcion.\n\n");
    printf("1. Ver la lista de viajes.\n");
    printf("2. Buscar un viaje\n");
    printf("3. Filtrar viajes\n");
    printf("4. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 1:
            printf("Ingrese una opcion.\n\n");
            printf("1. Orden alfabetico.\n");
            printf("2. Orden por ID.\n");
            scanf("%i", &op);

            system("pause");
            system("cls");

            if(op==1){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenDestinoActivosV();
                printf("\nCalendario:\n");
                mostrarCalendarioCompleto();
            }else if (op==2){
                printf("LISTA DE VIAJES\n\n");
                mostrarOrdenIDActivosV();
                printf("\nCalendario:\n");
                mostrarCalendarioCompleto();
            }else{
                printf("No existe la opcion.\n");
            }
            system("pause");
            system("cls");
    break;
case 2:
            printf("Ingrese la ID del viaje que desea buscar: \n");
            fflush(stdin);
            scanf("%d", &id);

            stViaje A;

            system("pause");
            system("cls");

            A= buscarViajePorID(id);
            mostrarViaje(A);
            system("pause");
            system("cls");
    break;
case 3:
            printf("Si desea filtrar el/los viaje/s por el destino, ingrese 1.\n\n");
            printf("Si desea filtrar el/los viaje/s por el transporte, ingrese 2.\n\n");
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
            system("pause");
            system("cls");
    break;
case 4:
    system("cls");
    break;
default:
    printf("No existe la opcion.\n");
    break;
    }
    }while(op!=4);

}

/// MENU COMPRAS CLIENTE ///////////////////////////////////

void menuComprasCliente (){

    int op=0;

    do{
    printf("\nIngrese una opcion.\n\n");
    printf("1. Ver compras\n");
    printf("2. Atras\n");
    scanf("%i", &op);
    system("pause");
    system("cls");
    switch(op){
case 1:
            printf("\n");
            char dni[10];
            printf("Por favor, ingrese su dni.\n");
            fflush(stdin);
            gets(dni);

            system("pause");
            system("cls");

            encontrarVentaDNIC(dni);
            system("pause");
            system("cls");
    break;
case 2:
    system("cls");
    break;
default:
    printf("No existe la opcion.\n");
    break;
    }
    }while(op!=2);
}
