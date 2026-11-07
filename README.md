# PG205-2024-1302 - Promoción de una tienda de libros

- Matrícula: 2024-1302
- Correo: 20241302@itla.edu.do

## Modelo y decisiones
- `muestras[20][8]` guarda los precios; `Registro` (typedef struct) contiene `id`, `nombre[16]`, `Config cfg {tipo, p}`, `score`, `estado`.
- `calcular` trabaja sobre una copia de los precios (ordenada de mayor a menor), suma el último de cada grupo completo de k = tipo+3, aplica min(p, suma) y devuelve `estado` por apuntador. Cada unidad se calcula con variables locales nuevas.
- `total_rec` es recursiva (caso base n=0). Orden: inserción (precios, ids) y selección (score desc, id asc). `buscar` es búsqueda binaria sobre una copia ordenada por id. No se usa qsort, bsearch ni memoria dinámica.
- Toda la entrada se valida antes de imprimir; ante cualquier error se imprime solo `ERROR`.
- Media (no se imprime en stdout): `media = total / (double)n`, mostrada con `printf("%.2f", media)`.

| Caso | total | n | media |
|---|---|---|---|
| g1 | 50 | 2 | 25.00 |
| g2 | 0 | 1 | 0.00 |
| g3 | 60 | 3 | 20.00 |
| g4 | 200 | 2 | 100.00 |
| g5 | 0 | 2 | 0.00 |
| p1 | 50 | 1 | 50.00 |
| p2 | 45 | 3 | 15.00 |

## Compilación y ejecución
```
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o reto
./reto < pruebas/g1.in            (Windows: reto.exe < pruebas\g1.in)
python3 evaluar.py publicas.json ./reto
```

## Resultados
Públicos g1-g6: 6/6 OK. Pruebas propias en `pruebas/` (`.in`, `.out` esperado, `.obt` obtenido):
p1 borde (m = k), p2 tres unidades con ambos tipos y orden por score, p3 q ausente y grupos incompletos,
p4 id repetido, p5 entrada incompleta, p6 tipo fuera de dominio (los tres últimos dan ERROR).
Los `.out` de las pruebas propias se calcularon a mano antes de ejecutar.

## Fuentes consultadas
Corona Nakamura y Ancona Valdez (2011), Diseño de algoritmos y su codificación en lenguaje C, McGraw-Hill; enunciado del reto.

## Historial de commits
| # | Hash | Avance |
|---|------|--------|
| 1 |      | estructura, interpretación y plan |
| 2 |      | desarrollo parcial verificable |
| 3 |      | pruebas, validación y revisión |
