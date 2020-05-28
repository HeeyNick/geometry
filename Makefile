C = gcc

all: bin/ready_file bin/test_file
	./bin/ready_file
	./bin/test_file

bin/test_file: build/operation.o build/readfile.o build/main_test.o build/function_test.o
	$(C) -Wall -Werror build/main_test.o build/operation.o build/readfile.o build/function_test.o -o bin/test_file -lm

build/main_test.o: test/main.c
	$(C)  -Wall -Werror -I thirdparty -I src -c test/main.c -o build/main_test.o 

build/function_test.o: test/function_test.c
	$(C)  -Wall -Werror -I thirdparty -I src -c test/function_test.c -o build/function_test.o

bin/ready_file: build/main.o build/operation.o build/readfile.o
	$(C)  -Wall -Werror build/main.o build/operation.o build/readfile.o -o bin/ready_file -lm

build/operation.o: src/operation.c
	$(C)  -Wall -Werror -c src/operation.c -o build/operation.o 

build/readfile.o: src/readfile.c
	$(C)  -Wall -Werror -c src/readfile.c -o build/readfile.o 

build/main.o: src/main.c
	$(C)  -Wall -Werror -c src/main.c -o build/main.o 
clean:
	rm -rf build/*.o bin/circles_app

.PHONY: all clean
