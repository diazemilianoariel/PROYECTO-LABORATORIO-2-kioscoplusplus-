#include <iostream>
#include <cstring>
#include <windows.h>  // Necesario para Sleep
using namespace std;
#include "../KioscoPLUSPLUS/PRODUCTO/CLASE ArchivoProducto/ArchivoProducto.h"
#include "../KioscoPLUSPLUS/PRODUCTO/CLASE menuProducto/menuProducto.h"
#include "../KioscoPLUSPLUS/PRODUCTO/CLASE producto/producto.h"
#include "VENTA/CLASE menuVenta/menuVenta.h"
#include "VENTA/CLASE Venta/Venta.h"
#include "VENTA/CLASE archivoVenta/archivoVenta.h"
#include "..//KioscoPLUSPLUS/CLASE FECHA/Fecha.h"
#include "MENU PRINCIPAL/CLASE menuPrincipal/menuPrincipal.h"
#include "PROVEEDORES/CLASE menuProveedores/menuProveedores.h"
#include "PROVEEDORES/CLASE proveedor/proveedor.h"
#include "PROVEEDORES/CLASE ArchivoProveedor/ArchivoProveedor.h"
#include "../KioscoPLUSPLUS/MENU PRINCIPAL/CLASE menuPrincipal/menuPrincipal.h"



/*
*hacer el menu en main principal, e ir haciendo de  a una clase completa y probarla que funcione, en esta instancia primero la de producto.
hacer la clase cargar cadena

si hago el uso del string tengo que ver la clase de angel donde explica  utilizar string con archivos y sino usar el cargar cadena con archivos y no utilizar string
*/


/*verificar que se limpie la consola cuando se ingresa desde el menú principal al subMenú */






int main() {

	menuPrincipal(); // funcion 

	return 0;
}
