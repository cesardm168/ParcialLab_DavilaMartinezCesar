#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "validaciones.h"
#include "tipo.h"
#include "fecha.h"
#include "cliente.h"


#define TAM 30
#define TAMT 5
#define TAMC 5
#define TAMS 3
#define TAMTRA 10
#define TAMCLI 5


int main()
{
    char salir ='n';
    int proximoId = 6000;
    eMascota mascotas[TAM];
    int proximoIdTrabajo = 8000;
    eTrabajo trabajos[TAMTRA];
    eTipo tipos[TAMT] =
    {
        {1000, "Ave"},
        {1001, "Roedor"},
        {1002, "Gato"},
        {1003, "Pez"},
        {1004, "Perro"}
    };
      eColor colores[TAMC] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"}
    };
       eServicio servicios[TAMS] =
    {
        {20000, "Corte", 450},
        {20001, "Desparasitado", 800},
        {20002, "Castrado",600}
    };
       eCliente clientes[TAMCLI] =
    {
        {3000, "Manuel", 'm'},
        {3001, "Laura", 'f'},
        {3002, "Carlos",'m'},
        {3003, "Daniela", 'f'},
        {3004, "Sofia",'f'}
    };
    inicializarMascotas(mascotas,TAM);
    inicializarTrabajo(trabajos,TAMTRA);

    hardcodearMascotas(mascotas, TAM,10, &proximoId);
    hardcodearTrabajos(trabajos, TAMTRA,10, &proximoIdTrabajo);

    do {
		switch (menu()) {
		case 1:
			if( altaMascota(mascotas, TAM, tipos, TAMT,colores,TAMC, &proximoId, clientes, TAMCLI))
            {
                printf("Mascota agregada con exito!!!\n");
            }
            else
            {
                printf("Problema al hacer el alta de Mascota\n");
            }

			break;
		case 2:
			if( modificarMascota(mascotas, TAM, tipos, TAMS, colores, TAMC, clientes, TAMCLI) == 0)
            {
                printf("Problema al hacer la modificacion de la mascota \n");
            }
			break;
		case 3:
			 if( bajaMascota(mascotas, TAM, tipos, TAMT, colores, TAMC, clientes, TAMCLI) == 0)
            {
                printf("Problema al hacer la baja de empleado\n");
            }
			break;
		case 4:
		    ordenarMascotasPorTipoYNombre(mascotas,TAM);
			listarMascota(mascotas,TAM,tipos,TAMT,colores,TAMC, clientes, TAMCLI);
			break;
		case 5:
			listarTipo(tipos,TAMT);
			break;
        case 6:
			listarColor(colores,TAMC);
			break;
        case 7:
			listarServicio(servicios,TAMS);
			break;
        case 8:
			 if( altaTrabajo(trabajos, TAMTRA, mascotas, TAM, tipos, TAMT, colores, TAMC,servicios, TAMS, &proximoIdTrabajo, clientes, TAMCLI))
            {
                printf("Trabajo agregado con exito!!!\n");
            }
            else
            {
                printf("Problema al hacer el alta de Trabajo\n");
            }

			break;
        case 9:
			listarTrabajo(trabajos,TAMTRA,mascotas,TAM, tipos, TAMT,colores,TAMC,servicios,TAMS);
			break;
          case 10:
			mostrarInformes(mascotas, TAM, tipos, TAMT, colores, TAMC, clientes, TAMCLI);
			break;
            case 11:
           // mostrarInformesTrabajo(trabajos,TAMTRA,mascotas, TAM,tipos,TAMT,colores, TAMC,clientes , TAMCLI);
			break;

        case 12:

			salir = 's';
			break;
		default:
			printf("La Opcion ingresada es incorrecta\n");
		}
		system("pause");
	} while (salir != 's');

}
