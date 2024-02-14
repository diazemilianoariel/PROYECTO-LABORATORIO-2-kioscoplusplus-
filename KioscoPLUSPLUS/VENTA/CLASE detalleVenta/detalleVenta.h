#pragma once
class detalleVenta{
private:
	int idVenta;
	int idProducto;
	int cantidad;
	float precioUnitario;
	float subtotal;
public:
	detalleVenta();
	detalleVenta(int idV, int idP, int cant, float precioU, float sub);


	void setIdVenta(int idVenta);
	void setIdProducto(int idProducto);
	void setCantidad(int cantidad);
	void setPrecioUnitario(float precioUnitario);
	void setSubtotal(float subtotal);


	int getIdVenta() const;
	int getIdProducto() const;
	int getCantidad() const;
	float getPrecioUnitario() const;
	float getSubtotal() const;


	void cargarDetalleVenta();
	void mostrarDetalleVenta();
};

