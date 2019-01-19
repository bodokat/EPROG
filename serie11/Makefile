run: fractionVectorTest.exe


fraction.o: fraction.cpp fraction.hpp
	g++ -c fraction.cpp -o fraction.o

fractionTest.exe: fractionTest.cpp fraction.o
	g++ fractionTest.cpp fraction.o -o fractionTest.exe

fractionVector.o: fractionVector.cpp fractionVector.hpp fraction.o
	g++ -c fractionVector.cpp fraction.o -o fractionVector.o

fractionVectorTest.exe: fractionVectorTest.cpp fractionVector.o
	g++ fractionVectorTest.cpp fractionVector.cpp fraction.cpp -o fractionVectorTest.exe
