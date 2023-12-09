#ifndef CAPITULO_H
#define CAPITULO_H
#include "Video.h"
#include <string>
#include <iostream>
using namespace std;

class Capitulo: public Video{
private:
string serie;
int episodio;

public:
Capitulo(string&, string&, int, string&, string&, int);
~Capitulo();
string getSerie();
int getEpisodio();

friend std::ostream& operator<<(std::ostream& os, Capitulo& vid);
};





#endif