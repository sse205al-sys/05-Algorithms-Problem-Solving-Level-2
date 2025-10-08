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

void ArrayElement(int arr[100], int& NumberOfElement)
{
    NumberOfElement = ReadPositiveNumber("Enter number of elements: ");
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < NumberOfElement; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
}

int Check(int arr[100], int NumberOfElement, int check)
{
    int count = 0;
    for (int i = 0; i < NumberOfElement; i++)
    {
        if (arr[i] == check)
            count++;
    }
    return count;
}

int main()
{
    int arr[100];
    int NumberOfElement;
    ArrayElement(arr, NumberOfElement);

    cout << "Original array: ";
    for (int i = 0; i < NumberOfElement; i++)
        cout << arr[i] << " ";
    cout << endl;

    int check = ReadPositiveNumber("Enter the number you want to check: ");
    cout << check << " is repeated " << Check(arr, NumberOfElement, check) << " times" << endl;
}