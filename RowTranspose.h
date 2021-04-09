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

/**
 * This class implements the playfair cipher.
 * The class extends the abstract class
 * CipherInterface.
 */

class RowTranspose : public CipherInterface
{
	/** The public members **/
public:

	/**
	 * Sets the key to use
	 * @param key - the key to use
	 * @return - True if the key is valid and False otherwise
	 */
	virtual bool setKey(const string& key);

	/**
	 * Encrypts a plaintext string
	 * @param plaintext - the plaintext string
	 * @return - the encrypted ciphertext string
	 */
	virtual string encrypt(const string& plaintext);

	/**
	 * Decrypts a string of ciphertext
	 * @param ciphertext - the ciphertext
	 * @return - the plaintext
	 */
	virtual string decrypt(const string& ciphertext);

	/**
	 * Prints the Playfair matrix
	 * @param fp - the file pointer
	 */
	void printMatrix(FILE* fp);

	/* The protected members */
protected:
	string secretkey;

};

#endif