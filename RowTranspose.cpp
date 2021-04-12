
#include "RowTranspose.h"
using namespace std;

// ======================================================================
bool RowTranspose::setKey(const string& key) 
{
	//IF KEY IS INVALID, RETURN FALSE
		//key can only be numbers and spaces
	for (int i = 0; i < key.length(); i++) 
		if (!isdigit(key[i]) && key[i] !=' ') return false;

	//KEY IS VALID, RETURN TRUE
		// save it to protected variable
	cipherKey = key;
	return true;
}


// ======================================================================
string RowTranspose::encrypt(const string& plaintext) 
{ 
	//GET MAX COLUMNS
	int maxcolumns = 0;
	for (int i = 0; i < cipherKey.length(); i++)
		if (cipherKey[i] != ' ') maxcolumns++;

	//GET MAX ROWS
		//ceil use for +1 row to account for extra chars
	int maxrows = ceil(plaintext.length()/(double)maxcolumns);


	//INITIALIZE MATRIX (using max rows/columns)
	vector<vector<char>> matrix(maxrows, vector<char>(maxcolumns));


	//POPULATE MATRIX (with plaintext passed in)
	int i = 0;
	for (int row = 0; row < maxrows; row++) {
		for (int col = 0; col < maxcolumns; col++) {
			if (i < plaintext.length()) {
				matrix[row][col] = plaintext[i];
				i++;
			}
			// fill extra elements in matrix with 'x'
			else matrix[row][col] = 'x';
		}
	}
	

	//RETRIEVE CIPHERTEXT (from matrix)
	string ciphertext = "";
	for (int j = 0; j < cipherKey.length(); j++) {
		if (cipherKey[j] == ' ') continue;
		else {
			for (int row = 0; row < maxrows; row++) {
				ciphertext.push_back(matrix[row][cipherKey[j] - '1']);
			}
		}
	}

	//RETURN CIPHERTEXT
	return ciphertext;
}


// ======================================================================
string RowTranspose::decrypt(const string& ciphertext) 
{
	//GET MAX COLUMNS
	int maxcolumns = 0;
	for (int i = 0; i < cipherKey.length(); i++)
		if (cipherKey[i] != ' ') maxcolumns++;

	//GET MAX ROWS
	int maxrows = ceil(ciphertext.length()/(double)maxcolumns);
	

	//INITIALIZE MATRIX (using max rows/columns)
	vector<vector<char>> matrix(maxrows, vector<char>(maxcolumns));
	

	//POPULATE MATRIX (with ciphertext passed in)
	int i = 0;
	for (int col = 0; col < cipherKey.length(); col++) {
		for (int row = 0; row < maxrows; row++) {
			if (cipherKey[col] == ' ') break;
			else {
				matrix[row][cipherKey[col] - '1'] = ciphertext[i];
				i++;
			}
		}
	}


	//RETRIEVE PLAINTEXT (from matrix)
	string plaintext = "";
	for (int row = 0; row < maxrows; row++) 
		for (int col = 0; col < maxcolumns; col++) 
			if(matrix[row][col] != 'x') plaintext.push_back(matrix[row][col]);

	//RETURN PLAINTEXT	
	return plaintext;
}
