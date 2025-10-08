
#include<iostream>
#include<string>
using namespace std;

string ReadText()
{
	string text ;
	
	cout << "Please enter text you wont to encrypt it : ";
	
	getline(cin, text);
	
	return text;
}

string EncryptText(string text,short Encryptionkey)
{
	
	for (int i = 0; i <= text.length(); i++)
	{
		text[i] = char((int)text[i] + Encryptionkey);//حولنا الحرف لرقم فصار عندي رقمه بالاسكي و زدت عليه 2وحولته ل حرف
	} 
	return text;
}
string DecryptText(string encryptText,short Encryptionkey)
{
	
	for (int i = 0; i <= encryptText.length(); i++)
	{
		encryptText[i]= char((int)encryptText[i] - Encryptionkey);
	}
	return encryptText;
}
int main()
{
	const short Encryptionkey = 2;
	string Text = ReadText();
	cout << "Text before encryption : " << Text << endl;
	string Encrypt = EncryptText(Text, Encryptionkey);
	cout << "Text after encryption : " << Encrypt<< endl;
	string Decrypt = DecryptText(Encrypt,Encryptionkey);
	cout << "Text after decryption : " << Decrypt << endl;
	return 0;
}