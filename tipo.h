#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eTipo;


/** \brief Funcion que se encarga de Listar los tipos de mascotas
 *
 * \param tipos[] eTipo estructura del array de mascotas
 * \param tam int tamaño de la estructura
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int listarTipo(eTipo tipos[], int tam);


/** \brief Funcion que sirve para cargar el tipo de descripcion de la mascota
 *
 * \param tipos[] eTipo se hace uso de la estructura del tipo de mascota
 * \param tam int tamaño de la estructura
 * \param id int identificacion del tipo de mascota
 * \param descripcion[] char descripcion del tipo de mascota
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);


/** \brief Funcion que nos ayuda a validar el tipo de mascota
 *
 * \param tipos[] eTipo se hace uso de la estructura del tipo de mascota
 * \param tam int tamaño de la estructura
 * \param id int identificacion del tipo de mascota
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int validarTipo(eTipo tipos[], int tam, int id);



/** \brief Funcion que se usa para buscar el tipo de mascota dentro de nuestra estructura
 *
 * \param tipos[] eTipo se hace uso de la estructura del tipo de mascota
 * \param tam int tamaño de la estructura
 * \param id int identificacion del tipo de mascota
 * \param int* Se hace uso del puntero para corroborar que haya datos cargados
 * \return
 *
 */
int buscarTipo (eTipo tipos[],int tam, int id, int* pIndice);



#endif // TIPO_H_INCLUDED

