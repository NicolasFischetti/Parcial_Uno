#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "ventas.h"
#define DEFINE_DEL_ARCHIVO  "hola"

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
int initCliente(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

/*int cliente_mostrar(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("%s - %s - %d\n",array[i].nombre, array[i].apellido, array[i].cuilt);
        }
    }
    return retorno;
}*/

int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    int indice;
    char nombre[51];
    char apellido[51];
    char Auxcuit[51];

    if(limite > 0 && array != NULL)
    {
        indice = buscarLugarLibre(array,limite);

        if(indice >= 0)
        {

            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",apellido,40,2))
                {
                        if(!pedirCUIT(Auxcuit, "CUIT?", "Error", 2))
                        {
                            retorno = 0;
                            strcpy(array[indice].nombre,nombre);
                            strcpy(array[indice].apellido,apellido);
                            strcpy(array[indice].cuit,Auxcuit);
                            //------------------------------
                            //------------------------------
                            array[indice].id = proximoId();
                            array[indice].isEmpty = 0;
                        }

                }
            }

        }
    }
    return retorno;

}


int cliente_baja(Cliente* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    int opcion;
    int menu;
    indiceAEliminar = cliente_buscarPorId(array,limite,id);

    do {
        getValidInt("\n\n1.Confirmar baja de cliente y venta\n2.NO dar de baja\n","\nNo valida\n",&menu,1,2,1);

        switch(opcion) {

        case 1:
            if(indiceAEliminar>=0)
            {
                array[indiceAEliminar].isEmpty=1;
                retorno=0;

            }
            break;
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


int cliente_buscarPorId(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].id ==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
