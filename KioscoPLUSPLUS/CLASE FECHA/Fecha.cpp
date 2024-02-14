#define _CRT_SECURE_NO_WARNINGS  // Agregar esta línea al principio del archivo CPP
#include "Fecha.h"
#include <iostream>
#include <ctime>

 // Constructor por defecto
Fecha::Fecha() {
    cargarFechaSistema();
}

    // Constructor con parámetros
Fecha::Fecha(int d, int m, int a) {
    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::setDia(int d) {dia = d;}
void Fecha::setMes(int m) {mes = m;}
void Fecha::setAnio(int a) {anio = a;}

int Fecha::getDia() {return dia;}
int Fecha::getMes() {return mes;}
int Fecha::getAnio() {return anio;}

void Fecha::cargarFechaSistema() {
    // Obtener la fecha actual del sistema
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* tiempoLocal = std::localtime(&tiempoActual);

    // Configurar la fecha en formato día/mes/año
    setDia(tiempoLocal->tm_mday);
    setMes(tiempoLocal->tm_mon + 1);  // tm_mon es 0-indexed, sumamos 1
    setAnio(tiempoLocal->tm_year + 1900);  // tm_year es 1900-indexed

}

void Fecha::mostrarFecha() {

    std::cout << "Fecha de Ingreso: " << getDia() << '/' << getMes() << '/' << getAnio() << std::endl;
}




