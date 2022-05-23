#include "fecha.h"

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED




#endif // VALIDACIONES_H_INCLUDED

/** \brief Funcion que se utiliza para verificar una fecha
 *
 * \param fecha eFecha Nombre del array fecha
 * \return int
 *
 */

int validarUnaFecha(eFecha fecha);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getName(char* pArray, char* MSG, char* MSG_ERROR, int RETRY);
