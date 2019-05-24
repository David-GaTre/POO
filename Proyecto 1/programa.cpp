/**
   @progName LecturadeMapa
  @desc Programa que lee un archivo con cantidad de puertas en cada direccion dichas en un archivo
  @autor David Garcia
  @date 19 de Noviembre de 2018

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct oRoom
{ 
	string sName;
	short int iDoors;
	string sDirections;
};

/**
@funcName readFile 
@desc lee los datos de un archivo en un formato especifico y guarda los datos en un arreglo 
@param oArrRoom para meter los datos en el arreglo para las siguientes opciones de direcciones
@return regresa el arreglo completo con los datos del archivo

  */

void readFile( oRoom oArrRoom[])
{ 
	string sFile;
	//cout << "Which file will you read? " << endl;
	cin >> sFile;
	ifstream fMyFile;
	fMyFile.open(sFile.c_str());
	for( int iCounter = 0; iCounter < 10; iCounter++)
	{ 
		fMyFile >> oArrRoom[iCounter].sName;
		fMyFile >> oArrRoom[iCounter].iDoors;
		fMyFile >> oArrRoom[iCounter].sDirections;
	}
	fMyFile.close();
}

/**
@funcName calculateAverage
@desc la funcion agarra los numeros del archivo que representan el numero de puertas, suma las cantidades y luego lo divide entre 10 (porque asi vienen los casos de prueba)
@param fAverage guarda el promedio de puertas, oArrRoom es el arreglo que contiene la cantidad de puertas y la direccion de cada cuarto
@return regresa el promedio de la cantidad de puerta de los cuartos

*/

void calculateAverage ( float &fAverage, oRoom oArrRoom[])
{ 
	float fNumber = 0;

	for( int iCounter = 0; iCounter < 10; iCounter++)
	{ 
		fNumber += oArrRoom[iCounter].iDoors;
	}
	fAverage = fNumber / 10.0;
}

/** 
@funcName countDirections
@desc esta funcion agarra un string encontrado en el arreglo del archivo y busca caracteres que indican la direccion de las puertas de los cuartos, en caso de encontrarlo, lo guarda la posicion en la que esta (positivo) y esto le a;ade 1 al arreglo de las coordenadas de las puertas, de lo contrario saca un -1 y no suma nada al arreglo
@param oArrRoom da un arreglo con las direcciones de las puertas de los cuartos, iArrDirections guarda la cuenta de la cantidad de veces que se repiten las direcciones (Norte, Sur, Este y Oeste)
@return regresa el arreglo de iArrDirections con la cuenta de Nortes, Sures, Estes y Oestes que estan en el archivo

*/

void countDirections ( oRoom oArrRoom[], int iArrDirections[]) 
{ 
	for ( int iCounter = 0; iCounter < 10; iCounter++)
	{ 
		if (oArrRoom[iCounter].sDirections.find('N') != -1)
		{ 
			iArrDirections[0] += 1;
		}
		if (oArrRoom[iCounter].sDirections.find('S') != -1)
		{ 
			iArrDirections[1] += 1;
		}
		if (oArrRoom[iCounter].sDirections.find('E') != -1)
		{ 
			iArrDirections[2] += 1;
		}
		if (oArrRoom[iCounter].sDirections.find('W') != -1)
		{ 
			iArrDirections[3] += 1;
		}

	}
}

/**
@funcName printResult
@desc es una funcion de salida que muestra primero al usuario el promedio de la cantidad de puertas que hay en un archivo y luego despliega cuantas puertas hay apuntando a cada punto cardinal
@param fAvarage para desplegar el promedio de puertas, iArrDirections despliega la cantidad de veces que se repite cada punto cardinal con respecto a las puertas de cada cuarto
@return despliega al usuario el contenido de cada parametro

*/

void printResult( float fAverage, int iArrDirections[])
{ 
	cout << fAverage << endl;
	cout << 'N' << iArrDirections[0] << endl;
	cout << 'S' << iArrDirections[1] << endl;
	cout << 'E' << iArrDirections[2] << endl;
	cout << 'W' << iArrDirections[3] << endl;
}

/**
@funcName main
@desc la funcion agarra un archivo, lo lee, y regresa el promedio de las puertas de cada cuarto y las direcciones de las puertas de cada cuarto

*/

int main ()
{ 	
	//Variables
	oRoom oArrRoom[10];
	float fAverage = 0;
	int iArrDirections[4];

	//Input
	readFile( oArrRoom);

	//Processing
	calculateAverage( fAverage, oArrRoom);
	countDirections( oArrRoom, iArrDirections);

	//Output
	printResult( fAverage, iArrDirections);

	return 0;
}