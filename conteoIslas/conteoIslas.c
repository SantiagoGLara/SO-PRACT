#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define FILAS 8
#define COLUMNAS 8

int mapa[FILAS][COLUMNAS];
bool visitado[FILAS][COLUMNAS];

int desplazamientoX[4] = {-1, 1, 0, 0};
int desplazamientoY[4] = {0, 0, -1, 1};

void inicializarVisitado() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            visitado[i][j] = false;
        }
    }
}

int generarNumeroAleatorio() {
    return (rand() % 2);
}

void mostrarMapa() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", mapa[i][j]);
        }
        printf("\n");
    }
}

void llenarMapa() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            mapa[i][j] = generarNumeroAleatorio();
        }
    }
}

void busquedaProfunda(int x, int y) {
    visitado[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nuevoX = x + desplazamientoX[i];
        int nuevoY = y + desplazamientoY[i];
        if (nuevoX >= 0 && nuevoX < FILAS && nuevoY >= 0 && nuevoY < COLUMNAS && !visitado[nuevoX][nuevoY] && mapa[nuevoX][nuevoY] == 1) {
            busquedaProfunda(nuevoX, nuevoY);
        }
    }
}

int contarIslas() {
    int contador = 0;
    inicializarVisitado();
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (mapa[i][j] == 1 && !visitado[i][j]) {
                busquedaProfunda(i, j);
                contador++;
            }
        }
    }
    return contador;
}

int main() {
    srand(time(NULL));
    llenarMapa();
    mostrarMapa();
    printf("Total de Islas: %d", contarIslas());
    return 0;
}
