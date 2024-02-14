#include <iostream>

using namespace std;
#include "detalleVenta.h"

detalleVenta::detalleVenta(){
	idVenta = 0;
	idProducto = 0;
	cantidad = 0;
	precioUnitario = 0;
	subtotal = 0;
}

detalleVenta::detalleVenta(int idV, int idP, int cant, float precioU, float sub) {
	idVenta = idV;
	idProducto = idP;
	cantidad = cant;
	precioUnitario = precioU;
	subtotal = sub;
}

void detalleVenta::setIdVenta(int idVenta) { idVenta = idVenta; }
void detalleVenta::setIdProducto(int idProducto) { idProducto = idProducto; }
void detalleVenta::setCantidad(int cantidad) { cantidad = cantidad; }
void detalleVenta::setPrecioUnitario(float precioUnitario) { precioUnitario = precioUnitario; }
void detalleVenta::setSubtotal(float subtotal) { subtotal = subtotal; }

int detalleVenta::getIdVenta() const { return idVenta; }
int detalleVenta::getIdProducto() const { return idProducto; }
int detalleVenta::getCantidad() const { return cantidad; }
float detalleVenta::getPrecioUnitario() const { return precioUnitario; }
float detalleVenta::getSubtotal() const { return subtotal; }


void detalleVenta::cargarDetalleVenta() {
	cout << "Ingrese el id de la venta: ";
	cin >> idVenta;
	cout << "Ingrese el id del producto: ";
	cin >> idProducto;
	cout << "Ingrese la cantidad: ";
	cin >> cantidad;
	cout << "Ingrese el precio unitario: ";
	cin >> precioUnitario;
	subtotal = cantidad * precioUnitario;
}

void detalleVenta::mostrarDetalleVenta() {
	cout << "Id de la venta: " << idVenta << std::endl;
	cout << "Id del producto: " << idProducto << std::endl;
	cout << "Cantidad: " << cantidad << std::endl;
	cout << "Precio unitario: " << precioUnitario << std::endl;
	cout << "Subtotal: " << subtotal << std::endl;
}
