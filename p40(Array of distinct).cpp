
#include <iostream>
using namespace std;
void FillArray(int arr[100],int &arrLength)
{
	arrLength = 10;
	
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;	
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
}
short FindNumberPositionInArray(int num, int arr[100], int arrLength)
{
    for (int indx = 0; indx < arrLength ;indx++)
    {
        if (arr[indx] == num)
            return indx;
    }
    return -1;
}
bool IsNumberInArr(int num, int arr[100], int arrLength)
{
    if (FindNumberPositionInArray(num, arr, arrLength) == -1)
        return false;
    return true;
}
void AddArrayElement(int num, int arr[100], int& arrLength)//هاذ بدنا نعبي الاري الحديده
{
    arrLength++;
    arr[arrLength - 1] = num;
}
void CopyDistinctNumbers(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        if (!IsNumberInArr(arrSource[i], arrDestination, DestinationLength))
            AddArrayElement(arrSource[i], arrDestination,DestinationLength);
    }
}
int main()
{
    int arrSource[100], SourceLength = 0, arrDestination[100], DestinationLength = 0;
    FillArray(arrSource, SourceLength);

    cout << "array 1 element : ";
    PrintArray(arrSource, SourceLength);

    CopyDistinctNumbers(arrSource, arrDestination, SourceLength, DestinationLength);

    cout << "\n\narray 2 distinct element : ";
    PrintArray(arrDestination, DestinationLength);

    return 0;
}