#include <iostream>
#include <string>
//#include <math.h>
#include "Caesar.h"

using namespace std;

bool Caesar::setKey(const string& key)
{
    for (int i = 0; i < key.length(); i++) {
        if (!isdigit(key[i])) return false;
    }
    int tempKey = stoi(key);
    shift = tempKey;
    return true;
}

string Caesar::encrypt(const string& plaintext)
{
    string result="";
    for (int i = 0; i < plaintext.length(); i++) {
        char position = plaintext.at(i);

        for (int j = 0; j < shift; j++) {

            if (isalpha(position)) {
                if (position == 'z') position = 'a';
                else position++;
            }
        }
        if (isalpha(position)) result += position;
    }
    return result;
}

string Caesar::decrypt(const string& ciphertext)
{
    string result="";
    for (int i = 0; i < ciphertext.length(); i++) {
        char position = ciphertext.at(i);

        for (int j = 0; j < shift; j++) {
            if (isalpha(position)) {
                if (position == 'a') position = 'z';
                else position--;
            }
        }
        if (isalpha(position)) result += position;
    }
    return result;
}