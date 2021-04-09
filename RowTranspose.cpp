// This file is the function implementation of the Row Transposition Cipher.


#include "RowTranspose.h"
#include <iostream>
#include <cmath>
using namespace std;


// setKey function implementation
bool RowTranspose::setKey(const string& key) {
	for (int i = 0; i < key.length(); i++) 
	{
		if (isdigit(key[i]))
			return false;
	}
	secretkey = key;
	return true;
}


// encrypt function implementation
string RowTranspose::encrypt(const string& plaintext) {
	string ciphertext = "";
	int maxcolumns = secretkey.length();
	int maxrows = ceil(plaintext.length() / (double)maxcolumns);
	int plaintextlength = plaintext.length();
	vector<vector<char>> matrix;

	int i = 0;
	for (int r = 0; r < maxrows; r++) {
		for (int c = 0; c < maxcolumns; c++) {
			if (i < plaintextlength) {
				matrix[r][c] = plaintext[i];
				i++;
			}
			else {
				matrix[r][c] = 'x';
			}
		}
	}
	for (i = 0; i < maxcolumns; i++) {
		for (int r = 0; r < maxrows; r++) {
			ciphertext.push_back(matrix[r][secretkey[i] - '1']);
		}
	}
	cout << "enc complete" << endl;
	return ciphertext;
}


// decrypt function implementation
string RowTranspose::decrypt(const string& ciphertext) {
	string plaintext = "";
	int maxcolumns = secretkey.length();
	int maxrows = ciphertext.length() / maxcolumns;
	vector<vector<char>> matrix;

	int i = 0;
	for (int c = 0; c < maxcolumns; c++) {
		for (int r = 0; r < maxrows; r++) {
			matrix[r][secretkey[c] - '1'] = ciphertext[i];
			i++;
		}
	}
	for (int r = 0; r < maxrows; r++) {
		for (int c = 0; c < maxcolumns; c++) {
			plaintext.push_back(matrix[r][c]);
		}
	}
	return plaintext;
}


//=================End of RowTranspose.cpp file=======================
