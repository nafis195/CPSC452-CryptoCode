// This file is the public and private function of the Row Transposition Cipher.


#ifndef ROWTRANSPOSITION_H
#define ROWTRANSPOSITION_H

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CipherInterface.h"

using namespace std;

// This class extends the abstract class CipherInterface.

class RowTranspose : public CipherInterface
{
	// Public members
public:
	bool setKey(const string& key);
	string encrypt(const string& plaintext);
	string decrypt(const string& ciphertext);

	// Private members
protected:
	string secretkey;
};

#endif


//=================End of RowTranspose.h file=======================