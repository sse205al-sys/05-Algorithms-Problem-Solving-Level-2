
#include <iostream>
#include <string>
using namespace std;

enum enPrime { prime = 1, notprime = 2 };
enPrime IsPrime(int n)
{
    int m = round(n / 2);
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
            return enPrime::notprime;
    }
    return enPrime::prime;
}
int Random(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
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

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}
void CopyOfPrimeNumbers(int arr[100], int CopyPrimeArr[100], int length, int& lengthOfCopyArr)
{
    lengthOfCopyArr = 0;
    for (int i = 0; i < length; i++)
    {
        if (IsPrime(arr[i]) == enPrime::prime)
        {
            AddArrayElement(arr[i], CopyPrimeArr, lengthOfCopyArr);
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int arr[100], length;
    FillArrayWithRandom(arr, length);//هون الاصليه

    int CopyPrimeArr[100], lengthOfCopyArr;

    CopyOfPrimeNumbers(arr, CopyPrimeArr, length, lengthOfCopyArr);

    cout << "Array element : ";
    PrintIntArray(arr, length);//طبعنا الاصليه


    cout << "prime numbers in array : ";
    PrintIntArray(CopyPrimeArr, lengthOfCopyArr);

    return 0;
}