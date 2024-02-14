#include "menuProveedores.h"
#include "../CLASE proveedor/proveedor.h"
#include "..//..//MENU PRINCIPAL/CLASE menuPrincipal/menuPrincipal.h"


void menuProveedores(){
	 proveedor proveedores; // objeto de la clase proveedores
   int opcionProveedores;
   /*a la hora de realizar una venta se tienen que actualizar los productos en el inventario*/

   do {
	  system("cls"); //limpia la consola
	  cout << "********* Menu de proveedores *********" << endl;
	  cout << "1. Agregar proveedor" << endl;
	  cout << "2. Eliminar proveedor" << endl;
	  cout << "3. Modificar proveedor" << endl;
	  cout << "4. Listar proveedores" << endl;
	  cout << "5. Volver" << endl;
	  cout << "Ingrese una opcion: ";
	  cin >> opcionProveedores;
	  cout << endl;

	  system("cls"); //limpia la consola
	  switch (opcionProveedores) {

	  case 1: {
		 /*agregar proveedor*/
		  proveedores.cargarProveedor();
		 break;
	  }

	  case 2: {
		 /*eliminar proveedor*/
		  proveedores.eliminarProveedor();
		 break;
	  }
	  case 3: {
		 /*modificar proveedor*/
		  proveedores.modificarProveedor();
		 break;
	  }
	  case 4: {
		  /*listar proveedores*/
		  proveedores.listarProveedores();
		 break;
	  }

	  case 5: {
		 /*volver al menu principal*/
		 return menuPrincipal();
		 break;
	  }
   }
   } while (opcionProveedores != 5);
}
