#ifndef RAILFENCECIPHER_H
#define RAILFENCECIPHER_H

#include <iostream>
#include <string>
#include <math.h>
#include "CipherInterface.h"

using namespace std;


//This class implements the railfence cipher.
class RailFence : public CipherInterface {
	protected:
		int securitykey;


	public:
		//check & sets user's key if valid (cant contain nums)
		bool setKey(const string& key);

		//Encrypts a string of plaintext
		string encrypt(const string& plaintext);

		
		//Decrypts a string of ciphertext
		string decrypt(const string& ciphertext);
}
