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


int Random(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

void FillArrayWithRandom(int arr[100], int length)
{   
    for (int i = 0; i < length; i++)
    {     
        arr[i] = Random(1, 100);
    }
    cout << endl;
}



void SumArrElement(int arr[100],int arr2[100],int sumArr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        sumArr[i] = arr[i] + arr2[i];
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

    int arr[100], arr2[100], sumArr[100];
    int length = ReadPositivNumber("How many element : ");

    FillArrayWithRandom(arr, length);
    FillArrayWithRandom(arr2, length);

    SumArrElement(arr, arr2,sumArr, length);

    cout << "arr1 : ";
    PrintIntArray(arr, length);

    cout << "\narr2 : ";
    PrintIntArray(arr2, length);

    cout << "\nsum arr : ";
    PrintIntArray(sumArr, length);
   
  
    return 0;
}