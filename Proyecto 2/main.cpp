#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Materia.h"
#include "Tema.h"
#include "Autor.h"
#include "EjemploVideo.h"

void recibirMaterias ( Materia materias[], string sTemp, int iTemp ) {
	cout << "Escriba el nombre (con extension) del archivo de Materias" << endl;
	getline(cin, sTemp);
	ifstream fMateria;
	fMateria.open(sTemp.c_str());
	for ( int i = 0; i < 5; i++ ) {
		fMateria >> iTemp;
		getline ( fMateria, sTemp );
		materias[i].setMateria(iTemp);
		materias[i].setNombre(sTemp);
	}
	fMateria.close();
}

void recibirTemas ( Tema temas[], string sTemp, int iTemp ) {
	ifstream fTema;
	int i = 0;
	cout << "Escriba el nombre (con extension) del archivo de Temas" << endl;
	getline(cin, sTemp);
	fTema.open(sTemp.c_str());
	while (fTema >> iTemp) {
		temas[i].setTema(iTemp);
		fTema >> iTemp;
		temas[i].setMateria(iTemp);
		getline ( fTema, sTemp );
		temas[i].setNombre(sTemp);	
		i++;	
	}
	fTema.close();
}

void recibirAutores ( Autor autores[], string sTemp, int iTemp ) {
	ifstream fAutor;
	int i = 0;
	cout << "Escriba el nombre (con extension) del archivo de Autores" << endl;
	getline(cin, sTemp);
	fAutor.open(sTemp.c_str());

	while ( fAutor >> iTemp ) {
		getline ( fAutor, sTemp );
		autores[i].setAutor(iTemp);
		autores[i].setNombre(sTemp);
		i++;
	}
	fAutor.close();
}

void recibirVideos ( EjemploVideo videos[], string sTemp, int iTemp, Tema temas[], Autor autores[], int &iContadorV ) {
	int iTema, iDia, iMes, iAno, iCant, i = 0;
	ifstream fVideo;
	cout << "Escriba el nombre (con extension) del archivo de EjemploVideo" << endl;
	getline(cin, sTemp);
	fVideo.open(sTemp.c_str());
	
	while ( fVideo >> iTemp ){
		bool bExisteT = false, bExisteA2 = true;
		
		fVideo >> sTemp;
		fVideo >> iTema;

		for ( int j = 0; j < 10; j++ ) {
			if ( iTema == temas[j].getTema() ) {
				bExisteT = true;
				j = 10;
			}
		}
		
		
		if ( !bExisteT ) {
			cout << "El dato en la linea " << i << " no es valido." << endl;
			getline ( fVideo, sTemp );
		} else {
			
			fVideo >> iDia;
			fVideo >> iMes;
			fVideo >> iAno;
			fVideo >> iCant;
			
			int iTemp2[iCant];
			
			for ( int j = 0; j < iCant; j++ ) {
				bool bExisteA = false;
				fVideo >> iTemp2[j];
				
				for ( int k = 0; k < 10; k++ ) {
					if ( iTemp2[j] == autores[k].getAutor() ) {
						bExisteA = true;
						k = 10;
					}	
				}
				
				if ( !bExisteA ) {
					cout << "El dato en la linea " << i << " no es valido." << endl;
					j = iCant;
					bExisteA2 = false;
					getline ( fVideo, sTemp );
				}
				
			}
			if ( bExisteA2 ) {
				videos[iContadorV].setVideo(iTemp);
				videos[iContadorV].setNombre(sTemp);
				videos[iContadorV].setTema(iTema);
				videos[iContadorV].setFechaE(iDia,iMes,iAno);
				for ( int j = 0; j < iCant; j++ ) {
					videos[iContadorV].agregaAutor(iTemp2[j]);
				}
				iContadorV++;
			}
		}
		i++;
		
	}
	fVideo.close();
}

int main() {
	
	Materia materias[5];
	Tema temas[10];
	Autor autores[10];
	EjemploVideo videos[20];
	string sTemp;
	int iTemp, iContadorV = 0;
	char cMenu;
	
	recibirMaterias ( materias, sTemp, iTemp );
	recibirTemas ( temas, sTemp, iTemp );
	recibirAutores ( autores, sTemp, iTemp );
	recibirVideos ( videos, sTemp, iTemp, temas, autores, iContadorV );
	
	do {
		
		cout << "\t\t MENU \n a) Consulta info de materias, temas y autores \n b) Dar de alta videos de ejemplo" << endl;
		cout << " c) Consultar lista de videos por tema \n d) Consultar lista de videos por materia \n e) Consultar lista de Videos \n f) Consulta videos por autor \n g) Terminar" << endl;
		cin >> cMenu;
		cMenu = tolower(cMenu);
		cout << endl;
		switch (cMenu) {

		case 'a':
			cout << "\t MATERIAS" << endl;
			for ( int i = 0; i < 5; i++ ) {
				cout << materias[i].getMateria() << ' ' << materias[i].getNombre() << endl;
			}
			cout << endl;
			cout << "\t TEMAS" << endl;
			for ( int i = 0; i < 10; i++ ) {
				cout << temas[i].getTema() << ' ' << temas[i].getMateria() << ' ' << temas[i].getNombre() << endl;
			}
			cout << endl;
			cout << "\t AUTORES"  << endl;
			for ( int i = 0; autores[i].getAutor() != 0; i++ ) {
				cout << autores[i].getAutor() << ' ' << autores[i].getNombre() << endl;
			}
			cout << endl;
			break;
		//Arreglar b TODO, menu 3 veces, no agrega aunque este bien	
		case 'b':
		{
			cout << "Ingrese los datos del nuevo video en el orden solicitado" << endl;
			int iTema, iDia, iMes, iAno, iAutores, iTemp2, iContador;
			
			cout << "Introduzca el id del nuevo video." << endl;
			cin >> iTemp;
			
				for ( int i = 0; i < iContadorV; i++ ) {
					
					if ( iTemp == videos[i].getVideo() ) {
						cout << "El ID de ese video ya existe, pruebe otro numero." << endl;
						i = -1;
						cin >> iTemp;
					}
					
				}

			cout << "Introduzca el nombre del video (sin espacios) y luego el ID del tema." << endl;
			cin >> sTemp >> iTema;
			iContador = 0;
			
			for ( int i = 0; i < 10; i++ ) {
				if ( iTema == temas[i].getTema() ) {
					i = 10;
				}
				
				if ( i == 9 ) {
					cout << "Hubo un problema con el ID del tema que quizo agregar, intente introducirlo nuevamente" << endl;
					cin >> iTema;
					i = -1;
				}
					
			}
				
			cout << "Introduzca la fecha de elaboracion (dia mes a;o) seguido del numero de autores" << endl;
			cin >> iDia >> iMes >> iAno >> iAutores;
			
			for ( int i = 0; i < iAutores; i++ ) {
				bool bExiste = false;
				cout << "Agregue el ID del Autor " << i << endl;
				cin >> iTemp2;
				
				while (!bExiste) {
					
					for ( int j = 0; j < 10; j++ ) {
						if ( iTemp2 == autores[j].getAutor() ) {
							bExiste = true;
							bExiste = videos[iContadorV].agregaAutor(iTemp2);
						}
					}
					
					if (!bExiste) {
						cout << "El ID que introdujo no corresponde a ningun autor, intente de nuevo. Agregue el ID del Autor " << i << endl;
						cin >> iTemp2;
					}
				}
			}
				
					videos[iContadorV].setVideo(iTemp);
					videos[iContadorV].setNombre(sTemp);
					videos[iContadorV].setTema(iTema);
					videos[iContadorV].setFechaE(iDia,iMes,iAno);
					iContadorV++;
					cout << "Video a;adido con exito" << endl;
				
		}
			break;
			
		case 'c':
		{
			cout << "Cual es el id del tema del cual desea buscar?" << endl;
			cin >> iTemp;
			cout << endl;
			int iCounter = 0, iTemp2; 
			
			for ( int i = 0; i < iContadorV; i++ ) {
				if ( iTemp == videos[i].getTema() ) {
					cout << "Video " << iCounter + 1 << ':' << endl;
					cout << "Fecha de elaboracion: ";
					videos[i].getFecha();
					cout << "ID del Video: " << videos[i].getVideo() << endl;
					cout << "Nombre del Video: " << videos[i].getNombre() << endl;
					cout << "Autor(es): ";
					for ( int j = 0; j < videos[i].getCantidad(); j++ ) {
						iTemp2 = videos[i].getAutor(j);
						for ( int k = 0; k < 10; k++ ) {
							if ( iTemp2 == autores[k].getAutor() ) {
								cout << autores[k].getNombre() << "\n";
								k = 10;
							}
						}
					}
					cout << endl;
					iCounter++;
				}
			}
			
			if ( iCounter == 0 ) {
				cout << "No hay videos con el id del tema que esta buscando\n" << endl;
			}
		}
			break;
			
		case 'd':
		{
			cout << "Cual es el id de la materia que desea buscar?" << endl;
			cin >> iTemp;
			cout << endl;
			int iCounter = 0, iTemp2, iTemp3, iLugar;
			
			for ( int i = 0; i < iContadorV; i++ ) {
				
				iTemp2 = videos[i].getTema();
				for ( int j = 0; j < 10; j++ ) {
					if ( iTemp2 == temas[j].getTema() ) {
						iLugar = j;
						j = 10;
					}
				}
				
				if ( iTemp == temas[iLugar].getMateria() ) {
					cout << "Video " << iCounter + 1 << ':' << endl;
					cout << "Tema del Video: " << temas[iLugar].getNombre() << endl;
					cout << "Fecha de elaboracion: ";
					videos[i].getFecha();
					cout << "ID del Video: " << videos[i].getVideo() << endl;
					cout << "Nombre del Video: " << videos[i].getNombre() << endl;
					cout << "Autor(es): ";
					
					for ( int j = 0; j < videos[i].getCantidad(); j++ ) {
						iTemp3 = videos[i].getAutor(j);
						for ( int k = 0; k < 10; k++ ) {
							if ( iTemp3 == autores[k].getAutor() ) {
								cout << autores[k].getNombre() << "\n";
								k = 10;
							}
						}
					}
					
					cout << endl;
					iCounter++;
				}
			}
			
			if ( iCounter == 0 ) {
				cout << "No hay videos de el id de la materia que esta buscando" << endl;
			}
		}
			break;
			
		case 'e':
		{
			cout << "A continuacion un listado de todos los videos disponibles con sus caracteristicas: " << endl;
			int iLugar, iTemp, iTemp2;
			for ( int i = 0; i < iContadorV; i++ ) {
				
				iTemp = videos[i].getTema();
				for ( int j = 0; j < 10; j++ ) {
					if ( iTemp == temas[j].getTema() ) {
						iLugar = j;
						j = 10;
					}
				}
				
				cout << "Video " << i + 1 << ':' << endl;
				cout << "Materia del Video";
				iTemp = temas[iLugar].getMateria();
				for ( int j = 0; j < 5; j++ ) {
					if ( iTemp == materias[j].getMateria() ) {
						cout << materias[j].getNombre() << endl;
						j = 5;
					}
				}
				cout << "Tema del Video: "<< temas[iLugar].getNombre() << endl;
				cout << "Fecha de elaboracion: ";
				videos[i].getFecha();
				cout << "ID del Video: " << videos[i].getVideo() << endl;
				cout << "Nombre del Video: " << videos[i].getNombre() << endl;
				cout << "Autor(es): ";
					
				for ( int j = 0; j < videos[i].getCantidad(); j++ ) {
					iTemp2 = videos[i].getAutor(j);
					for ( int k = 0; k < 10; k++ ) {
						if ( iTemp2 == autores[k].getAutor() ) {
							cout << autores[k].getNombre() << "\n";
							k = 10;
						}
					}
				}
				cout << endl;
			}	
		}
			break;
			
		case 'f':
		{
			int iTemp2;
			bool bParticipo = false;
			cout << "Introduzca el ID del autor del que desea conocer los videos en los que ha participado: " << endl;
			cin >> iTemp;
			
			for ( int i = 0; i < 10; i++ ) {
				if ( autores[i].getAutor() == iTemp ) {
					cout << "Nombre del autor: " << autores[i].getNombre() << endl;
					i = 10;
				}
				if ( i == 9 ) {
					cout << "No existe el autor" << endl;
				}
			}
			
			cout << "Participo en: " << endl;
			
			for ( int i = 0; i < iContadorV; i++ ) {
				
				for ( int j = 0; j < videos[i].getCantidad(); j++ ) {
					if ( iTemp == videos[i].getAutor(j) ) {
						cout << "ID: " << videos[i].getVideo() << " Nombre: ";
						cout << videos[i].getNombre() << endl;
						j = 10;
						bParticipo = true;
					}
				}
				
			}
			
			if (!bParticipo) {
				cout << "Ninguno :(" << endl;
			}
		}
			break;
		}
			
		
	} while ( cMenu != 'g' );
	
	return 0;
}
