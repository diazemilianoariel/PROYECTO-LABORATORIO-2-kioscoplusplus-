#include "menuPrincipal.h"
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include "..//..//PRODUCTO/CLASE menuProducto/menuProducto.h"
#include "..//..//VENTA/CLASE menuVenta/menuVenta.h"
#include "..//..//PROVEEDORES/CLASE menuProveedores/menuProveedores.h"

using namespace std;



void menuPrincipal() {



	//implementar un menu  para que el usuario pueda elegir que quiere hacer
	//1. *Registro de productos:*
	//   - Permitir al usuario agregar, eliminar o modificar productos en el inventario.
	//   - Actualizar la cantidad de productos disponibles después de una venta.
	//2. *Proceso de venta:*
	//   - Seleccionar productos a vender.
	//   - Calcular el total de la venta.
	//   - Registrar la venta asociándola al cliente correspondiente.
	//   - Actualizar el inventario luego de la venta.
	//3. *Registro de Proveedores:*
	//   - Permitir agregar, eliminar o modificar información de Proveedores.
	//   - Mantener un historial de compras para cada proveedor.

	system("cls");
	int opcionPrincipal;
	cout << "********* Bienvenido al Kiosco++ *********" << endl;
	cout << "Seleccione una opcion: (1 / 2 / 3)" << endl;
	cout << "1. menu productos" << endl;
	cout << "2. menu venta" << endl;
	cout << "3. menu proveedores" << endl;
	cout << "4. Salir" << endl;

	cout << "Ingrese una opcion: ";
	cin >> opcionPrincipal;

	system("cls");
	switch (opcionPrincipal) {
	case 1: {
		menuProducto(); //llama al menu de productos
		break;
	}
	case 2: {
		///menuVenta(); //llama al menu de ventas
		break;
	}
	case 3: {
		menuProveedores(); //llama al menu de Proveedores
		break;
	}
	case 4: {
		/*realizar un for con puntos que genere un vista de  cerrando el programa...*/
		cout << " <<<<<GRACIAS POR UTILIZAR--->(KioscoPlusPlus) >>>>> "; //mensaje de despedida
		for (int i = 0;i < 4;i++) {
			cout << ".";
			Sleep(400);
		}
		break;
	}
	}
}