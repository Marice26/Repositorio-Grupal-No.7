#include "Venta.h"//COMENTADO POR MEILYN
// Constructor de la clase Venta
// Inicializa un objeto de tipo Venta con los datos del cliente, el producto y la cantidad especificada.
Venta::Venta(Cliente c, Producto p, int cant) : cliente(c), producto(p), cantidad(cant) {}
