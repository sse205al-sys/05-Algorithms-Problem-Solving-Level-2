#include <iostream>
using namespace std;
float ReadNumber()
{
	float number;
	cout << "please enter number : ";
	cin >> number;
	return number;
}
float GetFractionPart(float Number)
{
	return Number - int(Number);
}
int MyRound(float Number)
{
	 int intPart = int(Number);
	 float FractionPart = GetFractionPart(Number);
	 
	 if (abs(FractionPart) >= 0.5)
	 {
		 if (Number > 0)
			 return ++intPart;
		 else
			 return --intPart;
	 }
	 else
		 return intPart;
	 
}
int main()
{
	float number = ReadNumber();
	cout << "My Round : " << MyRound(number) << endl;
	cout << "c++ Round : "<<round(number);

	
	return 0;
}