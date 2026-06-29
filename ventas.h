#ifndef VENTAS_H
#define VENTAS_H


#include "productos.h"


typedef struct{


    int factura;

    int codigoProducto;

    char nombreProducto[100];

    int cantidad;

    float costo;

    float precioVenta;

    char fecha[11];


} Venta;



int obtenerFactura();



void registrarVenta(
    Producto *productos,
    int cantidadProductos
);



#endif
