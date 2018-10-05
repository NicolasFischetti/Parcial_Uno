#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "ventas.h"
#define CLIENTES 100
#define VENTAS 1000


int main()
{
    Cliente array[CLIENTES];
    Venta arrayVenta[VENTAS];
    int menu;
    int auxiliarId;

    do
    {
        getValidInt("\n\n1.Alta Cliente\n2.Baja Cliente\n3.Modificar Cliente\n4.Vender Afiches\n5.Editar Ventas\n6.Cobrar Ventas\n7.Imprimir ventasles\n.8. Salir\n","\nNo valida\n",&menu,1,8,1);

        switch(menu)
        {
            case 1:
                cliente_alta(array, CLIENTES);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_baja(array,CLIENTES,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_modificacion(array,CLIENTES,auxiliarId);
                break;
            case 4:
                venta_alta(arrayVenta,VENTAS,array, CLIENTES, auxiliarId);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;


        }

    }while(menu != 8);

    return 0;
}

