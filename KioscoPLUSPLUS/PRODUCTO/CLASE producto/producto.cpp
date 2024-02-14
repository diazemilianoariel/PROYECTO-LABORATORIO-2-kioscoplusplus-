#include <iostream>
#include <cstring>
#include "Producto.h"
#include "../CLASE ArchivoProducto/ArchivoProducto.h"
#include "../CLASE menuProducto/menuProducto.h"

using namespace std;



// constructor por defecto
Producto::Producto() {
	_IdProducto = 0;
	strcpy_s(_nombre, "Sin nombre");
	_precioUnitario = 0.0;
	_stock = 0;
	fecha.cargarFechaSistema();
	strcpy_s(_descripcion, "Sin descripcion");
	_estado = true;
}

// Constructor con parametros
Producto::Producto(int Id, const char* nombre, float precio, int stock, const char* descripcion, Fecha f(const Fecha f()), bool est) {
	_IdProducto = Id;
	strcpy_s(_nombre, nombre);
	_precioUnitario = precio;
	_stock = stock;
	strcpy_s(_descripcion, descripcion);
	fecha.cargarFechaSistema();
	_estado = est;
}

// Metodos de acceso y modificacion
void Producto::setId(int Id) { _IdProducto = Id; }
int Producto::getId() { return _IdProducto; }

void Producto::setNombre(const char* nombre) { strcpy_s(_nombre, nombre); }
char* Producto::getNombre() { return _nombre; }

void Producto::setPrecio(float precio) { _precioUnitario = precio; }
float Producto::getPrecio() { return _precioUnitario; }

void Producto::setStock(int stock) { _stock = stock; }
int Producto::getStock() { return _stock; }

void Producto::setDescripcion(const char* descripcion) { strcpy_s(_descripcion, descripcion); }
char* Producto::getDescripcion() { return _descripcion; }

void Producto::setFecha(Fecha f){fecha = f;}
Fecha Producto::getFecha(){return fecha;}

void Producto::setEstado(bool estado) { _estado = estado; }
bool Producto::getEstado() { return _estado; }






//hacer el metodo de cargar producto
void Producto::cargarProducto(){ //metodo para cargar los datos del producto
	ArchivoProducto archPro;
	Producto reg;
	int pos;
			cout << "Ingrese el Id: ";
			cin >> _IdProducto;
				

			if ((pos = archPro.buscarProducto(_IdProducto)) >= 0) {
				cout << "el producto existe." << endl;
				
				reg = archPro.leerRegistro(pos);
				reg.mostrarProducto();

				cout << "queres darlo de alta ( s / n)? " << endl;
				char op;
				cin >> op;

				switch (op)
				{
				case 's':
					altaProducto(reg, pos);
					break;
				case 'n':
					cout << "producto no dado de alta" << endl;
					break;

				default:
					break;
				}

			}
			else{
				cout << "Ingrese el nombre: ";
				cin.ignore();
				cin.getline(_nombre, 50);
				cout << "Ingrese el precio: ";
				cin >> _precioUnitario;
				cout << "Ingrese el stock: ";
				cin >> _stock;
				cout << "Ingrese la descripcion: ";
				cin.ignore();
				cin.getline(_descripcion, 60);
				fecha.cargarFechaSistema();
				_estado = true;

				reg.setId(_IdProducto);
				reg.setNombre(_nombre);
				reg.setPrecio(_precioUnitario);
				reg.setStock(_stock);
				reg.setDescripcion(_descripcion);
				reg.setFecha(fecha);
				reg.setEstado(_estado);
			
				archPro.grabarRegistro(reg);
				cout << "Producto cargado con exito" << endl;

				}



		}

void Producto::bajaLogicaProd(){
	ArchivoProducto ap;
	int id, pos;
	char choice;
	cout << "Ingrese el ID del PRODUCTO: ";
	cin >> id;
	pos = ap.buscarProducto(id);
	if (pos == -1) {
		cout << endl << "No existe el PRODUCTO con ese ID" << endl;
		return;
	}
	else {
		if (pos == -2) {
			cout << endl << "ERROR DE ARCHIVO - baja" << endl;
			return;
		}
	}
	Producto reg = ap.leerRegistro(pos);
	cout << "******************************************" << endl;
	reg.mostrarProducto();
	cout << "******************************************" << endl;
	cout << "\nQuiere dar de baja el producto?\tS/N: ";
	cin >> choice;
	if (choice == 'S' || choice == 's') {
		reg.setEstado(false);
		cout << "Estado del producto despues de la eliminacion: " << reg.getEstado() << endl;
		bool quePaso = ap.remplazarReg(reg, pos);
		if (quePaso == true) {
			cout << endl << "PRODUCTO eliminado con exito" << endl;
		}
		else {
			cout << endl << "No se pudo eliminado el PRODUCTO" << endl;
		}
	}
	else if (choice == 'N' || choice == 'n') {
		cout << "Operacion cancelada\n";
	}
	system("pause");
	system("cls");
}

void Producto::modificarProducto() { //metodo para modificar los datos del producto
	ArchivoProducto ap;
	Producto reg;
	/*permitir al usuario modificar productos en el inventario(es decir en el archivo).
				checkear como funciona esta opcion.*/
	system("cls");
	cout << "ingrese ID de producto a modificar: ";
	int id;
	cin >> id;


	
	int cantProductos = ap.contarRegistros(); //cuenta los registros


	

	for (int i = 0; i < cantProductos; i++) {
		reg = ap.leerRegistro(i);
		if (reg.getId() == id) {
			cout << "------------------------------------" << endl;
			reg.mostrarProducto();
			cout << "------------------------------------" << endl;


			cout << "Esta seguro que desea modificar este producto? (s/n): ";
			char opcion;
			cin >> opcion;
			if (opcion == 's') {
				cout << "ingrese nueva informacion: " << endl;
				cout << "Ingrese el nombre: ";
				cin.ignore();
				cin.getline(_nombre, 50);
				cout << "Ingrese el precio: ";
				cin >> _precioUnitario;
				cout << "Ingrese el stock: ";
				cin >> _stock;
				cout << "Ingrese la descripcion: ";
				cin.ignore();
				cin.getline(_descripcion, 60);
				fecha.cargarFechaSistema();
				_estado = true;

				
				reg.setNombre(_nombre);
				reg.setPrecio(_precioUnitario);
				reg.setStock(_stock);
				reg.setDescripcion(_descripcion);
				reg.setFecha(fecha);
				reg.setEstado(_estado);
				
				ap.remplazarReg(reg, i);
				cout << "El producto fue modificado" << endl;
			}
			else {
				cout << "El producto no fue modificado" << endl;
			}
		}
	}

}

void Producto::listarProductos(){
	ArchivoProducto ap;
	int cantProductos = ap.contarRegistros(); //cuenta los registros
	Producto regProd; //crea un registro

	if (cantProductos == 0) {	// Si no hay registros
			cout << "No hay productos cargados" << endl;
		}
	else {
		for (int i = 0; i < cantProductos; i++) { //recorre los registros
					regProd = ap.leerRegistro(i); //lee el registro
					if (regProd.getEstado() == true) { //si el registro esta activo
									cout << "------------------------------------" << endl;
									regProd.mostrarProducto(); //muestra el registro
									cout << "------------------------------------" << endl;
								}
				}
	}
}



// metodo  que muestra el producto y sus detalles en pantalla para verificar que se cargaron correctamente
void Producto::mostrarProducto() {
	cout << "Id: " << _IdProducto << endl;
	cout << "Nombre: " << _nombre << endl;
	cout << "Precio: " << _precioUnitario << endl;
	cout << "Stock: " << _stock << endl;
	cout << "Descripcion: " << _descripcion << endl;
	fecha.mostrarFecha();
	if (_estado == true) cout << "Estado: Activo" << endl;
	else { cout << "Estado: Inactivo" << endl; }

}

void altaProducto(Producto reg, int pos){
	ArchivoProducto archProd;

	reg.setEstado(true);

	archProd.remplazarReg(reg, pos);
	cout << "producto dado de alta " << endl;

	

}
