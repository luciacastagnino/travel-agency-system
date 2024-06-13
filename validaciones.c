#include "validaciones.h"
#include "clientes.h"
#include "empleados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// validacion inicio sesion/registro

int lenghtContrasenia(char contrasenia[]){

    int flag=0;
    if(strlen(contrasenia)>8){
        flag=1;
    }
    return flag;
}

int lenghtDNI(char dni[]){

    int flag=0;
    if(strlen(dni)<10){
        flag=1;
    }
    return flag;
}

int lenghtTelefono(char telefono[]){

    int flag=0;
    if(strlen(telefono)<11){
        flag=1;
    }
    return flag;
}

int validacionContrasenia (char contrasenia[], char contrasenia2[]){

    int flag=0;
    if(strcmp(contrasenia, contrasenia2)==0){
        flag=1;
    }
    return flag;
}

int validarDiaFecha(int dia)
{
    int flag=0;

    if(dia>=1 && dia<=31)
    {
        flag=1;
    }

    return flag;
}

int validarMesFecha(int mes)
{
    int flag=0;

    if(mes>=1 && mes<=12)
    {
        flag=1;
    }
    return flag;
}

int validarExistenciaCliente (char dniC[]){

    FILE* buf;
    buf=fopen(archCliente, "rb");
    stCliente A;
    int flag=0;
    if(buf){
        while(fread(&A, sizeof(stCliente), 1, buf)>0 && flag==0){
            if(strcmp(A.dni, dniC)==0){
                flag=1;
            }
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo.\n");
    }

    return flag;
}

int validarExistenciaEmpleado (char dniE[]){

    FILE* buf;
    buf=fopen(archEmpleado, "rb");
    stEmpleado A;
    int flag=0;
    if(buf){
        while(fread(&A, sizeof(stEmpleado), 1, buf)>0 && flag==0){
            if(strcmp(A.dni, dniE)==0){
                flag=1;
            }
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo.\n");
    }

    return flag;
}
