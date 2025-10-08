#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string m)
{
    int num;
    do
    {
        cout << m;
        cin >> num;
    } while (num <= 0);
    return num;
}

void ReadArr(int arr[100], int& length)
{
    cout << "enter numer of element : ";
    cin >> length;
    cout << "\n";
    
    cout << "array elemrnts : \n\n";
    for (int i = 0; i < length; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << endl;
}
void PrintIntArray(int arr[100] , int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int TimesRepeted(int NumberTicheck, int arrLength, int arr[100])
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == NumberTicheck)
            count++;
    }
    return count;
}
int main()
{
    int length;
    int arr[100];
    ReadArr(arr, length);

    int numberToCheck = ReadPositiveNumber("enter number you want to check : ");
    cout << "Original array : ";
    PrintIntArray(arr, length);
    cout << "\n" << numberToCheck << " is repeated " << TimesRepeted(numberToCheck, length, arr) <<" time(s)\n";
    return 0;
