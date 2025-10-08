#include <iostream>
#include <string>
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

int Random(int to)
{
    return rand() % to ;
}


void FillArray(int arr[100], int length)
{   
    for (int i = 0; i < length; i++)
    {     
        arr[i] = i + 1;
    }
    cout << endl;
}

void ShuffleArr(int arr[100], int length)
{
    
    for (int i = 0; i < length; i++)
    {
        int RandomIndex = Random(length);
        int temp;
        temp = arr[i];
        arr[i] = arr[RandomIndex];
        arr[RandomIndex] = temp;


    }
}


void PrintIntArray(int arr[100] , int length)
{
    
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    srand((unsigned)time(NULL));
    
    int length = ReadPositivNumber("enter number of element : ");
    int arr[100];

    FillArray(arr, length);
    cout << "arry elements befor shuffle : ";
    PrintIntArray(arr, length);

    ShuffleArr(arr, length);

    cout << "array element after shuffle : ";
    PrintIntArray(arr, length);

    return 0;
}
