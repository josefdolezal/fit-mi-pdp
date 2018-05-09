build: latexmk -pdf

assets_:
	(cd assets; gnuplot parallel-data-oriented.gp > parallel-data-oriented.png)
	(cd assets; gnuplot parallel-task-oriented.gp > parallel-task-oriented.png)
	(cd assets; gnuplot parallel-data-oriented-2.gp > parallel-data-oriented-2.png)

watch:
	latexmk -pdf -pvc

clean:
	latexmk -c