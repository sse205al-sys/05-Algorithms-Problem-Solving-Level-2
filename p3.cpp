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

bool IsPrefect(int number)
{
	int sum = 0;
	for (int i = 1; i < number; i++)
	{
		if (number % i == 0)
			sum += i;
	}
	return sum == number;
}
void PrintIsPrefectOrNot(int number)
{
	if (IsPrefect(number))
		cout<<number << " is prefect\n";
	else
		cout<<number <<" is not prefect\n";
}

int main()
{
	PrintIsPrefectOrNot( ReadPositivNumber("write the number you want to check if it prefect or not : "));
	return 0;

}