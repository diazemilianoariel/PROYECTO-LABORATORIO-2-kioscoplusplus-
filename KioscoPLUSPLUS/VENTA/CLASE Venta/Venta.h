#pragma once
#include "..//..//CLASE FECHA/Fecha.h"
#include <vector>
#include "../CLASE detalleVenta/detalleVenta.h"
using namespace std;
class Venta{
	private:
		int idVenta;
		float total;
		Fecha fecha;
		bool estado;
		

	public:
		Venta();
;
		Venta(int idV,  float total, Fecha f(const Fecha f()), bool est);



		void setIdVenta(int idVenta);
		void setTotal(float precio);
		void setFecha(Fecha fecha);
		void setEstado(bool estado);



		int getIdVenta() const;
		float getTotal() const;
		Fecha getFecha() const;
		bool getEstado() const;


		void cargarVenta();
		void mostrarVenta();


};





