#define _CRT_SECURE_NO_WARNINGS // agrgar esto en cada clase que tenga un strcpy
#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include "..//CLASE archivoVenta/archivoVenta.h"
#include "../CLASE Venta/Venta.h"
using namespace std;

class archivoVenta{
private:
	char nombre[30];
public:

	archivoVenta();

	Venta leerRegistro(int pos);
	
	int contarRegistros();

	bool remplazarReg(Venta reg, int pos);

	void mostrarTodasLasVentas();

	bool grabarRegistro(Venta reg);

	bool eliminarRegistro(int pos, Venta reg);

	int buscarVenta(int id);


	


};

