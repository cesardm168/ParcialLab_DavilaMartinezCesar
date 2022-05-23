#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int listarCliente(eCliente clientes[], int tam)
{
    int todoOk = 0;

    if(clientes != NULL && tam > 0)
    {
        //system("cls");
        printf("________________________________________\n");
        printf("|                                       |\n");
        printf("|   *** Lista de Clientes           *** |\n");
        printf("|_______________________________________|\n");
        printf("|                                       |\n");
        printf("|    Id     |  Nombre        |   Sexo   |\n");
        printf("|_______________________________________|\n");
        for(int i=0; i < tam; i++)
        {
            printf("|  %4d     %13s       %c      |\n", clientes[i].id, clientes[i].nombre ,clientes[i].sexo);
        }
        printf("|_______________________________________|\n");
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionCliente(eCliente clientes[], int tam, int id, char nombre[])
{
    int todoOk = 0;
    int indice;

    buscarCliente(clientes,tam, id, &indice);

    if(nombre != NULL && indice != -1)
    {

        strcpy(nombre, clientes[indice].nombre);

        todoOk = 1;
    }
    return todoOk;
}


int buscarCliente (eCliente clientes[],int tam, int id, int* pIndice)
{
    int todoOk = 0;

    if(clientes != NULL && tam > 0 && pIndice != NULL )
    {
        *pIndice= - 1;
        for(int i=0; i < tam; i++)
        {
            if(clientes[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;

}

int validarCliente(eCliente  clientes[], int tam, int id){
    int esValido=0;
    int indice;

    buscarCliente(clientes, tam, id , &indice);

    if (indice != -1){
        esValido = 1;
    }

    return esValido;
}

