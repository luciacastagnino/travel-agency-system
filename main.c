#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "menu.h"
#include "empleados.h"
#include "clientes.h"
#include "ventas.h"
#include "viajes.h"
#include "home.h"
#include "admin.h"
#include "validaciones.h"

int main()
{

    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///               ////              ////       /////////              /////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////         ///////   ////////////////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   ///    //////   ////////////////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   /////   /////   ////////////////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   //////   ////              /////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   //////   ////   ////////////////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   /////   /////   ////////////////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   ////   //////   ////////////////////////////////////////////////////////////\n");
    printf("///               ////              ////        ////////               ////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                ////          //////              ////   //////////////   ////               ////   ////////////////\n");
    printf("/////////   ///////////   /////   /////   ////////   /////   ////////////   /////   ////////////////   ////////////////\n");
    printf("/////////   ///////////   /////    ////   ////////   /////   ///////////   //////   ////////////////   ////////////////\n");
    printf("/////////   ///////////   ////    /////   ////////   //////   /////////   ///////   ////////////////   ////////////////\n");
    printf("/////////   ///////////         ///////              ///////   ///////   ////////               ////   ////////////////\n");
    printf("/////////   ///////////   //   ////////   ////////   ////////   /////   /////////   ////////////////   ////////////////\n");
    printf("/////////   ///////////   ///   ///////   ////////   /////////   ///   //////////   ////////////////   ////////////////\n");
    printf("/////////   ///////////   ////   //////   ////////   //////////   /   ///////////   ////////////////   ////////////////\n");
    printf("/////////   ///////////   /////   /////   ////////   ///////////     ////////////               ////               ////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\n");

    system("pause");
    system("cls");

    stAdmin admin;
    stEmpleado empleado;
    stCliente cliente;
    int op, opcion;

    printf("\nBienvenido a CodeTravel!\n\n");

    do {

        printf("1. Iniciar sesion\n");
        printf("2. Registro\n");
        printf("3. Salir del sistema.\n");
        fflush(stdin);
        scanf("%d", &op);
        system("cls");

        switch (op) {
            case 1:
                do {
                    printf("\nIngrese su tipo de usuario:\n\n");
                    printf("1. Empleado\n");
                    printf("2. Cliente\n");
                    printf("3. Salir\n");
                    scanf("%i", &opcion);
                    system("cls");
                    switch (opcion){
                        case -1:
                            printf("INICIO DE SESION:\n\n");
                            admin=iniciarSesionAdmin();
                            system("pause");
                            system("cls");
                            printf("Bienvenido/a %s.\n", admin.nYa);
                            menuAdmin(admin.nYa);
                            break;
                        case 1:
                            printf("INICIO DE SESION:\n\n");
                            empleado=iniciarSesionEmpleado();
                            system("pause");
                            system("cls");
                            printf("Bienvenido/a %s.\n", empleado.nYa);
                            menuEmpleados(empleado.nYa);
                            break;
                        case 2:
                            printf("INICIO DE SESION:\n\n");
                            cliente=iniciarSesionCliente();
                            system("pause");
                            system("cls");
                            printf("Bienvenido/a %s.\n", cliente.nYa);
                            menuClientes(cliente.nYa);
                            break;
                        case 3:
                            system("cls");
                            break;
                        default:
                            printf("No existe la opcion.\n");
                            break;
                    }
                } while (opcion!=3);
                break;

            case 2:
                {
                    int option;
                    printf("Ingrese su tipo de usuario:\n\n");
                    printf("1. Empleado\n");
                    printf("2. Cliente\n");
                    printf("3. Salir\n");
                    scanf("%i", &option);
                    system("cls");
                    if (option==1) {
                        printf("REGISTRO DE CLIENTE:\n\n");
                        registrarEmpleado();
                        system("pause");
                        system("cls");
                    } else if (option==2) {
                        printf("REGISTRO DE CLIENTE:\n\n");
                        registrarCliente();
                        system("pause");
                        system("cls");
                    }
                    break;
                }

            case 3:
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("No existe la opcion.\n");
                break;
        }
    } while (op != 3);

    return 0;
}
