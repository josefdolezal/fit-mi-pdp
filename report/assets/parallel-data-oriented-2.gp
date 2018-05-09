set terminal png
set xlabel "počet vláken"
set ylabel "čas (s)"
plot "parallel-data-oriented-2.data" using 1:2 with lines title "Průměrný čas (datově orientovaný par.)"