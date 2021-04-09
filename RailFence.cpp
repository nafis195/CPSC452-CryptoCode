
#include <iostream>
#include <string>
#include "RailFence.h"
using namespace std;

// ==================================================================================
bool RailFence::setKey(const string& mykey) {
    // CHECK IF KEY IS VALID
        //if key contains a num, returns false
    for (int i = 0; i < mykey.length(); i++) {
        if (!isdigit(mykey[i])) {
            return false;
        }
    }

    // checkpoint is reached, key is valid
    //cout << "Checkpoint: setKey";
    int temp = stoi(key);

    // save key into protected variable
    secretkey = temp;
    return true;

}


// ==================================================================================
string RailFence::encrypt(const string& plaintext) {
    
    //GET COLUMN VALUE
    //round up to nearest int, ++1
    int len = round(plaintext.length() / secretkey);
    len++;
    //len is now equal to num of columns needed for our rail fence

    //CREATE RAIL FENCE (using a table)
    char** table = new char* [secretkey];
    for (int i = 0; i < secretkey; ++i) {
        table[i] = new char[len];
    }

    //EMPTY THE TABLE
    char null = ' ';
    for (int row = 0; row < secretkey; row++) {
        for (int col = 0; col < len; col++) {
            table[row][col] = null;
        }
    }

    //BEGIN ENCRYPTION (putting plaintext into rail fence table)
    int temp = 0;
    for (int col = 0; col < len; col++) {
        for (int row = 0; row < secretkey; row++) {
            
            if (temp < plaintext.length()) {
                char tableValue = plaintext.at(temp);
                if (isalpha(tableValue)) {
                    table[row][col] = tableValue;
                    temp++;
                }
                else {
                    temp++;
                    row--;
                }
            }
        }
    }

    //RETRIEVE CIPHERTEXT (from rail fence)
    string ciphertext;
    for (int row = 0; row < secretkey; row++) {
        for (int col = 0; col < len; col++) {
            
            cout << table[row][col];
            if (isalpha(table[row][col])) {
                ciphertext += table[row][col];
            }
        }
    }
    return ciphertext;
}


// ==================================================================================
string RailFence::decrypt(const string& ciphertext) {
    
    //GET COLUMN VALUE
    //round up to nearest int, ++1
    int len = round(ciphertext.length() / secretkey);
    len++;

    //RETRIEVE HOW MANY LEFTOVER LETTERS IN CIPHERTEXT (saves it to leftover)
        // rowlengthArray will hold the length of every row in an array []
        // lettersPerRow will hold the minimum length of all rows
    int* rowLengthArray;    
    rowLengthArray = new int[secretkey];
    int lettersPerRow = floor(ciphertext.length() / secretkey);

    // update rowLengthArray to include leftover characters to the rows that have them
    int extraCharCounter = ciphertext.length() % secretkey;
    for (int i = 0; i < secretkey; i++) {
        // does (lettersPerRow +1) to rowLengthArray if extraCharCounter is not zero
        if (excessCharCounter != 0) {
            rowLengthArray[i] = lettersPerRow + 1;
            excessCharCounter--;
        }
        //else, rowLengthArray is the size of minimum length of all rows
        else {
            rowLengthArray[i] = lettersPerRow;
        }
    }

    //CREATE RAIL FENCE (using a table)
    char** table = new char* [secretkey];
    for (int i = 0; i < secretkey; ++i) {
        table[i] = new char[len];
    }

    //EMPTY THE TABLE
    char null = ' ';
    for (int row = 0; row < secretkey; row++) {
        for (int col = 0; col < len; col++) {
            table[row][col] = null;
        }
    }

    //BEGIN DECRYPTION (putting ciphertext into rail fence table)
    int count = 0;
    for (int row = 0; row < secretkey; row++) {
        for (int col = 0; col < rowLengthArray[row]; col++) {

            if (count < ciphertext.length()) {
                char charHolder = ciphertext.at(count);
                if (isalpha(charHolder)) {
                    table[row][col] = charHolder;
                    cout << table[row][col];
                    count++;
                }
                else {
                    count++;
                    col--;
                }
            }
        }
    }

    //RETRIEVE PLAINTEXT (from rail fence)
    string plaintext;
    for (int col = 0; col < len; col++) {
        for (int row = 0; row < secretkey; row++) {

            if (isalpha(table[row][col])) {
                plaintext += table[row][col];
            }
        }
    }
    return plaintext;
}
