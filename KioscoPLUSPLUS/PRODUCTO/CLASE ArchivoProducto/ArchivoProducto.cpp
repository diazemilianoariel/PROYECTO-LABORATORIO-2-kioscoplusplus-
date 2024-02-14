#include "..//CLASE ArchivoProducto/ArchivoProducto.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#include "../CLASE producto/producto.h"
#include "../../VENTA/CLASE Venta/Venta.h"
using namespace std;





 /*utilizar este metodo en el resto del programa */
ArchivoProducto::ArchivoProducto(){
    strcpy(nombre, "productos.dat");
}

ArchivoProducto::ArchivoProducto(const char* nom){
    strcpy(nombre, nom);
}

Producto ArchivoProducto::leerRegistro(int pos) {
	Producto reg;
	FILE* p = fopen(nombre, "rb");
    if (p == NULL) {
		cout << "ERROR DE ARCHIVO - leer" << endl;
		reg.setId(-2);
		return reg;
	}
	fseek(p, sizeof reg * pos, 0);
	fread(&reg, sizeof reg, 1, p);
	fclose(p);
	return reg;
}

int ArchivoProducto::contarRegistros() {
    FILE* p;
    p = fopen(nombre, "rb");
    if (p == nullptr) return -1;
    int conatdor = 0;
    Producto reg;
    while (fread(&reg, sizeof(Producto), 1, p) == 1) {
        conatdor++;
    }
    fclose(p);
    return conatdor;
}

bool ArchivoProducto::remplazarReg(Producto reg, int pos) {
    FILE* p = fopen(nombre, "rb+");
    if (p == nullptr) { return false; }
    fseek(p, pos * sizeof(Producto), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Producto), 1, p) == 1;
    fclose(p);
    return pudoEscribir;
}

bool ArchivoProducto::grabarRegistro(Producto reg) {
    FILE* p;
    p = fopen(nombre, "ab");
    if (p == NULL) return false;
    bool escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoProducto::eliminarRegistro(int pos, Producto reg) {
    reg.setEstado(false); // marca el registro como eliminado
    FILE* p;
    p = fopen(nombre, "rb+"); // abre el archivo
    if (p == nullptr) return false;
    fseek(p, sizeof reg * pos, 0);
    fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    cout << "Producto eliminado - ID: " << reg.getId() << endl;
    return true;

}

int ArchivoProducto::buscarProducto(int idProducto) {
    Producto reg;
    FILE* p = fopen(nombre, "rb");
    if (p == NULL) {return -2;}
    int cont = 0;
    while (fread(&reg, sizeof reg, 1, p) == 1) {
        if (idProducto == reg.getId()) {
			fclose(p);
			return cont;
		}
        cont++;
	}
    fclose(p);
    return -1;
}

const char* ArchivoProducto::buscarProducto(char* nombre){
Producto reg;
	FILE* p = fopen(nombre, "rb");
	if (p == NULL) {
		cout << "ERROR DE ARCHIVO - buscar" << endl;
		return "ERROR";
	}
	int cont = 0;
	while (fread(&reg, sizeof reg, 1, p) == 1) {
		if (strcmp(nombre, reg.getNombre()) == 0) {
			fclose(p);
			return reg.getNombre();
		}
		cont++;
	}
	fclose(p);
	return "ERROR";
}


