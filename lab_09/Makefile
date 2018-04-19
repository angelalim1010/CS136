CXXFLAGS=-std=c++14

main: main.o lab-images.o
		g++ -o main main.o lab-images.o

main.o: main.cpp funcs.h
		g++ $(CXXFLAGS) -c main.cpp

lab-images.o: lab-images.cpp funcs.h
		g++ $(CXXFLAGS) -c lab-images.cpp
clean:
		rm -f main.o lab-images.o