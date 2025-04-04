#ifndef VENTA_H//COMENTADO POR MEILYN
#define VENTA_H

#include "Cliente.h"
#include "Producto.h"

// Definición de la clase Venta
// Esta clase representa una venta realizada, que incluye al cliente, el producto adquirido y la cantidad.
class Venta {
public:
    Cliente cliente;  // Objeto que representa al cliente que realizó la compra
    Producto producto; // Objeto que representa el producto comprado
    int cantidad;     // Cantidad del producto adquirido en la venta

    // Constructor de la clase Venta
    // Inicializa una nueva venta con los detalles del cliente, producto y cantidad.
    Venta(Cliente c, Producto p, int cant);
};

#endif // VENTA_H
