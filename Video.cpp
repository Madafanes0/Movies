#include "Video.h"
#include <iostream>
#include <string>
using namespace std;

Video::Video(string& id, string& nombre, int duracion, string& genero){}

Video::~Video() {}

string Video::getId() {
    return id;
}

string Video::getNombre() {
    return nombre;
}

int Video::getDuracion() {
    return duracion;
}

string Video::getGenero() {
    return genero;
}

void Video::agregarCalificacion(int calificacion) {
    Calificaciones.push_back(calificacion);
}

float Video::caliProm() {
    if (Calificaciones.empty()) {
        return -1;
    }

    int sum = 0;
    for (int calificacion : Calificaciones) {
        sum += calificacion;
    }

    return static_cast<float>(sum) / Calificaciones.size();
}


ostream& operator<<(ostream& os, Video& vid) {
    os << vid.getId() << "," << vid.getNombre() << "," << vid.getDuracion() << "," << vid.getGenero() << ",";

    float promedio = vid.caliProm();
    if (promedio == -1) {
        os << "SC";
    } else {
        os << promedio;
    }

    os << endl;
    return os;
}

string Video::imprimirPorCal(){
    string cal=to_string(caliProm());
return this->id+", " + this->nombre + ", " + cal+"\n";

}

string Video::imprimirPorGen(){
    float calificacion = caliProm();
    string c;

    if (calificacion == -1.0f) {
        c = "SC";
    } else {
        c = to_string(calificacion);
    }

return this->id+", " + this->nombre + ", " + this->genero +", " + c+"\n";

}