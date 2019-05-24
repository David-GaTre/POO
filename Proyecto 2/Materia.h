class Materia {
	public:
		//Constructores
		Materia();
		Materia(int i, string n);
		
		//Metodos de Acceso
		int getMateria() { return idMateria; }
		string getNombre() { return nombre; }
		
		//Metodos de Modificacion
		void setMateria ( int i ) { idMateria = i; }
		void setNombre ( string n ) { nombre = n; }
		
	private:
		int idMateria;
		string nombre;
};

Materia :: Materia () {
	idMateria = 0;
	nombre = ' ';
}

Materia :: Materia (int i, string n) {
	idMateria = i;
	nombre = n;
}
