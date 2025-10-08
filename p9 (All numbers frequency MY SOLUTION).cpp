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

int CountDigitFrequency(int number , short digit)
{
	int remainder = 0, freqCount = 0;
	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;
		if (remainder == digit)
			freqCount++;
	}
	return freqCount;
}
void PrintAllDigitFrequency(int number)
{
	string s = "";
	int remainder = 0;
	while (number > 0)
	{
		remainder = number % 10;
		if (s.find(to_string(remainder)) != string::npos) // هون حكينا اذا انه الحرف الي بندور عليه لا يساوي مش موجود لانه الفايند اذا ما لقت القيمه بترجع string ::npos
		{
			number /= 10;
			continue;
		}
		else
		{
			s += to_string(remainder);
			cout << "Digit " << remainder << " frequency is " << CountDigitFrequency(number, remainder) << endl;
			number /= 10;
			
		}
	}
}

int main()
{
	int number = ReadPositivNumber("enter number : ");

	 PrintAllDigitFrequency(number);
	
	return 0;
}