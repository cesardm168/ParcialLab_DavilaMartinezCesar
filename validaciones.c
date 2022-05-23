#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"



int validarUnaFecha(eFecha fecha){
    int todoOk = 0;

    while((fecha.anio < 1990 || fecha.anio > 2022)
          || (fecha.mes < 1 || fecha.mes > 12)
          || (fecha.dia < 1 || fecha.dia > 31)
          || (fecha.mes == 2 && fecha.dia >= 29)
          || (fecha.mes == 1 && fecha.dia >= 32)
          || (fecha.mes == 3 && fecha.dia >= 32)
          || (fecha.mes == 5 && fecha.dia >= 32)
          || (fecha.mes == 7 && fecha.dia >= 32)
          || (fecha.mes == 8 && fecha.dia >= 32)
          || (fecha.mes == 10 && fecha.dia >= 32)
          || (fecha.mes == 12 && fecha.dia >= 32)
          || (fecha.mes == 4 && fecha.dia >= 31)
          || (fecha.mes == 6 && fecha.dia >= 31)
          || (fecha.mes == 9 && fecha.dia >= 31)
          || (fecha.mes == 11 && fecha.dia >= 30)
          ){
            printf("Error, reingrese fecha: ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
            }

    return todoOk;
}
static int getInt (int* pResultado);
static int esNumerica(char* cadena);
static int myGets(char* cadena, int longitud);
static int getName(char* pArray);
static int isName(char* pString);



/** \brief solicita un numero al usuario. luego de verificarlo lo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char*  es el mensaje mostrado
 * \param mensajeError char* Es el mensaje de error a ser mostrado
 * \param minimo int Es el numero minimo a ser aceptado
 * \param maximo int Es el numero maximo a ser aceptado
 * \param reintentos int Cantidad de reintentos para cometer el error de poner mal el numero
 * \return int retorna  0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int buffer;

    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <=maximo && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            reintentos--;
        }while (reintentos >= 0);
    }
}


/** \brief
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param Retorna 0(exito) si se obtiene un numero entero y -1 (error) si no
 * \return
 *
 */
static int getInt (int* pResultado)
{
    int retorno=-1;
    char buffer[4096];

    if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
    {
        retorno=0;
        *pResultado = atoi(buffer);
    }
    return retorno;
}

/** \brief Verifica si la cadena eingresada es numerica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \return int Retorna 1 (verdadero) si la cadena es numerica y 0(falso) si no lo es
 *
 */
static int esNumerica(char* cadena)
{
    int retorno = 1;
    int i;

    if(cadena[0] == '-') //esto en caso de que sea negativo
    {
        i = 1;
    }
    for(i = 0; cadena[i] != '\0'; i++ )
    {

        if(cadena[i] > '9' || cadena[i] <'0')
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

/** \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un
 *          maximo de 'longitud -1' caracteres.
* \param cadena char* puntero al espacio de memoria donde se copiar la cadena obtenida
 * \param longitud int define el tamalo de cadena
 * \return int retorna 0 (exito) si se obtiene una cadena y -1 (error) si no
 *
 */
static int myGets(char* cadena, int longitud)
{
    fflush(stdin);
    fgets(cadena, longitud, stdin);
    cadena[strlen(cadena)-1 ]= '\0';
    return 0;
}



/** \brief Solicita al usuario una cadena de caracteres y verifica que sea correcta
 *
 * \param pArray char* Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param MSG char* Mensaje de peticion para el usuario
 * \param MSG_ERROR char* Mensaje de Error si los datos son incorrectos
 * \param RETRY int Numero de reintentos
 * \return int retorna 0 (exito) si se obtiene una cadena y -1 (error) si no
 *
 */
 /*
int utn_getName(char* pArray, char* MSG, char* MSG_ERROR, int RETRY)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getName(buffer)) {
				strcpy(pArray, buffer);
				rtn = 0;
				break;
			}
			printf("%s >> Reintentos = %d \n", MSG_ERROR, RETRY);
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getName(char* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isName(buffer)) {
			strcpy(pArray, buffer);
			rtn = 0;
		}
	}
	return rtn;
}



static int isName(char* pString)
{
	int rtn = 1;
	int i;

	if (pString != NULL && strlen(pString) > 0) {

		if (pString[0] < 'A' || 'Z' < pString[0] ) {
			return 0;
		}
		for (i = 1; pString[i] != '\0'; i++) {
			if (pString[i] < 'a' || 'z' < pString[i] ) {
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}
*/
