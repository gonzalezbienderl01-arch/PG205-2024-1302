# Pruebas

Cada caso tiene tres archivos: `.in` (entrada), `.out` (salida esperada) y `.obt` (salida obtenida al ejecutar `./reto < caso.in`).

| Caso | Tipo | Que verifica |
|---|---|---|
| g1 - g6 | publicos | los seis casos del enunciado |
| p1 | propio valido (borde) | m == k: un unico grupo completo, estado 0 |
| p2 | propio valido | tres unidades, ambos tipos, ORDER por score y FIND presente |
| p3 | propio valido | q ausente (FIND -1) y grupos incompletos con empate en ORDER |
| p4 | propio invalido | id repetido -> ERROR |
| p5 | propio invalido | entrada incompleta -> ERROR |
| p6 | propio invalido | tipo fuera de dominio -> ERROR |

Los `.out` de p1 a p6 se calcularon a mano antes de ejecutar el programa.
Comprobacion: `cmp pruebas/p2.out pruebas/p2.obt` (sin salida = iguales).
