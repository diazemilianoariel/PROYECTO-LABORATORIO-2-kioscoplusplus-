#pragma once
#include <iostream>
#include <cstring>
#include "..//..//CLASE FECHA/Fecha.h"
using namespace std;

/*
1. *Producto:*
   - Atributos: ID, nombre, precio, cantidad en stock, descripción, etc.
   - Métodos: Obtener detalles, actualizar stock, etc.*/
class Producto {
private:
	int _IdProducto;
	char _nombre[50];
	float _precioUnitario;
	int _stock;
	char _descripcion[100];
	Fecha fecha;
	bool _estado = true;
public:
	// Constructor por defecto
	Producto();

	// Constructor con parametros
	Producto(int Id, const char* nombre, float precio, int stock, const char* descripcion, Fecha f(const Fecha f()), bool est);

	// Metodos de acceso y modificacion
	void setId(int Id);
	int getId();
	void setNombre(const char* nombre);
	char* getNombre();
	void setPrecio(float precio);
	float getPrecio();
	void setStock(int stock);
	int getStock();
	void setDescripcion(const char* descripcion);
	char* getDescripcion();
	void setFecha(Fecha f);
	Fecha getFecha();
	void setEstado(bool estado);
	bool getEstado();


	// Metodos de la clase y operaciones que se pueden realizar con el producto
	void cargarProducto();//metodo para cargar los datos del producto
	void bajaLogicaProd();//metodo para dar de baja un producto
	void modificarProducto();//metodo para modificar los datos del producto
	void listarProductos();//metodo para listar los productos

	


	//metodo que muestra los datos del producto en pantalla, para verificar que se cargaron correctamente
	void mostrarProducto();
};


void altaProducto(Producto reg, int pos);



