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
		arr[i] = RandomNumber(1, 100);
	}
}
int EvenCount(int arr[100], int length)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] % 2 == 0)
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

	cout << "\nEven Numbers count is: ";
	cout << EvenCount(arr, length) << endl;

	return 0;

}