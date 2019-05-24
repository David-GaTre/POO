#include "Material.h"

class Disco : public Material {
	public:
		Disco ();
		Disco (int i, string t, int d);
		
		void setDura (int d) {duracion = d;}
		
		int getDura () {return duracion;}
		
		void muestra ();
		int cantidadDeDiasDePrestamo();	
		
	private:
		int duracion;
};

Disco :: Disco () : Material () {
	duracion = 1;
}

Disco :: Disco (int i, string t, int d) : Material (i, t) {
	duracion = d;
}

void Disco::muestra ()  {
	cout << "Disco " << idMaterial << "\nTitulo: " << titulo << "\nDuracion:" << duracion << "\n" <<  endl;
}

int Disco::cantidadDeDiasDePrestamo() {
	return 3;
}
