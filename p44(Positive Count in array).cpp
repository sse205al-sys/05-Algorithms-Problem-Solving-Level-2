#include <iostream>
using namespace std;
int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
void FillArray(int arr[100], int& arrLength)
{
	cout << "enter array length  : ";
	cin >> arrLength;
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(-100, 100);
	}
}
int PositiveCount(int arr[100], int length)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >  0)
			counter++;
	}
	return counter;
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], length;
	
	FillArray(arr, length);
	cout << "\nArray Elements: ";
	PrintArray(arr, length);

	cout << "\nPositive Numbers count is: ";
	cout << PositiveCount(arr, length) << endl;

	return 0;

}