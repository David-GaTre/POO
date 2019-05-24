#ifndef ClaseMaterial
#define ClaseMaterial

class Material {
	public:
		Material ();
		Material (int i, string t);
		
		void setMate (int m) {idMaterial = m;}
		void setTitu (string t) {titulo = t;}
		
		int getMate () {return idMaterial;}
		string getTitu () {return titulo;}
		
		virtual void muestra() = 0;
		virtual int cantidadDeDiasDePrestamo () = 0;
		
	protected:
		int idMaterial;
		string titulo;
};

Material :: Material () {
	idMaterial = 1;
	titulo = " ";
}

Material :: Material (int i, string t) {
	idMaterial = i;
	titulo = t;
}
#endif
