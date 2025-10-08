#include <iostream>
using namespace std;
float ReadNumber()
{
	float number;
	cout << "please enter number : ";
	cin >> number;
	return number;
}

int MySqrt(float Number)
{
	return pow(Number, 0.5);
}
int main()
{
	float number = ReadNumber();
	cout << "My Sqrt : " << MySqrt(number) << endl;
	cout << "c++ Sqrt : "<<sqrt(number);

	
	return 0;
}