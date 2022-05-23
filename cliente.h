#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
} eCliente;


#endif // CLIENTE_H_INCLUDED

int listarCliente(eCliente clientes[], int tam);
int cargarDescripcionCliente(eCliente clientes[], int tam, int id, char nombre[]);
int buscarCliente (eCliente clientes[],int tam, int id, int* pIndice);
int validarCliente(eCliente  clientes[], int tam, int id);
