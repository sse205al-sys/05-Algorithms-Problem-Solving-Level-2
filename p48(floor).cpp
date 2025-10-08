#include <iostream>
using namespace std;
float ReadNumber()
{
	float number;
	cout << "please enter number : ";
	cin >> number;
	return number;
}

int MyFloor(float Number)
{
	 
	 if (Number > 0)
	 {
		 return int(Number);
	 }
	 else
		 return int(Number) - 1;
	 
}
int main()
{
	float number = ReadNumber();
	cout << "My Floor : " << MyFloor(number) << endl;
	cout << "c++ Floor : "<<floor(number);

	
	return 0;
}