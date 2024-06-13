#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "clientes.h"
#include "ordenamientos.h"
#include "validaciones.h"

///CLIENTE ORDEN///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarOrdenAlfabCActivo()
{
            stCliente *arrDinC;
            int validosC=0;
            validosC= ArchivoToArregloClienteActivo(&arrDinC, validosC);
            //printf("LISTA DE CLIENTES ORDENADOS:\n");
            ordenamientoSeleccionCliente(arrDinC, validosC);
            MostrarArregloCliente(arrDinC, validosC);
            if(validosC == 0){
            printf("No se encontraron clientes activos\n");
        }
}

void mostrarOrdenDNIActivosC(){

    stCliente* arrDinC;
    int validosC=0;
    validosC=ArchivoToArregloClienteActivo(&arrDinC, validosC);
    ordenamientoInserccionCliente(arrDinC, validosC);
    MostrarArregloCliente(arrDinC, validosC);
    if(validosC == 0){
            printf("No se encontraron clientes activos\n");
        }
}

void mostrarOrdenAlfabBajaC()
{
            stCliente *arrDinC;
            int validosC = 0;
            validosC = ArchivoToArregloBajaClientes(&arrDinC, validosC);
            //printf("LISTA DE CLIENTES ORDENADOS:\n");
            ordenamientoSeleccionCliente(arrDinC, validosC);
            MostrarArregloCliente(arrDinC, validosC);
            if(validosC == 0){
            printf("No se encontraron clientes dados de baja\n");
        }

}

void mostrarOrdenDNIBajaC(){

    stCliente* arrDinC;
    int validosC=0;
    validosC=ArchivoToArregloBajaClientes(&arrDinC, validosC);
    ordenamientoInserccionCliente(arrDinC, validosC);
    MostrarArregloCliente(arrDinC, validosC);
    if(validosC == 0){
            printf("No se encontraron clientes dados de baja\n");
        }

}

/// muestra archivo completo ///

void mostrarOrdenAlfabC()
{
            stCliente *arrDinC;
            int validosC=0;
            validosC= ArchivoToArregloCliente(&arrDinC, validosC);
            //printf("LISTA DE CLIENTES ORDENADOS:\n");
            ordenamientoSeleccionCliente(arrDinC, validosC);
            MostrarArregloCliente(arrDinC, validosC);
            if(validosC == 0){
            printf("No se encontraron clientes\n");
        }
}

void mostrarOrdenDNIC(){

    stCliente* arrDinC;
    int validosC=0;
    validosC=ArchivoToArregloCliente(&arrDinC, validosC);
    ordenamientoInserccionCliente(arrDinC, validosC);
    MostrarArregloCliente(arrDinC, validosC);
    if(validosC == 0){
            printf("No se encontraron clientes\n");
        }
}

///calcular registros/////////////////////////////
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

int calcularRegistrosActivosC(){

    int cant = 0;
    stCliente A;

    FILE *buf;
    buf = fopen(archCliente, "rb");

    if(buf){
        while(fread(&A, sizeof(stCliente), 1, buf))
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

int calcularRegistrosInactivosC(){

    int cant = 0;
    stCliente A;

    FILE *buf;
    buf = fopen(archCliente, "rb");

    if(buf){
        while(fread(&A, sizeof(stCliente), 1, buf))
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

int ArchivoToArregloClienteActivo(stCliente** arrD, int validos)
{

    FILE* buf;
    stCliente A;

    int cantRegistrosC = calcularRegistrosActivosC();

    *arrD = (stCliente*)malloc(sizeof(stCliente)*cantRegistrosC);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    buf = fopen(archCliente, "rb");

    if (buf){
        while(fread(&A, sizeof(stCliente), 1, buf) > 0 && validos < cantRegistrosC){
            if(A.estado == 1)
                {
                   (*arrD)[validos] = A;
                   validos++;

                }
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validos;
}

int ArchivoToArregloBajaClientes(stCliente** arrD, int validos)
{

    FILE* buf;
    stCliente A;

    int cantRegistrosC = calcularRegistrosInactivosC();

    *arrD = (stCliente*)malloc(sizeof(stCliente)*cantRegistrosC);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    buf = fopen(archCliente, "rb");

    if (buf){
        while(fread(&A, sizeof(stCliente), 1, buf) > 0 && validos < cantRegistrosC){
            if(A.estado == 0)
                {
                    (*arrD)[validos] = A;
                     validos++;
                }
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validos;
}

///ordenar arreglo/////////////////////////////////

void ordenarArrDinamicoClientes (stCliente** arrD, int validos){

    ordenamientoSeleccionCliente(*arrD, validos);

}
///mostrar arreglo/////////////////////////////////////////////////

void MostrarArregloCliente(stCliente A[], int validos){

int i;

for(i=0; i<validos; i++){
    mostrarCliente(A[i]);
    }
}
///Cargar cliente/////////////////////////////////////////////////////////////////////////////////////////////////////////////

stCliente cargarCliente()
{
    stCliente A;
    char dni[10], telefono[10];
    int flag=0, flag1=0, flagDni=0, flagTel=0;

    system("cls");
    printf("CARGANDO CLIENTE...\n");

    printf("Ingrese el nombre y apellido del cliente\n");
    fflush(stdin);
    gets(A.nYa);

    printf("\n");

    A=cargarContraseniaCliente(A);

    printf("\n");

     while(flagDni==0){
        printf("Ingrese el DNI:\n");
        fflush(stdin);
        gets(dni);
        flagDni=lenghtDNI(dni);
        if(flagDni==0){
            printf("El DNI es muy corto. Vuelva a ingresarlo.\n");
        }else{
            strcpy(A.dni, dni);
        }
    }

    printf("\n");

    printf("Ingrese la fecha de nacimiento:\n");

    while(flag!=1){
        printf("Dia:");
        scanf("%d", &A.fechaN.dia);
        flag=validarDiaFecha(A.fechaN.dia);
        if(flag!=1){
            printf("Dia invalido. Vuelva a ingresar una fecha valida.\n");
        }
    }

    while(flag1!=1){
        printf("Mes:");
        scanf("%d", &A.fechaN.mes);
        flag1=validarMesFecha(A.fechaN.mes);
        if(flag1!=1){
            printf("Mes invalido. Vuelva a ingresar un mes valido.\n");
        }
    }

    printf("Anio:");
    scanf("%i", &A.fechaN.anio);

    printf("\n");

    printf("Ingrese el genero M/F (En mayuscula)\n");
    fflush(stdin);
    scanf("%c", &A.genero);

    while((A.genero != 'M') && (A.genero !='F')){
        printf("\nSexo erroneo, ingrese nuevamente. ");
        fflush(stdin);
        scanf("%c", &A.genero);
    }

    printf("\n");

     while(flagTel==0){
        printf("Ingrese su numero de telefono celular:\n");
        fflush(stdin);
        gets(telefono);
        flagTel=lenghtTelefono(telefono);
        if(flagTel==0){
            printf("El telefono es muy corto. Vuelva a ingresarlo.\n");
        }else{
            strcpy(A.tel, telefono);
        }
    }

    printf("\n");

    printf("Ingrese el domicilio del cliente\n");
    A.dom = cargarDomicilio();

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
    printf("\n");
    printf("Nombre y Apellido: %s\n", A.nYa);
    printf("Fecha de nacimiento: %i/%i/%i\n", A.fechaN.dia, A.fechaN.mes, A.fechaN.anio);
    printf("Genero: %c\n", A.genero);
    printf("DNI: %s\n", A.dni);
    printf("Telefono: %s\n", A.tel);
    mostrarDomicilio(A.dom);
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

        fseek(buf, sizeof(stCliente)* (-1), SEEK_CUR);
        fwrite(&aux, sizeof(stCliente), 1, buf);
        fclose(buf);
    }
}

stCliente modificarDatosCliente(stCliente aux)
{

        int op=0;
        do{
        printf("\nQue desea modificar?\n\n");
        printf("1. Nombre y apellido.\n");
        printf("2. DNI.\n");
        printf("3. Fecha de nacimiento.\n");
        printf("4. Genero.\n");
        printf("5. Telefono.\n");
        printf("6. Domicilio.\n");
        printf("7. Contrasenia.\n");
        printf("8. Salir.\n");
        scanf("%i", &op);
        switch(op){
    case 1:
        aux = modificarNyAC(aux);
        break;
    case 2:
        aux=modificarDniC(aux);
        break;
    case 3:
        aux=modificarFechaNacC(aux);
        break;
    case 4:
        aux=modificarGeneroC(aux);
        break;
    case 5:
        aux=modificarTelC(aux);
        break;
    case 6:
        aux=modificarDomicilioC(aux);
        break;
    case 7:
        aux=modificarContraseniaC(aux);
        break;
    case 8:
        system("cls");
        break;
    default:
        printf("No existe la opcion.\n");
        break;
        }}while(op!=8);

        printf("Asi quedo modificado el cliente: \n");
        mostrarCliente(aux);
        system("pause");
        system("cls");

        return aux;
}
///EMPLEADO MODIFICA CLIENTE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modificarClienteEaux (char nYa[30]){

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

        aux = modificarDatosClienteEmpleado(aux);

        fseek(buf, sizeof(stCliente)* (-1), SEEK_CUR);
        fwrite(&aux, sizeof(stCliente), 1, buf);
        fclose(buf);
    }
}

stCliente modificarDatosClienteEmpleado(stCliente aux)
{

        int op=0;
        do{
        mostrarCliente(aux);
        printf("\nQue desea modificar?\n\n");
        printf("1. Nombre y apellido.\n");
        printf("2. DNI.\n");
        printf("3. Fecha de nacimiento.\n");
        printf("4. Genero.\n");
        printf("5. Telefono.\n");
        printf("6. Domicilio.\n");
        printf("8. Salir.\n");
        scanf("%i", &op);
        switch(op){
    case 1:
        aux = modificarNyAC(aux);
        break;
    case 2:
        aux=modificarDniC(aux);
        break;
    case 3:
        aux=modificarFechaNacC(aux);
        break;
    case 4:
        aux=modificarGeneroC(aux);
        break;
    case 5:
        aux=modificarTelC(aux);
        break;
    case 6:
        aux=modificarDomicilioC(aux);
        break;
    case 7:
        system("cls");
        break;
    default:
        printf("No existe la opcion.\n");
        break;
        }}while(op!=8);

        printf("Asi quedo modificado el cliente: \n");
        mostrarCliente(aux);
        system("pause");
        system("cls");

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
    int flag=0, flag1=0;

    while(flag!=1){
        printf("Ingrese su fecha de nacimiento para modificar la anterior:\n");
        printf("Dia:");
        scanf("%d", &A.fechaN.dia);
        flag=validarDiaFecha(A.fechaN.dia);
        if(flag==0){
            printf("Dia invalido. Vuelva a ingresar una fecha valida.\n");
        }
    }

    while(flag1!=1){
        printf("Mes:");
        scanf("%d", &A.fechaN.mes);
        flag1=validarMesFecha(A.fechaN.mes);
        if(flag1==0){
            printf("Mes invalido. Vuelva a ingresar un mes valido.\n");
        }
    }

    printf("Anio:");
    scanf("%i", &A.fechaN.anio);

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
    int flagDni=0;
    char dni[10];

    while(flagDni==0){
        printf("Ingrese el DNI:\n");
        fflush(stdin);
        gets(dni);
        flagDni=lenghtDNI(dni);
        if(flagDni==0){
            printf("El DNI es muy corto. Vuelva a ingresarlo.\n");
        }else{
            strcpy(A.dni, dni);
        }
    }

    return A;
}

stCliente modificarTelC(stCliente A)
{
    int flagTel=0;
    char telefono[11];

    while(flagTel==0){
        printf("Ingrese su numero de telefono celular:\n");
        fflush(stdin);
        gets(telefono);
        flagTel=lenghtTelefono(telefono);
        if(flagTel==0){
            printf("El telefono es muy corto. Vuelva a ingresarlo.\n");
        }else{
            strcpy(A.tel, telefono);
        }
    }

    return A;
}

stCliente modificarDomicilioC(stCliente A)
{
    A.dom = modificarDomicilio(A.dom);

    return A;
}

stCliente modificarContraseniaC (stCliente A){

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
            A=cargarContraseniaCliente(A);
            printf("Contrasenia actualizada con exito!\n");
            flag=1;
        }else{
            printf("Contrasenia incorrecta, vuelva a ingresar su contrasenia actual.\n");
        }
    }

    return A;
}

///Dar Baja Cliente//////////////////////////////////////////////////////////////////////////////////////////////////////////

void darBajaCliente (char nYa[]){

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

        aux = darBajaC(aux);

        fseek(buf, sizeof(stCliente)* (-1), SEEK_CUR);
        fwrite(&aux, sizeof(stCliente), 1, buf);
        fclose(buf);
    }
}

stCliente darBajaC(stCliente aux)
{

    char control = 's';

        printf("1. Desea dar de baja este cliente?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux.estado = 0;
        }

        printf("El cliente esta siendo dado de baja...\n");

        return aux;
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

    int op=0;
        do{
        printf("\nQue desea modificar?\n\n");
        printf("1. Calle.\n");
        printf("2. Numero.\n");
        printf("3. Localidad.\n");
        printf("4. Salir.\n");
        scanf("%i", &op);
        switch(op){
    case 1:
        printf("Ingrese la calle: \n");
	    fflush(stdin);
	    gets(A.calle);
        break;
    case 2:
        printf("Ingrese el numero de calle: \n");
	    fflush(stdin);
	    scanf("%i", &A.num);
        break;
    case 3:
        printf("Ingrese la localidad para modificar la anterior: \n");
        fflush(stdin);
        gets(A.localidad);
        break;
    case 4:
        system("cls");
        break;
    default:
        printf("No existe la opcion.\n");
        break;
        }}while(op!=4);

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
       while(fread(&A, sizeof(stCliente), 1, buff)>0 && flag == 0)
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
       while(fread(&A, sizeof(stCliente), 1, buf)>0 && flag == 0)
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
       while(fread(&A, sizeof(stCliente), 1, buff)>0)
        {
           if(A.genero == G)
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
       while(fread(&A, sizeof(stCliente), 1, buff)>0)
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

///CUENTA CLIENTE///////////////////////////////////////////////////////////////////////

stCliente cargarContraseniaCliente(stCliente A)
{
    char contrasenia[30];
    char contrasenia2[30];
    int flag=0;
    printf("Ingrese su contrasenia:  \n");
    fflush(stdin);
    gets(contrasenia);
    flag= lenghtContrasenia(contrasenia);

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

void registrarCliente() {

    FILE *buf;
    buf=fopen(archCliente, "ab");
    stCliente A;

    if(buf){
        A=cargarCliente();
        fwrite(&A, sizeof(stCliente), 1, buf);
        fclose(buf);
        printf("\nCliente registrado con exito.\n\n");
    }else{
        printf("No se pudo abrir el archivo.\n");
    }
}

stCliente busquedaClienteInicioSesion (char dni[], char contrasenia[])
{
    FILE* buf;
    buf=fopen(archCliente, "rb");
    int flag=0;
    stCliente A;

    if(buf)
    {
        while(flag != 1 && fread(&A, sizeof(stCliente), 1, buf)>0)
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

stCliente iniciarSesionCliente() {

    FILE *buf;
    buf = fopen(archCliente, "rb");
    char dni[10];
    char contrasenia[20];
    stCliente A;
    int flag=0;

    if(buf){
        while(flag!=1){

        printf("\nIngrese el DNI:\n");
        fflush(stdin);
        gets(dni);

        printf("\nIngrese contrasenia:\n");
        fflush(stdin);
        gets(contrasenia);
        A=busquedaClienteInicioSesion(dni, contrasenia);

        if((strcmp(A.dni, dni)==0) && strcmp(A.contrasenia, contrasenia)==0){
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


