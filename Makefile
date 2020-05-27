C = gcc

all: bin/circles_app
	./bin/circles_app figures.txt
bin/circles_app: build/main.o build/props.o build/scan.o
	$(C) -Wall -Werror build/main.o build/props.o build/scan.o -o bin/circles_app -lm

build/props.o: src/props.c
	$(C) -Wall -Werror -c src/props.c -o build/props.o 

build/scan.o: src/scan.c
	$(C) -Wall -Werror -c src/scan.c -o build/scan.o 

build/main.o: src/main.c
	$(C) -Wall -Werror -c src/main.c -o build/main.o 
clean:
	rm -rf build/*.o bin/circles_app

.PHONY: all clean

