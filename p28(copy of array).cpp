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
void CopyOfArray(int arr[100],int CopyArr[100], int length)
{
    
    for (int i = 0; i < length; i++)
    {
        CopyArr[i] = arr[i];
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int CopyArr[100];
    int length;

    FillArrayWithRandom(arr, length);//هون الاصليه

    CopyOfArray(arr, CopyArr, length);//هون النسحه

    
    cout << "Array 1 element : \n";
    PrintIntArray(arr, length);//طبعنا الاصليه

    cout << endl;
    cout << "Array 2 element : \n";
    PrintIntArray(CopyArr, length);//طبعنا النسخه

    return 0;
