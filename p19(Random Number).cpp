#include<iostream>
#include<string>
#include <cstdlib> //ممكن بزبط بدونها
using namespace std;

int RandomNumber(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;
	return randNum;
}
int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber(1, 5) << endl;
	cout << RandomNumber(1, 5) << endl;
	cout << RandomNumber(1, 5) << endl;

}