#include "Material.h"

class Libro : public Material {
	public:
		Libro ();
		Libro (int i, string t, int n, string a);
		
		void setPag (int n) {numPag = n;}
		void setAut (string a) {Autor = a;}
		
		int getPag () {return numPag;}
		string getAut () {return Autor;}
		
		void muestra ();
		int cantidadDeDiasDePrestamo();
 		
	private:
		int numPag;
		string Autor;
};

Libro :: Libro () : Material () {
	numPag = 1;
	Autor = " ";
}

Libro :: Libro (int i, string t, int n, string a) : Material (i, t) {
	numPag = n;
	Autor = a;
}

void Libro::muestra ()  {
	cout << "Libro " << idMaterial << "\nTitulo: " 
		 << titulo << "\nNumero de paginas: " 
		 << numPag << "\nAutor:" << Autor << "\n" << endl;
}

int Libro::cantidadDeDiasDePrestamo() {
	return 10;
}
