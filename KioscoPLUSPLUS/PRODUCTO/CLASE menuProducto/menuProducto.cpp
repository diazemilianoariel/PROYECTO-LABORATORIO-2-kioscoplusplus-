#include <iostream>
#include <cstring>
using namespace std;

#include "../CLASE menuProducto/menuProducto.h"
#include "../CLASE ArchivoProducto/ArchivoProducto.h"
#include "../CLASE producto/producto.h"
#include "..//..//MENU PRINCIPAL/CLASE menuPrincipal/menuPrincipal.h"



void menuProducto() {

	//hacer un submenu para permitir al usuario agregar, eliminar o modificar productos en el inventario.
			//1. *Registro de productos:*
			//   - Permitir al usuario agregar, eliminar o modificar productos en el inventario.
			//   - Actualizar la cantidad de productos disponibles después de una venta.

	/* validacion:  verificar si ese producto ya existe */
	


	Producto p; // objeto de la clase producto
	int opcionProducto;
	do {
		system("cls"); //limpia la consola
		cout << "********* Menu de productos *********" << endl;
		cout << "1. agregar producto" << endl; // hacer la validacion 
		cout << "2. eliminar producto" << endl;
		cout << "3. modificar producto" << endl;
		cout << "4. listar productos" << endl;
		cout << "5. volver" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcionProducto;
		cout << endl;



		system("cls");
		switch (opcionProducto) {

		case 1: {
			p.cargarProducto();
			break;
		}

		case 2: {
			p.bajaLogicaProd();  
			break;
		}
		case 3: {
			/*modificar producto*/
			p.modificarProducto();
			break;
		}
		case 4: {
			/*listar productos*/
			p.listarProductos();
			break;
		}

		case 5: {
			/*volver al menu principal*/
			return menuPrincipal();
			break;
		}


		default: {
			cout << "opcion incorrecta" << endl;
			break;
		}


		}
		system("pause");
	} while (opcionProducto != 6);

}



