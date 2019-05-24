class Tema {
	public:
		//Constructores
		Tema();
		Tema ( int t, string n, int m );
		
		//Metodos de Acceso
		int getTema () { return idTema; }
		string getNombre () { return nombre; }
		int getMateria () { return idMateria; }
		
		//Metodos de Modificacion
		void setTema ( int t ) { idTema = t; }
		void setNombre ( string n ) { nombre = n; }
		void setMateria ( int m ) { idMateria = m; } 
		
	private:
		int idTema;
		string nombre;
		int idMateria;
};

Tema :: Tema () {
	idTema = 0;
	nombre = ' ';
	idMateria = 0;
}

Tema :: Tema ( int t, string n, int m ) {
	idTema = t;
	nombre = n;
	idMateria = m;
}
