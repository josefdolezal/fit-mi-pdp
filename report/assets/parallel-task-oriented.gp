set terminal png
set xlabel "počet vláken"
set ylabel "čas (s)"
plot "parallel-task-oriented.data" using 1:2 with lines title "Průměrný čas (taskově orientovaný par.)"