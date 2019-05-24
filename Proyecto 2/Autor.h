class Autor {
	public:
		//Constructores
		Autor();
		Autor( int a, string n );
		
		//Metodos de acceso
		int getAutor() { return idAutor; }
		string getNombre() { return nombre; }
		
		//Metodos de modificacion
		void setAutor(int a) { idAutor = a;}
		void setNombre(string n) { nombre = n; }
		
	private:
		int idAutor;
		string nombre;
};

Autor :: Autor () {	
	idAutor = 0;
	nombre = ' ';
}

Autor :: Autor ( int a, string n ) {
	idAutor = a;
	nombre = n;
}
