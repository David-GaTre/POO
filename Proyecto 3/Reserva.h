#include "Fecha.h"

class Reserva {
	public:
		Reserva ();
		Reserva (int m, int c, Fecha r);
		
		void setMat (int m) {idMaterial = m;}
		void setCli (int c) {idCliente = c;}
		void setRes (Fecha r) {fechaReservacion = r;}
		
		int getMat () {return idMaterial;}
		int getClie () {return idCliente;}
		Fecha getRes () {return fechaReservacion;}
		
		Fecha calculaFechaFinReserva (int cantDias);
		
	private:
		int idMaterial, idCliente;
		Fecha fechaReservacion;
};

Reserva :: Reserva () {
	Fecha f;
	idMaterial = 1;
	idCliente = 1;
	fechaReservacion = f;	
}

Reserva :: Reserva (int m, int c, Fecha r) {
	idMaterial = m;
	idCliente = c;
	fechaReservacion = r;
}

Fecha Reserva :: calculaFechaFinReserva (int cantDias) {
	Fecha f;
	f = fechaReservacion + cantDias;
	return f;
}
