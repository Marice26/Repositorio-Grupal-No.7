#ifndef CONFIGURACION_H//by to meilyn garcia 9959-23-17838, marzo 2025
#define CONFIGURACION_H

// Definición de la clase Configuracion
// Esta clase se utiliza para gestionar y almacenar la configuración del juego,
// que incluye las características del tablero y el estado del jugador.
class Configuracion {
public:
    // Variables públicas que definen los parámetros del juego
    int filas;      // Cantidad de filas en el tablero de juego
    int columnas;   // Cantidad de columnas en el tablero de juego
    int minas;      // Número total de minas distribuidas en el tablero
    int vidas;      // Número de vidas disponibles para el jugador
    int modo;       // Representa el modo de juego seleccionado
    int derrotas;   // Número de veces que el jugador ha perdido
    int victorias;  // Número de veces que el jugador ha ganado

    // Constructor de la clase Configuracion
    // Asigna valores iniciales a los atributos de la configuración del juego.
    // Parámetros:
    // - f: especifica el número de filas en el tablero
    // - c: especifica el número de columnas en el tablero
    // - m: especifica el número de minas presentes en el tablero
    // - v: especifica el número de vidas del jugador
    // - modo: define el modo de juego activo
    Configuracion(int f, int c, int m, int v, int modo);

    // Función para incrementar el contador de victorias en 1
    void aumentarVictoria();

    // Función para incrementar el contador de derrotas en 1
    void aumentarDerrota();
};

#endif // CONFIGURACION_H
