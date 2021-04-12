#ifndef RAILFENCECIPHER_H
#define RAILFENCECIPHER_H

#include <vector>
#include <string>
#include "CipherInterface.h"
using namespace std;


// RAIL FENCE CLASS
class RailFence : public CipherInterface
{
	protected:
		int cipherKey;

	public:
		//SETS USER'S KEY (if valid)
			//valid key =  numbers only
		virtual bool setKey(const string& key);
	
		//ENCRYPT USER PLAINTEXT
		virtual string encrypt(const string& plaintext);
	
		//DECRYPT USER CIPHERTEXT
		virtual string decrypt(const string& ciphertext);
};

#endif
