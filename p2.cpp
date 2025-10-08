#include <iostream>
#include <string>
using namespace std;
 enum enPrime {prime =1, notprime=2};
 int readPositivNumber(string m)
 {
	 int num = 0;
	 do
	 {
		 cout << m;
		 cin >> num;
	 } while (num <= 0);
	 return num;
 }
 enPrime CheckPrime(int num)
 {
	 int M = round(num/2);
	 for (int c = 2; c <= M; c++)
	 {
		 if (num % c == 0)
			 return enPrime::notprime; 
	 }
	 return enPrime::prime;
 }
 
 void PrintAllPrime(int num)
 {
	 cout << "\n";
	
	 cout << "Prime Numbers from " << 1 << " To " << num;
	 cout << " are : " << endl;
	 for (int i = 1; i < num; i++)
	 {
		 if (CheckPrime(i) == enPrime::prime)
			 cout << i << endl;
	 }
 }
 int main()
 {
	 PrintAllPrime(readPositivNumber("p :"));
	 return 0;
 }