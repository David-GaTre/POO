#include "Material.h"

class Software : public Material {
	public:
		Software ();
		Software (int i, string t, string s);
		
		void setSis (string s) {sistemaOper = s;}
		
		string getSis () {return sistemaOper;}
		
		void muestra ();
		int cantidadDeDiasDePrestamo();
		
	private:
		string sistemaOper;
};

Software::Software () : Material () {
	sistemaOper = " ";
}
Software::Software(int i, string t, string s) : Material (i, t) {
	sistemaOper = s;
}


void Software::muestra ()  {
	cout << "Software " << idMaterial << "\nTitulo: " 
	<< titulo << "\nSistema Operativo: " << sistemaOper<< "\n" << endl;
}

int Software::cantidadDeDiasDePrestamo() {
	return 1;
}
