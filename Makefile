output: main.o Array.o Treap.o
	g++ main.o Array.o Treap.o -o main

main.o: main.cpp
	g++ -c main.cpp

Array.o: array/Array.cpp array/Array.h
	g++ -c array/Array.cpp

Treap.o: treap/Treap.cpp  treap/Treap.h
	g++ -c treap/Treap.cpp

clean: 
	rm *.o