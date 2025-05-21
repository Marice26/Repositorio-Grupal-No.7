#ifndef BITACORA_H
#define BITACORA_H

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Bitacora {
private:
    char usuario[50];
    char accion[100];
    char fechaHora[25];

public:
    Bitacora() = default;
    Bitacora(string user, string acc);

    void guardarEnArchivo();
    static void mostrarBitacora();
};

void registrarEvento(const string& usuario, const string& accion);

#endif
