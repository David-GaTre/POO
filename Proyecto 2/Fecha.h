class Fecha {
	public:
		//Constructor
		Fecha();
		
		//Metodos de acceso
		int getDia () { return dd; }
		int getMes () { return mm; }
		int getAno () { return aa; }
		
		//Metodo de modificacion
		void setFecha ( int d, int m , int a);
		
	private:
		int dd, mm, aa;
};

Fecha :: Fecha () {
	dd = 1;
	mm = 1;
	aa = 2000;
}

void Fecha :: setFecha ( int d, int m, int a ) {
	dd = d;
	mm = m;
	aa = a;	
}
