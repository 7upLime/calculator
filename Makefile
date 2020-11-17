main: main.o test.o operations.o tree.o scanner.o identifiers.o
	g++ -o test -g test.o operations.o tree.o main.o scanner.o identifiers.o
main.o:	main.cxx test.h operations.h tree.h scanner.h
	g++ -c -g main.cxx
test.o: test.cxx test.h tree.h operations.h scanner.h
	g++ -c -g test.cxx
scanner.o: scanner.cxx scanner.h
	g++ -c -g scanner.cxx
identifiers.o: identifiers.cxx scanner.h
	g++ -c -g identifiers.cxx
operations.o: operations.cxx operations.h
	g++ -c -g operations.cxx
tree.o:	tree.cxx tree.h
	g++ -c -g tree.cxx
clean:
	rm *.o *~
