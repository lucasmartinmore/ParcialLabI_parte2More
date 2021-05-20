#ifndef CONTRIBUYENTE_H_INCLUDED
#define CONTRIBUYENTE_H_INCLUDED
typedef struct
{
    char nombre[25];
    char apellido[25];
    int cuil;
    int idContribuyente;
    int isEmpty;
    char idEstado[25];
}eContribuyente;
#endif // CONTRIBUYENTE_H_INCLUDED
int MenuPrincipal();
int iniciarContribuyente(eContribuyente contribuyentes[], int tamContribuyente);
int buscarContribuyenteVacio(eContribuyente contribuyentes[], int tamContribuyente, int* error);
int altaContribuyente(eContribuyente contribuyentes[],int tamContribuyente,int posicion,int idContribuyente);
int submenuModificarContribuyente();



