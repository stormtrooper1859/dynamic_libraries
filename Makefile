.PHONY: all clean

all: bin/main

bin:
	mkdir bin

bin/main: bin bin/libstatic.a bin/libdynamic_link.so bin/libdynamic_runtime.so
	gcc -c src/main.c -o bin/main.o
	gcc bin/main.o -Lbin -lstatic -ldynamic_link -ldl -Wl,-rpath=./bin/ -o bin/main
	rm bin/*.o

bin/libstatic.a:
	gcc -c src/static_lib.c -o bin/static_lib.o
	ar rcs bin/libstatic.a bin/static_lib.o

bin/libdynamic_link.so:
	gcc -c src/dynamic_lib_link.c -o bin/dynamic_lib_link.o
	gcc -shared bin/dynamic_lib_link.o -o bin/libdynamic_link.so

bin/libdynamic_runtime.so:
	gcc -c -fPIC src/dynamic_lib_runtime.c -o bin/dynamic_lib_runtime.o
	gcc -shared bin/dynamic_lib_runtime.o -o bin/libdynamic_runtime.so

clean:
	rm -rf bin

run:
	./bin/main
