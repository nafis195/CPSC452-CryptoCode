all:	cipher

cipher:	cipher.o Playfair.o RowTranspose.o Vigenere.o Caesar.o RailFence.o
	g++ cipher.o Playfair.o RowTranspose.o Vigenere.o Caesar.o RailFence.o -o cipher

cipher.o: cipher.cpp
	g++ -g -c cipher.cpp 

Playfair.o:	Playfair.cpp Playfair.h CipherInterface.h
	g++ -g -c Playfair.cpp

RowTranspose.o:	RowTranspose.cpp RowTranspose.h CipherInterface.h
	g++ -g -c RowTranspose.cpp
	
Vigenere.o:	Vigenere.cpp Vigenere.h CipherInterface.h
	g++ -g -c Vigenere.cpp

Caesar.o: Caesar.cpp Caesar.h CipherInterface.h
	g++ -g -c Caesar.cpp

RailFence.o: RailFence.cpp RailFence.h CipherInterface.h
	g++ -g -c RailFence.cpp
	

clean:
	rm -rf *.o cipher
