#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Persona{
	private:	// Atributos
		int edad;
		string nombre;
	
	public:		//	Metodos
		Persona(int, string);	//	Constructor
		void leer();
		void correr();
};

//	Constructor: nos sirve para incializar los atributos

Persona::Persona(int _edad, string _nombre)
{
	edad = _edad;
	nombre = _nombre;
}

int main()
{
	Persona nombramiento = Persona(20, "Nachito");
	nombramiento.leer();
	
	getch();
	return EXIT;
}

void Persona::leer()
{
	printf("Soy %s y estoy leyendo un libro.", &nombre);
}

void Persona::correr()
{
	printf("Soy %s y estoy corriendo.", &s);
}
