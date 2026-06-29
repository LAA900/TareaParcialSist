#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "productos.h"



Producto *cargarProductos(int *cantidad){


    FILE *archivo;


    archivo=fopen("producto.txt","r");


    if(archivo==NULL){

        return NULL;

    }


    Producto *lista=NULL;


    Producto temp;


    int total=0;



    while(fscanf(
        archivo,
        "%d,%[^,],%d,%f,%f\n",
        &temp.codigo,
        temp.nombre,
        &temp.cantidad,
        &temp.costo,
        &temp.precioVenta
    ) != EOF){


        lista=realloc(
            lista,
            sizeof(Producto)*(total+1)
        );


        lista[total]=temp;


        total++;

    }


    fclose(archivo);


    *cantidad=total;


    return lista;

}



int buscarProducto(
    Producto *lista,
    int cantidad,
    int codigo
){


    for(int i=0;i<cantidad;i++){


        if(lista[i].codigo==codigo)
            return i;


    }


    return -1;

}




void mostrarProductos(
    Producto *lista,
    int cantidad
){


    for(int i=0;i<cantidad;i++){


        printf(
        "%d %s Stock:%d Precio:%.2f\n",
        lista[i].codigo,
        lista[i].nombre,
        lista[i].cantidad,
        lista[i].precioVenta
        );


    }

}




void actualizarInventario(
    Producto *lista,
    int cantidad
){

    FILE *archivo=fopen(
        "producto.txt",
        "w"
    );


    for(int i=0;i<cantidad;i++){


        fprintf(
        archivo,
        "%d,%s,%d,%.2f,%.2f\n",
        lista[i].codigo,
        lista[i].nombre,
        lista[i].cantidad,
        lista[i].costo,
        lista[i].precioVenta
        );


    }


    fclose(archivo);

}
