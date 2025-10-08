#include <iostream>
#include <string>
using namespace std;
int RandomNumber(int from , int to)
{
	int number = rand() % (to - from + 1) + from;
	return number;
}

void FillArrayWhithRandomNumbers(int arr[100], int& length)
{
	cout << "how many elements : ";
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}
void PrintArray(int arr[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout<<arr[i] << " ";
	}
}
void AddArrayElement(int NumberToAdd, int CopyArray[100], int& Copylength)
{
	Copylength++;
	CopyArray[Copylength - 1] = NumberToAdd;
}
void CopyOddNumbers(int arr[100], int CopyArr[100], int ArrLength, int& Copylength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		if (arr[i] % 2 != 0)
			AddArrayElement(arr[i], CopyArr, Copylength);	
	}
}
int main()
{
	srand((unsigned)time(NULL));

	int arr[100],ArrLength = 0;
	int CopyArray[100], Copylength = 0;

	FillArrayWhithRandomNumbers(arr, ArrLength);
	
	CopyOddNumbers(arr, CopyArray, ArrLength, Copylength);


	cout << "\nArreay 1 elements : ";
	PrintArray(arr, ArrLength);

	cout << "\n";

	cout << "\nOdd numbers array : ";
	PrintArray(CopyArray, Copylength);
	cout << "\n";
}