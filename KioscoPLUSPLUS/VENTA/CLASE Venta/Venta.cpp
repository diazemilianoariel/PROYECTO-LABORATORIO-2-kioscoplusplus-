#include <iostream>
#include <cstring>
#include <windows.h>  // Necesario para Sleep
#include "..//..//PRODUCTO/CLASE menuProducto/menuProducto.h"
#include "..//..//PRODUCTO/CLASE producto/producto.h"
#include "..//..//PRODUCTO/CLASE ArchivoProducto/ArchivoProducto.h"
#include "Venta.h"
#include "..//..//CLASE FECHA/Fecha.h"
#include "../CLASE archivoVenta/archivoVenta.h"
#include "../CLASE Venta/Venta.h"
#include "../CLASE detalleVenta/detalleVenta.h"




using namespace std;


//constructor por defecto
Venta::Venta(){
	idVenta = 0;
	total = 0.0;
	fecha.cargarFechaSistema();
	estado = false;
}

//constructor  con parametros
Venta::Venta(int idV, float tot, Fecha f(const Fecha f()), bool est) {
	idVenta = idV;
	total = tot;
	fecha.cargarFechaSistema();
	estado = est;
}


//	SETTERS
void Venta::setIdVenta(int idVenta){idVenta = idVenta;}
void Venta::setTotal(float precio){precio = precio;}
void Venta::setFecha(Fecha fecha){fecha = fecha;}
void Venta::setEstado(bool estado){estado = estado;}


//	GETTERS
int Venta::getIdVenta() const{return idVenta;}
float Venta::getTotal() const{return total;}
Fecha Venta::getFecha() const{return fecha;}
bool Venta::getEstado() const{return estado;}



void Venta::cargarVenta() {


	
}


void Venta::mostrarVenta(){
	
}




