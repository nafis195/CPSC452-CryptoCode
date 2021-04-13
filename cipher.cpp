#include <string>
#include "CipherInterface.h"
#include "RowTranspose.h"
#include "Vigenere.h"
#include "RailFence.h"
#include "Caesar.h"
#include "Playfair.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	// Variable to hold input from the text file
	string input;

	// Variable to hold cipher name. User options are: PLF RTS RFC VIG CES
	string cipher = argv[1];

	// Variable to hold the encryption key
	string keyInput = argv[2];

	// Variable to hold whether we encode or decode. User options are: ENC or DEC
	string funcType = argv[3];

	//  Varible to hold the file contents
	string inFile = argv[4];

	// Varibale to hold what is being written into the output file 
	string outFile = argv[5];

	// Opening file
	ifstream infile;
	infile.open(inFile);
	string line;
	while (getline(infile, line)) {
		input += line;
	}
	infile.close();



	// Playfair Cipher
	if (cipher == "PLF") {

		// Creating an instance of the Playfair cipher
		CipherInterface* cipher = new Playfair();
		cout << "Making a new Playfair" << endl;

		// Error checks
		if (!cipher)
		{
			fprintf(stderr, "ERROR\n",
				__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}

		// Setting the encryption key
		cout << "setting the key" << endl;
		cipher->setKey(keyInput);
		cout << "key should be set" << endl;

		if (funcType == "ENC")
		{
			cout << "doing encryption1" << endl;
			cout << input << endl;

			// Performing encryption
			input = cipher->encrypt(input);
			cout << input << endl;
			cout << "after encryption1" << endl;
		}
		if (funcType == "DEC")
		{
			// Performing decryption
			input = cipher->decrypt(input);
		}

	}

	// Row Transposition Cipher
	if (cipher == "RTS") {

		// Creating an instance of the Row Transposition cipher
		CipherInterface* cipher = new RowTranspose();

		// Error checks
		if (!cipher)
		{
			fprintf(stderr, "ERROR\n",
				__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}

		// Setting the encryption key
		cipher->setKey(keyInput);

		if (funcType == "ENC")
		{
			cout << "doing encryption2" << endl;
			// Performing encryption
			input = cipher->encrypt(input);
		}
		if (funcType == "DEC")
		{
			// Performing decryption
			input = cipher->decrypt(input);
		}
	}

	// Railfence Cipher
	if (cipher == "RFC") {

		// Creating an instance of the Railfence cipher
		CipherInterface* cipher = new RailFence();

		// Error checks
		if (!cipher)
		{
			fprintf(stderr, "ERROR\n",
				__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}

		// Setting the encryption key
		cipher->setKey(keyInput);

		if (funcType == "ENC")
		{
		
			// Performing encryption
			input = cipher->encrypt(input);
		}
		if (funcType == "DEC")
		{
			// Performing decryption
			input = cipher->decrypt(input);
		}
	}
	// Vigenere Cipher
	if (cipher == "VIG") {

		// Creating an instance of the Vigenere cipher
		CipherInterface* cipher = new Vigenere();

		// Error checks
		if (!cipher)
		{
			fprintf(stderr, "ERROR\n",
				__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}

		// Setting the encryption key
		cipher->setKey(keyInput);

		if (funcType == "ENC")
		{
		
			// Performing encryption
			input = cipher->encrypt(input);
		;
		}
		if (funcType == "DEC")
		{
			// Performing decryption
			input = cipher->decrypt(input);
		}
	}
	// Caesar Cipher
	if (cipher == "CES") {

		// Creating an instance of the Ceasar cipher
		CipherInterface* cipher = new Caesar();

		// Error checks
		if (!cipher)
		{
			fprintf(stderr, "ERROR\n",
				__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}

		// Setting the encryption key
		cipher->setKey(keyInput);


		if (funcType == "ENC")
		{
			cout << "doing encryption5" << endl;
			// Performing encryption
			input = cipher->encrypt(input);
		}
		if (funcType == "DEC")
		{
			// Performing decryption
			input = cipher->decrypt(input);
		}
	}


	// Placing the contents of the encryption algorithm to the output file.
	ofstream out(outFile);
	out << input;
	out.close();

	return 0;
}