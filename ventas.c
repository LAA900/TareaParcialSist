#include <stdio.h>
#include <string.h>
#include <time.h>

#include "ventas.h"



int obtenerFactura(){


    FILE *archivo;


    archivo=fopen(
        "ventas.txt",
        "r"
    );


    if(archivo==NULL)
        return 1;



    int ultima=0;


    Venta v;



    while(fscanf(
        archivo,
        "%d,%d,%[^,],%d,%f,%f,%s\n",
        &v.factura,
        &v.codigoProducto,
        v.nombreProducto,
        &v.cantidad,
        &v.costo,
        &v.precioVenta,
        v.fecha

    )!=EOF){


        ultima=v.factura;

    }


    fclose(archivo);



    return ultima+1;


}




void registrarVenta(
    Producto *productos,
    int cantidadProductos
){



    Venta venta;



    int factura=obtenerFactura();


    FILE *archivo;



    archivo=fopen(
        "ventas.txt",
        "a"
    );



    time_t t=time(NULL);


    struct tm fechaActual=*localtime(&t);



    char fecha[11];


    sprintf(
        fecha,
        "%04d-%02d-%02d",
        fechaActual.tm_year+1900,
        fechaActual.tm_mon+1,
        fechaActual.tm_mday
    );



    printf("\nFactura: %d\n",factura);

    printf("Fecha: %s\n",fecha);



    char continuar='s';



    while(continuar=='s'){



        int codigo;

        int cantidad;



        printf("\nCodigo producto: ");

        scanf("%d",&codigo);



        int pos=buscarProducto(
            productos,
            cantidadProductos,
            codigo
        );



        if(pos==-1){


            printf("Producto no existe\n");

            continue;

        }



        printf("Cantidad:");

        scanf("%d",&cantidad);



        if(cantidad >
           productos[pos].cantidad){



            printf(
            "Inventario insuficiente\n"
            );

            continue;

        }



        printf(
        "%s total %.2f\n",
        productos[pos].nombre,
        productos[pos].precioVenta*cantidad
        );



        productos[pos].cantidad -= cantidad;



        fprintf(
        archivo,
        "%d,%d,%s,%d,%.2f,%.2f,%s\n",
        factura,
        productos[pos].codigo,
        productos[pos].nombre,
        cantidad,
        productos[pos].costo,
        productos[pos].precioVenta,
        fecha
        );



        printf(
        "Agregar otro producto? s/n: "
        );


        scanf(" %c",&continuar);


    }



    fclose(archivo);



    actualizarInventario(
        productos,
        cantidadProductos
    );



    printf("\nVenta registrada\n");


}
