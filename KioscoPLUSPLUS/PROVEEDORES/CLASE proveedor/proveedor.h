#pragma once
#include <iostream>


using namespace std;
class proveedor{
private:
	int idProveedor;
	char nombre[50];
	char direccion[50];
	char telefono[50];
	bool estado;

	public:

	//constructor por defecto sin parametros
	proveedor();
	//constructor con parametros
	proveedor(int id, char* nomb, char* dir, char* tel, bool est);


	//setters
	void setidProveedor(int id);
	void setNombre(char nombre[50]);
	void setDireccion(char direccion[50]);
	void setTelefono(char telefono[50]);
	void setEstado(bool est);

	//getters
	int getidProveedor();
	char* getNombre();
	char* getDireccion();
	char* getTelefono();
	bool getEstado();



	void cargarProveedor();
	void eliminarProveedor(); // al elinimar un proveedor debe mostrarme los datos de mismo con tan solo ingresar el id
	void modificarProveedor(); // al modificar un proveedor que me muestre el proveedor con tan solo ingresar el id
	void listarProveedores();
};

void altaProveedor(proveedor reg, int pos);

