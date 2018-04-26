# fit-mi-pdp
Repozitář k předmětu MI-PDP 2017/18

### OpenMP v Xcode

Pro správné fungování je potřeba doinstalovat `clang` s knihovnou OpenMP. Podrobný návod [zde](http://antonmenshov.com/2017/09/09/clang-openmp-setup-in-xcode/). Projekt už správné nastavení pro linkování obsahuje, pro správné fungování by mělo stačit spustit:

```bash
$ brew install llvm
```

### OpenMPI v Xcode

Pro nalinkování OpenMPI je potřeba pomocí `brew` knihovnu doinstalovat. V nastavení projektu je potřeba přidat hlavičky a spouštět binárku pomocí `mpirun`, návod [zde](https://stackoverflow.com/a/31525928/9016753).

```bash
$ brew install open-mpi
```

### Spouštění na Star

```
grun <mb> <count> <queue> job.sh
```

| Parametr | Hodnota                                          |
|----------|--------------------------------------------------|
| `mb`     | Typ základní desky - využít 20c                  |
| `count`  | Počet využitých desek (1, 2, 3)                  |
| `queue`  | Priorita fronty (vysoká - méně času), `pdp_fast` |

> Program by měl mít konfigurovatelný počet vláken parametrem z CLI

3 problémy, zhruba 5 až 15 minut při sekvenčním řešení.
Různý počet procesů MPI - 1 až 3.
Různý počet vláken OMP - 1 až 20.

Zdroje: 6xMB (každá 2 CPU, každé CPU má 10 jader). Spuštění je omezeno na 60 jader.
