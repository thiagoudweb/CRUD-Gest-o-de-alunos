all:
	gcc -o ./bin/main src/main.c src/arqimp.c src/arquivo.c -I*.h
	./bin/main