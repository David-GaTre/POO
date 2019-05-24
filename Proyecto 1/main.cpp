#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char movimientos ( string &sDato ) {
  string sDeterminar;

  if (sDato[0] != '@'){
    sDato.erase(0, sDato.find('@'));
  }
  sDeterminar = sDato.substr(0, sDato.find(" "));
  sDato = sDato.erase(0, sDato.find(" "));
  
  if (sDeterminar == "@progName")
    return 'a';
  if (sDeterminar == "@author")
    return 'b';
  if (sDeterminar == "@date")
    return 'c';
  if (sDeterminar == "@funcName")
    return 'd';
  if (sDeterminar == "@desc")
    return 'e';
  if (sDeterminar == "@param")
    return 'f';
  if (sDeterminar == "@return")
    return 'g';
    return 'z';
}

void generarArchivo ( string sNombreA ) {
  string sDato, sNuevo, sNombreB;
  ofstream aHTML;
  ifstream aOriginal;
  char cType;
  bool notNotes = false;

  sNombreB = sNombreA + ".cpp";
  sNuevo = sNombreA + ".html";

  aOriginal.open (sNombreB.c_str());
  aHTML.open (sNuevo.c_str());

  aHTML << "<!DOCTYPE html> \n <html> \n <head> \n <title> \n Documentacion del archivo " << sNombreB << "\n </title> \n </head> \n <body>" << endl;

  while ( aOriginal >> sDato ) {
  	
      if ( sDato == "/**"){
        
        getline (aOriginal,sDato);

        while (  sDato.find('*') - sDato.find('/') != -1  ){

          cType = movimientos (sDato);
          switch ( cType ) {

      case 'a':
        aHTML << "<h2> \n Programa: " << sDato << "<br> \n </h2>"<< endl;
        break;
      case 'b':
        aHTML << "<strong> Autor: </strong> "<< sDato << "<br>"<< endl;
        break;
      case 'c':
        aHTML << "<strong> Fecha de elaboracion </strong> " << sDato << "<br>" << endl;
        break;
      case 'd':
        aHTML << "<h3>\n <hr><br> Funcion: " << sDato << "<br> \n </h3>" << endl;
        break;
      case 'e':
      	aHTML << "<strong> Descripcion: </strong> " << sDato << "<br>" << endl;
      	break;
      case 'f':
      	aHTML << "<strong> Parametros: </strong> " << sDato << "<br>" << endl;
      	break;
      case 'g':
      	aHTML << "<strong> Valor de retorno: </strong> " << sDato << "<br>" << endl;
        break;
    }
          getline (aOriginal,sDato);

        }
      }
  }
  
  aHTML << "</body> \n </html>";

  aHTML.close();
  aOriginal.close();
}

int main () {

  string sNombreA;
  
  cout << "Cual es el nombre del archivo del que quiere generar el html?" << endl;
  getline ( cin, sNombreA );

  generarArchivo ( sNombreA );

  return 0;
}
