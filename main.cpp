#include "Catalogo.h"
#include <iostream>



int main() {
    CatalogoVideos catalogo;
    catalogo.cargarVideos("videos.txt");

    int opcion;
    do {
         cout << "-----Servicio de Streaming----- "<<endl;
         cout << "1. Mostrar catalogo con calificaciones"<<endl;
         cout << "2. Calificar un video "<<endl;
         cout << "3. Mostrar peliculas o capitulos por calificacion minima"<<endl;
         cout << "4. Mostrar peliculas o capitulos por genero"<<endl;
         cout << "9. Salir"<<endl;
         cin >> opcion;

        switch (opcion) {
            case 1:
                catalogo.mostrarCatalogo();
                break;
            case 2:
                catalogo.calificarVideo();
                break;
            case 3:
                catalogo.mostrarPorCalificacion();
                break;
            case 4:
                catalogo.mostrarPorGenero();
            break;
            case 9:
                 cout << "Gracias por entrar a calificar un video"<<endl;
                break;
            default:
                 cout << "Opcion invalida. Intente otra vez."<<endl;
        }
    } while (opcion != 9);

    // Liberar la memoria
    for (Video* video : catalogo.cargarVideos("videos.txt")) {
        delete video;
    }

    return 0;
}