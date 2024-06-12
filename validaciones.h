#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int lenghtContrasenia(char contrasenia[]);
int lenghtDNI(char dni[]);
int lenghtTelefono(char telefono[]);
int validacionContrasenia (char contrasenia[], char contrasenia2[]);
int validarDiaFecha(int dia);
int validarMesFecha(int mes);
int validarExistenciaCliente (char dniC[]);
int validarExistenciaEmpleado (char dniE[]);

#endif // VALIDACIONES_H_INCLUDED
