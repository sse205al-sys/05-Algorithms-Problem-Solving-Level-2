#include <iostream>
#include <string>
using namespace std;
int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a number : ";
    cin >> Number; 
    return Number; 
}
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}
void InputUserNumbersInArray(int arr[100], int& length)
{
    bool AddMor = true;
    do
    {
        AddArrayElement(ReadNumber(), arr, length);
        cout << "\nDo you want to add more numbers ? [0]:No,[1]:yes ";
        cin >> AddMor;
    } while (AddMor);
}

bool YouWantToAddNum()
{
    bool YesorNo;
    cout << "Do you want to add more numbers ? yes[1],no[0] : ";
    cin >> YesorNo;
    return YesorNo;
}
void PrintArray(int arr[100], int length)
{
    cout << "array element : ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[100];      
    int arrLength = 0; 

    
    InputUserNumbersInArray(arr, arrLength);

    
    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array elements: ";
    PrintArray(arr, arrLength);

    return 0;  


}