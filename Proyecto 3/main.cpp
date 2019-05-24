#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Reserva.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

void casoA ( Material *listaM[], int iSizeM) {
	for (int i = 0; i < iSizeM; i++) {
		listaM[i]-> muestra();
	}
}

void casoB ( Material *listaM[], Reserva listaR[], int iSizeM, int iSizeR ) {
	int mat;
	for (int i = 0; i < iSizeR; i++) {
		cout << "#" << i+1 << " Fecha de reservacion:" << listaR[i].getRes() << endl;		
		for (int j = 0; j < iSizeM; j++) {
			if (listaR[i].getMat() == (listaM[j]->getMate()) ) {
				mat = listaM[j]->cantidadDeDiasDePrestamo();
				cout << "Fecha de terminacion: " << listaR[i].calculaFechaFinReserva(mat) << endl;;
				cout << "Titulo: " << listaM[j]->getTitu() << endl;
				j = iSizeM;
			}					
		}
		cout << "Cliente: " << listaR[i].getClie() << "\n" << endl;
	}
}

void casoC ( Material *listaM[], Reserva listaR[], int iSizeM, int iSizeR ){
	int id, o=1, mat;
	string g = "_"; // No existe ningun libro con ese titulo
	cout << "Que material desea consultar?" << endl;
	cin >> id;

	for ( int i = 0; i < iSizeM; i++) {	
		if ( id == listaM[i]->getMate() )	{
			g = listaM[i]->getTitu();
			mat = listaM[i]->cantidadDeDiasDePrestamo();
			i = iSizeM;
		}
	}
	cout << endl;
	if (g == "_") {
		cout << "No existe el material" << endl;
	} else {
		for (int i = 0; i < iSizeR; i++) {
			if ( id == listaR[i].getMat() ) {
				cout << "Reservacion #" << o++ << " Material: " << g << endl;
				cout << "Inicio de reservacion: " << listaR[i].getRes() << endl;
				cout << "Fin de reservacion: " << listaR[i].calculaFechaFinReserva(mat) << endl;
				cout << "ID Cliente: " << listaR[i].getClie() << "\n" <<endl;					
			}
		}
	}
	if (o == 1)
		cout << "No hay reservaciones." << endl;
}

void casoD ( Material *listaM[], Reserva listaR[], int iSizeM, int iSizeR ) {
	Fecha f;
	string g;
	int mat, o = 1;
	cout << "Que fecha quiere consultar?(dd/mm/aa)" << endl;
	cin >> f;
	cout << "\nEn esa fecha estan las siguientes reservaciones: " << endl;
	for (int i = 0; i < iSizeR; i++) {
		if ( f >= listaR[i].getRes() ) {
			for (int j = 0; j < iSizeM; j++) {
				if (listaR[i].getMat() == listaM[j]->getMate() ) {
					g = listaM[j]->getTitu();
					mat = listaM[i]->cantidadDeDiasDePrestamo();
					j = iSizeM;
				}
			}
			if ( f <= listaR[i].calculaFechaFinReserva(mat) ){
				cout << "Reservacion #" << o++ << " Material: " << g << endl;
				cout << "Inicio de reservacion: " << listaR[i].getRes() << endl;
				cout << "Fin de reservacion: " << listaR[i].calculaFechaFinReserva(mat) << endl;
				cout << "ID Cliente: " << listaR[i].getClie() << "\n" << endl;	
			}
		}		
	}
	if (o == 1)
		cout << "No hay reservaciones en esa fecha" << endl;
}

void casoE ( Material *listaM[], Reserva listaR[], int iSizeM, int &iSizeR ) {
	int mat, client, dias;
	Fecha f, fin;
	bool validM, validF;
	cout << "Escriba el ID del cliente:" << endl;
	cin >> client;
	cout << "Escriba el ID del material:" << endl;

	do {
		cin >> mat;	
		validM = false;	
		for (int i = 0; i < iSizeM; i++) {
			if (mat == listaM[i]->getMate() )
				validM = true;
		}
		if (!validM)
			cout << "Este material no es valido, escriba otro." << endl;
			
	} while (!validM);
	
	cout << "Escriba la fecha(dd/mm/aa) de reserva: " << endl;	
	
	do{
	cin >> f;
	validF = true;
	for (int i = 0; i < iSizeR; i++) {
		if (mat == listaR[i].getMat()) {
			for (int j = 0; j < iSizeM; j++) {
				if ( mat == listaM[j]->getMate() ) {
					dias = listaM[j]->cantidadDeDiasDePrestamo();
					fin = listaR[i].calculaFechaFinReserva(dias);
					j = iSizeM;
				}
			}
			if ( (f >= listaR[i].getRes()) && (f <= fin) ) {
				validF = false;
				i = iSizeR;
			}							
		}
	}
	
	if (validF){
		listaR[iSizeR++] = Reserva (mat, client, f);
	} else {
		cout << "La fecha no es valida, no se pudo completar su reservacion. Ingrese otra fecha." << endl;
	}
	} while (!validF);
}

void recibirMateriales ( Material *listaM[], int &iSizeM ){
	int iTemp, iTemp2;
	string sTemp, sTemp2;
	ifstream Materiales;
	Materiales.open("Material.txt");
	
	while (Materiales >> iTemp) {		
		Materiales >> sTemp;
		Materiales >> sTemp2;
		if (sTemp2 == "L") {
			Materiales >> iTemp2;
			Materiales >> sTemp2;
			listaM[iSizeM] = new Libro (iTemp, sTemp, iTemp2, sTemp2);
		}
		if (sTemp2 == "D" ) {
			Materiales >> iTemp2;
			listaM[iSizeM] = new Disco (iTemp, sTemp, iTemp2);
		}
		if (sTemp2 == "S" ) {
			Materiales >> sTemp2;
			listaM[iSizeM] = new Software (iTemp, sTemp, sTemp2);
		}
		iSizeM++;
	}
	Materiales.close();
}

void recibirReservaciones ( Reserva listaR[], int &iSizeR ) {
	int mat, client;
	Fecha f;
	ifstream Reservaciones;
	Reservaciones.open("Reserva.txt");
	
	while (Reservaciones >> f){
		Reservaciones >> mat;
		Reservaciones >> client;

		listaR[iSizeR].setMat(mat);
		listaR[iSizeR].setCli(client);
		listaR[iSizeR].setRes(f);
		iSizeR++;
	}
	Reservaciones.close();
}

void casoF ( Reserva listaR[], int iSizeR, int iOriginal) {
	ofstream Reservaciones;
	Reservaciones.open("Reserva.txt", ios::app);
	
	while (iOriginal != iSizeR){
		Reservaciones << endl << listaR[iOriginal].getRes().getD() << ' '
					  << listaR[iOriginal].getRes().getM() << ' '
					  << listaR[iOriginal].getRes().getA() << ' '
					  << listaR[iOriginal].getMat() << ' '
					  << listaR[iOriginal].getClie();		
		iOriginal++;
	}
	
	Reservaciones.close();
}

int main (){
	Material *listaM[20];
	Reserva listaR[50];
	int iSizeM = 0, iSizeR = 0, iOriginal;
	char cMenu;	
	
	recibirMateriales ( listaM, iSizeM );
	recibirReservaciones ( listaR, iSizeR );
	iOriginal = iSizeR;
	
	do {
		cout << "\t\t MENU" << endl;
		cout << "a)Consultar lista de Materiales\nb)Consultar la lista de reservaciones" << endl;
		cout << "c)Consultar las reservaciones de un material dado\nd)Consultar las reservaciones de una fecha dada" << endl;
		cout << "e)Hacer una reservación\nf)Terminar" << endl;
		cin >> cMenu;
		cout << endl;
		switch (cMenu) {
			case 'a':
				casoA (listaM, iSizeM);
				break;
			case 'b':
				casoB (listaM, listaR, iSizeM, iSizeR);
				break;
			case 'c':
				casoC (listaM, listaR, iSizeM, iSizeR);
				break;
			case 'd':
				casoD (listaM, listaR, iSizeM, iSizeR);
				break;
			case 'e':
				casoE (listaM, listaR, iSizeM, iSizeR);
				break;
			case 'f':
				casoF ( listaR, iSizeR, iOriginal);
				break;
		}
	} while (cMenu != 'f');
	
	return 0;
}
