# fit-mi-pdp
Repozitář k předmětu MI-PDP 2017/18

### OpenMP v Xcode

Pro správné fungování je potřeba doinstalovat `clang` s knihovnou OpenMP. Podrobný návod [zde](http://antonmenshov.com/2017/09/09/clang-openmp-setup-in-xcode/). Projekt už správné nastavení pro linkování obsahuje, pro správné fungování by mělo stačit spustit:

```bash
$ brew install llvm
```

### Spouštění na Star

```
grun <mb> <count> <queue> job.sh
```

| Parametr | Hodnota                              |
|----------|--------------------------------------|
| `mb`     | Typ základní desky - využít 20c      |
| `count`  | Počet využitých desek (1, 2, 3)      |
| `queue`  | Priorita fronty (vysoká - méně času) |

> Program by měl mít konfigurovatelný počet vláken parametrem z CLI
