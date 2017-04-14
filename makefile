ReallyLongInt.o : ReallyLongInt.cc ReallyLongInt.h
	g++ -c  ReallyLongInt.cc

keygen: keygen.cc ReallyLongInt.o
	g++ -o keygen keygen.cc ReallyLongInt.o

encrypt: encrypt.cc ReallyLongInt.o
	g++ -o encrypt encrypt.cc ReallyLongInt.o

decrypt: decrypt.cc ReallyLongInt.o
	g++ -o decrypt decrypt.cc ReallyLongInt.o

factorial: factorial.cc ReallyLongInt.o
	g++ -o factorial factorial.cc ReallyLongInt.o

all:
	make ReallyLongInt.o keygen encrypt decrypt factorial
