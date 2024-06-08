#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "menu.h"
#include "empleados.h"
#include "clientes.h"
#include "ventas.h"
#include "viajes.h"


int main()
{
    int op;

    printf("Ingrese con que area va a trabajar\n\n");
    printf("1. Empleados.\n");
    printf("2. Viajes.\n");
    printf("3. Ventas.\n");
    printf("4. Clientes.\n");
    printf("5. Salir.\n");
    fflush(stdin);
    scanf("%d", &op);
    do{
    switch(op)
    {
    case 1:
        {
            menuEmpleados();
            break;
        }
    case 2:
        {
            menuViajes();
            break;
        }
    case 3:
        {
            menuVentas();
            break;
        }
    case 4:
        {
            menuClientes();
            break;
        }
    case 5:
        printf("\nSaliendo del sistema...\n");
    }}while(op!=5);

    return 0;
}
