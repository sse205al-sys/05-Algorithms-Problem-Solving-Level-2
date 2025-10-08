#include<iostream>
#include<string>
using namespace std;

string ReadText()
{
	string text ;
	
	cout << "Please enter text you wont to encrypt it : ";
	
	cin >> text;
	
	return text;
}

string EncryptText(string text)
{
	string EncryptText = "";
	for (int i = 0; i <= text.length(); i++)
	{
		EncryptText += text[i] + 2;
	}
	return EncryptText;
}
string DecryptText(string incryptText)
{
	string decryptText = "";
	for (int i = 0; i <= incryptText.length(); i++)
	{
		decryptText += incryptText[i] - 2;
	}
	return decryptText;
}
int main()
{
	string Text = ReadText();
	cout << "Text before encryption : " << Text << endl;
	string Encrypt = EncryptText(Text);
	cout << "Text after encryption : " << Encrypt<< endl;
	string Decrypt = DecryptText(Encrypt);
	cout << "Text after decryption : " << Decrypt << endl;

}