#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
typedef struct
{
 int idCliente;
 int idVenta;
 int cantAfiches;
 char nombreArchivoImagen[51];
 int zona;
 int estado;
 int isEmpty;
}Venta;



#endif // VENTAS_H_INCLUDED
int initVenta(Venta* arrayVenta,int limite);
int venta_alta(Venta* arrayVenta,int limite, Cliente* array, int lenClientes, int id);
