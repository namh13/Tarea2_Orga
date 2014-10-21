// queue::push/pop
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, list<Cumpleanios*>cumpleanios)
{
    ofstream out(nombre_archivo.c_str()); //Abrimos el archivo
    for(list<Cumpleanios*>::iterator i=cumpleanios.begin();
            i!=cumpleanios.end();
            i++) //creamos un ciclo para recorrer la lista
    {
        Cumpleanios *cumple = new Cumpleanios((*i)->cumpleaniero,(*i)->dia,(*i)->mes); //guardamos el cumpleanero que sacamos de la lista con el iteerador
        out<<cumple->cumpleaniero; //escribimos en el archivo el nombre del cumpleanero
        out<<" "; //dejamos un espacio
        out<<cumple->dia;//escribimos en el archivo el dia del cumpleanero
        out<<" "; //dejamos un espacio
        out<<cumple->mes;//escribimos en el archivo el mes del cumpleanero
        out<<"\n";
    }
    out.close();//cerramos el archivo
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
list<Cumpleanios*> leer(string nombre_archivo)
{
    list<Cumpleanios*>cumpleanios;
    cumpleanios.clear(); //limpiamos la lista
    ifstream in(nombre_archivo.c_str()); //abrimos el archivo
    string cumpleanero; //variable para guardar el nombre del cumpleanero
    int dia; //variable para guardar el dia del cumpleanero
    int mes; //variable para guardar el mes del cumpleanero


    while(in>>cumpleanero) //ciclo donde comparamos si hay otro cumpleanero o no
    {
        in>>dia; //sacamos el dia del cumpleanero del archivo
        in>>mes; //sacamos el mes del cumpleanero del archivo
        cumpleanios.push_back(new Cumpleanios(cumpleanero,dia,mes)); //guardamos en la lista el cumpleanero que sacamos del archivo
    }
    in.close();//cerramos el archivo
    return cumpleanios; //retornamos la lista
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
