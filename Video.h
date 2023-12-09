#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>
#include <iostream>

class Video {
protected:
    std::string id;
    std::string nombre;
    int duracion;
    std::string genero;
    std::vector<int> Calificaciones;

public:
    Video(std::string&, std::string&, int , std::string& );
    virtual ~Video();
    std::string getId() ;
    std::string getNombre() ;
    int getDuracion() ;
    std::string getGenero() ;
    void agregarCalificacion(int);
    std::string imprimirPorCal();
    std::string imprimirPorGen();
    float caliProm() ;
    friend std::ostream& operator<<(std::ostream& os, Video& vid);
};

#endif