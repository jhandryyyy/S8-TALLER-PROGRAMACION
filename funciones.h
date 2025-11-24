#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PROD 5
#define MAX_NAME 30

// Prototipos de funciones

void ingresarProducto(char nombres[][MAX_NAME], int tiempo[], int recursos[],
                      int demanda[], int *numProd);

int buscarProducto(char nombres[][MAX_NAME], int numProd, char nombre[]);

void editarProducto(char nombres[][MAX_NAME], int tiempo[], int recursos[],
                    int demanda[], int numProd);

void eliminarProducto(char nombres[][MAX_NAME], int tiempo[], int recursos[],
                      int demanda[], int *numProd);

int calcularTiempo(int tiempo[], int demanda[], int numProd);

int calcularRecursos(int recursos[], int demanda[], int numProd);

void mostrarProductos(char nombres[][MAX_NAME], int tiempo[], int recursos[],
                      int demanda[], int numProd);

int leerEnteroPositivo(const char *mensaje);

void leerCadena(char destino[], int tam, const char *mensaje);

#endif