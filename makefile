program:
	gcc -c -o ./lib/Random.o ./src/Random.c -I ./include
	gcc -c -o ./lib/RastgeleKarakter.o ./src/RastgeleKarakter.c -I ./include
	gcc -c -o ./lib/Program.o ./src/Program.c -I ./include
	gcc ./lib/Random.o ./lib/RastgeleKarakter.o ./lib/Program.o -o ./bin/Program.exe
	./bin/Program.exe