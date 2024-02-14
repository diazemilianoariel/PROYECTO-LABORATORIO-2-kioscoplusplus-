#pragma once
/*una clase fecha que permita mostrar la fecha del sistema  */
class Fecha{
private:
	int dia, mes, anio;
public:
	Fecha();//constructor por defecto
	Fecha(int d, int m, int a);//constructor con parametros
	//setters
	void setDia(int);
	void setMes(int);
	void setAnio(int);

	//getters
	int getDia();
	int getMes();
	int getAnio();

	void cargarFechaSistema();//metodo para cargar la fecha del sistema
	void mostrarFecha();// metodo para mostrar la fecha del sistema

};

