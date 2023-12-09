#include "Pelicula.h"
#include <string>
#include "Video.h"

using namespace std;


Pelicula::Pelicula(string& _id, string& _nombre, int _duracion, string& _genero): Video(id,nombre,duracion,genero){
    this->id = _id;
    this->nombre = _nombre;
    this->duracion = _duracion;
    this->genero = _genero;
}
Pelicula::~Pelicula(){  
}