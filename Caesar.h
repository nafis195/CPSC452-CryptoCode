#ifndef CAESAR_H
#define CAESAR_H

#include "CipherInterface.h"
using namespace std;


class Caesar : public CipherInterface
{
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

	

	/* The protected members */
protected:
	int shift;
};


#endif