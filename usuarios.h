#ifndef USUARIOS_H
#define USUARIOS_H

typedef struct {

    char usuario[50];
    char clave[50];
    char nombre[100];

} Usuario;


int validarUsuario();


#endif
