Rifatul H. Istiaque

CPS 222 Project 1

 

Files Submitted:

ReallyLongInt.cc

ReallyLongInt.h

numberTheory.cc

factorial.cc

keygen.cc

encrypt.cc

decrypt.cc

makefile

readme.txt

 

 

To compile all files, the makefile command is: make all

 

To compile files seperately:

 

--- ReallyLongInt.o ---

To Compile: make ReallyLongInt.o

Description: ReallyLongInt.o is comprised of ReallyLongInt.cc and ReallyLongInt.h. ReallyLongInt.h outlines all of the methods used in ReallyLongInt.cc. In ReallyLongInt.cc the barebones of the ReallyLongInt type is made there. All of the methods in ReallyLongInt.h are defined here. These methods are symbolic of another type of data structure for representing numbers, both signed and unsigned.

 

--- factorial.cc ---

To compile: make factorial

To run: factorial <number>

Description: factorial is comprised of ReallyLongInt.o and factorial.cc. In factorial.cc, ReallyLongInt's are used to calculate and print out the factorial of the number it recieved as an argument.

 

PLEASE NOTE: For the following programs, any valid text document names are applicable, as long as they are kept consistent with their associated spot in terms of running each program.

 

--- keygen.cc ---

To compile: make keygen

To run: ./keygen <prime number> <different prime number> <public.txt> <private.txt>

Description: keygen is comprised of ReallyLongInt.o - to use the ReallyLongInt type in the operations/calculatoions, numberTheory.o -is a template containing methods for keygen such as isPrime and extendedEuclid - used to generate keys, as well as keygen.cc. The purpose of this program is to generate keys that will assist in encrypting and decrypting text and store them in public.txt and private.txt. It is advised to use prime numbers that are at least 3 digits or greater to work well with this program.

 

--- encrypt.cc ---

To compile: make encrypt

To run: ./encrypt <public.txt> <plaintext.txt> <encrypted.txt>

Description: encrypt is comprised of ReallyLongInt.o, numberTheory.o and encrypt.cc. The purpose of this program is to use the keys that were generated before and put into the file from keygen called public.txt and use it to encrypt text which it will then print to encrypted.txt. The text that will be encrypted is in plaintext.txt which you should create.

 

--- decrypt.cc ---

To compile: make decrypt

To run: ./decrypt <private.txt> <encrypted.txt> <decrypted.txt>

Description: decrypt is comprised of ReallyLongInt.o, numberTheory.o and decrypt.cc. This program will use the keys that were stored in private.txt from keygen, decrypt the numbers in encrypted.txt and transfer them to another textfile called decrypted.txt.