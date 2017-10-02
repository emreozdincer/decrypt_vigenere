// M. Emre Ozdincer - 19398 - 10/1/2017

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cout << "This program decrypts a vigenere cipher given the key vector." 
		<< "\nSpaces are ignored. Please enter a ciphertext:"
		<< "\ne.g: WZWR FVAIV EHIJ JSIXIV RG MMXLIJ TDC SKSIZ JSMD ASEAR XAUP TILTQV\n";

	string cipher;
	getline (cin, cipher);

	int cipherLength = cipher.length();

	vector<int> cipVec; // cipher vector: holds the ascii values of letters
	vector<char> plainVec(cipherLength); // plain vector: holds the resulting plaintext

	// fill the cipher vector
	for (int i = 0; i<cipherLength; i++)
	{
		if (cipher[i] != ' ')
			cipVec.push_back(int(cipher[i])-65);
		else
			cipVec.push_back(int(cipher[i]));
	}

	int keyLength;
	
	cout << "\nPlease enter key size, then key values in order (e.g: 3 2 14 5)\n";
	cin >> keyLength;

	vector<int> key(keyLength);
	int keyValue;

	for (int i=0; i< keyLength; i++)
	{
		cin >> keyValue;
		key[i] = keyValue;
	}

	int spaceCount = 0; // to keep track of whitespaces

	// decryption algorithm
	for (int i = 0; i<cipherLength; i++)
	{

		if (cipVec[i] != 32)
			cipVec[i] = (cipVec[i]-key[(i-spaceCount)%keyLength])%26; // mod 26

		if (cipVec[i] < 0) cipVec[i] += 26; // mod 26

		// fill result
		if (cipVec[i] != 32)
			plainVec[i] = char(cipVec[i]+65); 
		else
		{
			spaceCount++;
			plainVec[i] = char(cipVec[i]);
		}

		cout << plainVec[i];
	}

	cout << endl;

	cin.get();
	cin.ignore();

	return 0;
}
