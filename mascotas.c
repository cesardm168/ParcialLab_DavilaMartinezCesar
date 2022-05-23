#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascotas.h"


int menu() {
	int opcion;
	system("cls");
	printf("________________________________________\n");
	printf("|                                       |\n");
	printf("|       ***  UTN  Veterinaria  **       |\n");
	printf("|_______________________________________|\n");
	printf("|                                       |\n");
	printf("| 1.-  Altas de Mascotas                |\n");
	printf("| 2.-  Modificar Mascotas               |\n");
	printf("| 3.-  Baja de mascotas                 |\n");
	printf("| 4.-  Listar Mascotas                  |\n");
	printf("| 5.-  Listar Tipos                     |\n");
	printf("| 6.-  Listar Colores                   |\n");
	printf("| 7.-  Listar Servicios                 |\n");
	printf("| 8.-  Alta Trabajo                     |\n");
	printf("| 9.-  Listar Trabajo                   |\n");
	printf("| 10.-  Informes                        |\n");
	printf("| 11.-  Informes de trabajo             |\n");
	printf("| 12.-  Salir                           |\n");
	printf("|_______________________________________|\n");
	printf(" Ingrese Opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int inicializarMascotas(eMascota vec[], int tam)
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


int buscarMascotaLibre(eMascota vec[], int tam, int* pIndex)
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

int altaMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip,eColor colores[],int tamCol,  int* pIdMascota, eCliente clientes[], int tamCli){
    int todoOk = 0;
    int indice;
    char auxCad[100];
   // int sw;
    eMascota nuevoMascota;
    eFecha fecha;

    if(vec != NULL && tam > 0 && pIdMascota != NULL)
    {
        if( buscarMascotaLibre(vec, tam, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
               // utn_getName(&nuevoMascota.nombre, "Ingrese el nombre de la mascota", "Error, ingrese un nombre correcto",3);
                printf("Ingrese el nombre de la Mascota: ");
                fflush(stdin);
                gets(auxCad);

               // ingresaNombre(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoMascota.nombre, auxCad);;


                fflush(stdin);
                utn_getNumero(&nuevoMascota.edad,"Ingrese La edad: ", "Error, ha ingresado una edad incorrecta: ",0,20,3);
               // scanf("%d", &nuevoMascota.edad);
               /* sw = validadNumero(&nuevoMascota.edad);
                if(sw ==0){
                    printf("Edad valida");
                }else{
                printf("Edad Invalida");
                }*/


                printf("Esta vacunado Si o No?: s ó n   ");
                 fflush(stdin);
                scanf("%c", &nuevoMascota.vacunado);

                listarTipo(tipos, tamTip);

                printf("Ingrese Id Tipo: ");
                scanf("%d", &nuevoMascota.idTipo);

                while( !validarTipo(tipos,tamTip, nuevoMascota.idTipo))
                {
                    printf("Tipo invalido.Ingrese Id Tipo: ");
                    scanf("%d", &nuevoMascota.idTipo);
                }


                printf("Ingrese Fecha ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                validarUnaFecha(fecha);
                nuevoMascota.fIngreso = fecha;


                listarColor(colores, tamCol);

                printf("Ingrese Id del color: ");
                scanf("%d", &nuevoMascota.idColor);

                while( !validarColor(colores,tamCol, nuevoMascota.idColor))
                {
                    printf("Color invalido.Ingrese Id color: ");
                    scanf("%d", &nuevoMascota.idColor);
                }

                listarCliente(clientes,tamCli);
                printf("Ingrese id del cliente: ");
                scanf("%d", &nuevoMascota.idCliente);

                 while( !validarCliente(clientes,tamCli, nuevoMascota.idCliente))
                {
                    printf("Cliente invalido.Ingrese Id cliente: ");
                    scanf("%d", &nuevoMascota.idCliente);
                }




                nuevoMascota.isEmpty = 0;
                nuevoMascota.id = *pIdMascota;
                *pIdMascota = *pIdMascota + 1;
                vec[indice] = nuevoMascota;
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


int modificarMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[],int tamCli )
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';
    char auxCad[100];

    if(vec != NULL && tam > 0)
    {
      listarMascota(vec, tam, tipos, tamTip, colores, tamCol, clientes, tamCli);
        printf("Ingrese ID: ");
        scanf("%d", &id);
        if( buscarMascota(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una Mascota con Id %d\n", id);
            }
            else
            {
                mostrarMascota(vec[indice], tipos,  colores,tam, clientes);


                do
                {
                    switch(menuModificarMascota())
                    {

                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(vec[indice].nombre, auxCad);
                        printf("Se ha modificado el nombre\n");
                        break;

                    case 2:
                        listarTipo(tipos, tamTip);
                        printf("Ingrese Id Tipo: ");
                        fflush(stdin);
                        scanf("%d", &vec[indice].idTipo);

                        while( !validarTipo(tipos,tamTip, vec[indice].idTipo))
                        {
                            printf("Tipo invalido.Ingrese Id Tipo: ");
                            scanf("%d", &vec[indice].idTipo);
                        }

                        printf("Se ha modificado el Tipo de la mascota\n");
                        break;

                    case 3:
                        listarColor(colores, tamCol);

                        printf("Ingrese Id del color: ");
                         fflush(stdin);
                        scanf("%d", &vec[indice].idColor);

                        while( !validarColor(colores,tamCol, vec[indice].idColor))
                        {
                            printf("Color invalido.Ingrese Id color: ");
                            scanf("%d", &vec[indice].idColor);
                        }

                        printf("Se ha modificado el Color de la mascota\n");

                        break;
                    case 4:
                        fflush(stdin);
                        utn_getNumero(&vec[indice].edad,"Ingrese La Nueva edad: ", "Error, ha ingresado una edad incorrecta: ",0,20,3);
                        printf("Se ha modificado la edad\n");

                        break;
                    case 5:
                        printf("Ingrese si esta vacunada la mascota : s or  n ");
                        fflush(stdin);
                        scanf("%c", &vec[indice].vacunado);
                        printf("Se ha modificado la vacuna\n");
                        break;
                    case 6:
                        salir = 's';
                        break;
                    }
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar la mascota\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int listarMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[],int tamCli )
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf(" _______________________________________________________________________________\n");
        printf("|                                                                               |\n");
        printf("|             *** Listado de Mascotas ***                                       |\n");
        printf("|_______________________________________________________________________________|\n");
        printf("|                                                                               |\n");
        printf("| Id         Nombre        Tipo       Color    Edad  vacuna  F.Ingreso  Duenho  |\n");
        printf("|_______________________________________________________________________________|\n");

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarMascota(vec[i], tipos, colores,tam, clientes);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay Mascotas en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarMascota(eMascota mascotas, eTipo tipos[],eColor colores[], int tam, eCliente clientes[])
{
    int todoOk = 0;
    char descTipo[20];
    char descColor[20];
   char descNombre[20];


    if((tipos != NULL && tam > 0 ) || (colores != NULL && tam > 0)|| (clientes != NULL && tam > 0))
    {

        cargarDescripcionTipo( tipos, tam, mascotas.idTipo, descTipo);
        cargarDescripcionColor(colores,tam,mascotas.idColor,descColor);
        cargarDescripcionCliente(clientes, tam, mascotas.idCliente, descNombre);

        printf("|%4d   %10s     %8s    %10s    %2d    %-1c   %02d/%02d/%d %10s|\n",
               mascotas.id,
               mascotas.nombre,
               descTipo,
               descColor,
               mascotas.edad,
               mascotas.vacunado,
               mascotas.fIngreso.dia,
               mascotas.fIngreso.mes,
               mascotas.fIngreso.anio,
               descNombre
            );
        printf("|_______________________________________________________________________________|\n");
        todoOk = 1;
    }
    return todoOk;
}


int menuModificarMascota()
{
    int opcion;
    printf("________________________________________\n");
    printf("|                                       |\n");
    printf("|     *** Campos a modificar ***        |\n");
    printf("|_______________________________________|\n");
    printf("|                                       |\n");
    printf("| 1- Nombre                             |\n");
    printf("| 2- tipo                               |\n");
    printf("| 3- color                              |\n");
    printf("| 4- edad                               |\n");
    printf("| 5- Vacunado                           |\n");
    printf("| 6- Salir                              |\n");
    printf("|_______________________________________|\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}


int buscarMascota(eMascota vec[], int tam,int id, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int bajaMascota(eMascota vec[], int tam,eTipo tipos[], int tamTip,eColor colores[],int tamCol, eCliente clientes[],int tamCli )
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec != NULL && tam > 0)
    {
        listarMascota(vec, tam, tipos, tamTip, colores, tamCol,clientes, tamCli);
        printf("Ingrese ID: ");
        scanf("%d", &id);
        if( buscarMascota(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay Mascotas  con ese Id %d\n", id);
            }
            else
            {
                mostrarMascota(vec[indice], tipos,colores, tam ,clientes);
                printf("Confirma baja?: s o n ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar a la mascota \n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int hardcodearMascotas(eMascota vec[], int tam, int cant, int* pId)
{

    int todoOk = 0;
    eMascota impostores[] =
    {
        {0, "Harry", 1001, 5000, 4,{2,5,2022},'s',3000},
        {0, "Ron", 1000, 5002, 3,{4,3,2022},'n',3001},
        {0, "Bobbis",1003, 5004, 11,{30,2,2021},'s',3002},
        {0, "Pusheen", 1002,5003, 8,{1,2,2022},'s',3003},
        {0, "Luna", 1004, 5002,7,{20,5,2022}, 'n',3004},
        {0, "Firulais", 1004,5004, 1,{15,4,2022},'s',3002},
        {0, "Manchas", 1002, 5000, 5,{7,3,2022},'s',3001},
        {0, "Alma", 1003, 5001, 6,{6,1,2022},'n',3004},
        {0, "Zeus", 1004, 5004, 3,{29,1,2022},'n',3000},
        {0, "Pelusa", 1001, 5002, 7,{2,4,2022},'s',3001}
    };

    if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }
    return todoOk;

}


int cargarDescripcionMascota(eMascota mascota[], int tam, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarMascota(mascota,tam, id, &indice);

    if(descripcion != NULL && indice != -1)
    {

        strcpy(descripcion, mascota[indice].nombre);
        todoOk = 1;
    }
    return todoOk;
}


int ordenarMascotasPorTipoYNombre(eMascota vec[], int tam)
{
    int todoOk = 0;
    eMascota auxMascota;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                //se ordena por nombre
                if(strcmp(vec[i].nombre, vec[j].nombre) > 0)

                 {
                    auxMascota = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxMascota;
               }//se ordena por tipo
                if (  vec[i].idTipo<vec[j].idTipo){
                    auxMascota = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxMascota;
                }
        }
        todoOk = 1;
    }
}

    return todoOk;
}

int menuInformes()
{
    int opcion;
    printf("___________________________________________\n");
    printf("|                                         |\n");
    printf("|     *** Informes de Mascotas  ***       |\n");
    printf("|_________________________________________|\n");
    printf("|                                         |\n");
    printf("| 1- Mascotas por color seleccionado      |\n");
    printf("| 2- Promedio mascotas vacunadas          |\n");
    printf("| 3- Mascotas de menor edad               |\n");
    printf("| 4- Mascotas por tipo                    |\n");
    printf("| 5- Mascotas por tipo y color            |\n");
    printf("| 6- Colores con mas cantidad de mascotas |\n");
    printf("| 7- Salir                                |\n");
    printf("|_________________________________________|\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int mostrarInformes(eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[],int tamCli )
{

    int todoOk = 0;
   // int indice;
 //   int id;
    char salir = 'n';
  //  char auxCad[100];

    do{
        switch (menuInformes()) {
		case 1:
		    informarXColor(vec,tam,tipos,tamTip,colores,tamCol,clientes, tamCli);
		    break;
        case 2:
            informarPromedioVacunados(vec, tam);
		    break;
        case 3:
            listarMascotaMenorE(vec, tam, tipos,tamTip, colores,tamCol,clientes,tamCli);
		    break;
        case 4:
            informarMascotasXTipo(vec, tam, tipos, tamTip, colores, tamCol, clientes,tamCli);
		    break;
        case 5:
            informarMascotasTipo(vec, tam, tipos, tamTip, colores, tamCol, clientes, tamCli);
		    break;
        case 6:
            colorMasCantidad(vec,tam,tipos,tamTip,colores,tamCol);
		    break;
        case 7:
            salir = 's';
		    break;
}
   }while (salir != 's');
return todoOk;
}


int informarXColor(eMascota vec[], int tam,eTipo tipos[], int tamTip, eColor colores[],int tamCol , eCliente clientes[],int tamCli )
{
    int todoOk = 0;
    int idColor;
    int flag = 1;
    char descripcion[20];


    if(vec != NULL && tipos != NULL && tam > 0 && tamTip > 0 && colores !=NULL && tamCol>0)
    {
        system("cls");


        listarColor(colores, tamCol);

        printf("Ingrese Id del color: ");
        fflush (stdin);
        scanf("%d", &idColor);

        while( !validarColor(colores,tamCol, idColor))
        {
            printf("Color invalido.Ingrese Id Color: ");
            scanf("%d", &idColor);
        }
        printf("   *** Listado de Mascotas por color  ***\n");
        printf("---------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].idColor == idColor)
            {
                mostrarMascota(vec[i],tipos, colores, tamCol,clientes);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionColor(colores,tamCol, idColor, descripcion);
            printf("No hay Mascotas regstrada con ese color %s\n", descripcion );
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}


int informarPromedioVacunados(eMascota vec[], int tam)
{

    int todoOk = 0;
    float acumVacunados = 0;
    int contVacunados = 0;
    float promedio = 0;

    if(vec != NULL && tam > 0 )
    {

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].vacunado== 's')
            {
                acumVacunados += vec[i].vacunado;
                contVacunados++;
            }
        }

        if(contVacunados > 0)
        {
            promedio = acumVacunados / contVacunados;
        }

        system("cls");
        printf("    *** Informe de Mascotas vacunadas   ***\n\n");
        printf("Promedio: $ %.2f\n", promedio);

        todoOk = 1;
    }
    return todoOk;

}


int listarMascotaMenorE(eMascota vec[], int tam,eTipo tipos[], int tamtip, eColor colores[], int tamCol , eCliente clientes[],int tamCli )
{
    int todoOk = 0;
    int edad;
    if(vec != NULL && tam > 0 )
    {
        system("cls");
        printf("Ingrese edad: ");
        scanf("%d", &edad);

        system("cls");
        printf("    *** Informe de mascotas de menor edad   ***\n", edad);
        printf(" Id          Nombre         Tipo       Color        Edad          F.Ingreso\n");
        printf("-------------------------------------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].edad < edad )
            {
                mostrarMascota(vec[i], tipos, colores, tam,clientes );
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int informarMascotasXTipo(eMascota vec[], int tam,eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[],int tamCli )
{
    int todoOk = 0;
    int flag;

    if(vec != NULL && tipos != NULL && tam > 0 && tamTip > 0 && colores != NULL && tamCol>0)
    {
        system("cls");
        printf("    *** Listado de Mascotas por Tipo ***\n");
        printf("-----------------------------------------------------\n");

        for(int t=0; t < tamTip; t++)
        {
            printf("Tipo: %s\n\n", tipos[t].descripcion );
            printf(" Id       Nombre           Tipo        Color    Edad  Vacuna F.Ingreso      \n");
            printf("-------------------------------------------------------------------------------------\n");

            flag = 1;
            for(int e = 0; e < tam; e++)
            {
                if( !vec[e].isEmpty && vec[e].idTipo == tipos[t].id)
                {
                    mostrarMascota(vec[e], tipos, colores, tam ,clientes);
                    flag = 0;
                }
            }
            if(flag)
            {
                printf("No hay Mascotas\n");
            }
            printf("\n\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int informarMascotasTipo(eMascota vec[], int tam,eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli)
{
    int todoOk = 0;
    int idTipo;
    int idColor;
    int flag = 1;
    char descTipo[20];
    char descColor[20];
    int contador=0;


    if(vec != NULL && tipos != NULL && tam > 0 && tamTip > 0 && colores != NULL && clientes != NULL && tamCol>0 && tamCli >0)
    {
        system("cls");


        listarTipo(tipos, tamTip);

        printf("Ingrese Id Tipo: ");
        scanf("%d", &idTipo);

        while( !validarTipo(tipos,tamTip, idTipo) )
        {
            printf("Tipo invalido.Ingrese Id Tipo: ");
            scanf("%d", &idTipo);
        }
       listarColor(colores, tamCol);

        printf("Ingrese Id Color: ");
        scanf("%d", &idColor);

        while ( !validarColor(colores, tamCol, idColor))
        {
            printf("Color invalido.Ingrese Id color: ");
            scanf("%d", &idColor);
        }
         printf("   *** Listado de mascotas de un Tipo y Color ***\n");
        printf("---------------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {

            if( !vec[i].isEmpty && vec[i].idTipo == idTipo && vec[i].idColor== idColor)
            {
                mostrarMascota(vec[i], tipos, colores, tam,clientes);
                contador++;
                flag = 0;

            }

        }
        if(flag)
        {
            cargarDescripcionTipo(tipos,tamTip, idTipo, descTipo);
            cargarDescripcionColor(colores,tamCol,idColor,descColor);
            printf("No hay Mascotas de ese color ni de ese tipo %s  %s\n ", descTipo, descColor );
        }

            printf("\nHay %d MAscotas de ese color y tipo", contador);
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}



int colorMasCantidad(eMascota vec[], int tam,eTipo tipos[], int tamTip, eColor colores[], int tamCol){
int todoOk = 0;
int totalColores;
int mayor;
int flag = 1;

   if(vec != NULL && tipos != NULL && tam > 0 && tamTip > 0 && colores != NULL && tamCol >0)
    {
        system("cls");
        printf("   *** Colores con mas cantidad de mascotas  ***\n");
        printf("---------------------------------------------------\n");


        for(int i=0; i < tamCol; i++){
            totalColores= 0;
        }

        for(int s = 0; s < tamCol; s++){
            for(int e = 0; e < tam; e++){
                if(!vec[e].isEmpty && vec[e].idColor == colores[s].id){
                    totalColores++;
                }
            }
        }

        for(int s = 0; s < tamCol; s++){
            if(flag || totalColores > mayor){
                mayor = totalColores;
                flag = 0;
            }
        }

        printf("El Color que mas mascotas tiene %2d y es :\n", mayor);
          for(int s = 0; s < tamCol; s++){
            if(totalColores == mayor){
                printf("%s\n", colores[s].descripcion);
            }
        }
      todoOk = 1;
    }
    return todoOk;
}


int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pId)
{

    int todoOk = 0;
    eTrabajo falsos[] =
    {
        {0, 6002, 20000, {2,5,2022}},
        {0, 6004, 20000, {4,3,2022}},
        {0, 6000, 20000, {30,2,2021}},
        {0, 6002, 20000, {1,2,2022}},
        {0, 6001, 20000, {20,5,2022}},
        {0, 6003, 20000, {15,4,2022}},
        {0, 6007, 20000, {7,3,2022}},
        {0, 6008, 20000, {6,1,2022}},
        {0, 6002, 20000, {29,1,2022}},
        {0, 6001, 20000, {2,4,2022}}
    };
     if(trabajos != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            trabajos[i] = falsos[i];
            trabajos[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }
    return todoOk;
}

int menuTrabajo()
{
    int opcion;
    printf("___________________________________________\n");
    printf("|                                         |\n");
    printf("|     *** Informes de trabajos  ***       |\n");
    printf("|_________________________________________|\n");
    printf("|                                         |\n");
    printf("| 1- Trabajo por nombre de mascota        |\n");
    printf("| 2- Total gastos por mascota             |\n");
    printf("| 3- Servicio por mascota                 |\n");
    printf("| 4- Mascotas por tipo                    |\n");
    printf("| 5- fecha de servicios                   |\n");
    printf("| 6- Salir                                |\n");
    printf("|_________________________________________|\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
/*
int mostrarInformesTrabajo (eTrabajo trabajos[],int tamTra, eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[],int tamCli )
{

    int todoOk = 0;

    char salir = 'n';


    do{
        switch (menuInformes()) {
		case 1:
		   // informarTrabajoXMascota(trabajos, tamTra, vec, tam,tipos,tamTip,colores,tamCol,clientes,tamCli, servicios, TAMS);
		    break;
        case 2:

		    break;
        case 3:

		    break;
        case 4:

		    break;
        case 5:

		    break;
        case 6:
            salir = 's';
		    break;
}
   }while (salir != 's');
return todoOk;
}


int informarTrabajoXMascota(eTrabajo trabajos[],int tamTra, eMascota vec[], int tam,eTipo tipos[], int tamTip, eColor colores[],int tamCol , eCliente clientes[],int tamCli , eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    int idMascota;
    int flag = 1;
    char descripcion[20];


    if(trabajos!=NULL && tamTra>0 && vec != NULL && tipos != NULL && tam > 0 && tamTip > 0 && colores !=NULL && tamCol>0)
    {
        system("cls");


        listarMascota(vec, tam, tipos, tamTip,colores, tamCol,clientes,tamCli);

        printf("Ingrese Id de la mascota: ");
        fflush (stdin);
        scanf("%d", &idMascota);

        while( !validarMascota(vec,tam,idMascota))
        {
            printf("mascota invalido.Ingrese Id mascota: ");
            scanf("%d", &idMascota);
        }
        printf("   *** Listado de Mascotas por   ***\n");
        printf("---------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !trabajos[i].isEmpty && trabajos[i].idMascota == idMascota)
            {
                listarTrabajo(trabajos, tamTra,vec, tam, tipos,tamTip,colores, tamCol,servicios,tamSer);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionMascota(vec,tam, idMascota, descripcion);
            printf("No hay Mascotas  %s\n", descripcion );
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}


int validarMascota(eMascota mascotas[], int tam, int id){
    int esValido=0;
    int indice;

    buscarMascota(mascotas, tam, id , &indice);

    if (indice != -1){
        esValido = 1;
    }

    return esValido;
}
*/
