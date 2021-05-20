#ifndef CONTRIBUYENTEXRECAUDACION_H_INCLUDED
#define CONTRIBUYENTEXRECAUDACION_H_INCLUDED
#include "Contribuyente.h"
#include "Recaudacion.h"



#endif // CONTRIBUYENTEXRECAUDACION_H_INCLUDED
int modificarContribuyente(eContribuyente contribuyentes[], int tamContribuyente, eRecaudacion recaudacion[], int tamRecaudacion);
void mostrarContribuyente(eContribuyente contribuyente, eRecaudacion recaudacion);
int mostrarContribuyentes(eContribuyente contribuyentes[], int tamContribuyente, eRecaudacion recaudaciones[], int tamRecaudacion);
int bajaContribuyente(eContribuyente contribuyente[], int tamContribuyente, eRecaudacion recaudaciones[], int tamRecaudaciones);
int altaRecaudacion(eRecaudacion recaudacion[],int tamRecaudacion,eContribuyente contribuyente[], int tamContribuyente, int posicion,int idRecaudacion);
int RefinanciarRecaudacion(eContribuyente contribuyentes[], int tamContribuyente, eRecaudacion recaudacion[], int tamRecaudacion);
int SaldarRecaudacion(eContribuyente contribuyentes[], int tamContribuyente, eRecaudacion recaudacion[], int tamRecaudacion);
void mostrarRecaudacion(eRecaudacion recaudacion, eContribuyente contribuyente);
int mostrarRecaudacionesSaldadas(eRecaudacion recaudacion[], int tamRecaudacion, eContribuyente contribuyente[], int tamContribuyente);
int mostrarRecaudacionesFinanciar(eRecaudacion recaudacion[], int tamRecaudacion, eContribuyente contribuyente[], int tamContribuyente);
int mostrarRecaudacionesSaldadasMayorMil(eRecaudacion recaudacion[], int tamRecaudacion, eContribuyente contribuyente[], int tamContribuyente);
int mostrarDatosContribuyentes(eRecaudacion recaudacion[], int tamRecaudacion, eContribuyente contribuyente[], int tamContribuyente);
int subMenuPreguntar();
int mostrarContribuyentesFebrero(eRecaudacion recaudacion[], int tamRecaudacion, eContribuyente contribuyente[], int tamContribuyente);

