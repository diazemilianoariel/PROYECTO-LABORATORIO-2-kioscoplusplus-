#include <iostream>
using namespace std;

#include "menuVenta.h"
#include "..//..//VENTA/CLASE Venta/Venta.h"
#include "../../PRODUCTO/CLASE menuProducto/menuProducto.h"
#include "..//..//MENU PRINCIPAL/CLASE menuPrincipal/menuPrincipal.h"






void menuVenta(){
	Venta venta; // objeto de la clase venta
   int opcionVenta;
   /*a la hora de realizar una venta se tienen que actualizar los productos en el inventario*/

   do {
	  system("cls"); //limpia la consola
	  cout << "********* Menu de ventas *********" << endl;
	  cout << "1. realizar venta" << endl;
	  cout << "2. eliminar venta" << endl;
	  cout << "3. modificar venta" << endl;
	  cout << "4. listar ventas" << endl;
	  cout << "5. volver" << endl;
	  cout << "Ingrese una opcion: ";
	  cin >> opcionVenta;
	  cout << endl;

	  system("cls"); //limpia la consola
	  switch (opcionVenta) {

	  case 1: {
		 /*realizar una venta*/
		//  venta.cargarVenta();
		 break;
	  }

	  case 2: {
		 /*eliminar venta*/
		//  venta.eliminarVenta();
		 break;
	  }
	  case 3: {
		 /*modificar venta*/
		//  venta.modificarVenta();
		 break;
	  }
	  case 4: {
		  /*listar ventas*/
		//  venta.listarVentas();
		 break;
	  }

	  case 5: {
		 /*volver al menu principal*/
		 return menuPrincipal();
		 break;
	  }

	  default: {
		 cout << "Opcion incorrecta, ingrese nuevamente" << endl;
		 break;
	  }
	  }
	  system("pause");
   } while (opcionVenta != 5);

}


