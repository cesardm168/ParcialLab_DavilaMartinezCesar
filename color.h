#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eColor;

/** \brief Funcion que se encarga de Listar los colores de la mascotas
 *
 * \param tipos[] eTipo estructura del array de colores
 * \param tam int tamaño de la estructura
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int listarColor(eColor colores[], int tam);


/** \brief Funcion que sirve para cargar el tipo de descripcion del color de la mascota
 *
 * \param tipos[] eTipo se hace uso de la estructura de color
 * \param tam int tamaño de la estructura
 * \param id int identificacion del color de mascota
 * \param descripcion[] char descripcion del color de mascota
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int cargarDescripcionColor(eColor colores[], int tam, int id, char descripcion[]);


/** \brief Funcion que nos ayuda a validar el color de mascota
 *
 * \param tipos[] eTipo se hace uso de la estructura de color
 * \param tam int tamaño de la estructura
 * \param id int identificacion del color  de mascota
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int validarColor(eColor colores[], int tam, int id);



/** \brief Funcion que se usa para buscar el tipo de color dentro de nuestra estructura
 *
 * \param tipos[] eTipo se hace uso de la estructura del color
 * \param tam int tamaño de la estructura
 * \param id int identificacion del  color
 * \param int* Se hace uso del puntero para corroborar que haya datos cargados
 * \return
 *
 */
int buscarColor (eColor colores[],int tam, int id, int* pIndice);

#endif // COLOR_H_INCLUDED

