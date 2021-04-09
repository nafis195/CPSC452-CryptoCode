#include "Vigenere.h"
using namespace std;


//=================================================================================================
string Vigenere::checkkeysize(const string& input) {
    // Increase the size of the secret key
    while (input.size() > secretkey.size()) {
        secretkey += secretkey;
    }
    // Return key
    return secretkey;
}


//=================================================================================================
int Vigenere::findpos(string x, int start) {
    vector<char> alphabet{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
                            'q','r','s','t','u','v','w','x','y','z' };
    // Checking position of value in alphavector
    for (int i = 0; i < alphabet.size(); i++) {
        if (x.at(start) == alphabet.at(i)) {
            return i;
        }
    }

    // Error message if no match
    cout << "No match, there was no letter\n";

    return 0;

}


//=================================================================================================
string Vigenere::encrypt(const string& input)
{
    vector<char> alphabet{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
                        'q','r','s','t','u','v','w','x','y','z' };
    string temp = input;
    // Format input string
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    string output;
    int keyloc = 0;
    int inputloc = 0;
    // Check key size to make sure its same as or bigger than input
    secretkey = checkkeysize(temp);

    //encypt
    for (int i = 0; i < input.size(); i++) {
        // Set location of key and string in alphavector
        keyloc = findpos(secretkey, i);
        inputloc = findpos(temp, i);

        // Add to output string
        output += (alphabet.at((keyloc + inputloc) % 26));
    }

    return output;

}

//=================================================================================================
string Vigenere::decrypt(const string& input)
{
    vector<char> alphabet{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
                        'q','r','s','t','u','v','w','x','y','z' };
    string temp = input;
    // Format input string
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    string output;
    int keyloc = 0;
    int inputloc = 0;
    // Check key size to make sure its same as or bigger than input
    secretkey = checkkeysize(temp);

    //decrypt
    for (int i = 0; i < input.size(); i++) {
        // Set location of key and string in alphavector
        keyloc = findpos(secretkey, i);
        inputloc = findpos(temp, i);
        // Add to output string
        output += (alphabet.at((inputloc - keyloc + 26) % 26));
    }

    return output;

}


//=================================================================================================
bool Vigenere::setKey(const string& key) {
    //Checks for digits in key string
    for (int i = 0; i < key.length(); i++)
    {
        if (isdigit(key[i])) {
            return false;
        }
    }
    secretkey = key;
    // Formats the key to lowercase
    transform(secretkey.begin(), secretkey.end(), secretkey.begin(), ::tolower);
    return true;
}
