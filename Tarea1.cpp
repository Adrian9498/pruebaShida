// Tarea1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina aqui.
//

#include<iostream>
#include<string.h>
#include<stdio.h>
#define MAX 10

using namespace std; 

//Estructura para generar registros
struct TRegistro {
    int id;
    char descripcion[MAX];
};


//Método main 
int main(){
    //Declaracion del arreglo de registros
    TRegistro arrayRecord[] = {1,"Juan",2,"Paco",3,"Pedro", 4,"Ana",5,"Rocio"};
    int tam = *(&arrayRecord + 1) - arrayRecord;
    FILE* archivo;

    //Sección de escritura en el archivo
    if ((archivo = fopen("DATOS.DAT", "wb")) == NULL) {
        cout << "Imposible escribir en el archivo.\n";
    } else {
        cout << "\nSe va a escribir en el archivo...\n";
        //Escritura en una sola instrucción de todos los registros
        fwrite(arrayRecord, sizeof(TRegistro), tam, archivo);
        cout << "\nGuardado en medio externo correctamente!\n";
        fclose(archivo);
        cout << "\nSe cerro correctamente el archivo\n";
    }

    //Creacion de la variable simple de tipo TRegistro
    TRegistro elem; 
    FILE* archivoLectura; 

    cout << "\nSe va a leer datos desde el archivo...\n";
    //Lectura del archivo e impresión de datos
    if ((archivoLectura = fopen("DATOS.DAT", "rb")) == NULL) {
        cout << "Imposible escribir en el archivo.\n";
    }
    else {
        cout << endl << "Datos leidos del archivo: " << endl;

        //Lectura de datos uno a uno
        fread(&elem, sizeof(TRegistro), 1, archivoLectura);

        while (!feof(archivoLectura)) {
            //Impresión de los datos
            cout << elem.id << " ";
            cout << elem.descripcion << " ";
            cout << "\n";

            //Lectura del siguiente elemento
            fread(&elem, sizeof(TRegistro), 1, archivoLectura);
        }

        fclose(archivoLectura);
    }

    cout << "\nLectura finalizada";
}
