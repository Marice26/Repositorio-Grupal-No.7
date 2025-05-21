/// Autor: Meilyn Juleisy Garc�a Lima

#include "bitacora.h"
#include <iomanip>        // Para formatear la salida con setw()
#include <cstring>        // Para funciones como strncpy()

// Constructor de la clase Bitacora que inicializa los datos del evento
Bitacora::Bitacora(string user, string acc) {
    strncpy(usuario, user.c_str(), sizeof(usuario));

    // Copia segura de la acci�n a la variable miembro
    strncpy(accion, acc.c_str(), sizeof(accion));

    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Guarda la fecha y hora en formato: DD/MM/AAAA HH:MM
    snprintf(fechaHora, sizeof(fechaHora), "%02d/%02d/%04d %02d:%02d",
             ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year,
             ltm->tm_hour, ltm->tm_min);
}

// M�todo que guarda el registro actual en el archivo binario "bitacora.dat"
void Bitacora::guardarEnArchivo() {
    ofstream archivo("bitacora.dat", ios::binary | ios::app);
    if (archivo.is_open()) {
        // Escribe el contenido del objeto actual en el archivo
        archivo.write(reinterpret_cast<char*>(this), sizeof(Bitacora));
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de bitacora.\n";
    }
}

// M�todo est�tico que lee y muestra todos los registros de la bit�cora
void Bitacora::mostrarBitacora() {
    ifstream archivo("bitacora.dat", ios::binary);
    if (!archivo) {
        cout << "No existe bit�cora.\n";
        return;
    }

    Bitacora b;

    // Encabezados de tabla para presentaci�n
    cout << left << setw(15) << "Usuario"
         << setw(40) << "Accion"
         << setw(20) << "Fecha y Hora" << endl;
    cout << "---------------------------------------------------------------------------\n";

    // Lee cada registro del archivo y lo muestra
    while (archivo.read(reinterpret_cast<char*>(&b), sizeof(Bitacora))) {
        cout << left << setw(15) << b.usuario
             << setw(40) << b.accion
             << setw(20) << b.fechaHora << endl;
    }

    archivo.close();
}

// Funci�n externa que simplifica el registro de eventos en la bit�cora
// Crea un objeto Bitacora con los datos proporcionados y lo guarda autom�ticamente
void registrarEvento(const string& usuario, const string& accion) {
    Bitacora b(usuario, accion); // Crea el objeto con los datos del evento
    b.guardarEnArchivo();
}
