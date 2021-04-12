
#include "RailFence.h"
using namespace std;


// ======================================================================
bool RailFence::setKey(const string& key)
{
    //IF KEY IS INVALID, RETURN FALSE
        // key must be numbers only
    for (int i = 0; i < key.length(); i++) {
        if (!isdigit(key[i])) return false;
    }
    
    // KEY IS VALID, RETURN TRUE
        // convert key to int and save it to protected variable
    int tempkey = stoi(key);
    cipherKey = tempkey;
    return true;
}


// ======================================================================
string RailFence::encrypt(const string& plaintext)
{
    //INITIALIZE MATRIX
    vector<vector<char>> matrix(cipherKey, vector<char>(plaintext.length()));
    for (int i = 0; i < cipherKey; i++)
        for (int j = 0; j < plaintext.length(); j++)
            matrix[i][j] = '\n';


    //POPULATE MATRIX (with plaintext passed in)
    bool direction = false;
    int row = 0;
    int col = 0;
    for (int i = 0; i < plaintext.length(); i++) {
        if (row == 0 || row == cipherKey - 1) direction = !direction;
        matrix[row][col++] = plaintext[i];
        if (direction) row++;
        else row--;
    }


    //RETRIEVE CIPHERTEXT (from matrix)
    string result = "";
    for (int i = 0; i < cipherKey; i++)
        for (int j = 0; j < plaintext.length(); j++)
            if (matrix[i][j] != '\n') result.push_back(matrix[i][j]);


    // RETURN CIPHERTEXT
    return result;
}


// ======================================================================
string RailFence::decrypt(const string& ciphertext)
{   
    //INITIALIZE MATRIX
    vector<vector<char>> matrix(cipherKey, vector<char>(ciphertext.length()));
    for (int i = 0; i < cipherKey; i++)
        for (int j = 0; j < ciphertext.length(); j++)
            matrix[i][j] = '\n';

    //FILL MATRIX WITH TEMPORY VAL
        // fills elements with '_'
    bool direction;
    int row = 0;
    int col = 0;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (row == 0) direction = true;
        if (row == cipherKey - 1) direction = false;
        matrix[row][col++] = '_';
        if (direction) row++;
        else row--;
    }


    //OVERWRITE MATRIX (with ciphtertext passed in)
        // if current element in matrix == "_", overwrite it with current ciphertext char
    int index = 0;
    for (int i = 0; i < cipherKey; i++)
        for (int j = 0; j < ciphertext.length(); j++)
            if (matrix[i][j] == '_' && index < ciphertext.length()) matrix[i][j] = ciphertext[index++];


    //RETRIEVE PLAINTEXT (from matrix)
        // push into plaintext string if element of matrix is not '_'
    row = 0, col = 0;
    string result = "";
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (row == 0) direction = true;
        if (row == cipherKey - 1) direction = false;
        if (matrix[row][col] != '_') result.push_back(matrix[row][col++]);
        if (direction) row++;
        else row--;
    }


    //RETURN PLAINTEXT
    return result;
}

