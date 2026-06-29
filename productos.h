#ifndef PRODUCTOS_H
#define PRODUCTOS_H
º

typedef struct {


    int codigo;

    char nombre[100];

    int cantidad;

    float costo;

    float precioVenta;


} Producto;



Producto *cargarProductos(int *cantidad);


void mostrarProductos(
    Producto *lista,
    int cantidad
);


int buscarProducto(
    Producto *lista,
    int cantidad,
    int codigo
);


void actualizarInventario(
    Producto *lista,
    int cantidad
);


#endif
