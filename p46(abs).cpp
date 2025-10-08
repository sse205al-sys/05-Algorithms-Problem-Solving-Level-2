
#include <iostream>
using namespace std;
float ReadNumber()
{
	float number;
	cout << "please enter number : ";
	cin >> number;
	return number;
}
 float MyAbs(float Number)
{
	 if (Number > 0)
		 return Number;
	 else
		 return Number * -1;
}
int main()
{
	float number = ReadNumber();
	cout << "My abs result : " << MyAbs(number) << endl;
	
	cout << "C++ abs result : " << abs(number) << endl;
	
	return 0;
}