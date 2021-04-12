#include"Playfair.h"
using namespace std;

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Playfair::setKey(const string& key)
{
    for (int i = 0; i < key.length(); i++)
    {
        if (isdigit(key[i])) {
            return false;
        }
    }
    cipherKey = key;
    return true;
}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Playfair::encrypt(const string& message)
{
    //Generating the matrix
    //flag indicates if letter is in matrix already
    int flag[26] = { 0 };
    int x = 0, y = 0;

    //Add key letters to the matrix
    for (int i = 0; i < cipherKey.length(); i++)
    {
        //change letter j to i
        if (cipherKey[i] == 'j') cipherKey[i] = 'i';

        if (flag[cipherKey[i] - 'a'] == 0)
        {
            matrix[x][y++] = cipherKey[i];
            flag[cipherKey[i] - 'a'] = 1;
        }
        else if (y == 5) x++, y = 0;
    }

    //Add rest of letters to the matrix except j since replaced with i
    // if flag = 0, letter is not in matrix
    // if flag = 1, letter is present in matrix
    for (char let = 'a'; let <= 'z'; let++)
    {
        if (let == 'j') continue;

        if (flag[let - 'a'] == 0)
        {
            matrix[x][y++] = let;
            flag[let - 'a'] = 1;
        }
        if (y == 5) x++, y = 0;
    }
        
    //message formatting
    string formMsg = message;
    for (int i = 0; i < formMsg.length(); i++)
    {
        if (formMsg[i] == 'j')  formMsg[i] = 'i';
    }

    //pairing two letters
    for (int i = 1; i < formMsg.length(); i += 2)
    {
        if (formMsg[i - 1] == formMsg[i])  formMsg.insert(i, "x");
    }

    if (formMsg.length() % 2 != 0)  formMsg += "x";
    
    string cipherText = "";
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;

    //check for pair values
    for (int i = 0; i < formMsg.length(); i += 2)
    {
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                if (formMsg[i] == matrix[j][k])
                {
                    x1 = j;
                    y1 = k;
                }
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                if (formMsg[i+1] == matrix[j][k])
                {
                    x2 = j;
                    y2 = k;
                }
       
        //identical row
        if (x1 == x2)
        {
            cipherText += matrix[x1][(y1 + 1) % 5];
            cipherText += matrix[x2][(y2 + 1) % 5];
        }
        //identical column
        else if (y1 == y2)
        {
            cipherText += matrix[(x1 + 1) % 5][y1];
            cipherText += matrix[(x2 + 1) % 5][y2];
        }
        else
        {
            cipherText += matrix[x1][y2];
            cipherText += matrix[x2][y1];
        }
    }
    return cipherText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Playfair::decrypt(const string& message)
{
    int flag[26] = { 0 };
    int x = 0, y = 0;

    //Add key letters to matrix
    for (int i = 0; i < cipherKey.length(); i++)
    {
        //change letter j to i
        if (cipherKey[i] == 'j') cipherKey[i] = 'i';

        if (flag[cipherKey[i] - 'a'] == 0)
        {
            matrix[x][y++] = cipherKey[i];
            flag[cipherKey[i] - 'a'] = 1;
        }
        if (y == 5) x++, y = 0;
    }

    //Add the rest of the letters except j since replaced with i
    for (char let = 'a'; let <= 'z'; let++)
    {
        if (let == 'j') continue;

        if (flag[let - 'a'] == 0)
        {
            matrix[x][y++] = let;
            flag[let - 'a'] = 1;
        }
        if (y == 5) x++, y = 0;
    }

    string plainText = "";
    string formMsg = message;
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;

    //check for pair values
    for (int i = 0; i < formMsg.length(); i += 2)
    {
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                if (formMsg[i] == matrix[j][k])
                {
                    x1 = j;
                    y1 = k;
                }
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                if (formMsg[i + 1] == matrix[j][k])
                {
                    x2 = j;
                    y2 = k;
                }

        //identical row
        if (x1 == x2)
        {
            plainText += matrix[x1][--y1 < 0 ? 4 : y1];
            plainText += matrix[x2][--y2 < 0 ? 4 : y2];
        }
        //identical column
        else if (y1 == y2)
        {
            plainText += matrix[--x1 < 0 ? 4 : x1][y1];
            plainText += matrix[--x2 < 0 ? 4 : x2][y2];
        }
        else
        {
            plainText += matrix[x1][y2];
            plainText += matrix[x2][y1];
        }
    }
    return plainText;
}