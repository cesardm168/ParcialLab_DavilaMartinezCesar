#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;


int validarFecha(eFecha unaFecha);

#endif // FECHA_H_INCLUDED

