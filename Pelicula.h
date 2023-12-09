#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"
#include <string>
#include <iostream>
using namespace std;
class Pelicula: public Video{

public:
Pelicula(string&, string&, int, string&);
~Pelicula();

};




#endif