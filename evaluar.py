
/*********************/
/*           Programación para mecatrónicos               */
/*  Nombre:    Bienderl Gonzalez                          */
/*  Matricula: 2024-1302                                  */
/*  Seccion:   Miercoles                                  */
/*  Practica:  Seguno parcial                             */
/*  Fecha:     7/11/2026                                   */                       
/* Link Practica: https://github.com/gonzalezbienderl01-arch/PG205-2024-1302.git  */
/*********************/

import json, subprocess, sys
from pathlib import Path
casos = json.loads(Path(sys.argv[1]).read_text(encoding="utf-8"))
exe = str(Path(sys.argv[2]).resolve())
ok = 0
for c in casos:
    try:
        r = subprocess.run([exe], input=c["entrada"], text=True,
                           capture_output=True, timeout=2)
        pasa = r.returncode == 0 and r.stdout.split() == c["salida"].split()
    except (subprocess.TimeoutExpired, OSError):
        pasa = False
    ok += pasa
    print("Grupo", c["grupo"], "OK" if pasa else "FALLO")
print("Casos correctos:", ok, "/", len(casos))
sys.exit(0 if ok == len(casos) else 1)
