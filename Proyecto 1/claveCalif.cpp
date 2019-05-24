//
//  main.cpp
//  funcionClaveCalif
//
//  Created by Yolanda Martínez on 2/20/14.
//  Copyright (c) 2014 Yolanda Martínez. All rights reserved.
//

/**
@progName Claves de calificaciones
@date 18 de Diciembre de 2014
@author Yolanda Martinez
@desc programa que usa una funcion de tipo char para obtener claves de calificaciones
*/

#include <iostream>
using namespace std;

/**
@funcName obtenerClave
 
@param calif - valor numerico.
@return clave que corresopnde al valor numerico
@desc funcion que regresa una clave dependiendo de la calificacion
@author El grupo de alumnos de la clase de fundamentos
@date A la hora de clase, en el semestre enero mayo 2014
*/
char obtenerClave(int calif)
{
    if (calif >= 70)
        return 'A';
    else
        return 'R';
}

/**
@funcName main
*/
int main()
{
    int cal;
    char clave;
    cout << "Teclea la calificacion " << endl;
    cin >> cal;
    
    // Se llama a la función
    clave = obtenerClave(cal);
    
    cout << "La clave es " << clave << endl;
    
    return 0;
}