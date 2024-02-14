#include "archivoVenta.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include "..//CLASE archivoVenta/archivoVenta.h"
#include "../CLASE Venta/Venta.h"
using namespace std;

archivoVenta::archivoVenta(){
	strcpy(nombre, "ventas.dat");
}



Venta archivoVenta::leerRegistro(int pos) {
	Venta reg;
	reg.setEstado(false);
	FILE* p;
	p = fopen(nombre, "rb");
	if (p == nullptr) return reg;
	fseek(p, sizeof reg * pos, 0);
	fread(&reg, sizeof reg, 1, p);
	fclose(p);
	return reg;
}


bool archivoVenta::grabarRegistro(Venta reg) {
	FILE* p;
	p = fopen(nombre, "ab");
	if (p == nullptr) return false;
	bool escribio = fwrite(&reg, sizeof(Venta), 1, p);
	fclose(p);
	return escribio;
}

bool archivoVenta::eliminarRegistro(int pos, Venta reg) {
	FILE* p;
	p = fopen(nombre, "rb+");
	if (p == nullptr) return false;
	fseek(p, pos * sizeof(Venta), SEEK_SET);
	reg.setEstado(false);
	bool escribio = fwrite(&reg, sizeof(Venta), 1, p);
	fclose(p);
	return escribio;
}

int archivoVenta::buscarVenta(int id) {
	FILE* p;
	p = fopen(nombre, "rb");
	if (p == nullptr) return -1;
	Venta reg;
	int pos = 0;
	while (fread(&reg, sizeof(Venta), 1, p) == 1) {
		if (reg.getIdVenta() == id && reg.getEstado()) {
			fclose(p);
			return pos;
		}
		pos++;
	}
	fclose(p);
	return -1;
}




int archivoVenta::contarRegistros(){
	FILE* p;
	p = fopen(nombre, "rb");
	if (p == nullptr) return -1;
	int conatdor = 0;
	Venta reg;
	while (fread(&reg, sizeof(Venta), 1, p) == 1) {
		conatdor++;
	}
	fclose(p);
	return conatdor;
	
}

bool archivoVenta::remplazarReg(Venta reg, int pos){
	FILE* p = fopen(nombre, "rb+");
	if (p == nullptr) { return false; }
	fseek(p, pos * sizeof(Venta), SEEK_SET);
	bool pudoEscribir = fwrite(&reg, sizeof(Venta), 1, p) == 1;
	fclose(p);
	return pudoEscribir;

}

void archivoVenta::mostrarTodasLasVentas() {
	FILE* p;
	p = fopen(nombre, "rb");
	if (p == nullptr) {
		cout << "No se pudo abrir el archivo de ventas." << endl;
		return;
	}

	Venta reg;
	cout << "Ventas registradas:" << endl;
	while (fread(&reg, sizeof(Venta), 1, p) == 1) {
		// Imprime los detalles de la venta
		cout << "ID Venta: " << reg.getIdVenta() << endl;
		cout << "Fecha: " << reg.getFecha().getDia() << "/" << reg.getFecha().getMes() << "/" << reg.getFecha().getAnio() << endl;
		cout << "Total: " << reg.getTotal() << endl;
		cout << "Estado: " << (reg.getEstado() ? "Cerrada" : "Abierta") << endl;
		cout << endl;
	}

	fclose(p);
}




