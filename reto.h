#ifndef RETO_H
#define RETO_H

#define MAX_UNIDADES 20
#define MAX_MUESTRAS 8
#define LONG_NOMBRE 16 /* 15 caracteres + '\0' */

typedef struct {
    int tipo; /* 0 o 1 */
    int p;    /* tope de score, 0..100 */
} Config;

typedef struct {
    int id;
    char nombre[LONG_NOMBRE];
    Config cfg;
    int score;
    int estado;
} Registro;

/* Ordena v[0..n-1] de mayor a menor (insercion). */
void ordenar(int *v, int n);
/* Score de una unidad; devuelve el estado por referencia. */
int calcular(const int *v, int m, int tipo, int p, const char *nombre, int *estado);
/* Suma recursiva de scores (caso base n=0). */
int total_rec(const Registro *r, int n);
/* Orden por score descendente y, en empate, id ascendente (seleccion). */
void ordenar_score(Registro *r, int n);
/* Orden por id ascendente (insercion). */
void ordenar_id(Registro *r, int n);
/* Busqueda binaria en arreglo ordenado por id; devuelve score o -1. */
int buscar(const Registro *r, int n, int q);

#endif
