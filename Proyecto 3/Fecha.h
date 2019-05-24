#ifndef ClaseFecha
#define ClaseFecha

class Fecha {
	public:
	Fecha ();
	Fecha (int d, int m, int a);
	int getD () { return dd; }
	int getM () { return mm; }
	int getA () { return aa; }
	void setFecha (int d, int m, int a);
	Fecha operator+ (int mas);
	bool operator> (Fecha f2);	
	bool operator>= (Fecha f2);
	bool operator<= (Fecha f2);
	bool operator< (Fecha f2);
	bool operator== (Fecha f2);
	friend istream& operator>> (istream &is, Fecha &f);
	friend ostream& operator<< (ostream &os, Fecha f);
	
	private:
	string nombreMes();
	bool esBisiesto();
	int dd, mm, aa;	
};

Fecha :: Fecha () {
	dd = 1;
	mm = 1;
	aa = 2010;
}

Fecha :: Fecha (int d, int m, int a) {
	dd = d;
	mm = m;
	aa = a;
}

void Fecha :: setFecha (int d, int m, int a) {
	dd = d;
	mm = m;
	aa = a;
}

//Luego lo cambiaré por un switch statement
string Fecha :: nombreMes () {
	string k;
	if (mm == 1) k = "Ene" ;
	if (mm == 2) k = "Feb" ;
	if (mm == 3) k = "Mar";
	if (mm == 4) k = "Abr" ;
	if (mm == 5) k = "May" ;
	if (mm == 6) k = "Jun" ;
	if (mm == 7) k = "Jul" ;
	if (mm == 8) k = "Ago" ;
	if (mm == 9) k = "Sep" ;
	if (mm == 10) k = "Oct" ;
	if (mm == 11) k = "Nov" ;
	if (mm == 12) k = "Dic" ;
	return k;
}

bool Fecha :: esBisiesto () {
	if ( (aa % 4) == 0 ) return true;
	return false; 
}

Fecha Fecha :: operator+ (int mas){
	Fecha fn (dd, mm, aa);
	fn.dd += mas;
		if ( (fn.dd > 31) && ( (fn.mm==1) || (fn.mm==3) || (fn.mm==5) || (fn.mm==7) || (fn.mm==8) || (fn.mm==10) || (fn.mm==12)) ) {
		fn.mm++;
		fn.dd -= 31;
		}
		if ( (fn.dd > 30) && ( (fn.mm==4) || (fn.mm==6) || (fn.mm==9) || (fn.mm==11) ) ) {
		fn.mm++;
		fn.dd -= 30;
		}
		if ( (fn.esBisiesto() && (fn.mm==2) && (fn.dd > 29)) || (!fn.esBisiesto() && (fn.mm==2) && (fn.dd > 28)) ){
			fn.mm++;
			if ( fn.esBisiesto() ){fn.dd -= 29;}
			else {fn.dd -= 28;}
		}
		if (fn.mm > 12) {
			fn.aa++;
			fn.mm -= 12;
		}
	return fn;
}

bool Fecha::operator> (Fecha f2){
	if (aa > f2.aa) return true;
	if ((aa==f2.aa) && (mm > f2.mm)) return true;
	if ((aa==f2.aa) && (mm == f2.mm) && (dd > f2.dd)) return true;
	return false;
}

bool Fecha::operator>= (Fecha f2){
	if (*this > f2) return true;
	if (*this == f2) return true;
	return false;
}

bool Fecha::operator<= (Fecha f2){
	if (*this < f2) return true;
	if (*this == f2 )return true; 
	return false;
}

bool Fecha::operator< (Fecha f2){
	if (aa < f2.aa) return true;
	if ((aa==f2.aa) && (mm < f2.mm)) return true;
	if ((aa==f2.aa) && (mm == f2.mm) && (dd < f2.dd)) return true;
	return false;
}

bool Fecha::operator== (Fecha f2){
	if ((aa==f2.aa) && (mm == f2.mm) && (dd == f2.dd)) return true;
	return false;
}

istream& operator>> (istream &is, Fecha &f){
	is >> f.dd;
	is >> f.mm;
	is >> f.aa;
}

ostream& operator<< (ostream &os, Fecha f){
	os << f.dd;
	os << '/';
	os << f.nombreMes();
	os << '/';
	os << f.aa;
}
#endif
