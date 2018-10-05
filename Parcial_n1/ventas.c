#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "ventas.h"
#define A_COBRAR 0

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Cliente* array,int limite);
//__________________



/** \brief
 * \param array Pantalla*
 * \param limite int
 * \return int
 *
 */
int initVenta(Venta* arrayVenta,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayVenta != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayVenta[i].isEmpty=1;
        }
    }
    return retorno;
}

int venta_alta(Venta* arrayVenta,int limite, Cliente* array, int lenClientes, int id)
{
    int retorno = -1;
    int indice;
    int cantAfiches;
    char nombreArchivoImagen[51];
    int zona;
    int menu;
    int auxiliarId;

    if(limite > 0 && arrayVenta != NULL)
    {
        indice = buscarLugarLibre(arrayVenta,limite);

        if(indice >= 0)
        {

            getValidInt("ID del cliente?","\nNumero valida\n",&auxiliarId,0,200,2);
            cliente_buscarPorId(array, lenClientes, id);

            if(!getValidInt("\n Cantidad de afiches? ","\nEso no es un afiches",&cantAfiches,0,1000,2))
            {
                if(!getValidString("\n Nombre del archivo? ","\nEso no es un nombre","El maximo es 40",nombreArchivoImagen,40,2))
                {
                        if(!getValidInt("\n Elija una zona para pegar sus afiches\n \n1.CABA \n2.ZONA SUR \n3.ZONA OESTE\n","\nNo valida\n",&menu,1,4,1))
                        {
                            do {
                                switch(menu) {

                                    case 1:
                                        if(arrayVenta[indice].zona == 1) {

                                            printf("La zona elegida es CABA");
                                        }
                                        break;
                                    case 2:
                                         if(arrayVenta[indice].zona == 1) {

                                            printf("La zona elegida es CABA");
                                        }
                                        break;
                                    case 3:
                                         if(arrayVenta[indice].zona == 1) {

                                            printf("La zona elegida es CABA");
                                        }
                                        break;
                                    case 4:
                                        break;

                                }

                            }while(menu != 4);

                            retorno = 0;
                            arrayVenta[indice].cantAfiches = cantAfiches;
                            strcpy(arrayVenta[indice].nombreArchivoImagen,nombreArchivoImagen);
                            arrayVenta[indice].zona  = zona;
                            //------------------------------
                            //------------------------------
                            arrayVenta[indice].idVenta = proximoId();
                            arrayVenta[indice].isEmpty = 0;
                            arrayVenta[indice].estado = A_COBRAR;
                        }

                }
            }

        }
    }
    return retorno;

}

/*
int cliente_baja(Cliente* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    int opcion;
    int menu;
    indiceAEliminar = cliente_buscarPorId(array,limite,id);

    do {
        getValidInt("\n\n1.Confirmar baja de cliente y venta\n2.NO dar de baja","\nNo valida\n",&menu,1,2,1);
        switch(opcion) {

        case 1:
            if(indiceAEliminar>=0)
            {
                array[indiceAEliminar].isEmpty=1;
                retorno=0;
                break;
            }
        case 2:
        break;

        }

    }while(menu != 2);

    return retorno;
}




int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[51];


    indiceAModificar = cliente_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
         if(!getValidString("\n Ingrese un nuevo nombre? ","\nEso no es un nombre","El maximo es 40",auxNombre,40,2))
            {
                if(!getValidString("\n Ingrese un nuevo apellido? ","\nEso no es un apellido","El maximo es 40",auxApellido,40,2))
                {
                        if(!pedirCUIT(auxCuit, "\n CUIT?", "Error", 2))
                        {
                            retorno = 0;
                            strcpy(array[indiceAModificar].nombre,auxNombre);
                            strcpy(array[indiceAModificar].apellido,auxApellido);
                            strcpy(array[indiceAModificar].cuit,auxCuit);
                            //------------------------------
                            //------------------------------
                            array[indiceAModificar].id = proximoId();
                            array[indiceAModificar].isEmpty = 0;
                        }

                }
            }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}
*/
static int buscarLugarLibre(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

