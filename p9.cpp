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
	for (int i = 0; i < 10; i++) \\ هون الي عملناه انه مرينا ع رقم من 1 الى 9 وشفنا كم مره تكرر كل رقم بالرقم الي بدي اشوف التكرتر فيه
	{
		short DigitFrequency = 0;
		DigitFrequency = CountDigitFrequency(number , i);

		if (DigitFrequency > 0)
		{
			cout << "Digit " << i << " Frequencey is "  
				<< DigitFrequency << " Time(s).\n";
		}

	}
}

int main()
{
	int number = ReadPositivNumber("enter number : ");

	 PrintAllDigitFrequency(number);
	
	return 0;
}