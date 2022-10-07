build/exec: obj/main.o
	gcc obj/main.o -o build/exec

obj/main.o: main.c
	gcc -c main.c -o obj/main.o

clean:
	rm -f build/*
	rm -f obj/*