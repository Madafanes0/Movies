#include "Capitulo.h"
#include <string>
#include "Video.h"

using namespace std;

Capitulo::Capitulo(string& _id, string& _nombre, int _duracion, string& _genero,string& _serieCap, int _episodio): Video(id,nombre,duracion,genero){
    this->id = _id;
    this->nombre = _nombre;
    this->duracion = _duracion;
    this->genero = _genero;
    this->serie=_serieCap;
    this->episodio=_episodio;
}

Capitulo::~Capitulo()
{}

string Capitulo::getSerie(){
return serie;
}
int Capitulo::getEpisodio(){
return episodio;
}


ostream& operator<<(std::ostream& os, Capitulo& vid) {
    os << vid.getId() << "," << vid.getNombre() << "," << vid.getDuracion() << "," << vid.getGenero()<< ","<<vid.getSerie()<< ","<<vid.getEpisodio()<< ",";
    
    float promedio = vid.caliProm();
    if (promedio == -1) {
        os << "SC";
    } else {
        os << promedio;
    }

    os << endl;
    return os;
}

