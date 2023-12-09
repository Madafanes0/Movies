#ifndef CATALOGO_H
#define CATALOGO_H
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Video.h"
#include "Pelicula.h"
#include "Capitulo.h"

class CatalogoVideos {
private:
     vector<Video*> videos;

public:
//https://es.stackoverflow.com/questions/338463/extraer-información-de-archivo-de-texto-en-c y ayuda de chatgpt, por los errores que salían, después de muchos errores ya lo hice yo :D.
  vector<Video*> cargarVideos(const string& archivo) {
    ifstream file(archivo);
    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            char tipo = linea[0];
            string resto = linea.substr(2);

            if (tipo == 'p') {
                istringstream ss(resto);
                string id, nombre, genero, duracionStr;
                getline(ss, id, ',');
                getline(ss, nombre, ',');
                getline(ss, duracionStr, ',');
                getline(ss, genero, ',');

                int duracion;
                if (!duracionStr.empty()) {
                    duracion = stoi(duracionStr);
                }
                videos.push_back(new Pelicula(id, nombre, duracion, genero));
            }
            else if (tipo == 'c') {
                istringstream ss(resto);
                string id, nombre, genero, serie, duracionStr, episodioStr;
                getline(ss, id, ',');
                getline(ss, nombre, ',');
                getline(ss, duracionStr, ',');
                getline(ss, genero, ',');
                getline(ss, serie, ',');
                getline(ss, episodioStr, ',');

                int duracion, episodio;
                if (!duracionStr.empty()) {
                    duracion = stoi(duracionStr);
                }
                if (!episodioStr.empty()) {
                    episodio = stoi(episodioStr);
                }

                videos.push_back(new Capitulo(id, nombre, duracion, genero, serie, episodio));
            }
        }
        file.close();
    }
    return videos;
}


    void mostrarCatalogo() const {
         ::cout << "Catalogo con calificaciones:\n";
        for (Video* video : videos) {
            if (Capitulo* capitulo = dynamic_cast<Capitulo*>(video)) {
                //creé otra sobrecarga de operador << para que me mostrara todos mis atributos de Capitulo y se puedan aplicar metodos que creé en mi clase Capitulo
            cout <<*capitulo;
        } else {
            cout << *video;
        }
        }
    }

    void calificarVideo() {
        string id;
         cout << "Ingrese el ID del video a calificar: ";
         cin >> id;

        // Buscar el video por ID
        Video* video = nullptr;
        for (Video* v : videos) {
            if (v->getId() == id) {
                video = v;
                break;
            }
        }

        if (video) {
            int calificacion;
             cout << "Ingrese la calificacion (entre 1 y 5 estrellas): ";
             cin >> calificacion;

            // Validar la calificacion
            if (calificacion < 1 || calificacion > 5) {
                 cout << "Calificacion invalida. Debe estar entre 1 y 5."<<endl;
                return;
            }

            video->agregarCalificacion(calificacion);
             cout << "Video calificado con exito."<<endl;
        }
        else {
             cout << "No se encontro ningun video con ese ID."<<endl;
        }
    }

    void mostrarPorCalificacion() const {
        int opcion;
         cout << "Seleccione una opcion:"<<endl;
         cout << "1. Mostrar peliculas"<<endl;
         cout << "2. Mostrar capitulos"<<endl;
         cout << "3. Mostrar ambos"<<endl;
         cin >> opcion;

        if (opcion < 1 || opcion > 3) {
             cout << "Opcion invalida."<<endl;
            return;
        }

        float calificacionMinima;
         cout << "Ingrese la calificacion minima: ";
         cin >> calificacionMinima;

         cout << "Videos con calificacion mayor o igual a " << calificacionMinima <<endl;
        for (Video* video : videos) {
            if (video->caliProm() >= calificacionMinima) {
                if ((opcion == 1 && dynamic_cast<Pelicula*>(video) != nullptr) ||
                    (opcion == 2 && dynamic_cast<Capitulo*>(video) != nullptr) ||
                    opcion == 3) {
                    cout<<video->imprimirPorCal();
                }
            }
        }
    }
void mostrarPorGenero() const {
    int opcion;
    cout << "Seleccione una opcion:"<<endl;
    cout << "1. Mostrar peliculas"<<endl;
    cout << "2. Mostrar capitulos"<<endl;
    cout << "3. Mostrar ambos"<<endl;
    cin >> opcion;

    if (opcion < 1 || opcion > 3) {
        cout << "Opcion invalida."<<endl;
        return;
    }

    string genero;
    cout << "Ingrese el genero: ";
    cin.ignore(); 
    getline(cin, genero);

    cout << "Videos del genero " << genero << ":" << endl;
    for (Video* video : videos) {
        if (video->getGenero() == genero) {
            if ((opcion == 1 && dynamic_cast<Pelicula*>(video) != nullptr) ||
                (opcion == 2 && dynamic_cast<Capitulo*>(video) != nullptr) ||
                opcion == 3) {
                cout << video->imprimirPorGen();
            }
        }
    }
}


};

#endif