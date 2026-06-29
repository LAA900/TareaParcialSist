#include <stdio.h>
#include <string.h>

#include "usuarios.h"


int validarUsuario(){

    FILE *archivo;

    Usuario u;


    char usuarioIngresado[50];
    char claveIngresada[50];


    int intentos = 0;


    while(intentos < 3){


        printf("\nUsuario: ");
        scanf("%s", usuarioIngresado);


        printf("Clave: ");
        scanf("%s", claveIngresada);



        archivo = fopen("vendedores.txt","r");


        if(archivo == NULL){

            printf("Error archivo vendedores\n");
            return 0;

        }


        while(fscanf(
            archivo,
            "%[^,],%[^,],%[^\n]\n",
            u.usuario,
            u.clave,
            u.nombre
        ) != EOF){



            if(strcmp(usuarioIngresado,u.usuario)==0 &&
               strcmp(claveIngresada,u.clave)==0){


                fclose(archivo);

                printf("\nBienvenido %s\n",u.nombre);

                return 1;

            }

        }


        fclose(archivo);


        printf("Datos incorrectos\n");


        intentos++;

    }


    printf("Demasiados intentos\n");


    return 0;

}
