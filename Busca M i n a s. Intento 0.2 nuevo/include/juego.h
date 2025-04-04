#ifndef JUEGO_H //by to meilyn garcia 9959-23-17838, marzo2025
#define JUEGO_H

#include "Tablero.h"
#include "Configuracion.h"
#include <chrono>

// Definición de la clase Juego
// Responsable de gestionar la dinámica del juego, interactuando con el tablero
// y utilizando la configuración definida. Facilita la ejecución del juego y controla el progreso de la partida.
class Juego {
private:
    Tablero tablero;                          // Representa el tablero donde se desarrolla el juego
    Configuracion& config;                    // Referencia al objeto que guarda la configuración del juego
    std::chrono::steady_clock::time_point inicio; // Registro de la hora de inicio de la partida

public:
    // Constructor de la clase Juego
    // Establece los parámetros iniciales del juego usando los valores de configuración proporcionados.
    // Parámetro:
    // - cfg: referencia a un objeto de tipo Configuracion que contiene los valores necesarios para el juego.
    Juego(Configuracion& cfg);

    // Función para comenzar el juego
    // Coloca las minas en el tablero y da inicio a la partida.
    void iniciar();

    // Función para ejecutar la lógica principal del juego
    // Permite al jugador descubrir celdas y controla la lógica que determina si gana o pierde.
    void jugar();
};

#endif // JUEGO_H

