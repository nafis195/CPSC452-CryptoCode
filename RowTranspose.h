#ifndef ROWTRANSPOSITION_H
#define ROWTRANSPOSITION_H

#include <vector>
#include <string>
#include "CipherInterface.h"
using namespace std;

// ROW TRANSPOSE CLASS
class RowTranspose : public CipherInterface
{
	protected:
		string cipherKey;

	public:
		//SETS USER'S KEY (if valid)
			//example key: "3 1 2 4"
		virtual bool setKey(const string& key);
		
		//ENCRYPT USER PLAINTEXT
		virtual string encrypt(const string& plaintext);
		
		//DECRYPT USER CIPHERTEXT
		virtual string decrypt(const string& ciphertext);

};

#endif
