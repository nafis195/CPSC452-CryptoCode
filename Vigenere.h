#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include "CipherInterface.h"

using namespace std;

// This class implements the Vigenere cipher using an abstraction of the CipherInterface class

class Vigenere : public CipherInterface
{

public:

	// Checks if user inputted key is valid and sets it
	virtual bool setKey(const string& key);

	//Encrypts a string of plaintext
	virtual string encrypt(const string& plaintext);

	//Decrypts a string of plaintext
	virtual string decrypt(const string& ciphertext);

	// increases the key size to be the same size or bigger than the input
	virtual string checkkeysize(const string& input);

	// Finds the position of the passed value in the alphavector/alphabet
	virtual int findpos(string input, int startval);


protected:
	string secretkey;

};

#endif
