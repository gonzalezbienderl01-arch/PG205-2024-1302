/*********************/
/*           Programación para mecatrónicos               */
/*  Nombre:    Bienderl Gonzalez                          */
/*  Matricula: 2024-1302                                  */
/*  Seccion:   Miercoles                                  */
/*  Practica:  Seguno parcial                             */
/*  Fecha:     7/11/2026                                   */                       
/* Link Practica: https://github.com/gonzalezbienderl01-arch/PG205-2024-1302.git  */
/*********************/

# Plan - PG205-2024-1302

## Interpretacion
Cada registro es independiente. Para cada unidad: copiar sus m precios, ordenar de mayor a menor,
recorrer grupos completos de k = tipo + 3 y sumar el ultimo de cada grupo (descuento).
score = min(p, suma); estado = (m % k != 0).

## Pseudocodigo
```
leer n, m, q; validar rangos
para cada registro i: leer id, nombre, tipo, p; validar; id unico; leer m muestras en [0,100]
si algo falla -> imprimir ERROR y terminar (antes de imprimir resultados)
para cada i: score[i] = calcular(muestras[i], m, tipo, p, nombre, &estado[i])
imprimir una linea por registro (orden original)
TOTAL = total_rec(regs, n)        // n == 0 -> 0; si no, regs[n-1].score + total_rec(regs, n-1)
copia1 = regs ordenada por (score desc, id asc)  -> ORDER
copia2 = regs ordenada por id asc -> buscar() busqueda binaria -> FIND q (score o -1)

calcular(v, m, tipo, p, nombre, *estado):
    c = copia de v; ordenar(c, m) descendente
    k = tipo + 3; suma = 0
    para i = k-1; i < m; i += k: suma += c[i]
    *estado = (m % k != 0); devolver min(p, suma)
```
