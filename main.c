#include <stdio.h>
#include "funciones.h"

int main() {

    char nombres[MAX_PROD][MAX_NAME];
    int tiempo_unitario[MAX_PROD];
    int recursos_unitarios[MAX_PROD];
    int demanda[MAX_PROD];

    int numProductos = 0;
    int opcion;

    do {
    printf("\n===== MENU =====\n");
    printf("1. Ingresar producto\n");
    printf("2. Editar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Mostrar productos\n");
    printf("5. Calcular tiempo total\n");
    printf("6. Calcular recursos totales\n");
    printf("7. Vender producto\n");
    printf("0. Salir\n");

    opcion = leerEnteroPositivo("Seleccione opcion: ");

    switch (opcion) {

        case 1:
            ingresarProducto(nombres, tiempo_unitario, recursos_unitarios, demanda, &numProductos);
            break;

        case 2:
            editarProducto(nombres, tiempo_unitario, recursos_unitarios, demanda, numProductos);
            break;

        case 3:
            eliminarProducto(nombres, tiempo_unitario, recursos_unitarios, demanda, &numProductos);
            break;

        case 4:
            mostrarProductos(nombres, tiempo_unitario, recursos_unitarios, demanda, numProductos);
            break;

        case 5:
            printf("Tiempo total: %d\n", 
                   calcularTiempo(tiempo_unitario, demanda, numProductos));
            break;

        case 6:
            printf("Recursos totales: %d\n", 
                   calcularRecursos(recursos_unitarios, demanda, numProductos));
            break;

        case 7:
            venderProducto(nombres, tiempo_unitario, recursos_unitarios, demanda, numProductos);
            break;

        case 0:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opcion invalida.\n");
    }

} while (opcion != 0);

    return 0;
}
}
