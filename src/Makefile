main: main.o test.o operations.o scanner.o identifiers.o parser.o
	g++ -o test -g test.o operations.o main.o scanner.o identifiers.o parser.o
main.o:	main.cxx test.h operations.h tree.h scanner.h token.h parser.h
	g++ -c -g main.cxx
test.o: test.cxx test.h tree.h operations.h scanner.h parser.h token.h
	g++ -c -g test.cxx
parser.o: parser.cxx parser.h scanner.h tree.h token.h
	g++ -c -g parser.cxx
scanner.o: scanner.cxx scanner.h parser.h token.h
	g++ -c -g scanner.cxx
identifiers.o: identifiers.cxx scanner.h operations.h
	g++ -c -g identifiers.cxx
operations.o: operations.cxx operations.h
	g++ -c -g operations.cxx
clean:
	rm *.o *~
