#define _CRT_SECURE_NO_WARNINGS // agrgar esto en cada clase que tenga un strcpy
#include "archivoProveedor.h"

archivoProveedor::archivoProveedor(){
	strcpy(nombre, "proveedores.dat");
}

archivoProveedor::archivoProveedor(const char* nom) {
	strcpy(nombre, nom);
}

proveedor archivoProveedor::leerRegistro(int pos){
	proveedor reg;
	FILE* p = fopen(nombre, "rb");

	if (p == NULL) {
		// Si el archivo no existe, intenta crearlo
		p = fopen(nombre, "ab+");
		if (p == NULL) {
			cout << "ERROR AL CREAR EL ARCHIVO" << endl;
			reg.setidProveedor(-2);
			return reg;
		}
		// Si se creó correctamente, ciérralo y vuélvelo a abrir en modo de lectura
		fclose(p);
		p = fopen(nombre, "rb");
		if (p == NULL) {
			cout << "ERROR DE ARCHIVO - leer" << endl;
			reg.setidProveedor(-2);
			return reg;
		}
	}

	fseek(p, sizeof reg * pos, 0);
	fread(&reg, sizeof reg, 1, p);
	fclose(p);
	return reg;
}

int archivoProveedor::contarRegistros() {
	FILE* p;
	p = fopen(nombre, "rb");
	if (p == nullptr) return -1;
	int conatdor = 0;
	proveedor reg;
	while (fread(&reg, sizeof(proveedor), 1, p) == 1) {
		conatdor++;
	}
	fclose(p);
	return conatdor;
}

bool archivoProveedor::remplazarReg(proveedor reg, int pos) {
	FILE* p = fopen(nombre, "rb+");
	if (p == nullptr) { return false; }
	fseek(p, pos * sizeof(proveedor), SEEK_SET);
	bool pudoEscribir = fwrite(&reg, sizeof(proveedor), 1, p) == 1;
	fclose(p);
	return pudoEscribir;
}

bool archivoProveedor::grabarRegistro(proveedor reg) {
	FILE* p;
	p = fopen(nombre, "ab");
	if (p == NULL) return false;
	bool escribio = fwrite(&reg, sizeof reg, 1, p);
	fclose(p);
	return escribio;
}

bool archivoProveedor::eliminarRegistro(int pos, proveedor reg){
	proveedor regVacio;
	regVacio.setidProveedor(-1);
	FILE* p = fopen(nombre, "rb+");
	if (p == nullptr) { return false; }
	fseek(p, pos * sizeof(proveedor), SEEK_SET);
	bool pudoEscribir = fwrite(&regVacio, sizeof(proveedor), 1, p) == 1;
	fclose(p);
	return pudoEscribir;
}

int archivoProveedor::buscarProveedor(int idProveedor){
	proveedor reg;
	int pos = 0;
	while (true) {
		reg = leerRegistro(pos);
		if (reg.getidProveedor() == idProveedor) {
			return pos;
		}
		if (reg.getidProveedor() == -2) {
			return -1;
		}
		pos++;
	}
}

const char* archivoProveedor::buscarProveedor(char* nombre){
	proveedor reg;
	int pos = 0;
	while (true) {
		reg = leerRegistro(pos);
		if (strcmp(reg.getNombre(), nombre) == 0) {
			return reg.getNombre();
		}
		if (reg.getidProveedor() == -2) {
			return "No se encontro el proveedor";
		}
		pos++;
	}
}


