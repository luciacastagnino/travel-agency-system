#include "ventas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viajes.h"
#include "clientes.h"
#include "empleados.h"
#include "ordenamientos.h"

///VENTAS EN ORDEN/////////////////////////////////////////////////////////////////////////////////////////////////////////////




/// Cargar un Ticket
stTickets CargarTicket()
{
    stTickets A;

    printf("Ingrese el cargo por servicio : ");
    scanf("%i", &A.monto);

    printf("Ingrese la fecha: ");
    fflush(stdin);
    gets(A.fecha);

    printf("Ingrese la id del cliente: ");
    fflush(stdin);
    gets(A.idCliente);

    printf("Ingrese la id del empleado: ");
    fflush(stdin);
    gets(A.idEmpleado);

    printf("Ingrese el metodo de pago: ");
    fflush(stdin);
    gets(A.metodo);

    printf("Ingrese el estado del ticket (1/0): ");
    scanf("%i", &A.estado);

    printf("Ingrese la id del ticket: ");
    scanf("%i", &A.id);

    printf("Ingrese los datos del viaje: \n");
    A.viaje = cargarViaje(); ///LLAMA LA FUNCION AUXILIAR PARA CARGAR EL VIAJE DENTRO DEL TICKET (PODEMOS MODIFICARLO DE ALGUNA MANERA PARA QUE SEA MAS COMODO)

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
    printf("DETALLES DEL TICKET: \n");
    printf("Cargos por servicio del ticket es: $%i\n", A.monto);
    printf("La fecha del ticket es: %s\n", A.fecha);
    printf("La id del ticket es: %i\n", A.id);
    printf("El metodo de pago es: %s\n", A.metodo);
    printf("La id del cliente es: %s\n", A.idCliente);
    printf("La id del empleado es: %s\n", A.idEmpleado);
    printf("Datos del viaje: \n\n");

    mostrarViaje(A.viaje);

    Cargos=A.monto+A.viaje.precio;
    printf("Monto total a pagar: $%i\n", Cargos);
}

///Mostrar Archivo Ventas
void mostrarArchivoVentas()
{
    stTickets A;

    FILE* buff;
    buff = fopen(archVentas, "rb");

    if(buff)
    {
        while(fread(&A, sizeof(stTickets), 1, buff))
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


/// //////////////////////////////////////////////////////////////////////////////

/////FUNCION COMPLETA DE MODIFICAR TICKET -Linea 181 a 246///
//
//stTickets ModificarTicket(stTickets A)
//{
//    int controlador;
//    char control='s';
//
//    printf("Desea modificar el ticket? (s/n)");
//    fflush(stdin);
//    scanf("%c", &control);
//
//    while (control=='s')
//    {
//        printf("1. Monto agregado\n2. Fecha del ticket\n3. Id del dliente\n4. Id del empleado\n5. Metodo de pago\n6. Id del ticket\nQue desea modificar: ");
//        scanf("%i", &controlador);
//
//        switch(controlador)
//        {
//
//        case 1:
//
//            {
//                A=ModificarMontoTicket(A);
//                break;
//            }
//
//        case 2:
//
//            {
//                A=ModificarFechaTicket(A);
//                break;
//            }
//
//        case 3:
//
//            {
//                A= ModificarIdDelClienteEnTicket(A);
//                break;
//            }
//
//        case 4:
//
//            {
//                A= ModificarIdDelEmpleadoEnTicket(A);
//                break;
//            }
//        case 5:
//
//            {
//                A= ModificarMetodoDePago(A);
//                break;
//            }
//
//        case 6:
//
//            {
//                A= ModificarIdTicket(A);
//                break;
//            }
//
//        }
//
//        printf("Desea continuar modificando el ticket? (s/n)\n");
//        fflush(stdin);
//        scanf("%c",&control);
//    }
//    return A;
//}
///// /////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////Dar de baja ticket///
//stTickets DarDeBaja(stTickets A)
//{
//    char control='s';
//    printf("Desea dar de baja el ticket? s/n");
//    fflush(stdin);
//    scanf("%c", &control);
//
//    if (control == 's')
//    {
//        A.estado=0;
//    }
//    return A;
//}
///// ////////////////////////////
//
///// //////////////////////////////////////////////////////////////////////////////////////////////////
//
/////MODIFICACIONES NECESARIAS PARA EL FUNCIONAMIENTO DE MODIFICACION PRINCIPAL -Linea 269 a 319///
//
//stTickets ModificarMetodoDePago(stTickets A)
//{
//    printf("Ingrese el nuevo metodo de pago: ");
//    fflush(stdin);
//    gets(A.metodo);
//
//    return A;
//}
//
//stTickets ModificarMontoTicket(stTickets A)
//{
//    printf("Ingrese el nuevo monto del ticket: ");
//    scanf("%d", &A.monto);
//
//    return A;
//}
//
//stTickets ModificarFechaTicket(stTickets A)
//{
//    printf("Ingrese la nueva fecha del ticket: ");
//    fflush(stdin);
//    gets(A.fecha);
//
//    return A;
//}
//
//stTickets ModificarIdDelClienteEnTicket(stTickets A)
//{
//    printf("Ingresar el nuevo id del cliente: ");
//    fflush(stdin);
//    gets(A.idCliente);
//
//    return A;
//}
//
//stTickets ModificarIdTicket(stTickets A)
//{
//    printf("Ingrese la nueva id del ticket: ");
//    scanf("%i",&A.id);
//
//    return A;
//}
//
//stTickets ModificarIdDelEmpleadoEnTicket(stTickets A)
//{
//    printf("Ingrese el nuevo id del empleado: ");
//    fflush(stdin);
//    gets(A.idEmpleado);
//
//    return A;
//}
///// /////////////////////////////////////////////////////////////////////////////////////////////////




