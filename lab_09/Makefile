CXXFLAGS=-std=c++14

main: main.o funcs.o
		g++ -o main main.o funcs.o

main.o: main.cpp funcs.h
		g++ $(CXXFLAGS) -c main.cpp

funcs.o: funcs.cpp funcs.h
		g++ $(CXXFLAGS) -c funcs.cpp

lab-images.o: lab-images.cpp funcs.h
		g++ $(CXXFLAGS) -c lab-images.cpp
clean:
		rm -f main.o funcs.o