#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "reto.h"

void ordenar(int *v, int n)
{
    int i, j, clave;
    for (i = 1; i < n; i++) {
        clave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] < clave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = clave;
    }
}

int calcular(const int *v, int m, int tipo, int p, const char *nombre, int *estado)
{
    int copia[MAX_MUESTRAS];
    int k = tipo + 3;
    int suma = 0, i;
    (void)nombre; /* la regla de este reto no usa el nombre */
    for (i = 0; i < m; i++)
        copia[i] = v[i];
    ordenar(copia, m);
    for (i = k - 1; i < m; i += k) /* ultimo de cada grupo completo */
        suma += copia[i];
    *estado = (m % k != 0) ? 1 : 0;
    return suma < p ? suma : p;
}

int total_rec(const Registro *r, int n)
{
    if (n == 0)
        return 0;
    return r[n - 1].score + total_rec(r, n - 1);
}

void ordenar_score(Registro *r, int n)
{
    int i, j, mejor;
    Registro tmp;
    for (i = 0; i < n - 1; i++) {
        mejor = i;
        for (j = i + 1; j < n; j++)
            if (r[j].score > r[mejor].score ||
                (r[j].score == r[mejor].score && r[j].id < r[mejor].id))
                mejor = j;
        tmp = r[i];
        r[i] = r[mejor];
        r[mejor] = tmp;
    }
}

void ordenar_id(Registro *r, int n)
{
    int i, j;
    Registro clave;
    for (i = 1; i < n; i++) {
        clave = r[i];
        j = i - 1;
        while (j >= 0 && r[j].id > clave.id) {
            r[j + 1] = r[j];
            j--;
        }
        r[j + 1] = clave;
    }
}

int buscar(const Registro *r, int n, int q)
{
    int ini = 0, fin = n - 1, mid;
    while (ini <= fin) {
        mid = ini + (fin - ini) / 2;
        if (r[mid].id == q)
            return r[mid].score;
        if (r[mid].id < q)
            ini = mid + 1;
        else
            fin = mid - 1;
    }
    return -1;
}

static int nombre_valido(const char *s)
{
    size_t i, len = strlen(s);
    if (len < 1 || len > 15)
        return 0;
    for (i = 0; i < len; i++)
        if (!(isalnum((unsigned char)s[i]) || s[i] == '_'))
            return 0;
    return 1;
}

static int error(void)
{
    printf("ERROR\n");
    return 0;
}

int main(void)
{
    int n, m, q, i, j;
    int muestras[MAX_UNIDADES][MAX_MUESTRAS];
    Registro regs[MAX_UNIDADES], copia[MAX_UNIDADES];
    char buf[64];

    if (scanf("%d %d %d", &n, &m, &q) != 3)
        return error();
    if (n < 1 || n > MAX_UNIDADES || m < 1 || m > MAX_MUESTRAS || q < 1 || q > 9999)
        return error();

    for (i = 0; i < n; i++) {
        if (scanf("%d %63s %d %d", &regs[i].id, buf,
                  &regs[i].cfg.tipo, &regs[i].cfg.p) != 4)
            return error();
        if (regs[i].id < 1 || regs[i].id > 9999 || !nombre_valido(buf) ||
            (regs[i].cfg.tipo != 0 && regs[i].cfg.tipo != 1) ||
            regs[i].cfg.p < 0 || regs[i].cfg.p > 100)
            return error();
        for (j = 0; buf[j] != '\0'; j++)
            regs[i].nombre[j] = (char)toupper((unsigned char)buf[j]);
        regs[i].nombre[j] = '\0';
        for (j = 0; j < i; j++)
            if (regs[j].id == regs[i].id)
                return error();
        for (j = 0; j < m; j++) {
            if (scanf("%d", &muestras[i][j]) != 1)
                return error();
            if (muestras[i][j] < 0 || muestras[i][j] > 100)
                return error();
        }
    }

    for (i = 0; i < n; i++)
        regs[i].score = calcular(muestras[i], m, regs[i].cfg.tipo, regs[i].cfg.p,
                                 regs[i].nombre, &regs[i].estado);

    for (i = 0; i < n; i++)
        printf("%d %s %d %d\n", regs[i].id, regs[i].nombre, regs[i].score, regs[i].estado);
    printf("TOTAL %d\n", total_rec(regs, n));

    for (i = 0; i < n; i++)
        copia[i] = regs[i];
    ordenar_score(copia, n);
    printf("ORDER");
    for (i = 0; i < n; i++)
        printf(" %d", copia[i].id);
    printf("\n");

    for (i = 0; i < n; i++)
        copia[i] = regs[i];
    ordenar_id(copia, n);
    printf("FIND %d %d\n", q, buscar(copia, n, q));
    return 0;
}
