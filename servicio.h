#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
} eServicio;

/** \brief Funcion que se encarga de Listar los servicios que se prestan
 *
 * \param tipos[] eTipo estructura del array de servicios
 * \param tam int tamaño de la estructura
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int listarServicio(eServicio servicios[], int tam);


/** \brief Funcion que sirve para cargar el tipo de descripcion del color de la mascota
 *
 * \param tipos[] eTipo se hace uso de la estructura de servicio
 * \param tam int tamaño de la estructura
 * \param id int identificacion del servicio
 * \param descripcion[] char descripcion del servicio que se presta
 * \param precio float Precio que se cobra en la veterinaria
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]);


/** \brief Funcion que nos ayuda a validar el servicio que se presta
 *
 * \param tipos[] eTipo se hace uso de la estructura de servicio
 * \param tam int tamaño de la estructura
 * \param id int identificacion del servicio que se presta
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int validarServicio(eServicio servicios[], int tam, int id);



/** \brief Funcion que se usa para buscar el servicio que se presta
 *
 * \param tipos[] eTipo se hace uso de la estructura del servicio
 * \param tam int tamaño de la estructura
 * \param id int identificacion del  servicio
 * \param int* Se hace uso del puntero para corroborar que haya datos cargados
 * \return
 *
 */
int buscarServicio (eServicio servicios[],int tam, int id, int* pIndice);


#endif // SERVICIO_H_INCLUDED

