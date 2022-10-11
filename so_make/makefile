build/exec: obj/somelib.o obj/main.o
	gcc obj/somelib.o obj/main.o -o build/exec

obj/somelib.o: somelib.c somelib.h
	gcc -c somelib.c -o obj/somelib.o

obj/main.o: main.c somelib.h
	gcc -c main.c -o obj/main.o

clean:
	rm -f build/*
	rm -f obj/*