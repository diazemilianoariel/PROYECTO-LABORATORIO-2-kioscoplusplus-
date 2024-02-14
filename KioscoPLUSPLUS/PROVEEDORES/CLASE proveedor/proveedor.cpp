#define _CRT_SECURE_NO_WARNINGS // agrgar esto en cada clase que tenga un strcpy
#include <iostream>

#include <cstring>
using namespace std;
#include "proveedor.h"
#include "..//CLASE archivoProveedor/archivoProveedor.h"



proveedor::proveedor(){
	idProveedor = 0;
	strcpy(nombre, "sin nombre");
	strcpy(direccion, "sin direccion");
	strcpy(telefono, "00-0000-0000");
	estado = true;
}

proveedor::proveedor(int id, char* nomb, char* dir, char* tel, bool est) {
	idProveedor = id;
	strcpy(nombre, nomb);
	strcpy(direccion, dir);
	strcpy(telefono, tel);
	estado = true;

}

void proveedor::setidProveedor(int id){idProveedor = id;}
void proveedor::setNombre(char nomb[50]) {strcpy(nombre, nomb);}
void proveedor::setDireccion(char dir[50]) {strcpy(direccion, dir);}
void proveedor::setTelefono(char tel[50]) { strcpy(telefono, tel); }
void proveedor::setEstado(bool est) { estado = est; }

int proveedor::getidProveedor(){return idProveedor;}
char* proveedor::getNombre() {return nombre;}
char* proveedor::getDireccion() {return direccion;}
char* proveedor::getTelefono() {return telefono;}
bool proveedor::getEstado() {return estado;}





void proveedor::cargarProveedor() {
	archivoProveedor archproveedor;
	proveedor reg;
	int cantProveedores = archproveedor.contarRegistros(); //cuenta los registros
	int pos = 0;
	bool bandera = false;
	char opcion;
	do {
		bandera = false; // reinicia la bandera en cada iteracion
		cout << "ingrese el id del proveedor: ";
		cin >> idProveedor;
		for (int i = 0; i < cantProveedores; i++) {
			reg = archproveedor.leerRegistro(i);
			if (idProveedor == reg.getidProveedor()) {
				bandera = true;// Si el ID ya existe, se establece la bandera en verdadero
				cout << "el id ya existe" << endl;
				system("pause");// Se pausa la ejecución del programa para que el usuario pueda leer el mensaje
				system("cls");// Se limpia la pantalla para una nueva entrada de datos
				break;
			}
		}
	} while (bandera == true); // El bucle se repite mientras la bandera sea verdadera (es decir, mientras el ID ingresado ya exista)


	// Después de que se haya ingresado un ID único, se solicitan los demás datos del proveedor
	cout << "ingrese el nombre del proveedor: ";
	cin.ignore(); // Se limpia el buffer de entrada
	cin.getline(nombre, 50);
	cout << "ingrese la direccion del proveedor: ";
	cin.getline(direccion, 50);
	cout << "ingrese el telefono del proveedor: ";
	cin.getline(telefono, 50);
	estado = true;


	// Se crea un nuevo registro con los datos ingresados
	reg.setidProveedor(idProveedor);
	reg.setNombre(nombre);
	reg.setDireccion(direccion);
	reg.setTelefono(telefono);
	reg.setEstado(estado);


	// Se guarda el registro en el archivo
	archproveedor.grabarRegistro(reg);
	cout << "proveedor cargado" << endl;
	system("pause");
	system("cls");

}

void proveedor::eliminarProveedor() {
	/*la idea es eliminar un proveedor estableciendo el id del mismo , mostrando por pantalla el id seleccionado y preguntando si es ese proveedor el que se intenta eliminar. */
	archivoProveedor archproveedor;
	proveedor reg;
	int cantProveedores = archproveedor.contarRegistros(); //cuenta los registros
	int pos = 0;
	bool bandera = false;
	char opcion;
	do {
		bandera = false; // reinicia la bandera en cada iteracion
		cout << "ingrese el id del proveedor: ";
		cin >> idProveedor;
		for (int i = 0; i < cantProveedores; i++) {
			reg = archproveedor.leerRegistro(i);
			if (idProveedor == reg.getidProveedor()) {
				bandera = true;// Si el ID ya existe, se establece la bandera en verdadero
				cout << "------------------------------------" << endl;
				cout << "Id: " << reg.getidProveedor() << endl;
				cout << "Nombre: " << reg.getNombre() << endl;
				cout << "Direccion: " << reg.getDireccion() << endl;
				cout << "Telefono: " << reg.getTelefono() << endl;
				cout << "estado: ";
				if (reg.getEstado() == true) {cout << "activo" << endl;}
				else {cout << "inactivo" << endl;}
				cout << "------------------------------------" << endl;
				cout << "esta seguro que desea eliminar este proveedor? (s/n): ";
				cin >> opcion;
				if (opcion == 's') {
					reg.setEstado(false);
					archproveedor.remplazarReg(reg, i);
					cout << "proveedor eliminado" << endl;
					system("pause");
					system("cls");
				}
				else if (opcion == 'n') {
					cout << "Operacion cancelada\n";
					system("pause");
					system("cls");
				}
				break;
			}
		}
	} while (bandera == false); // El bucle se repite mientras la bandera sea verdadera (es decir, mientras el ID ingresado ya exista)
	

}

void proveedor::modificarProveedor() {
	
}

void proveedor::listarProveedores(){
	archivoProveedor archproveedor;
	proveedor reg;
	int cantProveedores = archproveedor.contarRegistros(); //cuenta los registros

	for (int i = 0; i < cantProveedores; i++) {
		reg = archproveedor.leerRegistro(i);

		if (reg.getEstado() == true) {
				cout << "------------------------------------" << endl;
				cout << "Id: " << reg.getidProveedor() << endl;
				cout << "Nombre: " << reg.getNombre() << endl;
				cout << "Direccion: " << reg.getDireccion() << endl;
				cout << "Telefono: " << reg.getTelefono() << endl;
				cout << "estado: ";
				if (reg.getEstado() == true) {cout << "activo" << endl;}
				else {cout << "inactivo" << endl;}
				cout << "------------------------------------" << endl;
			}

		}
	cout << "lista de proveedores actuales " << endl;
	system("pause");
	system("cls");


}

void altaProveedor(proveedor reg, int pos) {
	archivoProveedor archProv;

	reg.setEstado(true);

	archProv.remplazarReg(reg, pos);
	cout << "proveedor dado de alta " << endl;



}





