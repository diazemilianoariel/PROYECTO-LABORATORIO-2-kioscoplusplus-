#pragma once
#include "../CLASE proveedor/proveedor.h"

class archivoProveedor{
private:
	char nombre[50];
public:
    //constructor por defecto
    archivoProveedor();
    //constructor con parametros
    archivoProveedor(const char* nom);

    proveedor leerRegistro(int pos);

    int contarRegistros();

    // void cargarProducto();

    bool remplazarReg(proveedor reg, int pos);

    bool grabarRegistro(proveedor reg);

    bool eliminarRegistro(int pos, proveedor reg);

    int buscarProveedor(int idProveedor);

    const char* buscarProveedor(char* nombre); // verificar si funcion ? -.... probarlo.

};

