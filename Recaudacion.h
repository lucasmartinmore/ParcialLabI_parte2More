#ifndef RECAUDACION_H_INCLUDED
#define RECAUDACION_H_INCLUDED
typedef struct
{
    int idContribuyente;
    int mes;
    int tipo;
    float importe;
    int idRecaudacion;
    int isEmpty;
    char estado[25];
}eRecaudacion;
#endif // RECAUDACION_H_INCLUDED
int iniciarRecaudacion(eRecaudacion recaudacion[], int tamRecaudacion);
int buscarRecaudacionvacia(eRecaudacion recaudacion[], int tamRecaudacion, int* error);
int subMenuTipoRecaudacion();




