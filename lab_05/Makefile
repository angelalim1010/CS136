main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

tests.o: tests.cpp funcs.h

main.o: main.cpp fact.h

funcs.o: funcs.cpp fact.h

clean:
	rm fact.o main.o