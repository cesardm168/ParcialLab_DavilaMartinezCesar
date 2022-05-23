#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "validaciones.h"
#include "cliente.h"
#include "trabajo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    eFecha fIngreso;
    char vacunado;
    int idCliente;
    int isEmpty;
} eMascota;



#endif // MASCOTAS_H_INCLUDED



/** \brief funcion que Imprime las opciones del programa
  * \return int devuelve el valor que ingresa el usuario
  */
int menu();

/** \brief funcion que inicializa el array de mascota
 * \param vec[] eMascota nombre del array
 * \param tam int tamaño del array
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 */
int inicializarMascotas(eMascota vec[], int tam);


/** \brief  Funcion que busca un espacio libre dentro del array mascotas para asignarlo
 * \param vec[] eMascota nombre del array de mascotas
 * \param tam int tamaño del array
 * \param pIndex int* puntero que nos permitira luego asignarle un Id al array
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 */
int buscarMascotaLibre(eMascota vec[], int tam, int* pIndex);


/** \brief Funcion que se utiliza para dar de alta a una mascota dentro del array
 * \param vec[] eMascota nombre del array de mascotas
 * \param tam int  tamaño del array
 * \param tipos[] eTipo Nombre del Array de tipos de animales
 * \param tamTip int Tamaño del array de tipos
 * \param colores[] eColor Nombre del array de colores de animales
 * \param tamCol int Tamaño del array de colores
 * \param pIdMascota int* Puntero a travez del cual se le asgina un Id a la mascota y va aumentando conforme se agreguen mas datos
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 */
int altaMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip,eColor colores[],int tamCol,  int* pIdMascota,eCliente clientes[], int tamCli);


/** \brief Funcion que se utiliza para modificar alguno de los datos de la mascota almacenado
 * \param vec[] eMascota nombre del array de mascotas
 * \param tam int tamaño del array
 * \param tipos[] eTipo Nombre del Array de tipos de animales
 * \param tamTip int Tamaño del array de tipos
 * \param eColor[] Nombre del array de colores de animales
 * \param tamCol int Tamaño del array de colores
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 */
int modificarMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor[], int tamCol, eCliente clientes[],int tamCli );


/** \brief Funcion que se utiliza para buscar a travez del Id una mascota especifica y ver todos sus datos
 * \param vec[] eMascota Nombre del array de mascotas
 * \param tam int Tamaño del array
 * \param id int Numero de Id que se le solicita al usuario
 * \param pIndex int* puntero a travez del cual se utiliza para verificar si esta en la base de datos
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 */
int buscarMascota(eMascota vec[], int tam,int id, int* pIndex);

/** \brief Funcion que se utiliza para mostrar el menu de modificacion del array de mascotas
 * \return int devuelve la opcion ingresada por el usuario
 */
int menuModificarMascota();


/** \brief Funcion que se mete dentro del array y ns muestra por pantalla los datos que se encuentran almacenados
 * \param mascotas eMascota Nombre del array de mascotas
 * \param tipos[] eTipo Usamos el array de tipo de animales para mostrarlos por pantalla
 * \param colores[] eColor Usamos el array de colores de animales para mostrarlos por pantalla
 * \param tam int Tamaño del array  de mascotas
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 */
int mostrarMascota(eMascota mascotas, eTipo tipos[],eColor colores[], int tam, eCliente clientes[]);

/** \brief Con esta Funcion listamos todos los datos que estan almacenados dentro de nuestro array
 * \param vec[] eMascota Nombre del array de mascotas el cual es usado como array principal
 * \param tam int Tamaño del array  de mascotas
 * \param tipos[] eTipo Usamos el array de tipo de animales para mostrarlos por pantalla
 * \param tamTip int tamaño del array de los tipos de animales
 * \param colores[] eColor Usamos el array de colores de animales para mostrarlos por pantalla
 * \param tamCol int Tamaño del array de colores de animales
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 */
int listarMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol , eCliente clientes[],int tamCli );


/** \brief Funcion para dar de baja a la mascota del sistema de manera logica
 * \param vec[] eMascota Nombre del array de mascotas el cual es usado como array principal
 * \param tam int Tamaño del array  de mascotas
 * \param tipos[] eTipo Usamos el array de tipo de animales para mostrarlos por pantalla
 * \param tamTip int tamaño del array de los tipos de animales
 * \param colores[] eColor Usamos el array de colores de animales para mostrarlos por pantalla
 * \param tamCol int Tamaño del array de colores de animales
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 */
int bajaMascota(eMascota vec[], int tam,eTipo tipos[], int tamTip,eColor colores[],int tamCol , eCliente clientes[],int tamCli );

/** \brief Funcion que utilizo para probar las funcionalidades del programa sin tener que estar ingrsando 1 por 1 los datos
 * \param vec[] eMascota Nombre del array de mascotas el cual es usado como array principal
 * \param tam int  Tamaño del array  de mascotas
 * \param cant int cantidad de datos que voy a utilizar en este caso son 10
 * \param pId int* puntero al Id de la mascota el cual va a ir aumentando dependiendo de los datos que yo haya harcodeado
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 *
 */
int hardcodearMascotas(eMascota vec[], int tam, int cant, int* pId);

/** \brief Funcion pensada para cuando se haga algun servicio poder traer a ese array el nombre de la mascota
 * \param mascota[] eMascota Nombre del array de mascotas el cual es usado como array principal
 * \param tam int Tamaño del array  de mascotas
 * \param id int id que fue asignado y por el cual se le busca
 * \param descripcion[] char Nombre de la mascota
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 */
int cargarDescripcionMascota(eMascota mascota[], int tam, int id, char descripcion[]);

/** \brief Funcion que ordena las mascotas por nombre y por tipo
 * \param vec[] eMascota Nombre del array de mascotas el cual es usado como array principal
 * \param tam int Tamaño del array  de mascotas
 * \return int retorna 1 si esta todo bien y 0 si algo sale mal
 */
int ordenarMascotasPorTipoYNombre(eMascota vec[], int tam);
int mostrarInformes(eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[],int tamCli );


//Informes

int informarXColor(eMascota vec[], int tam,eTipo tipos[], int tamTip, eColor colores[],int tamCol , eCliente clientes[],int tamCli );
int informarPromedioVacunados(eMascota vec[], int tam);
int listarMascotaMenorE(eMascota vec[], int tam,eTipo tipos[], int tamtip, eColor colores[], int tamCol , eCliente clientes[],int tamCli );
int informarMascotasXTipo(eMascota vec[], int tam,eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[],int tamCli );
int informarMascotasTipo(eMascota vec[], int tam,eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli);
int colorMasCantidad(eMascota vec[], int tam,eTipo tipos[], int tamTip, eColor colores[], int tamCol);

int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pId);

//informes trabajo
int menuTrabajo();

int mostrarInformesTrabajo (eTrabajo trabajos[],int tamTra, eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[],int tamCli );

int validarMascota(eMascota mascotas[], int tam, int id);
int informarTrabajoXMascota(eTrabajo trabajos[],int tamTra, eMascota vec[], int tam,eTipo tipos[], int tamTip, eColor colores[],int tamCol , eCliente clientes[],int tamCli  , eServicio servicios[], int tamSer);
