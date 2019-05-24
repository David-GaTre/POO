#include "Fecha.h"

class EjemploVideo {
	public:
		//Constructores
		EjemploVideo ();
		
		//Metodos de acceso
		int getVideo () { return idVideo; }
		string getNombre () { return nombre; }
		int getTema () { return idTema; }
		Fecha getFecha () { cout << fechaElaboracion.getDia() << '/' << fechaElaboracion.getMes() << '/' << fechaElaboracion.getAno() << endl ; }
		int getAutor ( int i ) { return listaAutores[i]; }
		int getCantidad () { return cantidadAutores; }
		
		//Metodos de modificacion
		void setVideo ( int v ) { idVideo = v; }
		void setNombre ( string n ) { nombre = n; }
		void setTema ( int t ) { idTema = t; }
		void setFechaE ( int d, int m, int a) { fechaElaboracion.setFecha(d, m, a); }
		
		//Otros metodos
		bool agregaAutor ( int id );
		
	private:
		int idVideo, idTema, cantidadAutores, listaAutores[10];
		string nombre;
		Fecha fechaElaboracion;
};

EjemploVideo :: EjemploVideo () {
	Fecha a;
	
	fechaElaboracion = a;
	nombre = ' ';
	idVideo = 0;
	idTema = 0;
	cantidadAutores = 0;
	for ( int i = 0; i < 10; i++ ){
		listaAutores[i] = 0;
	}
}

bool EjemploVideo :: agregaAutor ( int id ) {
	bool bExistente = true ;
	int j = 0;
	
	for ( int i = 0; i < 10; i++ ) {	
		if ( id == listaAutores[i] ) {
			bExistente = false;
		}
	}
	
	if ( cantidadAutores > 10 ) {
		bExistente = false;
	}
	
	if ( bExistente ) {
		cantidadAutores++;
		while ( listaAutores[j] != 0 ) {
			j++;
		}
		listaAutores[j] = id;
	}
	return bExistente;
}

