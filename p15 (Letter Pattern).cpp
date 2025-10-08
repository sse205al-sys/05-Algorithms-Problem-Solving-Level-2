#include<iostream>
#include<string>
using namespace std;

int ReadPositivNumber(string message)
{
	int num = 0;
	do
	{
		cout << message;
		cin >> num;
	} while (num <= 0);
	return num;
}
void LetterPattern(int number)
{ 
	for (int i = 65 ; i <= number + 65 - 1; i++)
	{
		
		for (int j = 1; j <= i - 65 + 1; j++)
		{
			cout << char(i);
			
		}
		cout << "\n";
		
	}
}
int main()
{
	LetterPattern(ReadPositivNumber("enter number : "));
}