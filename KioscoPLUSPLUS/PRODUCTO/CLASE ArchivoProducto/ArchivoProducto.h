#define _CRT_SECURE_NO_WARNINGS // agrgar esto en cada clase que tenga un strcpy
#pragma once
//#include "../CLASE producto/producto.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include "../CLASE producto/producto.h"

class ArchivoProducto {
private:
    char nombre[30];
public:


    ArchivoProducto();

    ArchivoProducto(const char* nom);

    Producto leerRegistro(int pos);

    int contarRegistros();

   // void cargarProducto();

    bool remplazarReg(Producto reg, int pos);

    bool grabarRegistro(Producto reg);

    bool eliminarRegistro(int pos, Producto reg);

    int buscarProducto(int id);

    const char* buscarProducto(char* nombre); // verificar si funcion ? -.... probarlo.


};


