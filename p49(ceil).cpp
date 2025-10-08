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


int MyCeil(float Number)
{
	 
	if (abs(GetFractionPart(Number)) > 0)
	{
		if (Number > 0)
			return int(Number) + 1;  
		else
			return int(Number);  
	}
	else
		return Number;

	 
}
int main()
{
	float number = ReadNumber();
	cout << "My Ceil : " << MyCeil(number) << endl;
	cout << "c++ Ceil : "<<ceil(number);

	
	return 0;
}