#include <stdio.h>
#include <string.h>
#include "funciones.h"


// Función para leer un entero válido

int leerEnteroPositivo(const char *mensaje) {
    int v;
    int r;

    printf("%s", mensaje);
    r = scanf("%d", &v);

    while (r != 1 || v < 0) {
        while (getchar() != '\n');
        printf("Entrada invalida. %s", mensaje);
        r = scanf("%d", &v);
    }

    while (getchar() != '\n');
    return v;
}


// Leer cadena sin espacios

void leerCadena(char destino[], int tam, const char *mensaje) {
    printf("%s", mensaje);
    scanf("%29s", destino);
    while (getchar() != '\n');
}


// AGREGAR PRODUCTO

void ingresarProducto(char nombres[][MAX_NAME], int tiempo[], int recursos[],
    int demanda[], int *numProd) {

    if (*numProd >= MAX_PROD) {
        printf("No se pueden agregar mas productos.\n");
        return;
    }

    leerCadena(nombres[*numProd], MAX_NAME, "Nombre: ");
    tiempo[*numProd] = leerEnteroPositivo("Tiempo por unidad: ");
    recursos[*numProd] = leerEnteroPositivo("Recursos por unidad: ");
    demanda[*numProd] = leerEnteroPositivo("Demanda: ");

    (*numProd)++;
    printf("Producto agregado.\n");
}


// BUSCAR PRODUCTO POR NOMBRE

int buscarProducto(char nombres[][MAX_NAME], int numProd, char nombre[]) {
    for (int i = 0; i < numProd; i++) {
        if (strcmp(nombres[i], nombre) == 0)
            return i;
    }
    return -1;
}


// EDITAR PRODUCTO

void editarProducto(char nombres[][MAX_NAME], int tiempo[], int recursos[],
    int demanda[], int numProd) {

    char buscar[MAX_NAME];
    leerCadena(buscar, MAX_NAME, "Nombre del producto a editar: ");

    int pos = buscarProducto(nombres, numProd, buscar);
    if (pos == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    leerCadena(nombres[pos], MAX_NAME, "Nuevo nombre: ");
    tiempo[pos] = leerEnteroPositivo("Nuevo tiempo por unidad: ");
    recursos[pos] = leerEnteroPositivo("Nuevos recursos por unidad: ");
    demanda[pos] = leerEnteroPositivo("Nueva demanda: ");

    printf("Producto editado.\n");
}


// ELIMINAR PRODUCTO 

void eliminarProducto(char nombres[][MAX_NAME], int tiempo[], int recursos[],
    int demanda[], int *numProd) {

    char buscar[MAX_NAME];
    leerCadena(buscar, MAX_NAME, "Nombre del producto a eliminar: ");

    int pos = buscarProducto(nombres, *numProd, buscar);
    if (pos == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    for (int i = pos; i < *numProd - 1; i++) {
        strcpy(nombres[i], nombres[i+1]);
        tiempo[i] = tiempo[i+1];
        recursos[i] = recursos[i+1];
        demanda[i] = demanda[i+1];
    }

    (*numProd)--;
    printf("Producto eliminado.\n");
}

// CALCULAR TIEMPO TOTAL

int calcularTiempo(int tiempo[], int demanda[], int numProd) {
    int total = 0;
    for (int i = 0; i < numProd; i++)
        total += tiempo[i] * demanda[i];
    return total;
}

// CALCULAR RECURSOS TOTALES

int calcularRecursos(int recursos[], int demanda[], int numProd) {
    int total = 0;
    for (int i = 0; i < numProd; i++)
        total += recursos[i] * demanda[i];
    return total;
}


// MOSTRAR PRODUCTOS

void mostrarProductos(char nombres[][MAX_NAME], int tiempo[], int recursos[],
    int demanda[], int numProd) {

    if (numProd == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    for (int i = 0; i < numProd; i++) {
        printf("[%d] %s | tiempo:%d | recursos:%d | demanda:%d\n", i+1, nombres[i], tiempo[i], recursos[i], demanda[i]);
    }
}