#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "mascotas.h"
#include "validaciones.h"
#include "trabajo.h"
#include "cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializarTrabajo(eTrabajo vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}




int altaTrabajo(eTrabajo trabajos[], int tamTra, eMascota mascotas[], int tamMas, eTipo tipos[], int tamTip,eColor colores[],int tamCol, eServicio servicios[], int tamSer, int* pIdTrabajo, eCliente clientes[],int tamCli ){
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    eFecha fecha;

    if(trabajos != NULL && mascotas != NULL && tipos != NULL && colores != NULL && servicios != NULL && pIdTrabajo != NULL && tamTra> 0 && tamMas > 0 && tamTip > 0 && tamCol > 0&& tamSer > 0)
    {

        //system("cls");
        printf("__________________________________________________\n");
        printf("|                                                |\n");
        printf("|           *** Alta Trabajos  ***               |\n");
        printf("|________________________________________________|\n");
        printf("|                                                |\n");

        if( buscarTrabajoLibre(trabajos, tamTra, &indice) )
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar
                listarMascota(mascotas, tamMas, tipos, tamTip, colores, tamCol, clientes, tamCli);
                printf("Ingrese id Mascota\n");
                scanf("%d", &nuevoTrabajo.idMascota);
                buscarMascota(mascotas, tamMas, nuevoTrabajo.idMascota, &indice);

                while( indice == -1){
                printf("Mascota invalido. Ingrese id Mascota\n");
                scanf("%d", &nuevoTrabajo.idMascota);
                buscarMascota(mascotas, tamMas, nuevoTrabajo.idMascota, &indice);
                }

                listarServicio(servicios, tamSer );
                printf("Ingrese Id del Servicio\n");
                scanf("%d", &nuevoTrabajo.idServicio);

                while( !validarServicio(servicios, tamSer, nuevoTrabajo.idServicio )){
                printf("Error, Servicio invalido. Ingrese Id Servicio\n");
                scanf("%d", &nuevoTrabajo.idServicio);
                }

                printf("Ingrese Fecha  dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                validarUnaFecha(fecha);
                nuevoTrabajo.fecha = fecha;

                nuevoTrabajo.isEmpty = 0;
                nuevoTrabajo.id = *pIdTrabajo;
                *pIdTrabajo = *pIdTrabajo + 1;
                trabajos[indice] = nuevoTrabajo;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int listarTrabajo(eTrabajo trabajos[], int tamTra, eMascota mascotas[], int tamMas, eTipo tipos[], int tamTip,eColor colores[],int tamCol, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    int flag = 0;
    char descripcion[20];
    char nombre[20];

     if(trabajos != NULL && mascotas != NULL && tipos != NULL && colores != NULL && servicios != NULL &&  tamTra> 0 && tamMas > 0 && tamTip > 0 && tamCol > 0&& tamSer > 0)
    {


        //system("cls");
        printf("_______________________________________________________________\n");
        printf("|                                                              |\n");
        printf("|          *** Listado de Trabajos ***                         |\n");
        printf("|______________________________________________________________|\n");
        printf("|                                                              |\n");
        printf("|  Id    IdMascota     Nombre      Servicio         Fecha      | \n");
        printf("|______________________________________________________________|\n");
        printf("|                                                              |\n");

        for(int i=0; i < tamTra; i++)
        {
            if( !trabajos[i].isEmpty )
            {
                cargarDescripcionMascota(mascotas,tamMas,mascotas[i].id,nombre);
                cargarDescripcionServicio(servicios, tamSer, trabajos[i].idServicio, descripcion);
                printf("|%5d     %5d      %-10s  %-13s     %02d/%02d/%02d |\n",
                       trabajos[i].id,
                       trabajos[i].idMascota,
                       nombre ,
                       descripcion,
                       trabajos[i].fecha.dia,
                       trabajos[i].fecha.mes,
                       trabajos[i].fecha.anio);
                printf("|______________________________________________________________|\n");
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay Mascotas  en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}






