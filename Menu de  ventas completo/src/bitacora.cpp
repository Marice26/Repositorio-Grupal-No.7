#include "bitacora.h"//MEILYN JULEISY GARCIA LIMA
#include <iomanip>
#include <cstring>

Bitacora::Bitacora(string user, string acc) {
    strncpy(usuario, user.c_str(), sizeof(usuario));
    strncpy(accion, acc.c_str(), sizeof(accion));

    time_t now = time(0);
    tm *ltm = localtime(&now);
    snprintf(fechaHora, sizeof(fechaHora), "%02d/%02d/%04d %02d:%02d",
             ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year,
             ltm->tm_hour, ltm->tm_min);
}

void Bitacora::guardarEnArchivo() {
    ofstream archivo("bitacora.dat", ios::binary | ios::app);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<char*>(this), sizeof(Bitacora));
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de bitacora.\n";
    }
}

void Bitacora::mostrarBitacora() {
    ifstream archivo("bitacora.dat", ios::binary);
    if (!archivo) {
        cout << "No existe bitácora.\n";
        return;
    }

    Bitacora b;
    cout << left << setw(15) << "Usuario"
         << setw(40) << "Accion"
         << setw(20) << "Fecha y Hora" << endl;
    cout << "---------------------------------------------------------------------------\n";

    while (archivo.read(reinterpret_cast<char*>(&b), sizeof(Bitacora))) {
        cout << left << setw(15) << b.usuario
             << setw(40) << b.accion
             << setw(20) << b.fechaHora << endl;
    }

    archivo.close();
}

void registrarEvento(const string& usuario, const string& accion) {
    Bitacora b(usuario, accion);
    b.guardarEnArchivo();
}
