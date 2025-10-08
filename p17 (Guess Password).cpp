#include<iostream>
#include<string>
using namespace std;

string ReadPass()
{
	string pass ;
	
	cout << "Please enter a 3-Letter Password (all capital)?\n";
	
	cin >> pass;
	
	return pass;
}

bool GuessPassword(string pass)
{ 
	string word;
	int Trial = 1;
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				Trial++;
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);

				cout << "Trial [" << Trial << "] : " << word << endl ;
				if (word == pass)
				{
					cout << "\n\n";
					cout <<"Password is " << word << "\n";
					cout << "Found after " << Trial << " try(s)";
					return true;
				}
				word = "";

			}
		}
		
	}
	return false;
}
int main()
{
	GuessPassword(ReadPass());
}