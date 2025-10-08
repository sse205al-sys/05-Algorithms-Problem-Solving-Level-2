
#include <iostream>
#include <string>
using namespace std;

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

void PrintIntArray(int arr[100] , int length)
{
    cout << "array element : ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int MaxNumberInArray(int arr[100], int length)
{
    int max = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int length;
    FillArrayWithRandom(arr, length);
    PrintIntArray(arr, length);
    cout << "\nmax number in the array is : " << MaxNumberInArray(arr, length) << endl;
    return 0;
}
