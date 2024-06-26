best_name: best_name.c levenshtein.c
	gcc best_name.c levenshtein.c -o best_name

run: best_name
	./best_name | sort -t ' ' -n -k 2

clean:
	rm best_name
