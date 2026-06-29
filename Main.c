#include <stdio.h>
#include <stdlib.h>


#include "usuarios.h"
#include "productos.h"
#include "ventas.h"



int main(){



    printf(
    "====== SISTEMA DE VENTAS ======\n"
    );



    if(!validarUsuario()){


        return 0;

    }



    int cantidadProductos;



    Producto *productos;



    productos=cargarProductos(
        &cantidadProductos
    );



    if(productos==NULL){


        printf(
        "Error cargando productos\n"
        );


        return 0;

    }



    mostrarProductos(
        productos,
        cantidadProductos
    );



    registrarVenta(
        productos,
        cantidadProductos
    );



    free(productos);



    return 0;


}
