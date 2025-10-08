
#include <iostream>
#include <string>
using namespace std;
int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a number to search for : ";
    cin >> Number;
    return Number;
}
int Random(int from, int to)
{
    int randNum = rand() % (to - from) + from;
    return randNum;
}

void FillArrayWithRandom(int arr[100], int& length)
{
    cout << "enter numer of element : ";
    cin >> length;



    for (int i = 0; i < length; i++)
    {
        arr[i] = Random(1, 100);
    }
    cout << endl;
}

void PrintIntArray(int arr[100], int length)
{
    cout << "array element : ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
short FindArrayPosition(int arr[100], int NumberToCheck, int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (arr[i] == NumberToCheck)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int length;

    FillArrayWithRandom(arr, length);
    PrintIntArray(arr, length);
    
    int NumberToChek = ReadNumber();
    cout << "number you are looking for is : " << NumberToChek <<endl;

    short NumberPosition = FindArrayPosition(arr, NumberToChek, length);

    if (NumberPosition == -1)
        cout << "number you looking for not found :-(\n";
    else
    {
        cout << "The number found at position: " << NumberPosition << endl;
        cout << "The number found its order  : " << NumberPosition + 1 << endl;
    }

    
    return 0;
}
