#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#include "empleados.h"
#include "ordenamientos.h"
#include "admin.h"
#include "validaciones.h"

stAdmin cargarContraseniaAdmin(stAdmin A){

    char contrasenia[30];
    char contrasenia2[30];
    int flag=0;
    printf("Ingrese su contrasenia:  \n");
    fflush(stdin);
    gets(contrasenia);
    flag=lenghtContrasenia(contrasenia);

    while(flag!=1)
    {
        printf("La contrasenia es muy corta, ingrese una contrasenia mas larga.\n");
        fflush(stdin);
        gets(contrasenia);
        flag=lenghtContrasenia(contrasenia);
    }
    printf("Vuelva a ingresar su contrasenia \n");
    fflush(stdin);
    gets(contrasenia2);

    int validacion=0;

    validacion=validacionContrasenia(contrasenia, contrasenia2);

    while(validacion!=1){
        printf("Las contrasenias no coinciden, ingrese nuevamente la contrasenia\n");
        fflush(stdin);
        gets(contrasenia);
        printf("Vuelva a ingresar su contrasenia \n");
        fflush(stdin);
        gets(contrasenia2);
        validacion=validacionContrasenia(contrasenia, contrasenia2);
    }
    strcpy(A.contrasenia, contrasenia);

    return A;
}

stAdmin cargarAdmin(){

    stAdmin A;
    char dni[10];
    int flagDni=0;

    printf("Ingrese su nombre y apellido:\n");
    fflush(stdin);
    gets(A.nYa);

    printf("\n");

    A=cargarContraseniaAdmin(A);

    printf("\n");

    while(flagDni==0){
        printf("Ingrese su DNI:\n");
        fflush(stdin);
        gets(dni);
        flagDni=lenghtDNI(dni);
        if(flagDni==0){
            printf("El DNI es muy corto. Ingrese uno mas largo.\n");
        }else{
            strcpy(A.dni, dni);
        }
    }


    A.estado=1;

    return A;
}

void registrarAdmin() {

    FILE *buf;
    buf=fopen(archAdmin, "ab");
    stAdmin A;

    if(buf){
        A=cargarAdmin();
        fwrite(&A, sizeof(stAdmin), 1, buf);
        fclose(buf);
        printf("\nAdministrador registrado con exito.\n\n");
    }else{
        printf("No se pudo abrir el archivo.\n");
    }
}

stAdmin busquedaAdminInicioSesion (char dni[], char contrasenia[])
{
    FILE* buf;
    buf=fopen(archAdmin, "rb");
    stAdmin A;
    int flag=0;

    if(buf)
    {
        while(flag != 1 && fread(&A, sizeof(stAdmin), 1, buf)>0)
        {
            if(strcmpi(A.dni, dni)==0 && strcmp(A.contrasenia, contrasenia)==0)
            {
                flag=1;
            }
        }
        fclose(buf);
    }

    return A;
}

stAdmin iniciarSesionAdmin() {

    FILE *buf;
    buf = fopen(archAdmin, "rb");
    char dni[10];
    char contrasenia[20];
    //char contrasenia2[20];
    stAdmin A;
    int flag=0;

    if(buf){
        while(flag!=1){

        printf("\nIngrese el DNI:\n");
        fflush(stdin);
        gets(dni);

        printf("\nIngrese contrasenia:\n");
        fflush(stdin);
        gets(contrasenia);
        A= busquedaAdminInicioSesion(dni, contrasenia);

        if((strcmp(A.dni, dni)==0) && strcmpi(A.contrasenia, contrasenia)==0){
            printf("\nInicio de sesion exitoso.\n\n");
            flag=1;
        }else{
            printf("\nDni o contrasenia incorrectos. Vuelva a iniciar sesion.\n\n");
        }

    }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo.\n");
    }

    return A;
}

/// Mostrar Admin ///////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAdmin(stAdmin A)
{
    printf("\n");
    printf("Nombre y Apellido: %s\n", A.nYa);
    printf("DNI: %s\n", A.dni);
    printf("\n");
}

/// Mostrar archivo admin /////////////////

void mostrarArchivoAdmin()
{
    stAdmin A;

    FILE* buf;
    buf = fopen(archAdmin, "rb");

    if(buf)
    {
        while(fread(&A, sizeof(stAdmin), 1, buf))
        {
            mostrarAdmin(A);
        }
        fclose(buf);
    }
    else
    {
        printf("El archivo no pudo abrirse\n");
    }
}

void mostrarPerfilAdmin (char nYa[]){

    FILE* buf;
    buf=fopen(archAdmin, "rb");
    stAdmin A;

    if(buf){
        while(fread(&A, sizeof(stAdmin), 1, buf)>0){
            if(strcmp(A.nYa, nYa)==0){
                mostrarAdmin(A);
            }
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo.\n");
    }
}

/// MODIFICAR ADMIN //////////////////////////////////////////////////////////////

stAdmin modificarnYaA(stAdmin A){

    printf("Ingrese el nuevo nombre y apellido:\n");
    fflush(stdin);
    gets(A.nYa);

    return A;
}

stAdmin modificarDniA(stAdmin A){

    int flagDni=0;
    char dni[10];

    while(flagDni==0){
        printf("Ingrese su DNI:\n");
        fflush(stdin);
        gets(dni);
        flagDni=lenghtDNI(dni);
        if(flagDni==0){
            printf("El DNI es muy corto. Ingrese uno mas largo.\n");
        }else{
            strcpy(A.dni, dni);
        }
    }

    return A;
}

stAdmin modificarContraseniaA (stAdmin A){

    char contraseniaActual[30];
    int flag=0;

    while(flag!=1){
        printf("Ingrese su contrasenia actual:\n");
        fflush(stdin);
        gets(contraseniaActual);

        if(strcmpi(A.contrasenia, contraseniaActual)==0){
            printf("Contrasenia actual correcta, por favor a continuacion ingrese la nueva contrasenia.\n");
            system("pause");
            system("cls");
            A=cargarContraseniaAdmin(A);
            printf("Contrasenia actualizada con exito!\n");
            flag=1;
        }else{
            printf("Contrasenia incorrecta, vuelva a ingresar su contrasenia actual.\n");
        }
    }

    return A;
}

void modificarAdmin (char nYa[]){

    stAdmin aux;
    int flag = 0;
    int pos=0;

    FILE* buf;
    buf = fopen(archAdmin, "r+b");

    if(buf){
        while((fread(&aux, sizeof(stAdmin), 1, buf)>0)&& flag==0){
            if(strcmpi(aux.nYa, nYa) == 0){
                flag = 1;
            }else{
                pos++;
            }
        }
        fseek(buf, sizeof(stAdmin) * pos, SEEK_SET);
        fread(&aux, sizeof(stAdmin), 1, buf);

        aux = modificarDatosAdmin(aux);

        fseek(buf, sizeof(stAdmin)*(-1), SEEK_CUR);
        fwrite(&aux, sizeof(stAdmin), 1, buf);
        fclose(buf);
    }
}

stAdmin modificarDatosAdmin(stAdmin aux){

        int op=0;

        mostrarAdmin(aux);

        do{

        printf("\nQue desea modificar?\n\n");
        printf("1. Nombre y apellido.\n");
        printf("2. DNI.\n");
        printf("3. Contrasenia.\n");;
        printf("4. Salir.\n");
        scanf("%i", &op);
        system("pause");
        system("cls");
        switch(op){
    case 1:
        aux = modificarnYaA(aux);
        break;
    case 2:
        aux=modificarDniA(aux);
        break;
    case 3:
        aux=modificarContraseniaA(aux);
        break;
    case 4:
        system("cls");
        break;
    default:
        printf("No existe la opcion.\n");
        break;
        }}while(op!=4);

        printf("Asi quedo modificado el admin: \n");
        mostrarAdmin(aux);
        system("pause");
        system("cls");

        return aux;
}


